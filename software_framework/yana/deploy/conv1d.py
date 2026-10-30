from __future__ import annotations

from dataclasses import dataclass
from typing import Iterable, List, Tuple

import numpy as np


def conv1d_output_length(
    in_length: int,
    kernel_size: int,
    stride: int,
    padding: int,
    dilation: int,
) -> int:
    """Compute Conv1d output length.

    Args:
        in_length: Input sequence length
        kernel_size: Kernel size (K)
        stride: Stride
        padding: Padding
        dilation: Dilation

    Returns:
        Output length (L_out)
    """
    out_l = (in_length + 2 * padding - dilation * (kernel_size - 1) - 1) // stride + 1
    if out_l <= 0:
        raise ValueError(
            f"Conv1d output length is non-positive: {out_l} "
            f"from in={in_length} k={kernel_size} stride={stride} pad={padding} dil={dilation}"
        )
    return out_l


def flatten_cl(c: int, x: int, length: int) -> int:
    """Converts a channel and position into a single linear neuron ID.

    Args:
        c: Channel index
        x: Position along the length axis
        length: Feature-map length (L)

    Returns:
        Linear id: c * L + x
    """
    return c * length + x


def unflatten_cl(index: int, length: int) -> Tuple[int, int]:
    """Inverse of flatten_cl.

    Args:
        index: Linear axon/neuron id
        length: Feature-map length (L)

    Returns:
        Tuple (c, x)
    """
    x = index % length
    c = index // length
    return c, x


def tap_index_1d(cout: int, cin: int, kx: int, in_channels: int, kernel_size: int) -> int:
    """Dense kernel tap id in shared-weight RAM order.

    Args:
        cout: Output channel
        cin: Input channel
        kx: Kernel tap index
        in_channels: Number of input channels
        kernel_size: Kernel size (K)

    Returns:
        Tap id (cout * Cin + cin) * K + kx
    """
    return (cout * in_channels + cin) * kernel_size + kx


def kernel_tap_count_1d(out_channels: int, in_channels: int, kernel_size: int) -> int:
    """Number of taps in a dense Conv1d kernel.

    Args:
        out_channels: Number of output channels
        in_channels: Number of input channels
        kernel_size: Kernel size (K)

    Returns:
        out_channels * in_channels * kernel_size
    """
    return out_channels * in_channels * kernel_size


@dataclass(frozen=True)
class Conv1dGeometry:
    """Immutable Conv1d geometry used by the event-driven CONV1D PE.

    Attributes:
        in_channels: Number of input channels
        out_channels: Number of output channels
        in_length: Input sequence length
        kernel_size: Kernel size (K)
        stride: Stride
        padding: Padding
        dilation: Dilation
    """

    in_channels: int
    out_channels: int
    in_length: int
    kernel_size: int
    stride: int
    padding: int
    dilation: int

    @property
    def out_length(self) -> int:
        """Output sequence length (L_out)"""
        return conv1d_output_length(
            self.in_length, self.kernel_size, self.stride, self.padding, self.dilation
        )

    @property
    def n_in_axons(self) -> int:
        """Number of flattened input axons (Cin * Lin)"""
        return self.in_channels * self.in_length

    @property
    def n_out_neurons(self) -> int:
        """Number of flattened output LIF neurons  (Cout * Lout)."""
        return self.out_channels * self.out_length

    @property
    def n_taps(self) -> int:
        """Number of shared kernel taps."""
        return kernel_tap_count_1d(self.out_channels, self.in_channels, self.kernel_size)

    def decode_input(self, axon_id: int) -> Tuple[int, int]:
        """Decode a flattened input axon id to (cin, ix).

        Args:
            axon_id: Flattened input axon index

        Returns:
            Tuple (cin, ix)
        """
        return unflatten_cl(axon_id, self.in_length)

    def encode_output(self, cout: int, ox: int) -> int:
        """Encode an output feature-map coordinate to a flat neuron id.

        Args:
            cout: Output channel
            ox: Output position

        Returns:
            Flattened dest neuron id
        """
        return flatten_cl(cout, ox, self.out_length)

    def encode_tap(self, cout: int, cin: int, kx: int) -> int:
        """Encode a kernel tap to its weight-RAM index.

        Args:
            cout: Output channel
            cin: Input channel
            kx: Kernel tap index

        Returns:
            Tap / synapse id
        """
        return tap_index_1d(cout, cin, kx, self.in_channels, self.kernel_size)


