"""NMNIST-shaped Conv2d deploy smoke (random-init weights, no full training).

Builds the network from ``nmnist_conv_feed_forward.yaml``, exports NIR, maps
onto ``accelerator_conv.yaml``, runs a few synthetic events through the golden
sim, and writes CONV PE params + memory images.
"""

from __future__ import annotations

import os
import sys
import tempfile
import unittest

import numpy as np
import torch

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from yana.core.config import AcceleratorConfig, CoreConfig
from yana.deploy.accelerator import Accelerator
from yana.deploy.conv import flatten_nchw, reference_conv2d_from_events
from yana.deploy.file_export import write_accelerator_memories
from yana.train.config import Cfg
from yana.train.model import Model
from yana.train.utils.nir_utils import extract_graph


def _software_framework_root() -> str:
    return os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


class ConvNmnistSmokeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        os.chdir(_software_framework_root())
        # NMNIST after spatial_factor=2, merge_polarities=false → (H,W,C)=(17,17,2)
        cls.sensor_size = (17, 17, 2)
        cls.num_classes = 10
        cls.in_c, cls.in_h, cls.in_w = 2, 17, 17

    def test_yaml_model_deploys_and_simulates(self):
        cfg = Cfg.from_yaml("yana/train/config/nmnist_conv_feed_forward.yaml")
        acc_cfg = AcceleratorConfig.from_yaml(
            "yana/core/config/default/accelerator_conv.yaml"
        )

        torch.manual_seed(0)
        model = Model(cfg.model_cfg, acc_cfg, self.sensor_size, self.num_classes)
        model.eval()

        # One frame (B=1, C, H, W) for NIR tracing — matches deploy_checkpoint.
        trace_sample = torch.zeros(1, self.in_c, self.in_h, self.in_w)
        nir_graph = extract_graph(
            model.network,
            trace_sample,
            dt=cfg.model_cfg.network_cfg.dt,
            infer_types=True,
            broadcast_params=True,
        )

        acc = Accelerator(
            nir_graph, acc_cfg, constraints_fatal=True, validate_neuron_params=True
        )
        self.assertIsNotNone(acc.conv_core)
        self.assertEqual(acc.conv_core.config.type, CoreConfig.Type.CONV)
        geom = acc.conv_core.conv.geom
        self.assertEqual(geom.in_channels, self.in_c)
        self.assertEqual(geom.in_h, self.in_h)
        self.assertEqual(geom.in_w, self.in_w)
        # stride 2, pad 1, k 3 → 9x9 feature map, Cout=8 → 648 neurons
        self.assertEqual(geom.out_hw, (9, 9))
        self.assertEqual(geom.out_channels, 8)
        self.assertEqual(geom.n_out_neurons, 8 * 9 * 9)
        self.assertLessEqual(geom.n_out_neurons, acc_cfg.neurons_per_core)

        # No spatial unroll on INPUT: one route per axon.
        n_input_routes = sum(len(r) for r in acc.input_core.routes.values())
        self.assertEqual(n_input_routes, geom.n_in_axons)

        # Shared kernel on the single HIDDEN dest core.
        dest_id = acc.conv_core.conv.dest_core_of_neuron[0]
        dest = acc.cores[dest_id]
        self.assertEqual(dest.config.type, CoreConfig.Type.HIDDEN)
        self.assertEqual(len(dest.weights), geom.n_taps)
        self.assertEqual(len(set(acc.conv_core.conv.dest_core_of_neuron)), 1)

        # Synthetic sparse events on first polarity, a few pixels.
        events = [
            flatten_nchw(0, 8, 8, self.in_h, self.in_w),
            flatten_nchw(0, 8, 9, self.in_h, self.in_w),
            flatten_nchw(1, 4, 4, self.in_h, self.in_w),
        ]
        # Pull conv weight from NIR for a dense reference charge check.
        conv_node = next(
            n for n in nir_graph.nodes.values() if type(n).__name__ == "Conv2d"
        )
        weight = np.asarray(conv_node.weight)
        ref_charge = reference_conv2d_from_events(events, geom, weight)

        hops = acc.network_depth()
        n_ts = max(hops.values()) + 4
        acc.reset()
        acc.run([(0, e) for e in events], num_timesteps=n_ts, progressbar=False)

        # Feature-map LIF should have received non-zero charge somewhere.
        self.assertTrue(np.any(np.abs(ref_charge) > 0))
        out_states = acc.get_output_states()
        self.assertGreater(len(out_states), 0)

        with tempfile.TemporaryDirectory() as tmp:
            write_accelerator_memories(acc, tmp, acc_cfg)
            params = os.path.join(tmp, "conv_pe_params.txt")
            self.assertTrue(os.path.isfile(params))
            with open(params) as pf:
                text = pf.read()
            self.assertIn("HAS_CONV=1", text)
            self.assertIn(f"CONV_CIN={self.in_c}", text)
            self.assertIn("CONV_COUT=8", text)
            self.assertIn(f"CONV_HIN={self.in_h}", text)
            self.assertIn("CONV_STRIDE_H=2", text)
            # Kernel lives on dest HIDDEN core, not on CONV.
            self.assertFalse(
                os.path.isfile(os.path.join(tmp, f"mem_weights_core_{acc.conv_core.id}.txt"))
            )
            self.assertTrue(
                os.path.isfile(os.path.join(tmp, f"mem_weights_core_{dest_id}.txt"))
            )


if __name__ == "__main__":
    unittest.main()
