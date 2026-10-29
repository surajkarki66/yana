`timescale 1ns / 1ps

`include "global_params.vh"

// Event-driven Conv2d PE.
// One input spike (flattened NCHW axon id) is walked across the kernel;
// each in-bounds (cout, oy, ox) produces a standard synaptic event
// {tap_id, dest_neuron_id} for the destination LIF core.
//
// Geometry matches PyTorch/NIR Conv2d:
//   iy == oy * stride_h + ky * dil_h - pad_h
module ConvPE #(
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

  parameter integer NEURON_ID_WIDTH = CORE_NEURON_ID_WIDTH_G,
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

  localparam integer OUT_H = (HIN + 2 * PAD_H - DIL_H * (KH - 1) - 1) / STRIDE_H + 1;
  localparam integer OUT_W = (WIN + 2 * PAD_W - DIL_W * (KW - 1) - 1) / STRIDE_W + 1;

  localparam integer CIN_W  = (CIN  <= 1) ? 1 : $clog2(CIN);
  localparam integer COUT_W = (COUT <= 1) ? 1 : $clog2(COUT);
  localparam integer KY_W   = (KH   <= 1) ? 1 : $clog2(KH);
  localparam integer KX_W   = (KW   <= 1) ? 1 : $clog2(KW);
  localparam integer H_W    = (HIN  <= 1) ? 1 : $clog2(HIN);
  localparam integer W_W    = (WIN  <= 1) ? 1 : $clog2(WIN);
  localparam integer OH_W   = (OUT_H <= 1) ? 1 : $clog2(OUT_H);
  localparam integer OW_W   = (OUT_W <= 1) ? 1 : $clog2(OUT_W);

  typedef enum logic [1:0] {
    IDLE,
    EVAL,
    EMIT
  } state_e;

  state_e state_q, state_d;

  logic [CIN_W-1:0]  cin_q,  cin_d;
  logic [H_W-1:0]    iy_q,   iy_d;
  logic [W_W-1:0]    ix_q,   ix_d;
  logic [KY_W-1:0]   ky_q,   ky_d;
  logic [KX_W-1:0]   kx_q,   kx_d;
  logic [COUT_W-1:0] cout_q, cout_d;

  logic signed [H_W+PAD_H+2:0] h_im;
  logic signed [W_W+PAD_W+2:0] w_im;
  logic signed [OH_W+1:0]      oy_s;
  logic signed [OW_W+1:0]      ox_s;
  logic                        in_bounds;

  logic [NEURON_ID_WIDTH-1:0]  dest_neuron;
  logic [SYNAPSE_ID_WIDTH-1:0] tap_id;

  function automatic [NEURON_ID_WIDTH-1:0] encode_out(
      input integer cout_i, input integer oy_i, input integer ox_i
  );
    encode_out = NEURON_ID_WIDTH'(cout_i * OUT_H * OUT_W + oy_i * OUT_W + ox_i);
  endfunction

  function automatic [SYNAPSE_ID_WIDTH-1:0] encode_tap(
      input integer cout_i, input integer cin_i, input integer ky_i, input integer kx_i
  );
    encode_tap = SYNAPSE_ID_WIDTH'(((cout_i * CIN + cin_i) * KH + ky_i) * KW + kx_i);
  endfunction

  always_comb begin
    h_im = $signed({1'b0, iy_q}) + PAD_H - $signed({1'b0, ky_q}) * DIL_H;
    w_im = $signed({1'b0, ix_q}) + PAD_W - $signed({1'b0, kx_q}) * DIL_W;
    in_bounds = 1'b0;
    oy_s = '0;
    ox_s = '0;
    dest_neuron = '0;
    tap_id = '0;

    if (h_im >= 0 && w_im >= 0 && (h_im % STRIDE_H) == 0 && (w_im % STRIDE_W) == 0) begin
      oy_s = h_im / STRIDE_H;
      ox_s = w_im / STRIDE_W;
      if (oy_s >= 0 && ox_s >= 0 && oy_s < OUT_H && ox_s < OUT_W) begin
        in_bounds   = 1'b1;
        dest_neuron = encode_out(integer'(cout_q), integer'(oy_s), integer'(ox_s));
        tap_id      = encode_tap(integer'(cout_q), integer'(cin_q), integer'(ky_q), integer'(kx_q));
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
      iy_q    <= '0;
      ix_q    <= '0;
      ky_q    <= '0;
      kx_q    <= '0;
      cout_q  <= '0;
    end else begin
      state_q <= state_d;
      cin_q   <= cin_d;
      iy_q    <= iy_d;
      ix_q    <= ix_d;
      ky_q    <= ky_d;
      kx_q    <= kx_d;
      cout_q  <= cout_d;
    end
  end

  always_comb begin
    state_d = state_q;
    cin_d   = cin_q;
    iy_d    = iy_q;
    ix_d    = ix_q;
    ky_d    = ky_q;
    kx_d    = kx_q;
    cout_d  = cout_q;

    unique case (state_q)
      IDLE: begin
        if (enable_i && spike_in_valid_i) begin
          ix_d    = spike_in_data_i % WIN;
          iy_d    = (spike_in_data_i / WIN) % HIN;
          cin_d   = spike_in_data_i / (WIN * HIN);
          ky_d    = '0;
          kx_d    = '0;
          cout_d  = '0;
          state_d = EVAL;
        end
      end

      EVAL: begin
        if (in_bounds) begin
          state_d = EMIT;
        end else begin
          // Advance kernel / channel counters; stay in EVAL or finish.
          if (cout_q == COUT - 1) begin
            cout_d = '0;
            if (kx_q == KW - 1) begin
              kx_d = '0;
              if (ky_q == KH - 1) begin
                state_d = IDLE;
              end else begin
                ky_d = ky_q + 1'b1;
              end
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
            if (kx_q == KW - 1) begin
              kx_d = '0;
              if (ky_q == KH - 1) begin
                state_d = IDLE;
              end else begin
                ky_d    = ky_q + 1'b1;
                state_d = EVAL;
              end
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
