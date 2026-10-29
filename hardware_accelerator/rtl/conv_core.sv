`timescale 1ns / 1ps

`include "global_params.vh"

// Mesh node that hosts a ConvPE. Same control handshake as Core
// (enable / init / timestep / done / idle) so the existing CU lock-step
// still works.
//
// Incoming events: payload.neuron_id = flattened input axon (cin,y,x).
// Outgoing events: standard synaptic packets {tap_id, dest_neuron_id}
//                  with fixed NoC hops DEST_DX/DEST_DY to the LIF core
//                  that holds the shared Cout×Cin×Kh×Kw kernel in weight RAM.
//
// v1 limitation: one destination core only (no per-pixel dest map).
module ConvCore #(
  parameter CORE_ID_X = 0,
  parameter CORE_ID_Y = 0,

  parameter integer CIN      = 1,
  parameter integer COUT     = 1,
  parameter integer HIN      = 8,
  parameter integer WIN      = 8,
  parameter integer KH       = 3,
  parameter integer KW       = 3,
  parameter integer STRIDE_H = 1,
  parameter integer STRIDE_W = 1,
  parameter integer PAD_H    = 0,
  parameter integer PAD_W    = 0,
  parameter integer DIL_H    = 1,
  parameter integer DIL_W    = 1,

  // Signed NoC hops from this CONV node to the dest LIF core.
  parameter integer DEST_DX  = 0,
  parameter integer DEST_DY  = 0,

  parameter TIMESTEP_WIDTH          = TIMESTEP_WIDTH_G,
  parameter CORE_NEURON_ID_WIDTH    = CORE_NEURON_ID_WIDTH_G,
  parameter CORE_WEIGHT_ID_WIDTH    = CORE_WEIGHT_ID_WIDTH_G,
  parameter CORE_FIFOS_DEPTH        = CORE_FIFOS_DEPTH_G,
  parameter CORE_INPUT_WIDTH        = CORE_INPUT_WIDTH_G,
  parameter CORE_FEEDBACK_DATA_WIDTH = CORE_EVENT_WIDTH_G,
  parameter MESH_PACKET_DATA_WIDTH_X = MESH_PACKET_DATA_WIDTH_X_G,
  parameter MESH_PACKET_DX_WIDTH    = MESH_PACKET_DX_WIDTH_G,
  parameter MESH_PACKET_DY_WIDTH    = MESH_PACKET_DY_WIDTH_G
) (
  input  logic                      clk_i,
  input  logic                      rst_i,
  input  logic                      enable_i,
  input  logic [TIMESTEP_WIDTH-1:0] timestep_i,
  input  logic                      init_i,
  output logic                      core_done_o,
  output logic                      core_idle_o,

  output logic                 packet_in_ready_o,
  input  logic                 packet_in_valid_i,
  input  pkt_core_event_data_s packet_in_data_i,

  input  logic                packet_out_ready_i,
  output logic                packet_out_valid_o,
  output pkt_noc_event_data_s packet_out_data_o
);

  logic init_d;
  assign init_d = ~enable_i && init_i;

  logic [2:0]                        rx_branch_out_ready;
  logic [2:0]                        rx_branch_out_valid;
  logic [2:0] [CORE_INPUT_WIDTH-1:0] rx_branch_out_data;
  Pipeline_Branch_One_Hot #(
    .WORD_WIDTH    (CORE_INPUT_WIDTH),
    .OUTPUT_COUNT  (3),
    .IMPLEMENTATION("AND")
  ) u_rx_branch (
    .selector    ((init_d) ? 3'b100 : (packet_in_data_i.ctrl_flag) ? 3'b010 : 3'b001),
    .input_ready (packet_in_ready_o),
    .input_valid (packet_in_valid_i),
    .input_data  (packet_in_data_i),
    .output_ready(rx_branch_out_ready),
    .output_valid(rx_branch_out_valid),
    .output_data ({rx_branch_out_data})
  );

  // v1: ignore command and init streams (shape is parameterized).
  assign rx_branch_out_ready[1] = 1'b1;
  assign rx_branch_out_ready[2] = 1'b1;

  localparam int EVENT_WIDTH = CORE_FEEDBACK_DATA_WIDTH;
  logic [EVENT_WIDTH-1:0] event_payload;
  assign event_payload = rx_branch_out_data[0][1+:EVENT_WIDTH];

  logic                            spike_fifo_in_ready;
  logic                            spike_fifo_out_ready;
  logic                            spike_fifo_out_valid;
  logic [CORE_NEURON_ID_WIDTH-1:0] spike_fifo_out_data;
  logic                            spike_fifo_empty;

  assign rx_branch_out_ready[0] = spike_fifo_in_ready;

  Pipeline_FIFO_Buffer #(
    .WORD_WIDTH     (CORE_NEURON_ID_WIDTH),
    .DEPTH          (CORE_FIFOS_DEPTH),
    .RAMSTYLE       ("mixed"),
    .CIRCULAR_BUFFER(0)
  ) u_spike_fifo (
    .clock       (clk_i),
    .clear       (rst_i),
    .input_ready (spike_fifo_in_ready),
    .input_valid (rx_branch_out_valid[0]),
    .input_data  (event_payload[CORE_NEURON_ID_WIDTH-1:0]),
    .output_ready(spike_fifo_out_ready),
    .output_valid(spike_fifo_out_valid),
    .output_data (spike_fifo_out_data),
    .empty       (spike_fifo_empty)
  );

  logic                           pe_done;
  logic                           charge_valid;
  logic                           charge_ready;
  logic [CORE_NEURON_ID_WIDTH-1:0] charge_neuron;
  logic [CORE_WEIGHT_ID_WIDTH-1:0] charge_synapse;

  ConvPE #(
    .CIN     (CIN),
    .COUT    (COUT),
    .HIN     (HIN),
    .WIN     (WIN),
    .KH      (KH),
    .KW      (KW),
    .STRIDE_H(STRIDE_H),
    .STRIDE_W(STRIDE_W),
    .PAD_H   (PAD_H),
    .PAD_W   (PAD_W),
    .DIL_H   (DIL_H),
    .DIL_W   (DIL_W)
  ) u_conv_pe (
    .clk_i               (clk_i),
    .rst_i               (rst_i),
    .enable_i            (enable_i),
    .done_o              (pe_done),
    .spike_in_ready_o    (spike_fifo_out_ready),
    .spike_in_valid_i    (spike_fifo_out_valid),
    .spike_in_data_i     (spike_fifo_out_data),
    .charge_out_ready_i  (charge_ready),
    .charge_out_valid_o  (charge_valid),
    .charge_neuron_id_o  (charge_neuron),
    .charge_synapse_id_o (charge_synapse)
  );

  pkt_noc_event_data_s charge_pkt;
  always_comb begin
    charge_pkt                              = '0;
    charge_pkt.core.ctrl_flag               = 1'b0;
    charge_pkt.core.payload.neuron_id       = charge_neuron;
    charge_pkt.core.payload.synapse_id      = charge_synapse;
    charge_pkt.target_core_x                = MESH_PACKET_DX_WIDTH'(DEST_DX);
    charge_pkt.target_core_y                = MESH_PACKET_DY_WIDTH'(DEST_DY);
  end

  logic tx_fifo_empty;
  Pipeline_FIFO_Buffer #(
    .WORD_WIDTH     (MESH_PACKET_DATA_WIDTH_X),
    .DEPTH          (CORE_FIFOS_DEPTH),
    .RAMSTYLE       ("mixed"),
    .CIRCULAR_BUFFER(0)
  ) u_tx_fifo (
    .clock       (clk_i),
    .clear       (rst_i),
    .input_ready (charge_ready),
    .input_valid (charge_valid),
    .input_data  (charge_pkt),
    .output_ready(packet_out_ready_i),
    .output_valid(packet_out_valid_o),
    .output_data (packet_out_data_o),
    .empty       (tx_fifo_empty)
  );

  logic rx_done;
  assign rx_done     = ~packet_in_valid_i && spike_fifo_empty;
  assign core_done_o = (init_d) ? 1'b1 : (rx_done && pe_done && tx_fifo_empty);
  assign core_idle_o = core_done_o;

  // Unused for now; keep the port so the CU handshake matches Core.
  logic unused_ts;
  assign unused_ts = |timestep_i;

endmodule
