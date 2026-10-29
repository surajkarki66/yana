"""Deploy + golden-sim smoke test for Conv2d → LIF on the CONV PE."""

import os
import sys
import tempfile
import unittest

import numpy as np

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from yana.core.config import AcceleratorConfig, CoreConfig
from yana.deploy.accelerator import Accelerator
from yana.deploy.conv import ConvGeometry, flatten_nchw, reference_conv2d_from_events
from yana.deploy.file_export import write_accelerator_memories, write_conv_pe_config


def _software_framework_root() -> str:
    return os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


class ConvDeployTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        os.chdir(_software_framework_root())

    def _tiny_cnn_graph(self):
        import nir

        cin, hin, win = 1, 5, 5
        cout, k = 2, 3
        stride, pad = 1, 0
        out_h, out_w = 3, 3
        n_out = cout * out_h * out_w
        n_class = 3

        weight = np.full((cout, cin, k, k), 0.5, dtype=np.float32)
        bias = np.zeros((cout,), dtype=np.float32)
        conv = nir.Conv2d(
            input_shape=(hin, win),
            weight=weight,
            stride=stride,
            padding=pad,
            dilation=1,
            groups=1,
            bias=bias,
        )
        conv.input_type = {"input": np.array([cin, hin, win])}
        conv.output_type = {"output": np.array([cout, out_h, out_w])}

        ones = np.ones(n_out, dtype=np.float32)
        lif = nir.LIF(
            tau=ones * 4.0,
            r=ones,
            v_leak=np.zeros(n_out, dtype=np.float32),
            v_threshold=ones * 0.05,
            v_reset=np.zeros(n_out, dtype=np.float32),
            input_type={"input": np.array([cout, out_h, out_w])},
            output_type={"output": np.array([cout, out_h, out_w])},
        )

        # Flatten is transparent in deploy; include it like the train YAML.
        flat = nir.Flatten(
            input_type={"input": np.array([cout, out_h, out_w])},
            output_type={"output": np.array([n_out])},
            start_dim=0,
            end_dim=-1,
        )

        fc_w = np.zeros((n_class, n_out), dtype=np.float32)
        fc_w[0, :] = 0.4
        linear = nir.Linear(weight=fc_w)
        linear.input_type = {"input": np.array([n_out])}
        linear.output_type = {"output": np.array([n_class])}

        i_ones = np.ones(n_class, dtype=np.float32)
        integ = nir.I(
            r=i_ones,
            input_type={"input": np.array([n_class])},
            output_type={"output": np.array([n_class])},
        )

        inp = nir.Input(input_type={"input": np.array([cin, hin, win])})
        out = nir.Output(output_type={"output": np.array([n_class])})

        return nir.NIRGraph(
            nodes={
                "input": inp,
                "conv": conv,
                "lif": lif,
                "flat": flat,
                "fc": linear,
                "outcell": integ,
                "output": out,
            },
            edges=[
                ("input", "conv"),
                ("conv", "lif"),
                ("lif", "flat"),
                ("flat", "fc"),
                ("fc", "outcell"),
                ("outcell", "output"),
            ],
            type_check=False,
        ), weight, (cin, hin, win, cout, out_h, out_w)

    def test_conv_deploys_without_unroll(self):
        graph, weight, shapes = self._tiny_cnn_graph()
        cin, hin, win, cout, out_h, out_w = shapes
        acc_cfg = AcceleratorConfig.from_yaml("yana/core/config/default/accelerator_conv.yaml")
        acc = Accelerator(graph, acc_cfg, constraints_fatal=True, validate_neuron_params=True)

        self.assertIsNotNone(acc.conv_core)
        self.assertEqual(acc.conv_core.config.type, CoreConfig.Type.CONV)
        self.assertIsNotNone(acc.conv_core.conv)

        geom = acc.conv_core.conv.geom
        self.assertEqual(geom.n_in_axons, cin * hin * win)
        self.assertEqual(geom.n_out_neurons, cout * out_h * out_w)

        # INPUT has one route per axon, all targeting the CONV core — not Cout*K*K.
        n_input_routes = sum(len(r) for r in acc.input_core.routes.values())
        self.assertEqual(n_input_routes, geom.n_in_axons)
        for routes in acc.input_core.routes.values():
            self.assertEqual(len(routes), 1)
            self.assertEqual(routes[0].target_core, acc.conv_core.id)

        # Dest hidden core holds the shared kernel, not a spatial unroll.
        hidden_ids = [
            cid for cid, c in acc.cores.items() if c.config.type == CoreConfig.Type.HIDDEN
        ]
        dest = acc.cores[hidden_ids[0]]
        self.assertEqual(len(dest.weights), geom.n_taps)
        self.assertEqual(dest.num_neurons(), geom.n_out_neurons)
        # RTL ConvPE addresses neurons geometrically.
        for nid in range(geom.n_out_neurons):
            self.assertEqual(acc.conv_core.conv.dest_local_of_neuron[nid], nid)
            self.assertEqual(acc.conv_core.conv.dest_core_of_neuron[nid], dest.id)

        # Center spike of a 5x5 valid 3x3 hits the full kernel.
        events = [flatten_nchw(0, 2, 2, hin, win)]
        acc.reset()
        hops = acc.network_depth()
        n_ts = max(hops.values()) + 2
        acc.run([(0, events[0])], num_timesteps=n_ts, progressbar=False)

        self.assertGreater(len(acc.get_output_states()), 0)

        with tempfile.TemporaryDirectory() as tmp:
            write_accelerator_memories(acc, tmp, acc_cfg)
            params_path = os.path.join(tmp, "conv_pe_params.txt")
            self.assertTrue(os.path.isfile(params_path))
            with open(params_path) as pf:
                text = pf.read()
            self.assertIn("HAS_CONV=1", text)
            self.assertIn(f"CONV_CIN={cin}", text)
            self.assertIn(f"CONV_COUT={cout}", text)
            # CONV core itself must not emit weight/route init files.
            self.assertFalse(os.path.isfile(os.path.join(tmp, f"mem_weights_core_{acc.conv_core.id}.txt")))
            self.assertFalse(os.path.isfile(os.path.join(tmp, f"mem_routing_core_{acc.conv_core.id}.txt")))
            # Dest core holds the shared kernel taps.
            self.assertTrue(os.path.isfile(os.path.join(tmp, f"mem_weights_core_{dest.id}.txt")))

    def test_event_geometry_center_pixel(self):
        geom = ConvGeometry(
            in_channels=1, out_channels=2, in_h=5, in_w=5,
            kernel=(3, 3), stride=(1, 1), padding=(0, 0), dilation=(1, 1),
        )
        weight = np.full((2, 1, 3, 3), 0.5)
        y = reference_conv2d_from_events([flatten_nchw(0, 2, 2, 5, 5)], geom, weight)
        # Every output location sees the same 0.5 (one overlapping tap from the center spike).
        self.assertTrue(np.allclose(y, 0.5))


if __name__ == "__main__":
    unittest.main()
