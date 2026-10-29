"""Leak LUT must match training's effective length (next_power_of_2(1/tau))."""

import os
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from yana.core.config import AcceleratorConfig
from yana.deploy.core import Core, _create_leak_lut, _effective_leak_lut_len
from yana.deploy.memory import write_core_leak_lut


class LeakLutTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        os.chdir(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

    def test_effective_len_matches_training_formula(self):
        # tau=0.25 -> 1/tau=4 -> next_power_of_2(4)=4
        self.assertEqual(_effective_leak_lut_len(0.25, 32), 4)
        # tau=0.1 -> 1/tau=10 -> 16
        self.assertEqual(_effective_leak_lut_len(0.1, 32), 16)

    def test_create_lut_truncated_to_effective_length(self):
        acc = AcceleratorConfig.from_yaml("yana/core/config/default/accelerator_conv.yaml")
        cfg = acc.core_configs[2]
        cfg.neuron_config.tau_mem_inv = 0.25
        cfg.neuron_config.leak_enabled = True
        cfg.neuron_config.leak_lut_len = 32

        lut = _create_leak_lut(cfg)
        self.assertEqual(len(lut), 4)
        self.assertEqual(lut[0].value, 0)
        self.assertAlmostEqual(lut[1].to_float(), 0.75)
        self.assertAlmostEqual(lut[2].to_float(), 0.5625)
        self.assertAlmostEqual(lut[3].to_float(), 0.421875)

    def test_export_pads_to_hardware_length(self):
        acc = AcceleratorConfig.from_yaml("yana/core/config/default/accelerator_conv.yaml")
        cfg = acc.core_configs[2]
        cfg.neuron_config.tau_mem_inv = 0.25
        cfg.neuron_config.leak_enabled = True
        cfg.neuron_config.leak_lut_len = 32
        core = Core(2, cfg)
        self.assertEqual(len(core.leak_lut), 4)

        with tempfile.TemporaryDirectory() as tmp:
            path = os.path.join(tmp, "leak_ram_core_2.txt")
            write_core_leak_lut(core, acc, path, as_events=False)
            with open(path) as f:
                lines = [ln.strip() for ln in f if ln.strip()]
            # addr + value per entry
            self.assertEqual(len(lines), 32 * 2)


if __name__ == "__main__":
    unittest.main()
