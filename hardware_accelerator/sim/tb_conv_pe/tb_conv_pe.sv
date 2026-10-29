`include "global_params.vh"

`timescale 1ns / 1ps

// Unit test for event-driven ConvPE.
// Geometry matches software tests/test_conv_geometry.py (5x5, k=3, Cout=2, pad=0).
module tb_conv_pe ();

  localparam int CLOCK_PERIOD = 10;

  localparam int CIN  = 1;
  localparam int COUT = 2;
  localparam int HIN  = 5;
  localparam int WIN  = 5;
  localparam int KH   = 3;
  localparam int KW   = 3;
  localparam int STRIDE_H = 1;
  localparam int STRIDE_W = 1;
  localparam int PAD_H = 0;
  localparam int PAD_W = 0;
  localparam int DIL_H = 1;
  localparam int DIL_W = 1;

  localparam int OUT_H = (HIN + 2 * PAD_H - DIL_H * (KH - 1) - 1) / STRIDE_H + 1;
  localparam int OUT_W = (WIN + 2 * PAD_W - DIL_W * (KW - 1) - 1) / STRIDE_W + 1;

  localparam int NEURON_ID_WIDTH  = CORE_NEURON_ID_WIDTH_G;
  localparam int SYNAPSE_ID_WIDTH = CORE_WEIGHT_ID_WIDTH_G;

  logic clk = 1'b0;
  always #(CLOCK_PERIOD / 2) clk = ~clk;

  logic rst;
  logic enable;
  logic done;

  logic                         spike_ready;
  logic                         spike_valid;
  logic [NEURON_ID_WIDTH-1:0]   spike_data;

  logic                         charge_ready;
  logic                         charge_valid;
  logic [NEURON_ID_WIDTH-1:0]   charge_neuron;
  logic [SYNAPSE_ID_WIDTH-1:0]  charge_synapse;

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
  ) dut (
    .clk_i              (clk),
    .rst_i              (rst),
    .enable_i           (enable),
    .done_o             (done),
    .spike_in_ready_o   (spike_ready),
    .spike_in_valid_i   (spike_valid),
    .spike_in_data_i    (spike_data),
    .charge_out_ready_i (charge_ready),
    .charge_out_valid_o (charge_valid),
    .charge_neuron_id_o (charge_neuron),
    .charge_synapse_id_o(charge_synapse)
  );

  function automatic int flatten_nchw(input int c, input int y, input int x);
    return (c * HIN + y) * WIN + x;
  endfunction

  function automatic int encode_out(input int cout_i, input int oy_i, input int ox_i);
    return cout_i * OUT_H * OUT_W + oy_i * OUT_W + ox_i;
  endfunction

  function automatic int encode_tap(
      input int cout_i, input int cin_i, input int ky_i, input int kx_i
  );
    return ((cout_i * CIN + cin_i) * KH + ky_i) * KW + kx_i;
  endfunction

  // Scoreboard for one spike
  int exp_neuron [$];
  int exp_tap    [$];
  int got_neuron [$];
  int got_tap    [$];
  int errors;

  task automatic clear_scoreboard();
    exp_neuron.delete();
    exp_tap.delete();
    got_neuron.delete();
    got_tap.delete();
  endtask

  task automatic expect_spike(input int cin_i, input int iy, input int ix);
    int ky, kx, cout_i;
    int h_im, w_im, oy, ox;
    clear_scoreboard();
    for (ky = 0; ky < KH; ky++) begin
      for (kx = 0; kx < KW; kx++) begin
        h_im = iy + PAD_H - ky * DIL_H;
        w_im = ix + PAD_W - kx * DIL_W;
        if (h_im < 0 || w_im < 0) continue;
        if ((h_im % STRIDE_H) != 0 || (w_im % STRIDE_W) != 0) continue;
        oy = h_im / STRIDE_H;
        ox = w_im / STRIDE_W;
        if (oy >= OUT_H || ox >= OUT_W) continue;
        for (cout_i = 0; cout_i < COUT; cout_i++) begin
          exp_neuron.push_back(encode_out(cout_i, oy, ox));
          exp_tap.push_back(encode_tap(cout_i, cin_i, ky, kx));
        end
      end
    end
  endtask

  task automatic drive_spike(input int axon_id);
    @(posedge clk);
    while (!spike_ready) @(posedge clk);
    spike_valid <= 1'b1;
    spike_data  <= NEURON_ID_WIDTH'(axon_id);
    @(posedge clk);
    spike_valid <= 1'b0;
    spike_data  <= '0;
  endtask

  // Collect charges until PE returns to done with empty pending work.
  task automatic collect_until_done(input int timeout_cycles);
    int cycles;
    cycles = 0;
    forever begin
      @(posedge clk);
      cycles++;
      if (charge_valid && charge_ready) begin
        got_neuron.push_back(int'(charge_neuron));
        got_tap.push_back(int'(charge_synapse));
      end
      if (done && !charge_valid && !spike_valid) begin
        // Wait one extra cycle to catch a trailing emit.
        @(posedge clk);
        if (charge_valid && charge_ready) begin
          got_neuron.push_back(int'(charge_neuron));
          got_tap.push_back(int'(charge_synapse));
        end
        break;
      end
      if (cycles > timeout_cycles) begin
        $error("Timeout waiting for ConvPE done");
        errors++;
        break;
      end
    end
  endtask

  task automatic check_scoreboard(input string name);
    int i, j;
    bit matched [$];
    int unmatched_got;
    if (got_neuron.size() != exp_neuron.size()) begin
      $error("%s: charge count got=%0d expected=%0d",
             name, got_neuron.size(), exp_neuron.size());
      errors++;
    end
    matched = {};
    for (i = 0; i < exp_neuron.size(); i++) matched.push_back(1'b0);
    unmatched_got = 0;
    for (i = 0; i < got_neuron.size(); i++) begin
      bit found;
      found = 1'b0;
      for (j = 0; j < exp_neuron.size(); j++) begin
        if (!matched[j] &&
            got_neuron[i] == exp_neuron[j] &&
            got_tap[i] == exp_tap[j]) begin
          matched[j] = 1'b1;
          found = 1'b1;
          break;
        end
      end
      if (!found) begin
        $error("%s: unexpected charge neuron=%0d tap=%0d",
               name, got_neuron[i], got_tap[i]);
        errors++;
        unmatched_got++;
      end
    end
    for (j = 0; j < exp_neuron.size(); j++) begin
      if (!matched[j]) begin
        $error("%s: missing charge neuron=%0d tap=%0d",
               name, exp_neuron[j], exp_tap[j]);
        errors++;
      end
    end
    if (unmatched_got == 0 && got_neuron.size() == exp_neuron.size()) begin
      $display("PASS: %s (%0d charges)", name, got_neuron.size());
    end
  endtask

  task automatic run_case(input string name, input int cin_i, input int iy, input int ix);
    expect_spike(cin_i, iy, ix);
    drive_spike(flatten_nchw(cin_i, iy, ix));
    collect_until_done(10_000);
    check_scoreboard(name);
  endtask

  initial begin
    errors       = 0;
    rst          = 1'b1;
    enable       = 1'b0;
    spike_valid  = 1'b0;
    spike_data   = '0;
    charge_ready = 1'b1;

    repeat (5) @(posedge clk);
    rst <= 1'b0;
    enable <= 1'b1;
    repeat (2) @(posedge clk);

    // Center spike: full 3x3 x Cout=2 = 18 charges
    run_case("center(0,2,2)", 0, 2, 2);

    // Corner spike: only (oy,ox)=(0,0) x Cout=2 = 2 charges
    run_case("corner(0,0,0)", 0, 0, 0);

    // Edge spike
    run_case("edge(0,0,2)", 0, 0, 2);

    repeat (5) @(posedge clk);
    if (errors == 0) begin
      $display("tb_conv_pe: ALL TESTS PASSED");
      $finish(0);
    end else begin
      $display("tb_conv_pe: FAILED with %0d errors", errors);
      $fatal(1);
    end
  end

  // Global watchdog
  initial begin
    #(CLOCK_PERIOD * 100_000);
    $error("Global watchdog timeout");
    $fatal(1);
  end

endmodule
