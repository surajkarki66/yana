// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_conv_core.h for the primary calling header

#include "Vtb_conv_core__pch.h"

VL_ATTR_COLD void Vtb_conv_core___024root___eval_initial__TOP(Vtb_conv_core___024root* vlSelf);
VlCoroutine Vtb_conv_core___024root___eval_initial__TOP__Vtiming__0(Vtb_conv_core___024root* vlSelf);
VlCoroutine Vtb_conv_core___024root___eval_initial__TOP__Vtiming__1(Vtb_conv_core___024root* vlSelf);
VlCoroutine Vtb_conv_core___024root___eval_initial__TOP__Vtiming__2(Vtb_conv_core___024root* vlSelf);

void Vtb_conv_core___024root___eval_initial(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_initial\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_conv_core___024root___eval_initial__TOP(vlSelf);
    Vtb_conv_core___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_conv_core___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_conv_core___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

void Vtb_conv_core___024root___eval_sample(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_sample\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv_core___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_conv_core___024root___eval_ico(Vtb_conv_core___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_ico\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_conv_core___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vtb_conv_core___024root___timing_ready(Vtb_conv_core___024root* vlSelf);
void Vtb_conv_core___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtb_conv_core___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtb_conv_core___024root___timing_resume(Vtb_conv_core___024root* vlSelf);
void Vtb_conv_core___024root___act_sequent__TOP__0(Vtb_conv_core___024root* vlSelf);

bool Vtb_conv_core___024root___eval_act(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_act\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.tb_conv_core__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_conv_core__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tb_conv_core__DOT__clk__0 
            = vlSelfRef.tb_conv_core__DOT__clk;
    }
    Vtb_conv_core___024root___timing_ready(vlSelf);
    Vtb_conv_core___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_conv_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_conv_core___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_conv_core___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_conv_core___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
                Vtb_conv_core___024root___act_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VactExecute);
}

bool Vtb_conv_core___024root___eval_inact(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_inact\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb_conv_core.sv", 7, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_conv_core___024root___nba_sequent__TOP__0(Vtb_conv_core___024root* vlSelf);
void Vtb_conv_core___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vtb_conv_core___024root___eval_nba(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_nba\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_conv_core___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_conv_core___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vtb_conv_core___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtb_conv_core___024root___eval_obs(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_obs\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtb_conv_core___024root___eval_react(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_react\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtb_conv_core___024root___eval_postponed(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_postponed\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_conv_core___024root____VbeforeTrig_h91936345__0(Vtb_conv_core___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_conv_core___024root___eval_initial__TOP__Vtiming__0(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_conv_core__DOT____VlemCall_1__flatten_nchw;
    IData/*31:0*/ tb_conv_core__DOT____VlemCall_0__flatten_nchw;
    IData/*31:0*/ tb_conv_core__DOT__errors;
    tb_conv_core__DOT__errors = 0;
    IData/*31:0*/ tb_conv_core__DOT__got_count;
    tb_conv_core__DOT__got_count = 0;
    IData/*31:0*/ tb_conv_core__DOT__unnamedblk1_1__DOT____Vrepeat0;
    tb_conv_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ tb_conv_core__DOT__unnamedblk1_2__DOT____Vrepeat1;
    tb_conv_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    IData/*31:0*/ tb_conv_core__DOT__unnamedblk1_3__DOT____Vrepeat2;
    tb_conv_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    IData/*31:0*/ __Vfunc_tb_conv_core__DOT__flatten_nchw__0__c;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__0__c = 0;
    IData/*31:0*/ __Vfunc_tb_conv_core__DOT__flatten_nchw__0__y;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__0__y = 0;
    IData/*31:0*/ __Vfunc_tb_conv_core__DOT__flatten_nchw__0__x;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__0__x = 0;
    IData/*31:0*/ __Vtask_tb_conv_core__DOT__send_axon__1__axon_id;
    __Vtask_tb_conv_core__DOT__send_axon__1__axon_id = 0;
    IData/*26:0*/ __Vtask_tb_conv_core__DOT__send_axon__1__pkt;
    __Vtask_tb_conv_core__DOT__send_axon__1__pkt = 0;
    IData/*31:0*/ __Vtask_tb_conv_core__DOT__collect_charges__2__expected;
    __Vtask_tb_conv_core__DOT__collect_charges__2__expected = 0;
    IData/*31:0*/ __Vtask_tb_conv_core__DOT__collect_charges__2__timeout_cycles;
    __Vtask_tb_conv_core__DOT__collect_charges__2__timeout_cycles = 0;
    IData/*31:0*/ __Vtask_tb_conv_core__DOT__collect_charges__2__cycles;
    __Vtask_tb_conv_core__DOT__collect_charges__2__cycles = 0;
    IData/*31:0*/ __Vfunc_tb_conv_core__DOT__flatten_nchw__3__c;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__3__c = 0;
    IData/*31:0*/ __Vfunc_tb_conv_core__DOT__flatten_nchw__3__y;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__3__y = 0;
    IData/*31:0*/ __Vfunc_tb_conv_core__DOT__flatten_nchw__3__x;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__3__x = 0;
    IData/*31:0*/ __Vtask_tb_conv_core__DOT__send_axon__4__axon_id;
    __Vtask_tb_conv_core__DOT__send_axon__4__axon_id = 0;
    IData/*26:0*/ __Vtask_tb_conv_core__DOT__send_axon__4__pkt;
    __Vtask_tb_conv_core__DOT__send_axon__4__pkt = 0;
    IData/*31:0*/ __Vtask_tb_conv_core__DOT__collect_charges__5__expected;
    __Vtask_tb_conv_core__DOT__collect_charges__5__expected = 0;
    IData/*31:0*/ __Vtask_tb_conv_core__DOT__collect_charges__5__timeout_cycles;
    __Vtask_tb_conv_core__DOT__collect_charges__5__timeout_cycles = 0;
    IData/*31:0*/ __Vtask_tb_conv_core__DOT__collect_charges__5__cycles;
    __Vtask_tb_conv_core__DOT__collect_charges__5__cycles = 0;
    // Body
    tb_conv_core__DOT__errors = 0U;
    vlSelfRef.tb_conv_core__DOT__rst = 1U;
    vlSelfRef.tb_conv_core__DOT__enable = 0U;
    vlSelfRef.tb_conv_core__DOT__init = 0U;
    vlSelfRef.tb_conv_core__DOT__packet_in_valid = 0U;
    vlSelfRef.tb_conv_core__DOT__packet_in_data = 0U;
    vlSelfRef.tb_conv_core__DOT__packet_out_ready = 1U;
    tb_conv_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 5U;
    while (VL_LTS_III(32, 0U, tb_conv_core__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                            "@(posedge tb_conv_core.clk)");
        co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv_core.clk)", 
                                                             "tb_conv_core.sv", 
                                                             154);
        tb_conv_core__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (tb_conv_core__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__VdlySet__tb_conv_core__DOT__rst__v0 = 1U;
    vlSelfRef.__VdlySet__tb_conv_core__DOT__enable__v0 = 1U;
    tb_conv_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    while (VL_LTS_III(32, 0U, tb_conv_core__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                            "@(posedge tb_conv_core.clk)");
        co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv_core.clk)", 
                                                             "tb_conv_core.sv", 
                                                             157);
        tb_conv_core__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (tb_conv_core__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    __Vfunc_tb_conv_core__DOT__flatten_nchw__0__x = 2U;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__0__y = 2U;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__0__c = 0U;
    tb_conv_core__DOT____VlemCall_0__flatten_nchw = 0U;
    tb_conv_core__DOT____VlemCall_0__flatten_nchw = 
        (VL_MULS_III(32, (IData)(5U), (VL_MULS_III(32, (IData)(5U), __Vfunc_tb_conv_core__DOT__flatten_nchw__0__c) 
                                       + __Vfunc_tb_conv_core__DOT__flatten_nchw__0__y)) 
         + __Vfunc_tb_conv_core__DOT__flatten_nchw__0__x);
    __Vtask_tb_conv_core__DOT__send_axon__1__axon_id 
        = tb_conv_core__DOT____VlemCall_0__flatten_nchw;
    __Vtask_tb_conv_core__DOT__send_axon__1__pkt = 0;
    __Vtask_tb_conv_core__DOT__send_axon__1__pkt = 0U;
    __Vtask_tb_conv_core__DOT__send_axon__1__pkt = 
        (0x000007feU & (__Vtask_tb_conv_core__DOT__send_axon__1__axon_id 
                        << 1U));
    Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                        "@(posedge tb_conv_core.clk)");
    co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv_core.clk)", 
                                                         "tb_conv_core.sv", 
                                                         90);
    while ((1U & (~ (0U != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT__combine_words__DOT__per_bit__BRA__0__KET____DOT__bit_word))))) {
        Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                            "@(posedge tb_conv_core.clk)");
        co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv_core.clk)", 
                                                             "tb_conv_core.sv", 
                                                             91);
    }
    vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v0 = 1U;
    vlSelfRef.__VdlyVal__tb_conv_core__DOT__packet_in_data__v0 
        = __Vtask_tb_conv_core__DOT__send_axon__1__pkt;
    vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v0 = 1U;
    Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                        "@(posedge tb_conv_core.clk)");
    co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv_core.clk)", 
                                                         "tb_conv_core.sv", 
                                                         94);
    vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v1 = 1U;
    vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v1 = 1U;
    __Vtask_tb_conv_core__DOT__collect_charges__2__timeout_cycles = 0x00004e20U;
    __Vtask_tb_conv_core__DOT__collect_charges__2__expected = 0x00000012U;
    __Vtask_tb_conv_core__DOT__collect_charges__2__cycles = 0U;
    tb_conv_core__DOT__got_count = 0U;
    __Vtask_tb_conv_core__DOT__collect_charges__2__cycles = 0U;
    {
        while (true) {
            Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                                "@(posedge tb_conv_core.clk)");
            co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_conv_core.clk)", 
                                                                 "tb_conv_core.sv", 
                                                                 104);
            __Vtask_tb_conv_core__DOT__collect_charges__2__cycles 
                = ((IData)(1U) + __Vtask_tb_conv_core__DOT__collect_charges__2__cycles);
            if (((IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid) 
                 & (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_ready))) {
                if (VL_UNLIKELY(((0xffffffffU != VL_EXTENDS_II(32,3, 
                                                               (7U 
                                                                & vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data)))))) {
                    VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:109: Assertion failed in %m: Bad DEST_DX: got %0d expected -1\n",4, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '~',3,(7U & vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data));
                    VL_STOP_MT("tb_conv_core.sv", 109, "");
                    tb_conv_core__DOT__errors = ((IData)(1U) 
                                                 + tb_conv_core__DOT__errors);
                }
                if (VL_UNLIKELY(((0xffffffffU != VL_EXTENDS_II(32,2, 
                                                               (3U 
                                                                & (vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data 
                                                                   >> 3U))))))) {
                    VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:114: Assertion failed in %m: Bad DEST_DY: got %0d expected -1\n",4, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '~',2,(3U & (vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data 
                                                >> 3U)));
                    VL_STOP_MT("tb_conv_core.sv", 114, "");
                    tb_conv_core__DOT__errors = ((IData)(1U) 
                                                 + tb_conv_core__DOT__errors);
                }
                if (VL_UNLIKELY(((0x00000020U & vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data)))) {
                    VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:119: Assertion failed in %m: Outgoing ctrl_flag must be 0\n",3, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000));
                    VL_STOP_MT("tb_conv_core.sv", 119, "");
                    tb_conv_core__DOT__errors = ((IData)(1U) 
                                                 + tb_conv_core__DOT__errors);
                }
                tb_conv_core__DOT__got_count = ((IData)(1U) 
                                                + tb_conv_core__DOT__got_count);
            }
            if ((((IData)(vlSelfRef.tb_conv_core__DOT__core_done) 
                  & (~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid))) 
                 & (~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid)))) {
                Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                                    "@(posedge tb_conv_core.clk)");
                co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_conv_core.clk)", 
                                                                     "tb_conv_core.sv", 
                                                                     125);
                if (((IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid) 
                     & (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_ready))) {
                    tb_conv_core__DOT__got_count = 
                        ((IData)(1U) + tb_conv_core__DOT__got_count);
                }
                goto __Vlabel0;
            }
            if (VL_UNLIKELY((VL_GTS_III(32, __Vtask_tb_conv_core__DOT__collect_charges__2__cycles, __Vtask_tb_conv_core__DOT__collect_charges__2__timeout_cycles)))) {
                VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:130: Assertion failed in %m: Timeout collecting charges (got %0d)\n",4, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '~',32,tb_conv_core__DOT__got_count);
                VL_STOP_MT("tb_conv_core.sv", 130, "");
                tb_conv_core__DOT__errors = ((IData)(1U) 
                                             + tb_conv_core__DOT__errors);
                goto __Vlabel0;
            }
        }
        __Vlabel0: ;
    }
    if (VL_UNLIKELY(((tb_conv_core__DOT__got_count 
                      != __Vtask_tb_conv_core__DOT__collect_charges__2__expected)))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:136: Assertion failed in %m: Charge count got=%0d expected=%0d\n",5, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '~',32,tb_conv_core__DOT__got_count
                     , '~',32,__Vtask_tb_conv_core__DOT__collect_charges__2__expected);
        VL_STOP_MT("tb_conv_core.sv", 136, "");
        tb_conv_core__DOT__errors = ((IData)(1U) + tb_conv_core__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: collected %0d charges with DEST=(-1,-1)\n",1
                     , '~',32,tb_conv_core__DOT__got_count);
    }
    __Vfunc_tb_conv_core__DOT__flatten_nchw__3__x = 0U;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__3__y = 0U;
    __Vfunc_tb_conv_core__DOT__flatten_nchw__3__c = 0U;
    tb_conv_core__DOT____VlemCall_1__flatten_nchw = 0U;
    tb_conv_core__DOT____VlemCall_1__flatten_nchw = 
        (VL_MULS_III(32, (IData)(5U), (VL_MULS_III(32, (IData)(5U), __Vfunc_tb_conv_core__DOT__flatten_nchw__3__c) 
                                       + __Vfunc_tb_conv_core__DOT__flatten_nchw__3__y)) 
         + __Vfunc_tb_conv_core__DOT__flatten_nchw__3__x);
    __Vtask_tb_conv_core__DOT__send_axon__4__axon_id 
        = tb_conv_core__DOT____VlemCall_1__flatten_nchw;
    __Vtask_tb_conv_core__DOT__send_axon__4__pkt = 0;
    __Vtask_tb_conv_core__DOT__send_axon__4__pkt = 0U;
    __Vtask_tb_conv_core__DOT__send_axon__4__pkt = 
        (0x000007feU & (__Vtask_tb_conv_core__DOT__send_axon__4__axon_id 
                        << 1U));
    Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                        "@(posedge tb_conv_core.clk)");
    co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv_core.clk)", 
                                                         "tb_conv_core.sv", 
                                                         90);
    while ((1U & (~ (0U != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT__combine_words__DOT__per_bit__BRA__0__KET____DOT__bit_word))))) {
        Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                            "@(posedge tb_conv_core.clk)");
        co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv_core.clk)", 
                                                             "tb_conv_core.sv", 
                                                             91);
    }
    vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v2 = 1U;
    vlSelfRef.__VdlyVal__tb_conv_core__DOT__packet_in_data__v2 
        = __Vtask_tb_conv_core__DOT__send_axon__4__pkt;
    vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v2 = 1U;
    Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                        "@(posedge tb_conv_core.clk)");
    co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv_core.clk)", 
                                                         "tb_conv_core.sv", 
                                                         94);
    vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v3 = 1U;
    vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v3 = 1U;
    __Vtask_tb_conv_core__DOT__collect_charges__5__timeout_cycles = 0x00004e20U;
    __Vtask_tb_conv_core__DOT__collect_charges__5__expected = 2U;
    __Vtask_tb_conv_core__DOT__collect_charges__5__cycles = 0U;
    tb_conv_core__DOT__got_count = 0U;
    __Vtask_tb_conv_core__DOT__collect_charges__5__cycles = 0U;
    {
        while (true) {
            Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                                "@(posedge tb_conv_core.clk)");
            co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_conv_core.clk)", 
                                                                 "tb_conv_core.sv", 
                                                                 104);
            __Vtask_tb_conv_core__DOT__collect_charges__5__cycles 
                = ((IData)(1U) + __Vtask_tb_conv_core__DOT__collect_charges__5__cycles);
            if (((IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid) 
                 & (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_ready))) {
                if (VL_UNLIKELY(((0xffffffffU != VL_EXTENDS_II(32,3, 
                                                               (7U 
                                                                & vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data)))))) {
                    VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:109: Assertion failed in %m: Bad DEST_DX: got %0d expected -1\n",4, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '~',3,(7U & vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data));
                    VL_STOP_MT("tb_conv_core.sv", 109, "");
                    tb_conv_core__DOT__errors = ((IData)(1U) 
                                                 + tb_conv_core__DOT__errors);
                }
                if (VL_UNLIKELY(((0xffffffffU != VL_EXTENDS_II(32,2, 
                                                               (3U 
                                                                & (vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data 
                                                                   >> 3U))))))) {
                    VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:114: Assertion failed in %m: Bad DEST_DY: got %0d expected -1\n",4, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '~',2,(3U & (vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data 
                                                >> 3U)));
                    VL_STOP_MT("tb_conv_core.sv", 114, "");
                    tb_conv_core__DOT__errors = ((IData)(1U) 
                                                 + tb_conv_core__DOT__errors);
                }
                if (VL_UNLIKELY(((0x00000020U & vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data)))) {
                    VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:119: Assertion failed in %m: Outgoing ctrl_flag must be 0\n",3, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000));
                    VL_STOP_MT("tb_conv_core.sv", 119, "");
                    tb_conv_core__DOT__errors = ((IData)(1U) 
                                                 + tb_conv_core__DOT__errors);
                }
                tb_conv_core__DOT__got_count = ((IData)(1U) 
                                                + tb_conv_core__DOT__got_count);
            }
            if ((((IData)(vlSelfRef.tb_conv_core__DOT__core_done) 
                  & (~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid))) 
                 & (~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid)))) {
                Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                                    "@(posedge tb_conv_core.clk)");
                co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_conv_core.clk)", 
                                                                     "tb_conv_core.sv", 
                                                                     125);
                if (((IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid) 
                     & (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_ready))) {
                    tb_conv_core__DOT__got_count = 
                        ((IData)(1U) + tb_conv_core__DOT__got_count);
                }
                goto __Vlabel1;
            }
            if (VL_UNLIKELY((VL_GTS_III(32, __Vtask_tb_conv_core__DOT__collect_charges__5__cycles, __Vtask_tb_conv_core__DOT__collect_charges__5__timeout_cycles)))) {
                VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:130: Assertion failed in %m: Timeout collecting charges (got %0d)\n",4, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '~',32,tb_conv_core__DOT__got_count);
                VL_STOP_MT("tb_conv_core.sv", 130, "");
                tb_conv_core__DOT__errors = ((IData)(1U) 
                                             + tb_conv_core__DOT__errors);
                goto __Vlabel1;
            }
        }
        __Vlabel1: ;
    }
    if (VL_UNLIKELY(((tb_conv_core__DOT__got_count 
                      != __Vtask_tb_conv_core__DOT__collect_charges__5__expected)))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:136: Assertion failed in %m: Charge count got=%0d expected=%0d\n",5, 'M',vlSymsp->name(),"tb_conv_core.collect_charges", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '~',32,tb_conv_core__DOT__got_count
                     , '~',32,__Vtask_tb_conv_core__DOT__collect_charges__5__expected);
        VL_STOP_MT("tb_conv_core.sv", 136, "");
        tb_conv_core__DOT__errors = ((IData)(1U) + tb_conv_core__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: collected %0d charges with DEST=(-1,-1)\n",1
                     , '~',32,tb_conv_core__DOT__got_count);
    }
    tb_conv_core__DOT__unnamedblk1_3__DOT____Vrepeat2 = 5U;
    while (VL_LTS_III(32, 0U, tb_conv_core__DOT__unnamedblk1_3__DOT____Vrepeat2)) {
        Vtb_conv_core___024root____VbeforeTrig_h91936345__0(vlSelf, 
                                                            "@(posedge tb_conv_core.clk)");
        co_await vlSelfRef.__VtrigSched_h91936345__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv_core.clk)", 
                                                             "tb_conv_core.sv", 
                                                             167);
        tb_conv_core__DOT__unnamedblk1_3__DOT____Vrepeat2 
            = (tb_conv_core__DOT__unnamedblk1_3__DOT____Vrepeat2 
               - (IData)(1U));
    }
    if ((0U == tb_conv_core__DOT__errors)) {
        VL_WRITEF_NX("tb_conv_core: ALL TESTS PASSED\n",0);
        VL_FINISH_MT("tb_conv_core.sv", 170, "");
    } else {
        VL_WRITEF_NX("tb_conv_core: FAILED with %0d errors\n[%0t] %%Fatal: tb_conv_core.sv:173: Assertion failed in %m\n",4, 'M',vlSymsp->name(),"tb_conv_core", 'T',-9
                     , '~',32,tb_conv_core__DOT__errors
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tb_conv_core.sv", 173, "", false);
    }
    co_return;
}

