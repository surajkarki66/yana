// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_conv1d_pe.h for the primary calling header

#include "Vtb_conv1d_pe__pch.h"

VlCoroutine Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__0(Vtb_conv1d_pe___024root* vlSelf);
VlCoroutine Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__1(Vtb_conv1d_pe___024root* vlSelf);
VlCoroutine Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__2(Vtb_conv1d_pe___024root* vlSelf);

void Vtb_conv1d_pe___024root___eval_initial(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_initial\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

void Vtb_conv1d_pe___024root___eval_sample(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_sample\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_pe___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_conv1d_pe___024root___eval_ico(Vtb_conv1d_pe___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_ico\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_conv1d_pe___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vtb_conv1d_pe___024root___timing_ready(Vtb_conv1d_pe___024root* vlSelf);
void Vtb_conv1d_pe___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_pe___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtb_conv1d_pe___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtb_conv1d_pe___024root___timing_resume(Vtb_conv1d_pe___024root* vlSelf);

bool Vtb_conv1d_pe___024root___eval_act(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_act\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.tb_conv1d_pe__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_conv1d_pe__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tb_conv1d_pe__DOT__clk__0 
            = vlSelfRef.tb_conv1d_pe__DOT__clk;
    }
    Vtb_conv1d_pe___024root___timing_ready(vlSelf);
    Vtb_conv1d_pe___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_conv1d_pe___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_conv1d_pe___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_conv1d_pe___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_conv1d_pe___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_sequent__TOP__0
                    vlSelfRef.tb_conv1d_pe__DOT__spike_ready 
                        = ((IData)(vlSelfRef.tb_conv1d_pe__DOT__enable) 
                           & (0U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)));
                    vlSelfRef.tb_conv1d_pe__DOT__done 
                        = ((~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid)) 
                           & (0U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)));
                    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_310 
                        = ((IData)(vlSelfRef.tb_conv1d_pe__DOT__enable) 
                           & (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid));
                }
            }
        }
    }
    return (__VactExecute);
}

