from __future__ import annotations


import numpy as np


from dataclasses import dataclass
from typing import Iterable, List, Sequence, Tuple, Union


IntPair = Tuple[int, int]


def as_pair(value: Union[int, Sequence[int], np.ndarray]) -> IntPair:
    """Converts a single value or sequence into a pair (height, width).
    
    Args:
        value: Scalar or length-1/2 sequence (int, list, or ndarray)
        
    Returns:
        Pair (h, w): a scalar is broadcast to both axes
    """
    if isinstance(value, (int, np.integer)):
        v = int(value)
        return (v, v)
    arr = np.asarray(value).flatten()
    if arr.size == 0:
        raise ValueError("Empty spatial pair")
    if arr.size == 1:
        v = int(arr[0])
        return (v, v)
    return (int(arr[0]), int(arr[1]))


def conv_output_hw(
    in_h: int,
    in_w: int,
    kernel: IntPair,
    stride: IntPair,
    padding: IntPair,
    dilation: IntPair,
) -> IntPair:
    """Compute Conv2d output spatial size.
    
    Args:
        in_h: Input height
        in_w: Input width
        kernel: Kernel size (kh, kw)
        stride: Stride (sh, sw)
        padding: Padding (ph, pw)
        dilation: Dilation (dh, dw)
        
    Returns:
        Output size (out_h, out_w)
    """
    k_h, k_w = kernel
    s_h, s_w = stride
    p_h, p_w = padding
    d_h, d_w = dilation
    out_h = (in_h + 2 * p_h - d_h * (k_h - 1) - 1) // s_h + 1
    out_w = (in_w + 2 * p_w - d_w * (k_w - 1) - 1) // s_w + 1
    if out_h <= 0 or out_w <= 0:
        raise ValueError(
            f"Conv2d output size is non-positive: {(out_h, out_w)} "
            f"from in=({in_h},{in_w}) k={kernel} stride={stride} pad={padding} dil={dilation}"
        )
    return (out_h, out_w)


def flatten_nchw(c: int, y: int, x: int, height: int, width: int) -> int:
    """Converts a channel, row, and column coordinate into a single linear neuron ID.
    
    Args:
        c: Channel index
        y: Row index
        x: Column index
        height: Feature-map height
        width: Feature-map width
        
    Returns:
        Linear id: ((c * H) + y) * W + x
    """
    return (c * height + y) * width + x


