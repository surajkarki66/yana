"""Unit tests for event-driven Conv1d geometry"""

import os
import sys
import unittest

import numpy as np

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from yana.deploy.conv1d import (
    Conv1dGeometry,
    conv1d_output_length,
    expand_input_axon,
    flatten_cl,
    reference_conv1d_from_events,
    unflatten_cl,
)


class Conv1dGeometryTests(unittest.TestCase):
    def test_flatten_roundtrip(self):
        length = 11
        for c in range(3):
            for x in range(length):
                idx = flatten_cl(c, x, length)
                self.assertEqual(unflatten_cl(idx, length), (c, x))

    def test_output_length_matches_pytorch_formula(self):
        self.assertEqual(conv1d_output_length(175, 7, 2, 3, 1), 88)
        self.assertEqual(conv1d_output_length(10, 3, 1, 0, 1), 8)

    def test_center_spike_full_kernel(self):
        geom = Conv1dGeometry(
            in_channels=1, out_channels=2, in_length=9,
            kernel_size=3, stride=1, padding=0, dilation=1,
        )
        # Center of length-9 valid-3 conv hits every output (out_l=7).
        charges = expand_input_axon(geom, flatten_cl(0, 4, 9))
        self.assertEqual(len(charges), 2 * 3)

    def test_event_accum_matches_dense_conv(self):
        try:
            import torch
        except ImportError:
            self.skipTest("torch not installed")

        cin, cout, length, k = 2, 3, 16, 5
        stride, pad = 1, 2
        torch.manual_seed(0)
        weight = torch.randn(cout, cin, k)
        conv = torch.nn.Conv1d(cin, cout, k, stride=stride, padding=pad, bias=False)
        with torch.no_grad():
            conv.weight.copy_(weight)

        x = torch.zeros(1, cin, length)
        rng = np.random.default_rng(1)
        events = []
        for c in range(cin):
            for xx in range(length):
                if rng.random() < 0.25:
                    x[0, c, xx] = 1.0
                    events.append(flatten_cl(c, xx, length))

        with torch.no_grad():
            y_ref = conv(x)[0].numpy()

        geom = Conv1dGeometry(
            in_channels=cin, out_channels=cout, in_length=length,
            kernel_size=k, stride=stride, padding=pad, dilation=1,
        )
        y_evt = reference_conv1d_from_events(events, geom, weight.numpy())
        np.testing.assert_allclose(y_evt, y_ref, rtol=1e-5, atol=1e-5)


if __name__ == "__main__":
    unittest.main()