bool Vtb_conv1d_pe___024root___eval_inact(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_inact\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb_conv1d_pe.sv", 7, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_conv1d_pe___024root___nba_sequent__TOP__0(Vtb_conv1d_pe___024root* vlSelf);
void Vtb_conv1d_pe___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vtb_conv1d_pe___024root___eval_nba(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_nba\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_conv1d_pe___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_conv1d_pe___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vtb_conv1d_pe___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtb_conv1d_pe___024root___eval_obs(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_obs\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtb_conv1d_pe___024root___eval_react(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_react\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtb_conv1d_pe___024root___eval_postponed(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_postponed\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(Vtb_conv1d_pe___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__0(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_conv1d_pe__DOT__errors;
    tb_conv1d_pe__DOT__errors = 0;
    IData/*31:0*/ tb_conv1d_pe__DOT__unnamedblk1_1__DOT____Vrepeat0;
    tb_conv1d_pe__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ tb_conv1d_pe__DOT__unnamedblk1_2__DOT____Vrepeat1;
    tb_conv1d_pe__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    IData/*31:0*/ tb_conv1d_pe__DOT__unnamedblk1_3__DOT____Vrepeat2;
    tb_conv1d_pe__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__0__cin_i;
    __Vtask_tb_conv1d_pe__DOT__run_case__0__cin_i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__0__ix;
    __Vtask_tb_conv1d_pe__DOT__run_case__0__ix = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__0____VlefCall_0__flatten_cl;
    __Vtask_tb_conv1d_pe__DOT__run_case__0____VlefCall_0__flatten_cl = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ix;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ix = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i;
    __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i;
    __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__c;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__c = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__x;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__x = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__drive_spike__6__axon_id;
    __Vtask_tb_conv1d_pe__DOT__drive_spike__6__axon_id = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__timeout_cycles;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__timeout_cycles = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__cycles;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__cycles = 0;
    CData/*0:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__unnamedblk1__DOT__found;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__unnamedblk1__DOT__found = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j = 0;
    VlQueue<CData/*0:0*/> __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched.atDefault() = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__9__cin_i;
    __Vtask_tb_conv1d_pe__DOT__run_case__9__cin_i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__9__ix;
    __Vtask_tb_conv1d_pe__DOT__run_case__9__ix = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__9____VlefCall_0__flatten_cl;
    __Vtask_tb_conv1d_pe__DOT__run_case__9____VlefCall_0__flatten_cl = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ix;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ix = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i;
    __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i;
    __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__c;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__c = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__x;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__x = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__drive_spike__15__axon_id;
    __Vtask_tb_conv1d_pe__DOT__drive_spike__15__axon_id = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__timeout_cycles;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__timeout_cycles = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__cycles;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__cycles = 0;
    CData/*0:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__unnamedblk1__DOT__found;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__unnamedblk1__DOT__found = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j = 0;
    VlQueue<CData/*0:0*/> __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched.atDefault() = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__18__cin_i;
    __Vtask_tb_conv1d_pe__DOT__run_case__18__cin_i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__18__ix;
    __Vtask_tb_conv1d_pe__DOT__run_case__18__ix = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__run_case__18____VlefCall_0__flatten_cl;
    __Vtask_tb_conv1d_pe__DOT__run_case__18____VlefCall_0__flatten_cl = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ix;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ix = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i;
    __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i;
    __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__Vfuncout;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__c;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__c = 0;
    IData/*31:0*/ __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__x;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__x = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__drive_spike__24__axon_id;
    __Vtask_tb_conv1d_pe__DOT__drive_spike__24__axon_id = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__timeout_cycles;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__timeout_cycles = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__cycles;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__cycles = 0;
    CData/*0:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__unnamedblk1__DOT__found;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__unnamedblk1__DOT__found = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i = 0;
    IData/*31:0*/ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j = 0;
    VlQueue<CData/*0:0*/> __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched.atDefault() = 0;
    // Body
    tb_conv1d_pe__DOT__errors = 0U;
    vlSelfRef.tb_conv1d_pe__DOT__rst = 1U;
    vlSelfRef.tb_conv1d_pe__DOT__enable = 0U;
    vlSelfRef.tb_conv1d_pe__DOT__spike_valid = 0U;
    vlSelfRef.tb_conv1d_pe__DOT__spike_data = 0U;
    vlSelfRef.tb_conv1d_pe__DOT__charge_ready = 1U;
    tb_conv1d_pe__DOT__unnamedblk1_1__DOT____Vrepeat0 = 5U;
    while (VL_LTS_III(32, 0U, tb_conv1d_pe__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                            "@(posedge tb_conv1d_pe.clk)");
        co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv1d_pe.clk)", 
                                                             "tb_conv1d_pe.sv", 
                                                             196);
        tb_conv1d_pe__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (tb_conv1d_pe__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__rst__v0 = 1U;
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__enable__v0 = 1U;
    tb_conv1d_pe__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    while (VL_LTS_III(32, 0U, tb_conv1d_pe__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                            "@(posedge tb_conv1d_pe.clk)");
        co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv1d_pe.clk)", 
                                                             "tb_conv1d_pe.sv", 
                                                             199);
        tb_conv1d_pe__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (tb_conv1d_pe__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    __Vtask_tb_conv1d_pe__DOT__run_case__0__ix = 4U;
    __Vtask_tb_conv1d_pe__DOT__run_case__0__cin_i = 0U;
    vlSelfRef.__Vtask_tb_conv1d_pe__DOT__run_case__0__name = "center(0,4)"s;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ix 
        = __Vtask_tb_conv1d_pe__DOT__run_case__0__ix;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i 
        = __Vtask_tb_conv1d_pe__DOT__run_case__0__cin_i;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im = 0U;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox = 0U;
    vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.clear();
    vlSelfRef.tb_conv1d_pe__DOT__exp_tap.clear();
    vlSelfRef.tb_conv1d_pe__DOT__got_neuron.clear();
    vlSelfRef.tb_conv1d_pe__DOT__got_tap.clear();
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ix;
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im)) {
            goto __Vlabel0;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im, (IData)(1U)))) {
            goto __Vlabel0;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox)) {
            goto __Vlabel0;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout 
            = VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout 
            = VL_MULS_III(32, (IData)(3U), ((IData)(1U) 
                                            + __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap);
        __Vlabel0: ;
    }
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im 
            = (__Vtask_tb_conv1d_pe__DOT__expect_spike__1__ix 
               - (IData)(1U));
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im)) {
            goto __Vlabel1;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im, (IData)(1U)))) {
            goto __Vlabel1;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox)) {
            goto __Vlabel1;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout 
            = ((IData)(1U) + VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout 
            = ((IData)(1U) + VL_MULS_III(32, (IData)(3U), 
                                         ((IData)(1U) 
                                          + __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i)));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap);
        __Vlabel1: ;
    }
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im 
            = (__Vtask_tb_conv1d_pe__DOT__expect_spike__1__ix 
               - (IData)(2U));
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im)) {
            goto __Vlabel2;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im, (IData)(1U)))) {
            goto __Vlabel2;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox)) {
            goto __Vlabel2;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout 
            = ((IData)(2U) + VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__3__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__3__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__1__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout 
            = ((IData)(2U) + VL_MULS_III(32, (IData)(3U), 
                                         ((IData)(1U) 
                                          + __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__cin_i)));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__4__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__1____VlefCall_1__encode_tap);
        __Vlabel2: ;
    }
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__x = __Vtask_tb_conv1d_pe__DOT__run_case__0__ix;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__c = __Vtask_tb_conv1d_pe__DOT__run_case__0__cin_i;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__Vfuncout = 0U;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__Vfuncout 
        = (VL_MULS_III(32, (IData)(9U), __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__c) 
           + __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__x);
    __Vtask_tb_conv1d_pe__DOT__run_case__0____VlefCall_0__flatten_cl 
        = __Vfunc_tb_conv1d_pe__DOT__flatten_cl__5__Vfuncout;
    __Vtask_tb_conv1d_pe__DOT__drive_spike__6__axon_id 
        = __Vtask_tb_conv1d_pe__DOT__run_case__0____VlefCall_0__flatten_cl;
    Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                        "@(posedge tb_conv1d_pe.clk)");
    co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv1d_pe.clk)", 
                                                         "tb_conv1d_pe.sv", 
                                                         106);
    while ((1U & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_ready)))) {
        Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                            "@(posedge tb_conv1d_pe.clk)");
        co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv1d_pe.clk)", 
                                                             "tb_conv1d_pe.sv", 
                                                             107);
    }
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v0 = 1U;
    vlSelfRef.__VdlyVal__tb_conv1d_pe__DOT__spike_data__v0 
        = (0x000003ffU & __Vtask_tb_conv1d_pe__DOT__drive_spike__6__axon_id);
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v0 = 1U;
    Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                        "@(posedge tb_conv1d_pe.clk)");
    co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv1d_pe.clk)", 
                                                         "tb_conv1d_pe.sv", 
                                                         110);
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v1 = 1U;
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v1 = 1U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__timeout_cycles = 0x00002710U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__cycles = 0U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__cycles = 0U;
    {
        while (true) {
            Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                                "@(posedge tb_conv1d_pe.clk)");
            co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_conv1d_pe.clk)", 
                                                                 "tb_conv1d_pe.sv", 
                                                                 119);
            __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__cycles 
                = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__cycles);
            if (((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)) 
                 & (IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready))) {
                vlSelfRef.tb_conv1d_pe__DOT__got_neuron.push_back(
                                                                  (0x000003ffU 
                                                                   & ((VL_MULS_III(32, (IData)(7U), (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)) 
                                                                       + 
                                                                       VL_EXTENDS_II(10,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                      & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                vlSelfRef.tb_conv1d_pe__DOT__got_tap.push_back(
                                                               (0x0000ffffU 
                                                                & ((VL_MULS_III(32, (IData)(3U), 
                                                                                ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q) 
                                                                                + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))) 
                                                                    + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)) 
                                                                   & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
            }
            if ((((IData)(vlSelfRef.tb_conv1d_pe__DOT__done) 
                  & (2U != (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))) 
                 & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid)))) {
                Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                                    "@(posedge tb_conv1d_pe.clk)");
                co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_conv1d_pe.clk)", 
                                                                     "tb_conv1d_pe.sv", 
                                                                     126);
                if (((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)) 
                     & (IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready))) {
                    vlSelfRef.tb_conv1d_pe__DOT__got_neuron.push_back(
                                                                      (0x000003ffU 
                                                                       & ((VL_MULS_III(32, (IData)(7U), (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)) 
                                                                           + 
                                                                           VL_EXTENDS_II(10,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                          & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                    vlSelfRef.tb_conv1d_pe__DOT__got_tap.push_back(
                                                                   (0x0000ffffU 
                                                                    & ((VL_MULS_III(32, (IData)(3U), 
                                                                                ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q) 
                                                                                + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))) 
                                                                        + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)) 
                                                                       & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                }
                goto __Vlabel3;
            }
            if (VL_UNLIKELY((VL_GTS_III(32, __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__cycles, __Vtask_tb_conv1d_pe__DOT__collect_until_done__7__timeout_cycles)))) {
                VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:134: Assertion failed in %m: Timeout waiting for Conv1dPE done\n",3, 'M',vlSymsp->name(),"tb_conv1d_pe.collect_until_done", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("tb_conv1d_pe.sv", 134, "");
                tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                             + tb_conv1d_pe__DOT__errors);
                goto __Vlabel3;
            }
        }
        __Vlabel3: ;
    }
    vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__name 
        = vlSelfRef.__Vtask_tb_conv1d_pe__DOT__run_case__0__name;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i = 0U;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j = 0U;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched.clear();
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched.atDefault() = 0;
    if (VL_UNLIKELY(((vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size() 
                      != vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:145: Assertion failed in %m: %s: charge count got=%0d expected=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__name)
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size()
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size());
        VL_STOP_MT("tb_conv1d_pe.sv", 145, "");
        tb_conv1d_pe__DOT__errors = ((IData)(1U) + tb_conv1d_pe__DOT__errors);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched.clear();
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched.push_back(0U);
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i, vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size())) {
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__unnamedblk1__DOT__found = 0U;
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__unnamedblk1__DOT__found = 0U;
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j = 0U;
        {
            while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
                if ((((~ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j)) 
                      & (vlSelfRef.tb_conv1d_pe__DOT__got_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i) 
                         == vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j))) 
                     & (vlSelfRef.tb_conv1d_pe__DOT__got_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i) 
                        == vlSelfRef.tb_conv1d_pe__DOT__exp_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j)))) {
                    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched.atWriteAppend(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j) = 1U;
                    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__unnamedblk1__DOT__found = 1U;
                    goto __Vlabel4;
                }
                __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j 
                    = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j);
            }
            __Vlabel4: ;
        }
        if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__unnamedblk1__DOT__found)))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:164: Assertion failed in %m: %s: unexpected charge neuron=%0d tap=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard.unnamedblk1", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__name)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i));
            VL_STOP_MT("tb_conv1d_pe.sv", 164, "");
            tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                         + tb_conv1d_pe__DOT__errors);
        }
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__i);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
        if (VL_UNLIKELY(((1U & (~ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__matched.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j)))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:171: Assertion failed in %m: %s: missing charge neuron=%0d tap=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__name)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j));
            VL_STOP_MT("tb_conv1d_pe.sv", 171, "");
            tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                         + tb_conv1d_pe__DOT__errors);
        }
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__j);
    }
    __Vtask_tb_conv1d_pe__DOT__run_case__9__ix = 0U;
    __Vtask_tb_conv1d_pe__DOT__run_case__9__cin_i = 0U;
    vlSelfRef.__Vtask_tb_conv1d_pe__DOT__run_case__9__name = "corner(0,0)"s;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ix 
        = __Vtask_tb_conv1d_pe__DOT__run_case__9__ix;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i 
        = __Vtask_tb_conv1d_pe__DOT__run_case__9__cin_i;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im = 0U;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox = 0U;
    if (VL_UNLIKELY(((vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size() 
                      == vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())))) {
        VL_WRITEF_NX("PASS: %s (%0d charges)\n",2, 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__8__name)
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size());
    }
    vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.clear();
    vlSelfRef.tb_conv1d_pe__DOT__exp_tap.clear();
    vlSelfRef.tb_conv1d_pe__DOT__got_neuron.clear();
    vlSelfRef.tb_conv1d_pe__DOT__got_tap.clear();
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ix;
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im)) {
            goto __Vlabel5;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im, (IData)(1U)))) {
            goto __Vlabel5;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox)) {
            goto __Vlabel5;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout 
            = VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout 
            = VL_MULS_III(32, (IData)(3U), ((IData)(1U) 
                                            + __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap);
        __Vlabel5: ;
    }
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im 
            = (__Vtask_tb_conv1d_pe__DOT__expect_spike__10__ix 
               - (IData)(1U));
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im)) {
            goto __Vlabel6;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im, (IData)(1U)))) {
            goto __Vlabel6;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox)) {
            goto __Vlabel6;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout 
            = ((IData)(1U) + VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout 
            = ((IData)(1U) + VL_MULS_III(32, (IData)(3U), 
                                         ((IData)(1U) 
                                          + __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i)));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap);
        __Vlabel6: ;
    }
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im 
            = (__Vtask_tb_conv1d_pe__DOT__expect_spike__10__ix 
               - (IData)(2U));
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im)) {
            goto __Vlabel7;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im, (IData)(1U)))) {
            goto __Vlabel7;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox)) {
            goto __Vlabel7;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout 
            = ((IData)(2U) + VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__12__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__12__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__10__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout 
            = ((IData)(2U) + VL_MULS_III(32, (IData)(3U), 
                                         ((IData)(1U) 
                                          + __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__cin_i)));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__13__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__10____VlefCall_1__encode_tap);
        __Vlabel7: ;
    }
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__x = __Vtask_tb_conv1d_pe__DOT__run_case__9__ix;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__c = __Vtask_tb_conv1d_pe__DOT__run_case__9__cin_i;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__Vfuncout = 0U;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__Vfuncout 
        = (VL_MULS_III(32, (IData)(9U), __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__c) 
           + __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__x);
    __Vtask_tb_conv1d_pe__DOT__run_case__9____VlefCall_0__flatten_cl 
        = __Vfunc_tb_conv1d_pe__DOT__flatten_cl__14__Vfuncout;
    __Vtask_tb_conv1d_pe__DOT__drive_spike__15__axon_id 
        = __Vtask_tb_conv1d_pe__DOT__run_case__9____VlefCall_0__flatten_cl;
    Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                        "@(posedge tb_conv1d_pe.clk)");
    co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv1d_pe.clk)", 
                                                         "tb_conv1d_pe.sv", 
                                                         106);
    while ((1U & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_ready)))) {
        Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                            "@(posedge tb_conv1d_pe.clk)");
        co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv1d_pe.clk)", 
                                                             "tb_conv1d_pe.sv", 
                                                             107);
    }
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v2 = 1U;
    vlSelfRef.__VdlyVal__tb_conv1d_pe__DOT__spike_data__v2 
        = (0x000003ffU & __Vtask_tb_conv1d_pe__DOT__drive_spike__15__axon_id);
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v2 = 1U;
    Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                        "@(posedge tb_conv1d_pe.clk)");
    co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv1d_pe.clk)", 
                                                         "tb_conv1d_pe.sv", 
                                                         110);
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v3 = 1U;
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v3 = 1U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__timeout_cycles = 0x00002710U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__cycles = 0U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__cycles = 0U;
    {
        while (true) {
            Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                                "@(posedge tb_conv1d_pe.clk)");
            co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_conv1d_pe.clk)", 
                                                                 "tb_conv1d_pe.sv", 
                                                                 119);
            __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__cycles 
                = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__cycles);
            if (((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)) 
                 & (IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready))) {
                vlSelfRef.tb_conv1d_pe__DOT__got_neuron.push_back(
                                                                  (0x000003ffU 
                                                                   & ((VL_MULS_III(32, (IData)(7U), (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)) 
                                                                       + 
                                                                       VL_EXTENDS_II(10,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                      & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                vlSelfRef.tb_conv1d_pe__DOT__got_tap.push_back(
                                                               (0x0000ffffU 
                                                                & ((VL_MULS_III(32, (IData)(3U), 
                                                                                ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q) 
                                                                                + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))) 
                                                                    + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)) 
                                                                   & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
            }
            if ((((IData)(vlSelfRef.tb_conv1d_pe__DOT__done) 
                  & (2U != (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))) 
                 & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid)))) {
                Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                                    "@(posedge tb_conv1d_pe.clk)");
                co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_conv1d_pe.clk)", 
                                                                     "tb_conv1d_pe.sv", 
                                                                     126);
                if (((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)) 
                     & (IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready))) {
                    vlSelfRef.tb_conv1d_pe__DOT__got_neuron.push_back(
                                                                      (0x000003ffU 
                                                                       & ((VL_MULS_III(32, (IData)(7U), (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)) 
                                                                           + 
                                                                           VL_EXTENDS_II(10,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                          & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                    vlSelfRef.tb_conv1d_pe__DOT__got_tap.push_back(
                                                                   (0x0000ffffU 
                                                                    & ((VL_MULS_III(32, (IData)(3U), 
                                                                                ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q) 
                                                                                + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))) 
                                                                        + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)) 
                                                                       & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                }
                goto __Vlabel8;
            }
            if (VL_UNLIKELY((VL_GTS_III(32, __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__cycles, __Vtask_tb_conv1d_pe__DOT__collect_until_done__16__timeout_cycles)))) {
                VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:134: Assertion failed in %m: Timeout waiting for Conv1dPE done\n",3, 'M',vlSymsp->name(),"tb_conv1d_pe.collect_until_done", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("tb_conv1d_pe.sv", 134, "");
                tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                             + tb_conv1d_pe__DOT__errors);
                goto __Vlabel8;
            }
        }
        __Vlabel8: ;
    }
    vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__name 
        = vlSelfRef.__Vtask_tb_conv1d_pe__DOT__run_case__9__name;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i = 0U;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j = 0U;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched.clear();
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched.atDefault() = 0;
    if (VL_UNLIKELY(((vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size() 
                      != vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:145: Assertion failed in %m: %s: charge count got=%0d expected=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__name)
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size()
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size());
        VL_STOP_MT("tb_conv1d_pe.sv", 145, "");
        tb_conv1d_pe__DOT__errors = ((IData)(1U) + tb_conv1d_pe__DOT__errors);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched.clear();
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched.push_back(0U);
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i, vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size())) {
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__unnamedblk1__DOT__found = 0U;
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__unnamedblk1__DOT__found = 0U;
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j = 0U;
        {
            while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
                if ((((~ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j)) 
                      & (vlSelfRef.tb_conv1d_pe__DOT__got_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i) 
                         == vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j))) 
                     & (vlSelfRef.tb_conv1d_pe__DOT__got_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i) 
                        == vlSelfRef.tb_conv1d_pe__DOT__exp_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j)))) {
                    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched.atWriteAppend(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j) = 1U;
                    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__unnamedblk1__DOT__found = 1U;
                    goto __Vlabel9;
                }
                __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j 
                    = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j);
            }
            __Vlabel9: ;
        }
        if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__unnamedblk1__DOT__found)))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:164: Assertion failed in %m: %s: unexpected charge neuron=%0d tap=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard.unnamedblk1", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__name)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i));
            VL_STOP_MT("tb_conv1d_pe.sv", 164, "");
            tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                         + tb_conv1d_pe__DOT__errors);
        }
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__i);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
        if (VL_UNLIKELY(((1U & (~ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__matched.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j)))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:171: Assertion failed in %m: %s: missing charge neuron=%0d tap=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__name)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j));
            VL_STOP_MT("tb_conv1d_pe.sv", 171, "");
            tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                         + tb_conv1d_pe__DOT__errors);
        }
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__j);
    }
    __Vtask_tb_conv1d_pe__DOT__run_case__18__ix = 2U;
    __Vtask_tb_conv1d_pe__DOT__run_case__18__cin_i = 0U;
    vlSelfRef.__Vtask_tb_conv1d_pe__DOT__run_case__18__name = "edge(0,2)"s;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ix 
        = __Vtask_tb_conv1d_pe__DOT__run_case__18__ix;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i 
        = __Vtask_tb_conv1d_pe__DOT__run_case__18__cin_i;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im = 0U;
    __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox = 0U;
    if (VL_UNLIKELY(((vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size() 
                      == vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())))) {
        VL_WRITEF_NX("PASS: %s (%0d charges)\n",2, 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__17__name)
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size());
    }
    vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.clear();
    vlSelfRef.tb_conv1d_pe__DOT__exp_tap.clear();
    vlSelfRef.tb_conv1d_pe__DOT__got_neuron.clear();
    vlSelfRef.tb_conv1d_pe__DOT__got_tap.clear();
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ix;
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im)) {
            goto __Vlabel10;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im, (IData)(1U)))) {
            goto __Vlabel10;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox)) {
            goto __Vlabel10;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout 
            = VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout 
            = VL_MULS_III(32, (IData)(3U), ((IData)(1U) 
                                            + __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap);
        __Vlabel10: ;
    }
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im 
            = (__Vtask_tb_conv1d_pe__DOT__expect_spike__19__ix 
               - (IData)(1U));
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im)) {
            goto __Vlabel11;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im, (IData)(1U)))) {
            goto __Vlabel11;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox)) {
            goto __Vlabel11;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout 
            = ((IData)(1U) + VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout 
            = ((IData)(1U) + VL_MULS_III(32, (IData)(3U), 
                                         ((IData)(1U) 
                                          + __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i)));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap);
        __Vlabel11: ;
    }
    {
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im 
            = (__Vtask_tb_conv1d_pe__DOT__expect_spike__19__ix 
               - (IData)(2U));
        if (VL_GTS_III(32, 0U, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im)) {
            goto __Vlabel12;
        }
        if ((0U != VL_MODDIVS_III(32, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im, (IData)(1U)))) {
            goto __Vlabel12;
        }
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__w_im;
        if (VL_LTES_III(32, 7U, __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox)) {
            goto __Vlabel12;
        }
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i;
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout 
            = ((IData)(2U) + VL_MULS_III(32, (IData)(3U), __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap);
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__ox;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout 
            = ((IData)(7U) + __Vfunc_tb_conv1d_pe__DOT__encode_out__21__ox_i);
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out 
            = __Vfunc_tb_conv1d_pe__DOT__encode_out__21__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_0__encode_out);
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i 
            = __Vtask_tb_conv1d_pe__DOT__expect_spike__19__cin_i;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout = 0U;
        __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout 
            = ((IData)(2U) + VL_MULS_III(32, (IData)(3U), 
                                         ((IData)(1U) 
                                          + __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__cin_i)));
        __Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap 
            = __Vfunc_tb_conv1d_pe__DOT__encode_tap__22__Vfuncout;
        vlSelfRef.tb_conv1d_pe__DOT__exp_tap.push_back(__Vtask_tb_conv1d_pe__DOT__expect_spike__19____VlefCall_1__encode_tap);
        __Vlabel12: ;
    }
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__x = __Vtask_tb_conv1d_pe__DOT__run_case__18__ix;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__c = __Vtask_tb_conv1d_pe__DOT__run_case__18__cin_i;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__Vfuncout = 0U;
    __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__Vfuncout 
        = (VL_MULS_III(32, (IData)(9U), __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__c) 
           + __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__x);
    __Vtask_tb_conv1d_pe__DOT__run_case__18____VlefCall_0__flatten_cl 
        = __Vfunc_tb_conv1d_pe__DOT__flatten_cl__23__Vfuncout;
    __Vtask_tb_conv1d_pe__DOT__drive_spike__24__axon_id 
        = __Vtask_tb_conv1d_pe__DOT__run_case__18____VlefCall_0__flatten_cl;
    Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                        "@(posedge tb_conv1d_pe.clk)");
    co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv1d_pe.clk)", 
                                                         "tb_conv1d_pe.sv", 
                                                         106);
    while ((1U & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_ready)))) {
        Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                            "@(posedge tb_conv1d_pe.clk)");
        co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv1d_pe.clk)", 
                                                             "tb_conv1d_pe.sv", 
                                                             107);
    }
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v4 = 1U;
    vlSelfRef.__VdlyVal__tb_conv1d_pe__DOT__spike_data__v4 
        = (0x000003ffU & __Vtask_tb_conv1d_pe__DOT__drive_spike__24__axon_id);
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v4 = 1U;
    Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                        "@(posedge tb_conv1d_pe.clk)");
    co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_conv1d_pe.clk)", 
                                                         "tb_conv1d_pe.sv", 
                                                         110);
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v5 = 1U;
    vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v5 = 1U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__timeout_cycles = 0x00002710U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__cycles = 0U;
    __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__cycles = 0U;
    {
        while (true) {
            Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                                "@(posedge tb_conv1d_pe.clk)");
            co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_conv1d_pe.clk)", 
                                                                 "tb_conv1d_pe.sv", 
                                                                 119);
            __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__cycles 
                = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__cycles);
            if (((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)) 
                 & (IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready))) {
                vlSelfRef.tb_conv1d_pe__DOT__got_neuron.push_back(
                                                                  (0x000003ffU 
                                                                   & ((VL_MULS_III(32, (IData)(7U), (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)) 
                                                                       + 
                                                                       VL_EXTENDS_II(10,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                      & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                vlSelfRef.tb_conv1d_pe__DOT__got_tap.push_back(
                                                               (0x0000ffffU 
                                                                & ((VL_MULS_III(32, (IData)(3U), 
                                                                                ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q) 
                                                                                + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))) 
                                                                    + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)) 
                                                                   & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
            }
            if ((((IData)(vlSelfRef.tb_conv1d_pe__DOT__done) 
                  & (2U != (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))) 
                 & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid)))) {
                Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                                    "@(posedge tb_conv1d_pe.clk)");
                co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_conv1d_pe.clk)", 
                                                                     "tb_conv1d_pe.sv", 
                                                                     126);
                if (((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)) 
                     & (IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready))) {
                    vlSelfRef.tb_conv1d_pe__DOT__got_neuron.push_back(
                                                                      (0x000003ffU 
                                                                       & ((VL_MULS_III(32, (IData)(7U), (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)) 
                                                                           + 
                                                                           VL_EXTENDS_II(10,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                          & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                    vlSelfRef.tb_conv1d_pe__DOT__got_tap.push_back(
                                                                   (0x0000ffffU 
                                                                    & ((VL_MULS_III(32, (IData)(3U), 
                                                                                ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q) 
                                                                                + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))) 
                                                                        + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)) 
                                                                       & (- (IData)(
                                                                                ((VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
                                                                                & (0U 
                                                                                == 
                                                                                VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))) 
                                                                                & (VL_LTES_III(32, 0U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
                                                                                & VL_GTS_III(32, 7U, 
                                                                                VL_EXTENDS_II(32,5, 
                                                                                (0x0000001fU 
                                                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))))))))));
                }
                goto __Vlabel13;
            }
            if (VL_UNLIKELY((VL_GTS_III(32, __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__cycles, __Vtask_tb_conv1d_pe__DOT__collect_until_done__25__timeout_cycles)))) {
                VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:134: Assertion failed in %m: Timeout waiting for Conv1dPE done\n",3, 'M',vlSymsp->name(),"tb_conv1d_pe.collect_until_done", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("tb_conv1d_pe.sv", 134, "");
                tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                             + tb_conv1d_pe__DOT__errors);
                goto __Vlabel13;
            }
        }
        __Vlabel13: ;
    }
    vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__name 
        = vlSelfRef.__Vtask_tb_conv1d_pe__DOT__run_case__18__name;
    if (VL_UNLIKELY(((vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size() 
                      != vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:145: Assertion failed in %m: %s: charge count got=%0d expected=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__name)
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size()
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size());
        VL_STOP_MT("tb_conv1d_pe.sv", 145, "");
        tb_conv1d_pe__DOT__errors = ((IData)(1U) + tb_conv1d_pe__DOT__errors);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i = 0U;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j = 0U;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched.clear();
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched.atDefault() = 0;
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched.clear();
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched.push_back(0U);
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i, vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size())) {
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__unnamedblk1__DOT__found = 0U;
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__unnamedblk1__DOT__found = 0U;
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j = 0U;
        {
            while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
                if ((((~ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j)) 
                      & (vlSelfRef.tb_conv1d_pe__DOT__got_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i) 
                         == vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j))) 
                     & (vlSelfRef.tb_conv1d_pe__DOT__got_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i) 
                        == vlSelfRef.tb_conv1d_pe__DOT__exp_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j)))) {
                    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched.atWriteAppend(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j) = 1U;
                    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__unnamedblk1__DOT__found = 1U;
                    goto __Vlabel14;
                }
                __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j 
                    = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j);
            }
            __Vlabel14: ;
        }
        if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__unnamedblk1__DOT__found)))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:164: Assertion failed in %m: %s: unexpected charge neuron=%0d tap=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard.unnamedblk1", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__name)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i));
            VL_STOP_MT("tb_conv1d_pe.sv", 164, "");
            tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                         + tb_conv1d_pe__DOT__errors);
        }
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__i);
    }
    __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j = 0U;
    while (VL_LTS_III(32, __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j, vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())) {
        if (VL_UNLIKELY(((1U & (~ __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__matched.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j)))))) {
            VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:171: Assertion failed in %m: %s: missing charge neuron=%0d tap=%0d\n",6, 'M',vlSymsp->name(),"tb_conv1d_pe.check_scoreboard", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__name)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j)
                         , '~',32,vlSelfRef.tb_conv1d_pe__DOT__exp_tap.at(__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j));
            VL_STOP_MT("tb_conv1d_pe.sv", 171, "");
            tb_conv1d_pe__DOT__errors = ((IData)(1U) 
                                         + tb_conv1d_pe__DOT__errors);
        }
        __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j 
            = ((IData)(1U) + __Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__j);
    }
    if (VL_UNLIKELY(((vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size() 
                      == vlSelfRef.tb_conv1d_pe__DOT__exp_neuron.size())))) {
        VL_WRITEF_NX("PASS: %s (%0d charges)\n",2, 'S',&(vlSelfRef.__Vtask_tb_conv1d_pe__DOT__check_scoreboard__26__name)
                     , '~',32,vlSelfRef.tb_conv1d_pe__DOT__got_neuron.size());
    }
    tb_conv1d_pe__DOT__unnamedblk1_3__DOT____Vrepeat2 = 5U;
    while (VL_LTS_III(32, 0U, tb_conv1d_pe__DOT__unnamedblk1_3__DOT____Vrepeat2)) {
        Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(vlSelf, 
                                                            "@(posedge tb_conv1d_pe.clk)");
        co_await vlSelfRef.__VtrigSched_h918b1c63__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_conv1d_pe.clk)", 
                                                             "tb_conv1d_pe.sv", 
                                                             210);
        tb_conv1d_pe__DOT__unnamedblk1_3__DOT____Vrepeat2 
            = (tb_conv1d_pe__DOT__unnamedblk1_3__DOT____Vrepeat2 
               - (IData)(1U));
    }
    if ((0U == tb_conv1d_pe__DOT__errors)) {
        VL_WRITEF_NX("tb_conv1d_pe: ALL TESTS PASSED\n",0);
        VL_FINISH_MT("tb_conv1d_pe.sv", 213, "");
    } else {
        VL_WRITEF_NX("tb_conv1d_pe: FAILED with %0d errors\n[%0t] %%Fatal: tb_conv1d_pe.sv:216: Assertion failed in %m\n",4, 'M',vlSymsp->name(),"tb_conv1d_pe", 'T',-9
                     , '~',32,tb_conv1d_pe__DOT__errors
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tb_conv1d_pe.sv", 216, "", false);
    }
    co_return;
}

