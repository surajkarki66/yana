"""SHD-shaped Conv1d deploy smoke: Builds the network from 
   shd_conv1d_feed_forward.yaml, exports NIR, maps onto accelerator_conv1d.yaml.
"""

from __future__ import annotations

import os
import sys
import tempfile
import unittest

import torch

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from yana.core.config import AcceleratorConfig, CoreConfig
from yana.deploy.accelerator import Accelerator
from yana.deploy.conv1d import flatten_cl, reference_conv1d_from_events
from yana.deploy.file_export import write_accelerator_memories
from yana.train.config import Cfg
from yana.train.model import Model
from yana.train.utils.nir_utils import extract_graph


def _software_framework_root() -> str:
    return os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


class Conv1dShdSmokeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        os.chdir(_software_framework_root())
        # SHD after spatial_factor=4, merge_polarities → (L, C) = (175, 1)
        cls.sensor_size = (175, 1)
        cls.num_classes = 20
        cls.in_c, cls.in_l = 1, 175

    def test_yaml_model_deploys(self):
        cfg = Cfg.from_yaml("yana/train/config/shd_conv1d_feed_forward.yaml")
        acc_cfg = AcceleratorConfig.from_yaml(
            "yana/core/config/default/accelerator_conv1d.yaml"
        )

        torch.manual_seed(0)
        model = Model(cfg.model_cfg, acc_cfg, self.sensor_size, self.num_classes)
        model.eval()

        trace_sample = torch.zeros(1, self.in_c, self.in_l)
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
        self.assertIsNotNone(acc.conv1d_core)
        self.assertEqual(acc.conv1d_core.config.type, CoreConfig.Type.CONV1D)
        geom = acc.conv1d_core.conv.geom
        self.assertEqual(geom.in_channels, self.in_c)
        self.assertEqual(geom.in_length, self.in_l)
        self.assertEqual(geom.out_length, 171)
        self.assertEqual(geom.n_out_neurons, 5 * 171)
        self.assertEqual(acc.output_core.num_neurons(), self.num_classes)

        conv_mod = next(m for m in model.network.modules() if isinstance(m, torch.nn.Conv1d))
        weight = conv_mod.weight.detach().cpu().numpy()
        events = [flatten_cl(0, x, self.in_l) for x in range(0, self.in_l, 20)]
        y_ref = reference_conv1d_from_events(events, geom, weight)
        self.assertEqual(y_ref.shape, (5, 171))

        with tempfile.TemporaryDirectory() as tmp:
            write_accelerator_memories(acc, tmp, acc_cfg, as_events=False)
            self.assertTrue(os.path.exists(os.path.join(tmp, "conv1d_pe_params.txt")))


if __name__ == "__main__":
    unittest.main()
