`timescale 1ns / 1ps

`include "global_params.vh"

// Event-driven Conv1d PE.
// One input spike (flattened CL axon id) is walked across the kernel;
// each in-bounds (cout, ox) produces a standard synaptic event
// {tap_id, dest_neuron_id} for the destination LIF core.
//
// Geometry matches PyTorch/NIR Conv1d:
//   ix == ox * stride + kx * dil - pad
module Conv1dPE #(
  parameter integer CIN      = 1,
  parameter integer COUT     = 1,
  parameter integer LIN      = 16,
  parameter integer K        = 3,
  parameter integer STRIDE   = 1,
  parameter integer PAD      = 0,
  parameter integer DIL      = 1,

  parameter integer NEURON_ID_WIDTH  = CORE_NEURON_ID_WIDTH_G,
  parameter integer SYNAPSE_ID_WIDTH = CORE_WEIGHT_ID_WIDTH_G
) (
  input  logic clk_i,
  input  logic rst_i,
  input  logic enable_i,
  output logic done_o,

  output logic                         spike_in_ready_o,
  input  logic                         spike_in_valid_i,
  input  logic [NEURON_ID_WIDTH-1:0]   spike_in_data_i,

  input  logic                         charge_out_ready_i,
  output logic                         charge_out_valid_o,
  output logic [NEURON_ID_WIDTH-1:0]   charge_neuron_id_o,
  output logic [SYNAPSE_ID_WIDTH-1:0]  charge_synapse_id_o
);

  localparam integer OUT_L = (LIN + 2 * PAD - DIL * (K - 1) - 1) / STRIDE + 1;

  localparam integer CIN_W  = (CIN  <= 1) ? 1 : $clog2(CIN);
  localparam integer COUT_W = (COUT <= 1) ? 1 : $clog2(COUT);
  localparam integer KX_W   = (K    <= 1) ? 1 : $clog2(K);
  localparam integer L_W    = (LIN  <= 1) ? 1 : $clog2(LIN);
  localparam integer OL_W   = (OUT_L <= 1) ? 1 : $clog2(OUT_L);

  typedef enum logic [1:0] {
    IDLE,
    EVAL,
    EMIT
  } state_e;

  state_e state_q, state_d;

  logic [CIN_W-1:0]  cin_q,  cin_d;
  logic [L_W-1:0]    ix_q,   ix_d;
  logic [KX_W-1:0]   kx_q,   kx_d;
  logic [COUT_W-1:0] cout_q, cout_d;

  logic signed [L_W+PAD+2:0] w_im;
  logic signed [OL_W+1:0]    ox_s;
  logic                      in_bounds;

  logic [NEURON_ID_WIDTH-1:0]  dest_neuron;
  logic [SYNAPSE_ID_WIDTH-1:0] tap_id;

  function automatic [NEURON_ID_WIDTH-1:0] encode_out(
      input integer cout_i, input integer ox_i
  );
    encode_out = NEURON_ID_WIDTH'(cout_i * OUT_L + ox_i);
  endfunction

  function automatic [SYNAPSE_ID_WIDTH-1:0] encode_tap(
      input integer cout_i, input integer cin_i, input integer kx_i
  );
    encode_tap = SYNAPSE_ID_WIDTH'((cout_i * CIN + cin_i) * K + kx_i);
  endfunction

  always_comb begin
    w_im = $signed({1'b0, ix_q}) + PAD - $signed({1'b0, kx_q}) * DIL;
    in_bounds = 1'b0;
    ox_s = '0;
    dest_neuron = '0;
    tap_id = '0;

    if (w_im >= 0 && (w_im % STRIDE) == 0) begin
      ox_s = w_im / STRIDE;
      if (ox_s >= 0 && ox_s < OUT_L) begin
        in_bounds   = 1'b1;
        dest_neuron = encode_out(integer'(cout_q), integer'(ox_s));
        tap_id      = encode_tap(integer'(cout_q), integer'(cin_q), integer'(kx_q));
      end
    end
  end

  assign spike_in_ready_o    = (state_q == IDLE) && enable_i;
  assign charge_out_valid_o  = (state_q == EMIT);
  assign charge_neuron_id_o  = dest_neuron;
  assign charge_synapse_id_o = tap_id;
  assign done_o              = (state_q == IDLE) && ~spike_in_valid_i;

  always_ff @(posedge clk_i) begin
    if (rst_i) begin
      state_q <= IDLE;
      cin_q   <= '0;
      ix_q    <= '0;
      kx_q    <= '0;
      cout_q  <= '0;
    end else begin
      state_q <= state_d;
      cin_q   <= cin_d;
      ix_q    <= ix_d;
      kx_q    <= kx_d;
      cout_q  <= cout_d;
    end
  end

  always_comb begin
    state_d = state_q;
    cin_d   = cin_q;
    ix_d    = ix_q;
    kx_d    = kx_q;
    cout_d  = cout_q;

    unique case (state_q)
      IDLE: begin
        if (enable_i && spike_in_valid_i) begin
          ix_d    = spike_in_data_i % LIN;
          cin_d   = spike_in_data_i / LIN;
          kx_d    = '0;
          cout_d  = '0;
          state_d = EVAL;
        end
      end

      EVAL: begin
        if (in_bounds) begin
          state_d = EMIT;
        end else begin
          if (cout_q == COUT - 1) begin
            cout_d = '0;
            if (kx_q == K - 1) begin
              state_d = IDLE;
            end else begin
              kx_d = kx_q + 1'b1;
            end
          end else begin
            cout_d = cout_q + 1'b1;
          end
        end
      end

      EMIT: begin
        if (charge_out_ready_i) begin
          if (cout_q == COUT - 1) begin
            cout_d = '0;
            if (kx_q == K - 1) begin
              state_d = IDLE;
            end else begin
              kx_d    = kx_q + 1'b1;
              state_d = EVAL;
            end
          end else begin
            cout_d  = cout_q + 1'b1;
            state_d = EVAL;
          end
        end
      end

      default: state_d = IDLE;
    endcase
  end

endmodule