@dataclass(frozen=True)
class Conv1dCharge:
    """One synaptic event produced by the CONV1D PE for a single input spike.

    Attributes:
        dest_neuron: Flattened output LIF neuron id
        tap_id: Shared-kernel weight index on the dest core
        cout: Output channel of this charge
        ox: Output position
        kx: Kernel tap that produced this charge
    """

    dest_neuron: int
    tap_id: int
    cout: int
    ox: int
    kx: int


def expand_input_spike(geom: Conv1dGeometry, cin: int, ix: int) -> List[Conv1dCharge]:
    """Walk the 1-D kernel around one input spike and list in-bounds output charges.

    Args:
        geom: Conv1d geometry
        cin: Input channel of the spike
        ix: Input position of the spike

    Returns:
        List of Conv1dCharge events (may be empty if fully out of bounds)
    """
    charges: List[Conv1dCharge] = []
    for kx in range(geom.kernel_size):
        w_im = ix + geom.padding - kx * geom.dilation
        if w_im < 0 or (w_im % geom.stride) != 0:
            continue
        ox = w_im // geom.stride
        if ox >= geom.out_length:
            continue
        for cout in range(geom.out_channels):
            charges.append(
                Conv1dCharge(
                    dest_neuron=geom.encode_output(cout, ox),
                    tap_id=geom.encode_tap(cout, cin, kx),
                    cout=cout,
                    ox=ox,
                    kx=kx,
                )
            )
    return charges


def expand_input_axon(geom: Conv1dGeometry, axon_id: int) -> List[Conv1dCharge]:
    """Expand a flattened input axon spike into dest charges.

    Args:
        geom: Conv1d geometry
        axon_id: Flattened input axon id (cin, ix)

    Returns:
        List of Conv1dCharge events (empty if axon_id is out of range)
    """
    cin, ix = geom.decode_input(axon_id)
    if cin < 0 or cin >= geom.in_channels or ix < 0 or ix >= geom.in_length:
        return []
    return expand_input_spike(geom, cin, ix)


def dense_kernel_taps_1d(weight: np.ndarray) -> np.ndarray:
    """Flatten W[Cout, Cin, K] into tap-major order used by tap_index_1d.

    Args:
        weight: Dense Conv1d weight tensor of shape (Cout, Cin, K)

    Returns:
        1-D array of length  (Cout * Cin * K) in tap-id order
    """
    if weight.ndim != 3:
        raise ValueError(f"Conv1d weight must be 3-D (Cout, Cin, K), got shape {weight.shape}")
    out_ch, in_ch, k = weight.shape
    taps = np.empty((out_ch * in_ch * k,), dtype=weight.dtype)
    for cout in range(out_ch):
        for cin in range(in_ch):
            for kx in range(k):
                taps[tap_index_1d(cout, cin, kx, in_ch, k)] = weight[cout, cin, kx]
    return taps


def reference_conv1d_from_events(
    events: Iterable[int],
    geom: Conv1dGeometry,
    weight: np.ndarray,
) -> np.ndarray:
    """Accumulate dense feature-map charge from flattened input axon ids (one timestep).

    Args:
        events: Iterable of flattened input axon ids that spiked
        geom: Conv1d geometry
        weight: Dense kernel (Cout, Cin, K)

    Returns:
        Accumulated charge of shape (Cout, Lout)
    """
    acc = np.zeros((geom.out_channels, geom.out_length), dtype=np.float64)
    w = np.asarray(weight)
    for axon_id in events:
        cin, _ = geom.decode_input(int(axon_id))
        for charge in expand_input_axon(geom, int(axon_id)):
            acc[charge.cout, charge.ox] += w[charge.cout, cin, charge.kx]
    return acc
