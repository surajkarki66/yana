// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_conv1d_pe.h for the primary calling header

#include "Vtb_conv1d_pe__pch.h"

void Vtb_conv1d_pe___024root___timing_ready(Vtb_conv1d_pe___024root* vlSelf);

VL_ATTR_COLD void Vtb_conv1d_pe___024root___eval_static(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_static\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.tb_conv1d_pe__DOT__clk = 0U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__tb_conv1d_pe__DOT__clk__0 = 0U;
    Vtb_conv1d_pe___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_pe___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_conv1d_pe___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vtb_conv1d_pe___024root___eval_stl(Vtb_conv1d_pe___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_stl\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_conv1d_pe___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_conv1d_pe___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
                    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_317 
                        = (1U & ((~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)) 
                                 & ((IData)(1U) + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q))));
                    vlSelfRef.tb_conv1d_pe__DOT__spike_ready 
                        = ((IData)(vlSelfRef.tb_conv1d_pe__DOT__enable) 
                           & (0U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)));
                    vlSelfRef.tb_conv1d_pe__DOT__done 
                        = ((~ (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid)) 
                           & (0U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__state_q)));
                    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_310 
                        = ((IData)(vlSelfRef.tb_conv1d_pe__DOT__enable) 
                           & (IData)(vlSelfRef.tb_conv1d_pe__DOT__spike_valid));
                    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_315 
                        = (3U & ((IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__cout_q)
                                  ? ((2U == (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q))
                                      ? (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)
                                      : ((IData)(1U) 
                                         + (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)))
                                  : (IData)(vlSelfRef.tb_conv1d_pe__DOT__dut__DOT__kx_q)));
                    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_311 
                        = VL_EXTENDS_II(32,7, (0x0000007fU 
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
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtb_conv1d_pe___024root___eval_dump_triggers__stl(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_dump_triggers__stl\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv1d_pe___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_pe___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv1d_pe___024root___eval_dump_triggers__ico(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_dump_triggers__ico\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv1d_pe___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_pe___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv1d_pe___024root___eval_dump_triggers__act(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_dump_triggers__act\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv1d_pe___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtb_conv1d_pe___024root___eval_dump_triggers__nba(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_dump_triggers__nba\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv1d_pe___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtb_conv1d_pe___024root___eval_dump_triggers__obs(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_dump_triggers__obs\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_conv1d_pe___024root___eval_dump_triggers__react(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_dump_triggers__react\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_conv1d_pe___024root___eval_final(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___eval_final\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_pe___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv1d_pe___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_conv1d_pe___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___trigger_anySet__stl\n"); );
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

bool Vtb_conv1d_pe___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_pe___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv1d_pe___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtb_conv1d_pe___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_pe___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv1d_pe___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_conv1d_pe.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv1d_pe___024root___ctor_var_reset(Vtb_conv1d_pe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_pe___024root___ctor_var_reset\n"); );
    Vtb_conv1d_pe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_conv1d_pe__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 156259839142874446ull);
    vlSelf->tb_conv1d_pe__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11619641613152835984ull);
    vlSelf->tb_conv1d_pe__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8430229535471465695ull);
    vlSelf->tb_conv1d_pe__DOT__spike_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17152508307373243300ull);
    vlSelf->tb_conv1d_pe__DOT__spike_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8257111371409115009ull);
    vlSelf->tb_conv1d_pe__DOT__spike_data = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 17485258202506513471ull);
    vlSelf->tb_conv1d_pe__DOT__charge_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10068230807929985137ull);
    vlSelf->tb_conv1d_pe__DOT__exp_neuron.atDefault() = 0;
    vlSelf->tb_conv1d_pe__DOT__exp_tap.atDefault() = 0;
    vlSelf->tb_conv1d_pe__DOT__got_neuron.atDefault() = 0;
    vlSelf->tb_conv1d_pe__DOT__got_tap.atDefault() = 0;
    vlSelf->tb_conv1d_pe__DOT__dut__DOT__state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8151800140497694718ull);
    vlSelf->tb_conv1d_pe__DOT__dut__DOT__cin_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2327240858693620460ull);
    vlSelf->tb_conv1d_pe__DOT__dut__DOT__ix_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10426377260923344864ull);
    vlSelf->tb_conv1d_pe__DOT__dut__DOT__kx_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2172877552685310582ull);
    vlSelf->tb_conv1d_pe__DOT__dut__DOT__cout_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2147669510058717481ull);
    vlSelf->tb_conv1d_pe__DOT__dut__DOT__in_bounds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5935689928536127162ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_310 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_311 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_315 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_317 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__rst__v0 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__enable__v0 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_valid__v0 = 0;
    vlSelf->__VdlyVal__tb_conv1d_pe__DOT__spike_data__v0 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_data__v0 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_valid__v1 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_data__v1 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_valid__v2 = 0;
    vlSelf->__VdlyVal__tb_conv1d_pe__DOT__spike_data__v2 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_data__v2 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_valid__v3 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_data__v3 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_valid__v4 = 0;
    vlSelf->__VdlyVal__tb_conv1d_pe__DOT__spike_data__v4 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_data__v4 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_valid__v5 = 0;
    vlSelf->__VdlySet__tb_conv1d_pe__DOT__spike_data__v5 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_conv1d_pe__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
