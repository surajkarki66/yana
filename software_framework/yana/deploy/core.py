import copy
import struct
from dataclasses import dataclass, field
from typing import Dict, List, NamedTuple, Optional, Set, Tuple

from yana.deploy.fixed_point import FixedPoint, float_to_fixed_point, max_value, min_value
from yana.core.logging import verbose

from yana.core.config import CoreConfig
from yana.deploy.conv import ConvGeometry, expand_input_axon as expand_input_axon_2d
from yana.deploy.conv1d import Conv1dGeometry, expand_input_axon as expand_input_axon_1d

class Route(NamedTuple):
    target_core: int
    target_neuron: int
    target_synapse: int

GlobalID = Tuple[str, int]

_PE_CORE_TYPES = (CoreConfig.Type.CONV, CoreConfig.Type.CONV1D)


@dataclass
class ConvRuntime:
    """State kept on a CONV / CONV1D core: geometry plus dest lookup for the following LIF layer.
    
    Attributes:
        geom: Conv2d or Conv1d geometry used by the PE
        dest_layer: NIR name of the dest LIF layer
        dest_core_of_neuron: Mesh core id per flattened output neuron
        dest_local_of_neuron: Core-local neuron id per flattened output neuron
        zero_taps: Tap ids with zero weight (skipped at expand time)
        pending_axons: Input axon ids queued for the next expand step
    """
    geom: object
    dest_layer: str
    dest_core_of_neuron: List[int]
    dest_local_of_neuron: List[int]
    zero_taps: Set[int] = field(default_factory=set)
    pending_axons: List[int] = field(default_factory=list)


def _to_float32(x: float) -> float:
    """Round a float64 to float32 precision, matching PyTorch's default tensor dtype.
    
    Args:
        x: Value to round
        
    Returns:
        x after a float32 round-trip
    """
    return struct.unpack('f', struct.pack('f', x))[0]


def _next_power_of_2(x: int) -> int:
    """Return the smallest power of two >= x (1 if x == 0).
    
    Args:
        x: Non-negative integer
        
    Returns:
        Next power of two
    """
    x = int(x)
    return 1 if x == 0 else 2 ** (x - 1).bit_length()


def _effective_leak_lut_len(tau_mem_inv: float, hardware_len: int) -> int:
    """Training-effective leak LUT length min(next_power_of_2(1/tau), hardware_len).
    
    Hardware may expose a longer LUT; sim truncates to this length so sparse
    layers (e.g. Conv→LIF) stay bit-exact with the torch model.
    
    Args:
        tau_mem_inv: Inverse membrane time constant
        hardware_len: Allocated hardware LUT depth
        
    Returns:
        Effective number of LUT entries used by the software sim
    """
    if tau_mem_inv <= 0 or hardware_len <= 0:
        return hardware_len
    return min(_next_power_of_2(int(1.0 / tau_mem_inv)), hardware_len)


def _create_leak_lut(core_config: CoreConfig) -> List[FixedPoint]:
    """Build the per-core leak factor LUT matching the training truncation length.
    
    Args:
        core_config: Core configuration (tau, leak enable, hardware LUT depth)
        
    Returns:
        LUT entries of length effective (empty if leak is disabled).
        Export pads zeros out to the full hardware depth.
    """
    if not core_config.neuron_config.leak_enabled:
        return []

    # Compute leak_per_ts in float32, matching the torch training path which stores
    # tau_mem_inv_l as a float32 tensor (torch.as_tensor defaults to float32) and
    # computes torch.pow(1 - tau_mem_inv_l, k) in float32.  Using float64 throughout
    # causes 1-ULP mismatches at large LUT indices for small tau_inv values.
    leak_per_ts_f32 = _to_float32(1.0 - _to_float32(core_config.neuron_config.tau_mem_inv))
    hardware_len = core_config.neuron_config.leak_lut_len
    # Match training ``leak_factor_lut_length``: sim treats indices beyond this as
    # out-of-range (membrane wiped). Export pads zeros out to hardware_len.
    effective = _effective_leak_lut_len(core_config.neuron_config.tau_mem_inv, hardware_len)

    # First entry (ts_diff = 0) is always 0.
    # Each subsequent entry is computed independently to avoid float32 accumulation error.
    lut: List[FixedPoint] = [FixedPoint(0, core_config.quant_config.format_tau_inv_l)]
    for k in range(1, effective):
        lut.append(float_to_fixed_point(_to_float32(leak_per_ts_f32 ** k), core_config.quant_config.format_tau_inv_l))

    return lut

