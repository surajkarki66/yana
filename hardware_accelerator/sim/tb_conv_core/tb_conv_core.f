# Verilator source list for tb_conv_core
+incdir+../../rtl
+incdir+../../rtl/control
+incdir+../../rtl/elements
+incdir+../../rtl/mem
+incdir+../../rtl/util
+incdir+../common

tb_conv_core.sv
../../rtl/conv_core.sv
../../rtl/conv_pe.sv

# Pipeline / FIFO dependency closure (same element set as tb_yana_top subset)
../../rtl/elements/accumulator_binary_saturating.sv
../../rtl/elements/adder_subtractor_binary.sv
../../rtl/elements/adder_subtractor_binary_saturating.sv
../../rtl/elements/address_decoder_behavioral.sv
../../rtl/elements/arithmetic_predicates_binary.sv
../../rtl/elements/annuller.sv
../../rtl/elements/binary_to_one_hot.sv
../../rtl/elements/bitmask_isolate_rightmost_bit.sv
../../rtl/elements/bit_reducer.sv
../../rtl/elements/carry_in_binary.sv
../../rtl/elements/counter_binary.sv
../../rtl/elements/demultiplexer_one_hot.sv
../../rtl/elements/multiplexer_binary_behavioural.sv
../../rtl/elements/multiplexer_one_hot.sv
../../rtl/elements/parallel_serial.sv
../../rtl/elements/pipeline_branch_one_hot.sv
../../rtl/elements/pipeline_credit_gate.sv
../../rtl/elements/pipeline_fifo_ping_pong.sv
../../rtl/elements/pipeline_fifo.sv
../../rtl/elements/pipeline_gate.sv
../../rtl/elements/pipeline_half_buffer.sv
../../rtl/elements/pipeline_join_asymm_words.sv
../../rtl/elements/pipeline_merge_one_hot.sv
../../rtl/elements/pipeline_sink.sv
../../rtl/elements/pipeline_skid_buffer.sv
../../rtl/elements/pulse_generator.sv
../../rtl/elements/pulse_latch.sv
../../rtl/elements/RAM_dual_port_simple_xilinx.sv
../../rtl/elements/register_pipeline.sv
../../rtl/elements/register.sv
../../rtl/elements/register_toggle.sv
../../rtl/elements/serial_parallel.sv
../../rtl/elements/width_adjuster.sv
../../rtl/elements/word_reducer.sv
