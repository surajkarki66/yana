"""Unit tests for event-driven Conv2d geometry (no RTL, no training)."""

import os
import sys
import unittest

import numpy as np

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from yana.deploy.conv import (
    ConvGeometry,
    conv_output_hw,
    expand_input_axon,
    flatten_nchw,
    reference_conv2d_from_events,
    unflatten_nchw,
)


class ConvGeometryTests(unittest.TestCase):
    def test_flatten_roundtrip(self):
        h, w = 4, 5
        for c in range(3):
            for y in range(h):
                for x in range(w):
                    idx = flatten_nchw(c, y, x, h, w)
                    self.assertEqual(unflatten_nchw(idx, h, w), (c, y, x))

    def test_output_hw_matches_pytorch_formula(self):
        self.assertEqual(conv_output_hw(5, 5, (3, 3), (1, 1), (0, 0), (1, 1)), (3, 3))
        self.assertEqual(conv_output_hw(17, 17, (3, 3), (2, 2), (1, 1), (1, 1)), (9, 9))

    def test_center_spike_full_kernel(self):
        geom = ConvGeometry(
            in_channels=1, out_channels=2, in_h=5, in_w=5,
            kernel=(3, 3), stride=(1, 1), padding=(0, 0), dilation=(1, 1),
        )
        # Center pixel (2,2) of a 5x5 valid 3x3 conv hits every output location.
        charges = expand_input_axon(geom, flatten_nchw(0, 2, 2, 5, 5))
        self.assertEqual(len(charges), 2 * 3 * 3)

    def test_event_accum_matches_dense_conv(self):
        try:
            import torch
        except ImportError:
            self.skipTest("torch not installed")

        cin, cout, h, w, k = 2, 3, 6, 6, 3
        stride, pad = 1, 1
        torch.manual_seed(0)
        weight = torch.randn(cout, cin, k, k)
        conv = torch.nn.Conv2d(cin, cout, k, stride=stride, padding=pad, bias=False)
        with torch.no_grad():
            conv.weight.copy_(weight)

        # Sparse binary input
        x = torch.zeros(1, cin, h, w)
        rng = np.random.default_rng(1)
        events = []
        for c in range(cin):
            for y in range(h):
                for xx in range(w):
                    if rng.random() < 0.2:
                        x[0, c, y, xx] = 1.0
                        events.append(flatten_nchw(c, y, xx, h, w))

        with torch.no_grad():
            y_ref = conv(x)[0].numpy()

        geom = ConvGeometry(
            in_channels=cin, out_channels=cout, in_h=h, in_w=w,
            kernel=(k, k), stride=(stride, stride), padding=(pad, pad), dilation=(1, 1),
        )
        y_evt = reference_conv2d_from_events(events, geom, weight.numpy())
        np.testing.assert_allclose(y_evt, y_ref, rtol=1e-5, atol=1e-5)


if __name__ == "__main__":
    unittest.main()