class Core():
    id: int
    config: CoreConfig
    tau_mem_inv: FixedPoint
    leak_lut: List[FixedPoint]
    threshold: FixedPoint
    # This map keeps track of which weights are saved at what index in the weights list.
    # By having this, adding a weight if it is unique becomes O(1) operation instead of
    # a O(n) operation.
    weight_indices: Dict[FixedPoint, int]
    weights: List[FixedPoint]
    routes: Dict[int, List[Route]]

    # This map keeps track of which layers have which neurons mapped on this core
    # by mapping global ids [layer_name, layer_local_id] to core local ids [core_local_id].
    neuron_id_map: Dict[GlobalID, int]
    last_ts: List[int]
    states: List[FixedPoint]
    weight_sums_prev: List[FixedPoint]
    weight_sums_curr: List[FixedPoint]

    def __init__(self, id: int, core_config: CoreConfig):
        self.id = id
        self.config = core_config
        self.tau_mem_inv = float_to_fixed_point(core_config.neuron_config.tau_mem_inv, core_config.quant_config.format_tau_inv_j)
        self.leak_lut = _create_leak_lut(core_config)
        self.threshold = float_to_fixed_point(core_config.neuron_config.threshold, core_config.quant_config.format_threshold)
        self.weight_indices = {}
        self.weights = []
        self.routes = {}

        self.neuron_id_map = {}
        self.last_ts = []
        self.states = []
        self.weight_sums_prev = []
        self.weight_sums_curr = []

        self._neuron_state_min = min_value(core_config.quant_config.format_state)
        self._neuron_state_max = max_value(core_config.quant_config.format_state)

        self.conv: Optional[ConvRuntime] = None

        if core_config.type == CoreConfig.Type.OUTPUT:
            self.output_states: Dict[int, List[FixedPoint]] = {}

    def apply_input(self, dest_enc_spike: Route):
        assert dest_enc_spike.target_core == self.id, f"Wrong target core id: required {self.id}, got {dest_enc_spike.target_core}"
        if self.config.type in _PE_CORE_TYPES:
            assert self.conv is not None, f"PE core {self.id} has no conv runtime"
            # Incoming event payload.neuron_id is the flattened input axon.
            self.conv.pending_axons.append(dest_enc_spike.target_neuron)
            return
        # trace(f"    Spike: core [{dest_enc_spike.target_core}], neuron [{dest_enc_spike.target_neuron}], synapse [{dest_enc_spike.target_synapse}]")

        weight = self.weights[dest_enc_spike.target_synapse]
        try:
            weight_sum_curr = self.weight_sums_curr[dest_enc_spike.target_neuron]
        except IndexError:
            raise IndexError(f"Invalid target neuron id {dest_enc_spike.target_neuron} for core {self.id} with only {self.num_neurons()} neurons")

        # trace(f"      Applied weight: neuron_id {dest_enc_spike.target_neuron}, weight [{weight}]")
        # trace(f"        Weight sum before: {weight_sum_curr}")
        weight_sum_curr += weight
        weight_sum_curr = weight_sum_curr.resized(self.config.quant_config.format_weight_sum)
        # trace(f"        Weight sum after:  {weight_sum_curr}")

    def apply_update(self, timestep: int, force_update: bool = False, injected_spikes: Optional[List[int]] = None) -> List[Route]:
        if self.config.type in _PE_CORE_TYPES:
            return self._conv_expand()

        src_enc_spikes = injected_spikes if injected_spikes is not None else []

        # Swap weight sums
        self.weight_sums_prev = self.weight_sums_curr
        self.weight_sums_curr = [FixedPoint(0, self.config.quant_config.format_weight_sum) for _ in range(self.num_neurons())]

        for neuron_id in range(self.num_neurons()):
            if self.id >= 0:
                verbose(f"\n    Started neuron update for neuron_id {neuron_id}")

            # If no input has been received, skip neuron update
            if not force_update and self.weight_sums_prev[neuron_id].value == 0:
                if self.id >= 0:
                    verbose(f"      Weight sum is 0, skipping neuron update. Keeping previous state: {self.states[neuron_id]}")
                continue

            if self.config.neuron_config.leak_enabled:
                # Apply leak
                timestep_diff = timestep - self.last_ts[neuron_id]
                self.last_ts[neuron_id] = timestep

                verbose(f"      State before update:            {self.states[neuron_id]}")

                # Leak calculation
                if timestep_diff > len(self.leak_lut) - 1:
                    self.states[neuron_id] *= float_to_fixed_point(0.0, self.config.quant_config.format_tau_inv_l)
                else:
                    leak_factor = self.leak_lut[timestep_diff]
                    if leak_factor.value > 0: # First entry in leak LUT (ts_diff = 0) is 0
                        self.states[neuron_id] *= leak_factor
                    else:
                        self.states[neuron_id] = self.states[neuron_id].resized_like(
                            self.states[neuron_id] * leak_factor
                        )

                verbose(f"      Leaked state:                   {self.states[neuron_id]}")

            # Compute leaked input and update state
            if not self.config.neuron_config.emit_spikes and not self.config.neuron_config.leak_enabled:
                # If both spiking and leak are disabled (I-neuron), don't multiply with
                # tau and instead only resize the input.
                # FIXME: make this a separate field in the 'neuron_config'!
                leaked_input = self.weight_sums_prev[neuron_id].resized_like(
                    self.weight_sums_prev[neuron_id] * self.tau_mem_inv
                )
            else:
                leaked_input = self.weight_sums_prev[neuron_id] * self.tau_mem_inv

            self.states[neuron_id] += leaked_input

            verbose(f"      Weight sum:                     {self.weight_sums_prev[neuron_id]}")
            verbose(f"      Leaked input:                   {leaked_input}")
            verbose(f"      State after update:             {self.states[neuron_id]}")

            compressed_state = self.states[neuron_id].resized(self.config.quant_config.format_state)
            verbose(f"      Neuron state after compression: {compressed_state}")

            if compressed_state < self._neuron_state_min:
                self.states[neuron_id] = copy.deepcopy(self._neuron_state_min)
                verbose(f"      Clipping neuron state to min:   {self._neuron_state_min}")
            else:
                if self.config.neuron_config.emit_spikes:
                    if self.states[neuron_id] >= self.threshold:
                        self.states[neuron_id] = float_to_fixed_point(0.0, self.config.quant_config.format_state)
                        src_enc_spikes.append(neuron_id)
                        verbose(f"      Neuron spiked, state reset to:  {self.states[neuron_id]}")
                    else:
                        self.states[neuron_id] = compressed_state
                else:
                    if compressed_state > self._neuron_state_max:
                        self.states[neuron_id] = copy.deepcopy(self._neuron_state_max)
                        verbose(f"      Clipping neuron state to max:   {self._neuron_state_max}")
                    else:
                        self.states[neuron_id] = compressed_state

        # Multicast source encoded spikes to destination encoded spikes
        dest_enc_spikes: List[Route] = []
        for source_neuron_id in src_enc_spikes:
            if source_neuron_id in self.routes:
                dest_enc_spikes.extend(self.routes[source_neuron_id])

        # Record neuron states if core is output core
        if self.config.type == CoreConfig.Type.OUTPUT:
            self.output_states[timestep] = copy.deepcopy(self.states)

        return dest_enc_spikes

    def add_neuron(self, global_id: GlobalID, compress: bool = True) -> int:
        if global_id in self.neuron_id_map:
            # Neuron already exists, return core-local ID
            return self.neuron_id_map[global_id]
        else:
            if compress:
                core_local_id = self.num_neurons()
            else:
                core_local_id = global_id[1]    # Core-local ID = layer-local ID

            self.neuron_id_map[global_id] = core_local_id

            self.last_ts.append(0)
            self.states.append(FixedPoint(0, self.config.quant_config.format_state))
            self.weight_sums_prev.append(FixedPoint(0, self.config.quant_config.format_weight_sum))
            self.weight_sums_curr.append(FixedPoint(0, self.config.quant_config.format_weight_sum))
            return core_local_id

    def add_weight(self, weight_value: float) -> int:
        weight = float_to_fixed_point(weight_value, self.config.quant_config.format_weights)
        if weight.value == 0:   # 0-valued weights are not relevant
            return -1
        # Use dictionary for fast lookup
        if weight not in self.weight_indices:
            self.weights.append(weight)
            self.weight_indices[weight] = len(self.weights) - 1
        weight_id = self.weight_indices[weight]
        return weight_id

    def add_weight_sequential(self, weight_value: float) -> int:
        """Append a weight at the next index even if the value is 0 or a duplicate.
        
        CONV kernel taps are addressed geometrically (tap_id), so slots must
        stay aligned with (cout, cin, ky, kx) rather than unique-value packed.
        
        Args:
            weight_value: Floating-point synaptic weight
            
        Returns:
            Newly assigned weight / tap index
        """
        weight = float_to_fixed_point(weight_value, self.config.quant_config.format_weights)
        self.weights.append(weight)
        if weight not in self.weight_indices:
            self.weight_indices[weight] = len(self.weights) - 1
        return len(self.weights) - 1

    def _conv_expand(self) -> List[Route]:
        """Expand pending input axons into dest-encoded charge routes.
        
        Returns:
            List of Route(dest_core, dest_neuron, tap_id) for non-zero taps
        """
        assert self.conv is not None, f"PE core {self.id} has no conv runtime"
        dest_enc_spikes: List[Route] = []
        geom = self.conv.geom
        if isinstance(geom, Conv1dGeometry):
            expand_fn = expand_input_axon_1d
        elif isinstance(geom, ConvGeometry):
            expand_fn = expand_input_axon_2d
        else:
            raise TypeError(f"Unsupported conv geometry type: {type(geom)!r}")
        for axon_id in self.conv.pending_axons:
            for charge in expand_fn(geom, axon_id):
                if charge.tap_id in self.conv.zero_taps:
                    continue
                dest_core_id = self.conv.dest_core_of_neuron[charge.dest_neuron]
                dest_local_id = self.conv.dest_local_of_neuron[charge.dest_neuron]
                dest_enc_spikes.append(Route(dest_core_id, dest_local_id, charge.tap_id))
        self.conv.pending_axons.clear()
        return dest_enc_spikes

    def add_route(self, pre_global_id: GlobalID, route: Route):
        pre_core_local_id = self.get_core_local_id(pre_global_id)
        # If no core-local ID is given yet, create one.
        # (This happens for example for input neurons)
        if pre_core_local_id == -1:
            # NOTE: this line is assumed to only be reached for input neurons
            assert self.config.type == CoreConfig.Type.INPUT, "This should only be reached for input cores"
            pre_core_local_id = self.add_neuron(pre_global_id, compress=False)

        if pre_core_local_id not in self.routes:
            self.routes[pre_core_local_id] = []
        self.routes[pre_core_local_id].append(route)

    def get_core_local_id(self, global_id: GlobalID) -> int:
        if global_id in self.neuron_id_map:
            return self.neuron_id_map[global_id]
        return -1

    def reset(self):
        self.weight_sums_curr = [FixedPoint(0, self.config.quant_config.format_weight_sum) for _ in range(self.num_neurons())]
        self.weight_sums_prev = [FixedPoint(0, self.config.quant_config.format_weight_sum) for _ in range(self.num_neurons())]
        self.states = [FixedPoint(0, self.config.quant_config.format_state) for _ in range(self.num_neurons())]
        self.last_ts = [0 for _ in range(self.num_neurons())]
        self.output_states = {}
        if self.conv is not None:
            self.conv.pending_axons.clear()

    def num_neurons(self):
        return len(self.neuron_id_map)
