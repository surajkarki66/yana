"""Event-driven Conv2d helpers for the YANA CONV PE.

Geometry matches PyTorch ``nn.Conv2d`` / NIR ``Conv2d`` (NCHW):

    out[c, oy, ox] += W[c, cin, ky, kx] * in[cin, oy*s + ky*d - pad, ox*s + kx*d - pad]

A spike at input coordinate ``(cin, iy, ix)`` is the inverse of that relation.
Flattening is C-major: ``id = ((c * H) + y) * W + x``.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Iterable, List, Sequence, Tuple, Union

import numpy as np


IntPair = Tuple[int, int]


def as_pair(value: Union[int, Sequence[int], np.ndarray]) -> IntPair:
    """Coerce NIR/PyTorch stride-style fields to ``(h, w)``."""
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
    return (c * height + y) * width + x


def unflatten_nchw(index: int, height: int, width: int) -> Tuple[int, int, int]:
    x = index % width
    y = (index // width) % height
    c = index // (height * width)
    return c, y, x


def tap_index(cout: int, cin: int, ky: int, kx: int, in_channels: int, k_h: int, k_w: int) -> int:
    """Dense kernel tap id: ``((cout * Cin + cin) * Kh + ky) * Kw + kx``."""
    return ((cout * in_channels + cin) * k_h + ky) * k_w + kx


def kernel_tap_count(out_channels: int, in_channels: int, k_h: int, k_w: int) -> int:
    return out_channels * in_channels * k_h * k_w


@dataclass(frozen=True)
class ConvGeometry:
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
        return conv_output_hw(
            self.in_h, self.in_w, self.kernel, self.stride, self.padding, self.dilation
        )

    @property
    def out_h(self) -> int:
        return self.out_hw[0]

    @property
    def out_w(self) -> int:
        return self.out_hw[1]

    @property
    def k_h(self) -> int:
        return self.kernel[0]

    @property
    def k_w(self) -> int:
        return self.kernel[1]

    @property
    def n_in_axons(self) -> int:
        return self.in_channels * self.in_h * self.in_w

    @property
    def n_out_neurons(self) -> int:
        return self.out_channels * self.out_h * self.out_w

    @property
    def n_taps(self) -> int:
        return kernel_tap_count(self.out_channels, self.in_channels, self.k_h, self.k_w)

    def decode_input(self, axon_id: int) -> Tuple[int, int, int]:
        return unflatten_nchw(axon_id, self.in_h, self.in_w)

    def encode_output(self, cout: int, oy: int, ox: int) -> int:
        return flatten_nchw(cout, oy, ox, self.out_h, self.out_w)

    def encode_tap(self, cout: int, cin: int, ky: int, kx: int) -> int:
        return tap_index(cout, cin, ky, kx, self.in_channels, self.k_h, self.k_w)


@dataclass(frozen=True)
class ConvCharge:
    """One synaptic event produced by the CONV PE for a single input spike."""
    dest_neuron: int
    tap_id: int
    cout: int
    oy: int
    ox: int
    ky: int
    kx: int


def expand_input_spike(geom: ConvGeometry, cin: int, iy: int, ix: int) -> List[ConvCharge]:
    """Walk the kernel around one input spike and list in-bounds output charges."""
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
    cin, iy, ix = geom.decode_input(axon_id)
    if cin < 0 or cin >= geom.in_channels or iy < 0 or iy >= geom.in_h or ix < 0 or ix >= geom.in_w:
        return []
    return expand_input_spike(geom, cin, iy, ix)


def dense_kernel_taps(weight: np.ndarray) -> np.ndarray:
    """Flatten ``W[Cout, Cin, Kh, Kw]`` into tap-major order used by ``tap_index``."""
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
    """Accumulate dense feature-map charge from flattened input axon ids (one timestep)."""
    acc = np.zeros((geom.out_channels, geom.out_h, geom.out_w), dtype=np.float64)
    w = np.asarray(weight)
    for axon_id in events:
        for charge in expand_input_axon(geom, int(axon_id)):
            acc[charge.cout, charge.oy, charge.ox] += w[
                charge.cout, geom.decode_input(int(axon_id))[0], charge.ky, charge.kx
            ]
    return acc