VlCoroutine Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__1(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000003b9aca00ULL, 
                                         nullptr, "tb_conv1d_pe.sv", 
                                         221);
    VL_WRITEF_NX("[%0t] %%Error: tb_conv1d_pe.sv:222: Assertion failed in %m: Global watchdog timeout\n",3, 'M',vlSymsp->name(),"tb_conv1d_pe", 'T',-9
                 , '#',64,VL_TIME_UNITED_Q(1000));
    VL_STOP_MT("tb_conv1d_pe.sv", 222, "");
    VL_WRITEF_NX("[%0t] %%Fatal: tb_conv1d_pe.sv:223: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_conv1d_pe", 'T',-9
                 , '#',64,VL_TIME_UNITED_Q(1000));
    VL_STOP_MT("tb_conv1d_pe.sv", 223, "", false);
    co_return;
}

VlCoroutine Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__2(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tb_conv1d_pe.sv", 
                                             25);
        vlSelfRef.tb_conv1d_pe__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__clk)));
    }
    co_return;
}

bool Vtb_conv1d_pe___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___trigger_anySet__ico\n"); );
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

bool Vtb_conv1d_pe___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___trigger_anySet__act\n"); );
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

void Vtb_conv1d_pe___024root___nba_sequent__TOP__0(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___nba_sequent__TOP__0\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__tb_conv1d_pe__DOT__dut__DOT__kx_q;
    __Vdly__tb_conv1d_pe__DOT__dut__DOT__kx_q = 0;
    CData/*0:0*/ __Vdly__tb_conv1d_pe__DOT__dut__DOT__cout_q;
    __Vdly__tb_conv1d_pe__DOT__dut__DOT__cout_q = 0;
    // Body
    __Vdly__tb_conv1d_pe__DOT__dut__DOT__cout_q = vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q;
    __Vdly__tb_conv1d_pe__DOT__dut__DOT__kx_q = vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q;
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__enable__v0) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__enable__v0 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__enable = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v0) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v0 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_valid = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v1) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v1 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_valid = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v2) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v2 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_valid = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v3) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v3 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_valid = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v4) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v4 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_valid = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v5) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_valid__v5 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_valid = 0U;
    }
    vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q = 
        ((1U & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__rst))) 
         && (1U & ((0U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                    ? ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_310)
                        ? VL_DIV_III(32, (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_data), (IData)(9U))
                        : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q))
                    : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cin_q))));
    __Vdly__tb_conv1d_pe__DOT__dut__DOT__cout_q = (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__rst))) 
                                                   && ((0U 
                                                        == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                                                        ? 
                                                       ((~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_310)) 
                                                        & (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))
                                                        : 
                                                       ((1U 
                                                         == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                                                         ? 
                                                        ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__in_bounds)
                                                          ? (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)
                                                          : (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_317))
                                                         : 
                                                        ((2U 
                                                          == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready)
                                                           ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_317)
                                                           : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))
                                                          : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)))));
    if (vlSelfRef.tb_conv1d_pe__DOT__rst) {
        vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__ix_q = 0U;
        __Vdly__tb_conv1d_pe__DOT__dut__DOT__kx_q = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q = 0U;
    } else {
        if ((0U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))) {
            vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__ix_q 
                = (0x0000000fU & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_310)
                                   ? VL_MODDIV_III(32, (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_data), (IData)(9U))
                                   : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__ix_q)));
            __Vdly__tb_conv1d_pe__DOT__dut__DOT__kx_q 
                = ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q) 
                   & (- (IData)((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_310))))));
        } else {
            vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__ix_q 
                = (0x0000000fU & (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__ix_q));
            __Vdly__tb_conv1d_pe__DOT__dut__DOT__kx_q 
                = ((1U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                    ? ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__in_bounds)
                        ? (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)
                        : (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_315))
                    : ((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                        ? ((IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready)
                            ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_315)
                            : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q))
                        : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)));
        }
        vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q 
            = ((0U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                ? ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_310)
                    ? 1U : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                : ((1U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q))
                    ? ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__in_bounds)
                        ? 2U : ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)
                                 ? ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q) 
                                    & (- (IData)((2U 
                                                  != (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)))))
                                 : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)))
                    : (((IData)(vlSelfRef.tb_conv1d_pe__DOT__charge_ready)
                         ? ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)
                             ? (1U & (- (IData)((2U 
                                                 != (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)))))
                             : 1U) : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)) 
                       & (- (IData)((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)))))));
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v0) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v0 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_data = vlSelfRef.__VdlyVal__tb_conv1d_pe__DOT__spike_data__v0;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v1) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v1 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_data = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v2) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v2 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_data = vlSelfRef.__VdlyVal__tb_conv1d_pe__DOT__spike_data__v2;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v3) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v3 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_data = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v4) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v4 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_data = vlSelfRef.__VdlyVal__tb_conv1d_pe__DOT__spike_data__v4;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v5) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__spike_data__v5 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__spike_data = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__rst__v0) {
        vlSelfRef.__VdlySet__tb_conv1d_pe__DOT__rst__v0 = 0U;
        vlSelfRef.tb_conv1d_pe__DOT__rst = 0U;
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_310 = ((IData)(vlSelfRef.tb_conv1d_pe__DOT__enable) 
                                                  & (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid));
    vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q = __Vdly__tb_conv1d_pe__DOT__dut__DOT__cout_q;
    vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q = __Vdly__tb_conv1d_pe__DOT__dut__DOT__kx_q;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_317 = (1U 
                                                  & ((~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)) 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))));
    vlSelfRef.tb_conv1d_pe__DOT__spike_ready = ((IData)(vlSelfRef.tb_conv1d_pe__DOT__enable) 
                                                & (0U 
                                                   == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)));
    vlSelfRef.tb_conv1d_pe__DOT__done = ((~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid)) 
                                         & (0U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_315 = (3U 
                                                  & ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)
                                                      ? 
                                                     ((2U 
                                                       == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q))
                                                       ? (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)
                                                       : 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)))
                                                      : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311 = VL_EXTENDS_II(32,7, 
                                                               (0x0000007fU 
                                                                & (VL_EXTENDS_II(7,5, (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__ix_q)) 
                                                                   - 
                                                                   VL_EXTENDS_II(7,3, (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)))));
    vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__in_bounds 
        = ((VL_LTES_III(32, 0U, VL_EXTENDS_II(32,5, 
                                              (0x0000001fU 
                                               & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311))) 
            & VL_GTS_III(32, 7U, VL_EXTENDS_II(32,5, 
                                               (0x0000001fU 
                                                & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311)))) 
           & (VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311) 
              & (0U == VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311, (IData)(1U)))));
}

void Vtb_conv1d_pe___024root___timing_ready(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___timing_ready\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h918b1c63__0.ready("@(posedge tb_conv1d_pe.clk)");
    }
}

void Vtb_conv1d_pe___024root___timing_resume(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___timing_resume\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h918b1c63__0.moveToResumeQueue(
                                                          "@(posedge tb_conv1d_pe.clk)");
    vlSelfRef.__VtrigSched_h918b1c63__0.resume("@(posedge tb_conv1d_pe.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_conv1d_pe___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vtb_conv1d_pe___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0(Vtb_conv1d_pe___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root____VbeforeTrig_h918b1c63__0\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.tb_conv1d_pe__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_conv1d_pe__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_conv1d_pe__DOT__clk__0 
        = vlSelfRef.tb_conv1d_pe__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h918b1c63__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_conv1d_pe___024root___eval_debug_assertions(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_debug_assertions\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
