`include "global_params.vh"

`timescale 1ns / 1ps

// Packet-level smoke for Conv1dCore (mesh node wrapper around Conv1dPE).
// Geometry matches tb_conv1d_pe: LIN=9, K=3, Cout=2, pad=0.
module tb_conv1d_core ();

  localparam int CLOCK_PERIOD = 10;

  localparam int CIN    = 1;
  localparam int COUT   = 2;
  localparam int LIN    = 9;
  localparam int K      = 3;
  localparam int STRIDE = 1;
  localparam int PAD    = 0;
  localparam int DIL    = 1;

  // CONV1D at (1,0), dest HIDDEN at (0,1) — matches accelerator_conv1d.yaml
  localparam int DEST_DX = 0 - 1; // -1
  localparam int DEST_DY = 0 - 1; // source_y - dest_y = -1

  logic clk = 1'b0;
  always #(CLOCK_PERIOD / 2) clk = ~clk;

  logic rst;
  logic enable;
  logic init;
  logic [TIMESTEP_WIDTH_G-1:0] timestep;
  logic core_done;
  logic core_idle;

  logic                 packet_in_ready;
  logic                 packet_in_valid;
  pkt_core_event_data_s packet_in_data;

  logic                packet_out_ready;
  logic                packet_out_valid;
  pkt_noc_event_data_s packet_out_data;

  Conv1dCore #(
    .CORE_ID_X(1),
    .CORE_ID_Y(0),
    .CIN      (CIN),
    .COUT     (COUT),
    .LIN      (LIN),
    .K        (K),
    .STRIDE   (STRIDE),
    .PAD      (PAD),
    .DIL      (DIL),
    .DEST_DX  (DEST_DX),
    .DEST_DY  (DEST_DY)
  ) dut (
    .clk_i            (clk),
    .rst_i            (rst),
    .enable_i         (enable),
    .timestep_i       (timestep),
    .init_i           (init),
    .core_done_o      (core_done),
    .core_idle_o      (core_idle),
    .packet_in_ready_o(packet_in_ready),
    .packet_in_valid_i(packet_in_valid),
    .packet_in_data_i (packet_in_data),
    .packet_out_ready_i(packet_out_ready),
    .packet_out_valid_o(packet_out_valid),
    .packet_out_data_o (packet_out_data)
  );

  int errors;
  int got_count;

  function automatic int flatten_cl(input int c, input int x);
    return c * LIN + x;
  endfunction

  task automatic send_axon(input int axon_id);
    pkt_core_event_data_s pkt;
    pkt = '0;
    pkt.ctrl_flag = 1'b0;
    pkt.payload.neuron_id = CORE_NEURON_ID_WIDTH_G'(axon_id);
    pkt.payload.synapse_id = '0;

    @(posedge clk);
    while (!packet_in_ready) @(posedge clk);
    packet_in_valid <= 1'b1;
    packet_in_data  <= pkt;
    @(posedge clk);
    packet_in_valid <= 1'b0;
    packet_in_data  <= '0;
  endtask

  task automatic collect_charges(input int expected, input int timeout_cycles);
    int cycles;
    got_count = 0;
    cycles = 0;
    forever begin
      @(posedge clk);
      cycles++;
      if (packet_out_valid && packet_out_ready) begin
        if ($signed(packet_out_data.target_core_x) != DEST_DX) begin
          $error("Bad DEST_DX: got %0d expected %0d",
                 $signed(packet_out_data.target_core_x), DEST_DX);
          errors++;
        end
        if ($signed(packet_out_data.target_core_y) != DEST_DY) begin
          $error("Bad DEST_DY: got %0d expected %0d",
                 $signed(packet_out_data.target_core_y), DEST_DY);
          errors++;
        end
        if (packet_out_data.core.ctrl_flag != 1'b0) begin
          $error("Outgoing ctrl_flag must be 0");
          errors++;
        end
        got_count++;
      end
      if (core_done && !packet_out_valid && !packet_in_valid) begin
        @(posedge clk);
        if (packet_out_valid && packet_out_ready) got_count++;
        break;
      end
      if (cycles > timeout_cycles) begin
        $error("Timeout collecting charges (got %0d)", got_count);
        errors++;
        break;
      end
    end
    if (got_count != expected) begin
      $error("Charge count got=%0d expected=%0d", got_count, expected);
      errors++;
    end else begin
      $display("PASS: collected %0d charges with DEST=(%0d,%0d)",
               got_count, DEST_DX, DEST_DY);
    end
  endtask

  initial begin
    errors           = 0;
    rst              = 1'b1;
    enable           = 1'b0;
    init             = 1'b0;
    timestep         = '0;
    packet_in_valid  = 1'b0;
    packet_in_data   = '0;
    packet_out_ready = 1'b1;

    repeat (5) @(posedge clk);
    rst <= 1'b0;
    enable <= 1'b1;
    repeat (2) @(posedge clk);

    // Center spike → K x Cout = 6
    send_axon(flatten_cl(0, 4));
    collect_charges(6, 20_000);

    // Corner spike → 2
    send_axon(flatten_cl(0, 0));
    collect_charges(2, 20_000);

    repeat (5) @(posedge clk);
    if (errors == 0) begin
      $display("tb_conv1d_core: ALL TESTS PASSED");
      $finish(0);
    end else begin
      $display("tb_conv1d_core: FAILED with %0d errors", errors);
      $fatal(1);
    end
  end

  initial begin
    #(CLOCK_PERIOD * 200_000);
    $error("Global watchdog timeout");
    $fatal(1);
  end

endmodule
