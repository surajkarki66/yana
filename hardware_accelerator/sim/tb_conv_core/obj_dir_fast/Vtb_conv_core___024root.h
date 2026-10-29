// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_conv_core.h for the primary calling header

#ifndef VERILATED_VTB_CONV_CORE___024ROOT_H_
#define VERILATED_VTB_CONV_CORE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_conv_core__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_conv_core___024root final {
  public:

    // DESIGN-SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_conv_core__DOT__clk;
        CData/*0:0*/ tb_conv_core__DOT__rst;
        CData/*0:0*/ tb_conv_core__DOT__enable;
        CData/*0:0*/ tb_conv_core__DOT__init;
        CData/*0:0*/ tb_conv_core__DOT__core_done;
        CData/*0:0*/ tb_conv_core__DOT__packet_in_valid;
        CData/*0:0*/ tb_conv_core__DOT__packet_out_ready;
        CData/*0:0*/ tb_conv_core__DOT__packet_out_valid;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__charge_ready;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_wren;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_rden;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__next_count;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__load_counter;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__clear_counter;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__next_count;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__load_counter;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__clear_counter;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_wrap_around_bit__DOT__new_value;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_wrap_around_bit__DOT__new_value;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_wren;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_rden;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__next_count;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__load_counter;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__clear_counter;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__next_count;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__load_counter;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__clear_counter;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_wrap_around_bit__DOT__new_value;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_wrap_around_bit__DOT__new_value;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT__combine_words__DOT__per_bit__BRA__0__KET____DOT__bit_word;
        CData/*1:0*/ tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cin_q;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q;
        CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q;
        CData/*1:0*/ tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q;
    };
    struct {
        CData/*1:0*/ tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q;
        CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__in_bounds;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_618;
        CData/*1:0*/ __VdfgRegularize_h6e95ff9d_0_627;
        CData/*1:0*/ __VdfgRegularize_h6e95ff9d_0_628;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_630;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_632;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__rst__v0;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__enable__v0;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__packet_in_valid__v0;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__packet_in_data__v0;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__packet_in_valid__v1;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__packet_in_data__v1;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__packet_in_valid__v2;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__packet_in_data__v2;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__packet_in_valid__v3;
        CData/*0:0*/ __VdlySet__tb_conv_core__DOT__packet_in_data__v3;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_conv_core__DOT__clk__0;
        SData/*9:0*/ tb_conv_core__DOT__dut__DOT__spike_fifo_out_data;
        IData/*26:0*/ tb_conv_core__DOT__packet_in_data;
        VlWide<3>/*80:0*/ tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data;
        IData/*31:0*/ tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data;
        IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_619;
        IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_620;
        IData/*26:0*/ __VdlyVal__tb_conv_core__DOT__packet_in_data__v0;
        IData/*26:0*/ __VdlyVal__tb_conv_core__DOT__packet_in_data__v2;
        IData/*31:0*/ __Vi;
        VlUnpacked<IData/*31:0*/, 8> tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram;
        VlUnpacked<SData/*9:0*/, 8> tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h91936345__0;

    // INTERNAL VARIABLES
    Vtb_conv_core__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_conv_core___024root(Vtb_conv_core__Syms* symsp, const char* namep);
    ~Vtb_conv_core___024root();
    VL_UNCOPYABLE(Vtb_conv_core___024root);

    // INTERNAL METHODS
};


#endif  // guard