VlCoroutine Vtb_conv_core___024root___eval_initial__TOP__Vtiming__1(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000077359400ULL, 
                                         nullptr, "tb_conv_core.sv", 
                                         178);
    VL_WRITEF_NX("[%0t] %%Error: tb_conv_core.sv:179: Assertion failed in %m: Global watchdog timeout\n",3, 'M',vlSymsp->name(),"tb_conv_core", 'T',-9
                 , '#',64,VL_TIME_UNITED_Q(1000));
    VL_STOP_MT("tb_conv_core.sv", 179, "");
    VL_WRITEF_NX("[%0t] %%Fatal: tb_conv_core.sv:180: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_conv_core", 'T',-9
                 , '#',64,VL_TIME_UNITED_Q(1000));
    VL_STOP_MT("tb_conv_core.sv", 180, "", false);
    co_return;
}

VlCoroutine Vtb_conv_core___024root___eval_initial__TOP__Vtiming__2(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tb_conv_core.sv", 
                                             26);
        vlSelfRef.tb_conv_core__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_conv_core__DOT__clk)));
    }
    co_return;
}

bool Vtb_conv_core___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

bool Vtb_conv_core___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_conv_core___024root___act_sequent__TOP__0(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___act_sequent__TOP__0\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__init_d;
    tb_conv_core__DOT__dut__DOT__init_d = 0;
    CData/*2:0*/ tb_conv_core__DOT__dut__DOT__rx_branch_out_valid;
    tb_conv_core__DOT__dut__DOT__rx_branch_out_valid = 0;
    CData/*2:0*/ tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector;
    tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready;
    tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0;
    CData/*2:0*/ __VdfgRegularize_h6e95ff9d_0_623;
    __VdfgRegularize_h6e95ff9d_0_623 = 0;
    // Body
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_618 = ((IData)(vlSelfRef.tb_conv_core__DOT__enable) 
                                                  & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid) 
           & (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_ready));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove 
        = tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle 
        = (1U & ((~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid)) 
                 & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_rden 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr)));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around 
        = tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__enable) 
              & (0U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle 
        = (1U & ((~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid)) 
                 & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_rden 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__init_d = ((~ (IData)(vlSelfRef.tb_conv_core__DOT__enable)) 
                                           & (IData)(vlSelfRef.tb_conv_core__DOT__init));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr))))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__load_counter 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr))))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__load_counter 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr));
    vlSelfRef.tb_conv_core__DOT__core_done = ((IData)(tb_conv_core__DOT__dut__DOT__init_d) 
                                              | ((((((~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid)) 
                                                     & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)) 
                                                    & (0U 
                                                       == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))) 
                                                   & (~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid))) 
                                                  & (~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid))) 
                                                 & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector 
        = ((IData)(tb_conv_core__DOT__dut__DOT__init_d)
            ? 4U : ((1U & vlSelfRef.tb_conv_core__DOT__packet_in_data)
                     ? 2U : 1U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv_core__DOT__packet_in_data 
           & (- (IData)((1U & ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                               >> 2U)))));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv_core__DOT__packet_in_data 
           & (- (IData)((1U & ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                               >> 1U)))));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv_core__DOT__packet_in_data 
           & (- (IData)((1U & (IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector)))));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid) 
           & ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
              >> 2U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid) 
           & ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
              >> 1U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid) 
           & (IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector));
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[0U] 
        = (IData)((((QData)((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out)) 
                    << 0x0000001bU) | (QData)((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[1U] 
        = ((tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
            << 0x00000016U) | (IData)(((((QData)((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out)) 
                                         << 0x0000001bU) 
                                        | (QData)((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out))) 
                                       >> 0x00000020U)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[2U] 
        = (tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
           >> 0x0000000aU);
    tb_conv_core__DOT__dut__DOT__rx_branch_out_valid 
        = (((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out) 
            << 2U) | (((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out) 
                       << 1U) | (IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out)));
    tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert 
        = ((IData)(tb_conv_core__DOT__dut__DOT__rx_branch_out_valid) 
           & (IData)(tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_wren 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr))))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__load_counter 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr));
    __VdfgRegularize_h6e95ff9d_0_623 = ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                                        & (6U | (IData)(tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready)));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out 
        = (1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_623) 
                 >> 2U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out 
        = (1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_623) 
                 >> 1U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out 
        = (1U & (IData)(__VdfgRegularize_h6e95ff9d_0_623));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT__combine_words__DOT__per_bit__BRA__0__KET____DOT__bit_word 
        = (((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out) 
            << 2U) | (((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out) 
                       << 1U) | (IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out)));
}

