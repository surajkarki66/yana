// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_conv1d_pe.h for the primary calling header

#ifndef VERILATED_VTB_CONV1D_PE___024ROOT_H_
#define VERILATED_VTB_CONV1D_PE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_conv1d_pe__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_conv1d_pe___024root final {
  public:

    // DESIGN-SPECIFIC STATE
    CData/*0:0*/ tb_conv1d_pe__DOT__clk;
    CData/*0:0*/ tb_conv1d_pe__DOT__rst;
    CData/*0:0*/ tb_conv1d_pe__DOT__enable;
    CData/*0:0*/ tb_conv1d_pe__DOT__done;
    CData/*0:0*/ tb_conv1d_pe__DOT__spike_ready;
    CData/*0:0*/ tb_conv1d_pe__DOT__spike_valid;
    CData/*0:0*/ tb_conv1d_pe__DOT__charge_ready;
    CData/*1:0*/ tb_conv1d_pe__DOT__dut__DOT__state_q;
    CData/*0:0*/ tb_conv1d_pe__DOT__dut__DOT__cin_q;
    CData/*3:0*/ tb_conv1d_pe__DOT__dut__DOT__ix_q;
    CData/*1:0*/ tb_conv1d_pe__DOT__dut__DOT__kx_q;
    CData/*0:0*/ tb_conv1d_pe__DOT__dut__DOT__cout_q;
    CData/*0:0*/ tb_conv1d_pe__DOT__dut__DOT__in_bounds;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_310;
    CData/*1:0*/ __VdfgRegularize_h6e95ff9d_0_315;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_317;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__rst__v0;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__enable__v0;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_valid__v0;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_data__v0;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_valid__v1;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_data__v1;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_valid__v2;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_data__v2;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_valid__v3;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_data__v3;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_valid__v4;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_data__v4;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_valid__v5;
    CData/*0:0*/ __VdlySet__tb_conv1d_pe__DOT__spike_data__v5;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_conv1d_pe__DOT__clk__0;
    SData/*9:0*/ tb_conv1d_pe__DOT__spike_data;
    SData/*9:0*/ __VdlyVal__tb_conv1d_pe__DOT__spike_data__v0;
    SData/*9:0*/ __VdlyVal__tb_conv1d_pe__DOT__spike_data__v2;
    SData/*9:0*/ __VdlyVal__tb_conv1d_pe__DOT__spike_data__v4;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_311;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlQueue<IData/*31:0*/> tb_conv1d_pe__DOT__exp_neuron;
    VlQueue<IData/*31:0*/> tb_conv1d_pe__DOT__exp_tap;
    VlQueue<IData/*31:0*/> tb_conv1d_pe__DOT__got_neuron;
    VlQueue<IData/*31:0*/> tb_conv1d_pe__DOT__got_tap;
    std::string __Vtask_tb_conv1d_pe__DOT__run_case__0__name;
    std::string __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__name;
    std::string __Vtask_tb_conv1d_pe__DOT__run_case__9__name;
    std::string __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__name;
    std::string __Vtask_tb_conv1d_pe__DOT__run_case__18__name;
    std::string __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__name;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h918b1c63__0;

    // INTERNAL VARIABLES
    Vtb_conv1d_pe__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_conv1d_pe___024root(Vtb_conv1d_pe__Syms* symsp, const char* namep);
    ~Vtb_conv1d_pe___024root();
    VL_UNCOPYABLE(Vtb_conv1d_pe___024root);

    // INTERNAL METHODS
};


#endif  // guard