def unflatten_nchw(index: int, height: int, width: int) -> Tuple[int, int, int]:
    """Inverse of flatten_nchw.
    
    Args:
        index: Linear axon/neuron id
        height: Feature-map height
        width: Feature-map width
        
    Returns:
        Tuple (c, y, x)
    """
    x = index % width
    y = (index // width) % height
    c = index // (height * width)
    return c, y, x


def tap_index(cout: int, cin: int, ky: int, kx: int, in_channels: int, k_h: int, k_w: int) -> int:
    """Dense kernel tap id in shared-weight RAM order.
    
    Args:
        cout: Output channel
        cin: Input channel
        ky: Kernel row
        kx: Kernel column
        in_channels: Number of input channels
        k_h: Kernel height
        k_w: Kernel width
        
    Returns:
        Tap id ``((cout * Cin + cin) * Kh + ky) * Kw + kx``
    """
    return ((cout * in_channels + cin) * k_h + ky) * k_w + kx


def kernel_tap_count(out_channels: int, in_channels: int, k_h: int, k_w: int) -> int:
    """Number of taps in a dense Conv2d kernel.
    
    Args:
        out_channels: Number of output channels
        in_channels: Number of input channels
        k_h: Kernel height
        k_w: Kernel width
        
    Returns:
        ``out_channels * in_channels * k_h * k_w``
    """
    return out_channels * in_channels * k_h * k_w


@dataclass(frozen=True)
class ConvGeometry:
    """Immutable Conv2d geometry used by the event-driven CONV PE.
    
    Attributes:
        in_channels: Number of input channels
        out_channels: Number of output channels
        in_h: Input height
        in_w: Input width
        kernel: Kernel size ``(kh, kw)``
        stride: Stride ``(sh, sw)``
        padding: Padding ``(ph, pw)``
        dilation: Dilation ``(dh, dw)``
    """
    in_channels: int
    out_channels: int
    in_h: int
    in_w: int
    kernel: IntPair
    stride: IntPair
    padding: IntPair
    dilation: IntPair

    @property
    def out_hw(self) -> IntPair:
        """Output spatial size ``(out_h, out_w)``."""
        return conv_output_hw(
            self.in_h, self.in_w, self.kernel, self.stride, self.padding, self.dilation
        )

    @property
    def out_h(self) -> int:
        """Output height."""
        return self.out_hw[0]

    @property
    def out_w(self) -> int:
        """Output width."""
        return self.out_hw[1]

    @property
    def k_h(self) -> int:
        """Kernel height."""
        return self.kernel[0]

    @property
    def k_w(self) -> int:
        """Kernel width."""
        return self.kernel[1]

    @property
    def n_in_axons(self) -> int:
        """Number of flattened input axons ``Cin * Hin * Win``."""
        return self.in_channels * self.in_h * self.in_w

    @property
    def n_out_neurons(self) -> int:
        """Number of flattened output LIF neurons ``Cout * Hout * Wout``."""
        return self.out_channels * self.out_h * self.out_w

    @property
    def n_taps(self) -> int:
        """Number of shared kernel taps."""
        return kernel_tap_count(self.out_channels, self.in_channels, self.k_h, self.k_w)

    def decode_input(self, axon_id: int) -> Tuple[int, int, int]:
        """Decode a flattened input axon id to ``(cin, iy, ix)``.
        
        Args:
            axon_id: Flattened input axon index
            
        Returns:
            Tuple ``(cin, iy, ix)``
        """
        return unflatten_nchw(axon_id, self.in_h, self.in_w)

    def encode_output(self, cout: int, oy: int, ox: int) -> int:
        """Encode an output feature-map coordinate to a flat neuron id.
        
        Args:
            cout: Output channel
            oy: Output row
            ox: Output column
            
        Returns:
            Flattened dest neuron id
        """
        return flatten_nchw(cout, oy, ox, self.out_h, self.out_w)

    def encode_tap(self, cout: int, cin: int, ky: int, kx: int) -> int:
        """Encode a kernel tap to its weight-RAM index.
        
        Args:
            cout: Output channel
            cin: Input channel
            ky: Kernel row
            kx: Kernel column
            
        Returns:
            Tap / synapse id
        """
        return tap_index(cout, cin, ky, kx, self.in_channels, self.k_h, self.k_w)


@dataclass(frozen=True)
class ConvCharge:
    """One synaptic event produced by the CONV PE for a single input spike.
    
    Attributes:
        dest_neuron: Flattened output LIF neuron id
        tap_id: Shared-kernel weight index on the dest core
        cout: Output channel of this charge
        oy: Output row
        ox: Output column
        ky: Kernel row that produced this charge
        kx: Kernel column that produced this charge
    """
    dest_neuron: int
    tap_id: int
    cout: int
    oy: int
    ox: int
    ky: int
    kx: int


def expand_input_spike(geom: ConvGeometry, cin: int, iy: int, ix: int) -> List[ConvCharge]:
    """Walk the kernel around one input spike and list in-bounds output charges.
    
    Args:
        geom: Conv2d geometry
        cin: Input channel of the spike
        iy: Input row of the spike
        ix: Input column of the spike
        
    Returns:
        List of ``ConvCharge`` events (may be empty if fully out of bounds)
    """
    s_h, s_w = geom.stride
    p_h, p_w = geom.padding
    d_h, d_w = geom.dilation
    charges: List[ConvCharge] = []
    for ky in range(geom.k_h):
        for kx in range(geom.k_w):
            h_im = iy + p_h - ky * d_h
            w_im = ix + p_w - kx * d_w
            if h_im < 0 or w_im < 0 or (h_im % s_h) != 0 or (w_im % s_w) != 0:
                continue
            oy = h_im // s_h
            ox = w_im // s_w
            if oy >= geom.out_h or ox >= geom.out_w:
                continue
            for cout in range(geom.out_channels):
                charges.append(
                    ConvCharge(
                        dest_neuron=geom.encode_output(cout, oy, ox),
                        tap_id=geom.encode_tap(cout, cin, ky, kx),
                        cout=cout,
                        oy=oy,
                        ox=ox,
                        ky=ky,
                        kx=kx,
                    )
                )
    return charges


def expand_input_axon(geom: ConvGeometry, axon_id: int) -> List[ConvCharge]:
    """Expand a flattened input axon spike into dest charges.
    
    Args:
        geom: Conv2d geometry
        axon_id: Flattened input axon id ``(cin, iy, ix)``
        
    Returns:
        List of ``ConvCharge`` events (empty if ``axon_id`` is out of range)
    """
    cin, iy, ix = geom.decode_input(axon_id)
    if cin < 0 or cin >= geom.in_channels or iy < 0 or iy >= geom.in_h or ix < 0 or ix >= geom.in_w:
        return []
    return expand_input_spike(geom, cin, iy, ix)


def dense_kernel_taps(weight: np.ndarray) -> np.ndarray:
    """Flatten ``W[Cout, Cin, Kh, Kw]`` into tap-major order used by ``tap_index``.
    
    Args:
        weight: Dense Conv2d weight tensor of shape ``(Cout, Cin, Kh, Kw)``
        
    Returns:
        1-D array of length ``Cout * Cin * Kh * Kw`` in tap-id order
    """
    if weight.ndim != 4:
        raise ValueError(f"Conv2d weight must be 4-D (Cout, Cin, Kh, Kw), got shape {weight.shape}")
    out_ch, in_ch, k_h, k_w = weight.shape
    taps = np.empty((out_ch * in_ch * k_h * k_w,), dtype=weight.dtype)
    for cout in range(out_ch):
        for cin in range(in_ch):
            for ky in range(k_h):
                for kx in range(k_w):
                    taps[tap_index(cout, cin, ky, kx, in_ch, k_h, k_w)] = weight[cout, cin, ky, kx]
    return taps


def reference_conv2d_from_events(
    events: Iterable[int],
    geom: ConvGeometry,
    weight: np.ndarray,
) -> np.ndarray:
    """Accumulate dense feature-map charge from flattened input axon ids (one timestep).
    
    Args:
        events: Iterable of flattened input axon ids that spiked
        geom: Conv2d geometry
        weight: Dense kernel ``(Cout, Cin, Kh, Kw)``
        
    Returns:
        Accumulated charge of shape ``(Cout, Hout, Wout)``
    """
    acc = np.zeros((geom.out_channels, geom.out_h, geom.out_w), dtype=np.float64)
    w = np.asarray(weight)
    for axon_id in events:
        for charge in expand_input_axon(geom, int(axon_id)):
            acc[charge.cout, charge.oy, charge.ox] += w[
                charge.cout, geom.decode_input(int(axon_id))[0], charge.ky, charge.kx
            ]
    return acc
