`include "global_params.vh"

`timescale 1ns / 1ps

// Unit test for event-driven Conv1dPE.
// Geometry: LIN=9, K=3, Cout=2, pad=0 → OUT_L=7.
module tb_conv1d_pe ();

  localparam int CLOCK_PERIOD = 10;

  localparam int CIN    = 1;
  localparam int COUT   = 2;
  localparam int LIN    = 9;
  localparam int K      = 3;
  localparam int STRIDE = 1;
  localparam int PAD    = 0;
  localparam int DIL    = 1;

  localparam int OUT_L = (LIN + 2 * PAD - DIL * (K - 1) - 1) / STRIDE + 1;

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

  Conv1dPE #(
    .CIN   (CIN),
    .COUT  (COUT),
    .LIN   (LIN),
    .K     (K),
    .STRIDE(STRIDE),
    .PAD   (PAD),
    .DIL   (DIL)
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

  function automatic int flatten_cl(input int c, input int x);
    return c * LIN + x;
  endfunction

  function automatic int encode_out(input int cout_i, input int ox_i);
    return cout_i * OUT_L + ox_i;
  endfunction

  function automatic int encode_tap(
      input int cout_i, input int cin_i, input int kx_i
  );
    return (cout_i * CIN + cin_i) * K + kx_i;
  endfunction

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

  task automatic expect_spike(input int cin_i, input int ix);
    int kx, cout_i, w_im, ox;
    clear_scoreboard();
    for (kx = 0; kx < K; kx++) begin
      w_im = ix + PAD - kx * DIL;
      if (w_im < 0) continue;
      if ((w_im % STRIDE) != 0) continue;
      ox = w_im / STRIDE;
      if (ox >= OUT_L) continue;
      for (cout_i = 0; cout_i < COUT; cout_i++) begin
        exp_neuron.push_back(encode_out(cout_i, ox));
        exp_tap.push_back(encode_tap(cout_i, cin_i, kx));
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
        @(posedge clk);
        if (charge_valid && charge_ready) begin
          got_neuron.push_back(int'(charge_neuron));
          got_tap.push_back(int'(charge_synapse));
        end
        break;
      end
      if (cycles > timeout_cycles) begin
        $error("Timeout waiting for Conv1dPE done");
        errors++;
        break;
      end
    end
  endtask

  task automatic check_scoreboard(input string name);
    int i, j;
    bit matched [$];
    if (got_neuron.size() != exp_neuron.size()) begin
      $error("%s: charge count got=%0d expected=%0d",
             name, got_neuron.size(), exp_neuron.size());
      errors++;
    end
    matched = {};
    for (i = 0; i < exp_neuron.size(); i++) matched.push_back(1'b0);
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
      end
    end
    for (j = 0; j < exp_neuron.size(); j++) begin
      if (!matched[j]) begin
        $error("%s: missing charge neuron=%0d tap=%0d",
               name, exp_neuron[j], exp_tap[j]);
        errors++;
      end
    end
    if (got_neuron.size() == exp_neuron.size()) begin
      $display("PASS: %s (%0d charges)", name, got_neuron.size());
    end
  endtask

  task automatic run_case(input string name, input int cin_i, input int ix);
    expect_spike(cin_i, ix);
    drive_spike(flatten_cl(cin_i, ix));
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

    // Center spike: full K x Cout = 6 charges
    run_case("center(0,4)", 0, 4);

    // Corner spike: only ox=0 x Cout=2 = 2 charges
    run_case("corner(0,0)", 0, 0);

    // Near-edge
    run_case("edge(0,2)", 0, 2);

    repeat (5) @(posedge clk);
    if (errors == 0) begin
      $display("tb_conv1d_pe: ALL TESTS PASSED");
      $finish(0);
    end else begin
      $display("tb_conv1d_pe: FAILED with %0d errors", errors);
      $fatal(1);
    end
  end

  initial begin
    #(CLOCK_PERIOD * 100_000);
    $error("Global watchdog timeout");
    $fatal(1);
  end

endmodule