void Vtb_conv_core___024root___nba_sequent__TOP__0(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___nba_sequent__TOP__0\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__init_d;
    tb_conv_core__DOT__dut__DOT__init_d = 0;
    CData/*2:0*/ tb_conv_core__DOT__dut__DOT__rx_branch_out_valid;
    tb_conv_core__DOT__dut__DOT__rx_branch_out_valid = 0;
    CData/*2:0*/ tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector;
    tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready;
    tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__insert = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle = 0;
    CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0;
    CData/*2:0*/ __VdfgRegularize_h6e95ff9d_0_623;
    __VdfgRegularize_h6e95ff9d_0_623 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_624;
    __VdfgRegularize_h6e95ff9d_0_624 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_625;
    __VdfgRegularize_h6e95ff9d_0_625 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_633;
    __VdfgRegularize_h6e95ff9d_0_633 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_634;
    __VdfgRegularize_h6e95ff9d_0_634 = 0;
    CData/*1:0*/ __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q;
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q = 0;
    CData/*1:0*/ __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q;
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q = 0;
    CData/*1:0*/ __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q;
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q = 0;
    CData/*0:0*/ __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q;
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q = 0;
    IData/*31:0*/ __VdlyVal__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0;
    __VdlyVal__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0;
    __VdlyDim0__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0;
    __VdlySet__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0 = 0;
    SData/*9:0*/ __VdlyVal__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0;
    __VdlyVal__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0;
    __VdlyDim0__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0;
    __VdlySet__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0 = 0;
    // Body
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q 
        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q;
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q 
        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q;
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q 
        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q;
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q 
        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q;
    __VdlySet__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0 = 0U;
    __VdlySet__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0 = 0U;
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v0) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v0 = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_in_valid = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v1) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v1 = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_in_valid = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v2) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v2 = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_in_valid = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v3) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_valid__v3 = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_in_valid = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v0) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v0 = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_in_data 
            = vlSelfRef.__VdlyVal__tb_conv_core__DOT__packet_in_data__v0;
    }
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v1) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v1 = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_in_data = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v2) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v2 = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_in_data 
            = vlSelfRef.__VdlyVal__tb_conv_core__DOT__packet_in_data__v2;
    }
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v3) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__packet_in_data__v3 = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_in_data = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__enable__v0) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__enable__v0 = 0U;
        vlSelfRef.tb_conv_core__DOT__enable = 1U;
    }
    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q 
        = ((1U & (~ (IData)(vlSelfRef.tb_conv_core__DOT__rst))) 
           && ((0U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))
                ? ((~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_618)) 
                   & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q))
                : ((1U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))
                    ? ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__in_bounds)
                        ? (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q)
                        : (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_630))
                    : ((2U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))
                        ? ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__charge_ready)
                            ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_630)
                            : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q))
                        : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q)))));
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_wren) {
        __VdlyVal__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0 
            = (0x1fU | ((((VL_MULS_III(32, (IData)(3U), 
                                       (VL_MULS_III(32, (IData)(3U), 
                                                    ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cin_q) 
                                                     + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q))) 
                                        + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q))) 
                           + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q)) 
                          & (- (IData)((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_632)))) 
                         << 0x00000010U) | (0x0000ffc0U 
                                            & (((- (IData)((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_632))) 
                                                & (VL_MULS_III(32, (IData)(9U), (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q)) 
                                                   + 
                                                   (VL_MULS_III(32, (IData)(3U), 
                                                                VL_EXTENDS_II(32,4, 
                                                                              (0x0000000fU 
                                                                               & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_619))) 
                                                    + 
                                                    VL_EXTENDS_II(10,4, 
                                                                  (0x0000000fU 
                                                                   & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_620))))) 
                                               << 6U))));
        __VdlyDim0__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0 
            = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr;
        __VdlySet__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0 = 1U;
    }
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_wren) {
        __VdlyVal__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0 
            = (0x000003ffU & (vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[0U] 
                              >> 1U));
        __VdlyDim0__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0 
            = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr;
        __VdlySet__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0 = 1U;
    }
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cin_q 
        = ((1U & (~ (IData)(vlSelfRef.tb_conv_core__DOT__rst))) 
           && (1U & ((0U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))
                      ? ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_618)
                          ? VL_DIV_III(32, (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_data), (IData)(0x00000019U))
                          : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cin_q))
                      : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cin_q))));
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register) {
        vlSelfRef.tb_conv_core__DOT__packet_out_valid 
            = (1U & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    }
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around 
        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_wrap_around_bit__DOT__new_value;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around 
        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_wrap_around_bit__DOT__new_value;
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid 
            = (1U & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)));
    }
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around 
        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_wrap_around_bit__DOT__new_value;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around 
        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_wrap_around_bit__DOT__new_value;
    if (vlSelfRef.tb_conv_core__DOT__rst) {
        __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q = 0U;
        __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q = 0U;
        __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q = 0U;
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q = 0U;
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q = 0U;
        vlSelfRef.tb_conv_core__DOT__packet_out_valid = 0U;
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around = 0U;
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around = 0U;
        vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid = 0U;
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around = 0U;
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around = 0U;
    } else if ((0U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))) {
        __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q 
            = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q) 
               & (- (IData)((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_618))))));
        __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q 
            = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q) 
               & (- (IData)((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_618))))));
        if (vlSelfRef.__VdfgRegularize_h6e95ff9d_0_618) {
            __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q = 1U;
            vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q 
                = (7U & VL_MODDIV_III(32, VL_DIV_III(32, (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_data), (IData)(5U)), (IData)(5U)));
            vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q 
                = (7U & VL_MODDIV_III(32, (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_data), (IData)(5U)));
        } else {
            __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q 
                = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q;
            vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q 
                = (7U & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q));
            vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q 
                = (7U & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q));
        }
    } else {
        if ((1U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))) {
            if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__in_bounds) {
                __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q 
                    = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q;
                __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q 
                    = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q;
                __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q = 2U;
            } else {
                __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q 
                    = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_627;
                __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q 
                    = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_628;
                __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q 
                    = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q)
                        ? ((2U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q))
                            ? ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q) 
                               & (- (IData)((2U != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q)))))
                            : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))
                        : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q));
            }
        } else {
            if ((2U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))) {
                if (vlSelfRef.tb_conv_core__DOT__dut__DOT__charge_ready) {
                    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q 
                        = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_627;
                    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q 
                        = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_628;
                } else {
                    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q 
                        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q;
                    __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q 
                        = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q;
                }
            } else {
                __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q 
                    = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q;
                __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q 
                    = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q;
            }
            __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q 
                = (((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__charge_ready)
                     ? ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q)
                         ? ((2U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q))
                             ? (1U & (- (IData)((2U 
                                                 != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q)))))
                             : 1U) : 1U) : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q)) 
                   & (- (IData)((2U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q)))));
        }
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q 
            = (7U & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q));
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q 
            = (7U & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q));
    }
    tb_conv_core__DOT__dut__DOT__init_d = ((~ (IData)(vlSelfRef.tb_conv_core__DOT__enable)) 
                                           & (IData)(vlSelfRef.tb_conv_core__DOT__init));
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_rden) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data 
            = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram
            [vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr];
    }
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q 
        = __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q 
        = __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q 
        = __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q 
        = __Vdly__tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q;
    if (vlSelfRef.__VdlySet__tb_conv_core__DOT__rst__v0) {
        vlSelfRef.__VdlySet__tb_conv_core__DOT__rst__v0 = 0U;
        vlSelfRef.tb_conv_core__DOT__rst = 0U;
    }
    tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector 
        = ((IData)(tb_conv_core__DOT__dut__DOT__init_d)
            ? 4U : ((1U & vlSelfRef.tb_conv_core__DOT__packet_in_data)
                     ? 2U : 1U));
    if (__VdlySet__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[__VdlyDim0__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0] 
            = __VdlyVal__tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram__v0;
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_630 = (1U 
                                                  & ((~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q)) 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q))));
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q) {
        vlSelfRef.__VdfgRegularize_h6e95ff9d_0_628 
            = (3U & (((IData)(1U) + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q)) 
                     & (- (IData)((2U != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q))))));
        vlSelfRef.__VdfgRegularize_h6e95ff9d_0_627 
            = (3U & ((2U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q))
                      ? ((2U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q))
                          ? (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q)
                          : ((IData)(1U) + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q)))
                      : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q)));
    } else {
        vlSelfRef.__VdfgRegularize_h6e95ff9d_0_628 
            = (3U & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q));
        vlSelfRef.__VdfgRegularize_h6e95ff9d_0_627 
            = (3U & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q));
    }
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__load_counter) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr 
            = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__next_count;
    }
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__clear_counter) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr = 0U;
    }
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__load_counter) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr 
            = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__next_count;
    }
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__clear_counter) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr = 0U;
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_619 = VL_EXTENDS_II(32,6, 
                                                               (0x0000003fU 
                                                                & (VL_EXTENDS_II(6,4, (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q)) 
                                                                   - 
                                                                   VL_EXTENDS_II(6,3, (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_620 = VL_EXTENDS_II(32,6, 
                                                               (0x0000003fU 
                                                                & (VL_EXTENDS_II(6,4, (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q)) 
                                                                   - 
                                                                   VL_EXTENDS_II(6,3, (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q)))));
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_rden) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_data 
            = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram
            [vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr];
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_618 = ((IData)(vlSelfRef.tb_conv_core__DOT__enable) 
                                                  & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv_core__DOT__packet_in_data 
           & (- (IData)((1U & ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                               >> 2U)))));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv_core__DOT__packet_in_data 
           & (- (IData)((1U & ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                               >> 1U)))));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv_core__DOT__packet_in_data 
           & (- (IData)((1U & (IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector)))));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid) 
           & ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
              >> 2U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid) 
           & ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
              >> 1U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid) 
           & (IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector));
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__load_counter) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr 
            = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__next_count;
    }
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__clear_counter) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr = 0U;
    }
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    __VdfgRegularize_h6e95ff9d_0_633 = (VL_LTES_III(32, 0U, 
                                                    VL_EXTENDS_II(32,4, 
                                                                  (0x0000000fU 
                                                                   & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_619))) 
                                        & (VL_LTES_III(32, 0U, 
                                                       VL_EXTENDS_II(32,4, 
                                                                     (0x0000000fU 
                                                                      & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_620))) 
                                           & (VL_GTS_III(32, 3U, 
                                                         VL_EXTENDS_II(32,4, 
                                                                       (0x0000000fU 
                                                                        & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_619))) 
                                              & VL_GTS_III(32, 3U, 
                                                           VL_EXTENDS_II(32,4, 
                                                                         (0x0000000fU 
                                                                          & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_620))))));
    __VdfgRegularize_h6e95ff9d_0_634 = (VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_619) 
                                        & (VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_620) 
                                           & ((0U == 
                                               VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_619, (IData)(1U))) 
                                              & (0U 
                                                 == 
                                                 VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_620, (IData)(1U))))));
    if (__VdlySet__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[__VdlyDim0__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0] 
            = __VdlyVal__tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram__v0;
    }
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[0U] 
        = (IData)((((QData)((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out)) 
                    << 0x0000001bU) | (QData)((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[1U] 
        = ((tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
            << 0x00000016U) | (IData)(((((QData)((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out)) 
                                         << 0x0000001bU) 
                                        | (QData)((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out))) 
                                       >> 0x00000020U)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[2U] 
        = (tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
           >> 0x0000000aU);
    tb_conv_core__DOT__dut__DOT__rx_branch_out_valid 
        = (((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out) 
            << 2U) | (((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out) 
                       << 1U) | (IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr) 
                 + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr) 
                 + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__in_bounds 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_633) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_634));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_632 = ((IData)(__VdfgRegularize_h6e95ff9d_0_634) 
                                                  & (IData)(__VdfgRegularize_h6e95ff9d_0_633));
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__load_counter) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr 
            = vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__next_count;
    }
    if (vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__clear_counter) {
        vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr = 0U;
    }
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr) 
                 + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    __VdfgRegularize_h6e95ff9d_0_624 = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr) 
                                        == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_624) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around) 
              != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_624) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around) 
              == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr) 
                 + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    __VdfgRegularize_h6e95ff9d_0_625 = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr) 
                                        == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__charge_ready 
        = (1U & (~ (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max)));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__insert 
        = ((2U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q)) 
           & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__charge_ready));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_wren 
        = tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr 
        = tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr)));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around 
        = tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid) 
           & (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_ready));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove 
        = tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle 
        = (1U & ((~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid)) 
                 & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_rden 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr)));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around 
        = tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_625) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around) 
              == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_625) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around) 
              != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__next_count 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr))))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__load_counter 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr))))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__load_counter 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr));
    vlSelfRef.tb_conv_core__DOT__core_done = ((IData)(tb_conv_core__DOT__dut__DOT__init_d) 
                                              | ((((((~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid)) 
                                                     & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)) 
                                                    & (0U 
                                                       == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))) 
                                                   & (~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_in_valid))) 
                                                  & (~ (IData)(vlSelfRef.tb_conv_core__DOT__packet_out_valid))) 
                                                 & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__enable) 
              & (0U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q))));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle 
        = (1U & ((~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid)) 
                 & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_rden 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr;
    tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert 
        = ((IData)(tb_conv_core__DOT__dut__DOT__rx_branch_out_valid) 
           & (IData)(tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_wren 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr)));
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around 
        = tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr))))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__load_counter 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr))))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__load_counter 
        = ((IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr) 
           | (IData)(tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr));
    __VdfgRegularize_h6e95ff9d_0_623 = ((IData)(tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                                        & (6U | (IData)(tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready)));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out 
        = (1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_623) 
                 >> 2U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out 
        = (1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_623) 
                 >> 1U));
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out 
        = (1U & (IData)(__VdfgRegularize_h6e95ff9d_0_623));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT__combine_words__DOT__per_bit__BRA__0__KET____DOT__bit_word 
        = (((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out) 
            << 2U) | (((IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out) 
                       << 1U) | (IData)(tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out)));
}

void Vtb_conv_core___024root___timing_ready(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___timing_ready\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h91936345__0.ready("@(posedge tb_conv_core.clk)");
    }
}

void Vtb_conv_core___024root___timing_resume(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___timing_resume\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h91936345__0.moveToResumeQueue(
                                                          "@(posedge tb_conv_core.clk)");
    vlSelfRef.__VtrigSched_h91936345__0.resume("@(posedge tb_conv_core.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_conv_core___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vtb_conv_core___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vtb_conv_core___024root____VbeforeTrig_h91936345__0(Vtb_conv_core___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root____VbeforeTrig_h91936345__0\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.tb_conv_core__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_conv_core__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_conv_core__DOT__clk__0 
        = vlSelfRef.tb_conv_core__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h91936345__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_conv_core___024root___eval_debug_assertions(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_debug_assertions\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
