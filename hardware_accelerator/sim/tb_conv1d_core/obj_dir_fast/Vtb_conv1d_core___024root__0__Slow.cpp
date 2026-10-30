// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_conv1d_core.h for the primary calling header

#include "Vtb_conv1d_core__pch.h"

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_static__TOP(Vtb_conv1d_core___024root* vlSelf);
void Vtb_conv1d_core___024root___timing_ready(Vtb_conv1d_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_static(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_static\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_conv1d_core___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_conv1d_core__DOT__clk__0 = 0U;
    Vtb_conv1d_core___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_core___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_conv1d_core___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vtb_conv1d_core___024root___stl_sequent__TOP__0(Vtb_conv1d_core___024root* vlSelf);

VL_ATTR_COLD bool Vtb_conv1d_core___024root___eval_stl(Vtb_conv1d_core___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_stl\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_conv1d_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_conv1d_core___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtb_conv1d_core___024root___stl_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_dump_triggers__stl(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_dump_triggers__stl\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv1d_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_core___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_dump_triggers__ico(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_dump_triggers__ico\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv1d_core___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_dump_triggers__act(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_dump_triggers__act\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv1d_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_dump_triggers__nba(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_dump_triggers__nba\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv1d_core___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_dump_triggers__obs(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_dump_triggers__obs\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_dump_triggers__react(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_dump_triggers__react\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_final(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_final\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_static__TOP(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_static__TOP\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__insert;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__insert = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__insert = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle = 0;
    // Body
    vlSelfRef.tb_conv1d_core__DOT__clk = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_wren = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_rden = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__insert = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__next_count = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__load_counter = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__clear_counter = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__next_count = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__load_counter = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__clear_counter = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_wrap_around_bit__DOT__new_value = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_wrap_around_bit__DOT__new_value = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_wren = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_rden = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__insert = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__next_count = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__load_counter = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__clear_counter = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__next_count = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__load_counter = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__clear_counter = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_wrap_around_bit__DOT__new_value = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_wrap_around_bit__DOT__new_value = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT__combine_words__DOT__per_bit__BRA__0__KET____DOT__bit_word = 0U;
}

VL_ATTR_COLD void Vtb_conv1d_core___024root___eval_initial__TOP(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___eval_initial__TOP\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ tb_conv1d_core__DOT__dut__DOT__rx_branch_out_valid;
    tb_conv1d_core__DOT__dut__DOT__rx_branch_out_valid = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__spike_fifo_in_ready;
    tb_conv1d_core__DOT__dut__DOT__spike_fifo_in_ready = 0;
    CData/*2:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0;
    // Body
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__charge_ready = 1U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around = 0U;
    vlSelfRef.tb_conv1d_core__DOT__packet_out_valid = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[0U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[1U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[2U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[3U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[4U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[5U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[6U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[7U] = 0U;
    tb_conv1d_core__DOT__dut__DOT__spike_fifo_in_ready = 1U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__spike_fifo_out_valid = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__spike_fifo_out_data = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[0U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[1U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[2U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[3U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[4U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[5U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[6U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[7U] = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out = 0U;
    tb_conv1d_core__DOT__dut__DOT__rx_branch_out_valid = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[0U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[1U] = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[2U] = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0U;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected = 1U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected = 1U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected = 1U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected = 1U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_core___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv1d_core___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_conv1d_core___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtb_conv1d_core___024root___stl_sequent__TOP__0(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___stl_sequent__TOP__0\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__init_d;
    tb_conv1d_core__DOT__dut__DOT__init_d = 0;
    CData/*2:0*/ tb_conv1d_core__DOT__dut__DOT__rx_branch_out_valid;
    tb_conv1d_core__DOT__dut__DOT__rx_branch_out_valid = 0;
    CData/*2:0*/ tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector;
    tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__spike_fifo_in_ready;
    tb_conv1d_core__DOT__dut__DOT__spike_fifo_in_ready = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__insert;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__insert = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle = 0;
    CData/*2:0*/ tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__insert = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0;
    CData/*0:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0;
    IData/*26:0*/ tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0;
    CData/*2:0*/ __VdfgRegularize_h6e95ff9d_0_484;
    __VdfgRegularize_h6e95ff9d_0_484 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_485;
    __VdfgRegularize_h6e95ff9d_0_485 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_486;
    __VdfgRegularize_h6e95ff9d_0_486 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_488;
    __VdfgRegularize_h6e95ff9d_0_488 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_489;
    __VdfgRegularize_h6e95ff9d_0_489 = 0;
    // Body
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__clear_counter 
        = vlSelfRef.tb_conv1d_core__DOT__rst;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__clear_counter 
        = vlSelfRef.tb_conv1d_core__DOT__rst;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__clear_counter 
        = vlSelfRef.tb_conv1d_core__DOT__rst;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__clear_counter 
        = vlSelfRef.tb_conv1d_core__DOT__rst;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_492 = (1U 
                                                  & ((~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__cout_q)) 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__cout_q))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_481 = ((IData)(vlSelfRef.tb_conv1d_core__DOT__enable) 
                                                  & (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__spike_fifo_out_valid));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_490 = (3U 
                                                  & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__cout_q)
                                                      ? 
                                                     ((2U 
                                                       == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__kx_q))
                                                       ? (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__kx_q)
                                                       : 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__kx_q)))
                                                      : (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__kx_q)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr) 
                 + ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr) 
                 + ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr) 
                 + ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr) 
                 + ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_482 = VL_EXTENDS_II(32,7, 
                                                               (0x0000007fU 
                                                                & (VL_EXTENDS_II(7,5, (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__ix_q)) 
                                                                   - 
                                                                   VL_EXTENDS_II(7,3, (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__kx_q)))));
    __VdfgRegularize_h6e95ff9d_0_485 = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr) 
                                        == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr));
    __VdfgRegularize_h6e95ff9d_0_486 = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr) 
                                        == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr));
    tb_conv1d_core__DOT__dut__DOT__init_d = ((~ (IData)(vlSelfRef.tb_conv1d_core__DOT__enable)) 
                                             & (IData)(vlSelfRef.tb_conv1d_core__DOT__init));
    __VdfgRegularize_h6e95ff9d_0_488 = (VL_LTES_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_482) 
                                        & (0U == VL_MODDIVS_III(32, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_482, (IData)(1U))));
    __VdfgRegularize_h6e95ff9d_0_489 = (VL_LTES_III(32, 0U, 
                                                    VL_EXTENDS_II(32,5, 
                                                                  (0x0000001fU 
                                                                   & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_482))) 
                                        & VL_GTS_III(32, 7U, 
                                                     VL_EXTENDS_II(32,5, 
                                                                   (0x0000001fU 
                                                                    & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_482))));
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_485) 
           & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around) 
              != (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_485) 
           & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around) 
              == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_486) 
           & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around) 
              == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_486) 
           & ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around) 
              != (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__init_d)
            ? 4U : ((1U & vlSelfRef.tb_conv1d_core__DOT__packet_in_data)
                     ? 2U : 1U));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__in_bounds 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_489) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_488));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_494 = ((IData)(__VdfgRegularize_h6e95ff9d_0_488) 
                                                  & (IData)(__VdfgRegularize_h6e95ff9d_0_489));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__charge_ready 
        = (1U & (~ (IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max)));
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__insert 
        = ((2U == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__state_q)) 
           & (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__charge_ready));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_wren 
        = tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__insert;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr 
        = tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__insert;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr)));
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around 
        = tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__packet_out_valid) 
           & (IData)(vlSelfRef.tb_conv1d_core__DOT__packet_out_ready));
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove 
        = tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal;
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle 
        = (1U & ((~ (IData)(vlSelfRef.tb_conv1d_core__DOT__packet_out_valid)) 
                 & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__remove) 
           | (IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_rden 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr)));
    tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around 
        = tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr;
    vlSelfRef.tb_conv1d_core__DOT__core_done = ((IData)(tb_conv1d_core__DOT__dut__DOT__init_d) 
                                                | ((((((~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__spike_fifo_out_valid)) 
                                                       & (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)) 
                                                      & (0U 
                                                         == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__state_q))) 
                                                     & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__packet_in_valid))) 
                                                    & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__packet_out_valid))) 
                                                   & (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero)));
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__spike_fifo_out_valid) 
           & ((IData)(vlSelfRef.tb_conv1d_core__DOT__enable) 
              & (0U == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__state_q))));
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove 
        = tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle 
        = (1U & ((~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__spike_fifo_out_valid)) 
                 & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__remove) 
           | (IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_rden 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)));
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register) 
           & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero)));
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr)));
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around 
        = tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr;
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv1d_core__DOT__packet_in_data 
           & (- (IData)((1U & ((IData)(tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                               >> 2U)))));
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv1d_core__DOT__packet_in_data 
           & (- (IData)((1U & ((IData)(tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                               >> 1U)))));
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out 
        = (vlSelfRef.tb_conv1d_core__DOT__packet_in_data 
           & (- (IData)((1U & (IData)(tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector)))));
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__packet_in_valid) 
           & ((IData)(tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
              >> 2U));
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__packet_in_valid) 
           & ((IData)(tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
              >> 1U));
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__packet_in_valid) 
           & (IData)(tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__next_count 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr))))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__load_counter 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr) 
           | (IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr))))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__load_counter 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr) 
           | (IData)(tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr))))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__load_counter 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr) 
           | (IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[0U] 
        = (IData)((((QData)((IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out)) 
                    << 0x0000001bU) | (QData)((IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[1U] 
        = ((tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
            << 0x00000016U) | (IData)(((((QData)((IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out)) 
                                         << 0x0000001bU) 
                                        | (QData)((IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out))) 
                                       >> 0x00000020U)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[2U] 
        = (tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out 
           >> 0x0000000aU);
    tb_conv1d_core__DOT__dut__DOT__rx_branch_out_valid 
        = (((IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out) 
            << 2U) | (((IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out) 
                       << 1U) | (IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out)));
    tb_conv1d_core__DOT__dut__DOT__spike_fifo_in_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max)));
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__insert 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__rx_branch_out_valid) 
           & (IData)(tb_conv1d_core__DOT__dut__DOT__spike_fifo_in_ready));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_wren 
        = tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr 
        = tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__insert;
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr) 
           & (7U == (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr)));
    tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around 
        = tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr;
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_wrap_around_bit__DOT__new_value 
        = (1U & ((IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around)
                  ? (~ (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around))
                  : (IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__next_count 
        = ((IData)(vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count) 
           & (- (IData)((1U & (~ (IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr))))));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__load_counter 
        = ((IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr) 
           | (IData)(tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr));
    __VdfgRegularize_h6e95ff9d_0_484 = ((IData)(tb_conv1d_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector) 
                                        & (6U | (IData)(tb_conv1d_core__DOT__dut__DOT__spike_fifo_in_ready)));
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out 
        = (1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_484) 
                 >> 2U));
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out 
        = (1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_484) 
                 >> 1U));
    tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out 
        = (1U & (IData)(__VdfgRegularize_h6e95ff9d_0_484));
    vlSelfRef.tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT__combine_words__DOT__per_bit__BRA__0__KET____DOT__bit_word 
        = (((IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out) 
            << 2U) | (((IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out) 
                       << 1U) | (IData)(tb_conv1d_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out)));
}

bool Vtb_conv1d_core___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_core___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv1d_core___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtb_conv1d_core___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv1d_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv1d_core___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_conv1d_core.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv1d_core___024root___ctor_var_reset(Vtb_conv1d_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv1d_core___024root___ctor_var_reset\n"); );
    Vtb_conv1d_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_conv1d_core__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2830714052334958249ull);
    vlSelf->tb_conv1d_core__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3528196714899676058ull);
    vlSelf->tb_conv1d_core__DOT__init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15759768531421425539ull);
    vlSelf->tb_conv1d_core__DOT__core_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17546702802351641006ull);
    vlSelf->tb_conv1d_core__DOT__packet_in_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14071500289585146856ull);
    vlSelf->tb_conv1d_core__DOT__packet_in_data = VL_SCOPED_RAND_RESET_I(27, __VscopeHash, 5601593918912928319ull);
    vlSelf->tb_conv1d_core__DOT__packet_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7104373869805673521ull);
    vlSelf->tb_conv1d_core__DOT__packet_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2427662229540338146ull);
    VL_ZERO_RESET_W(81, vlSelf->tb_conv1d_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__spike_fifo_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1620554147909941509ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__spike_fifo_out_data = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 13134604412484139536ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__charge_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1852856384230560590ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data = 0;
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5030750842961867954ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6373158604176242870ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18365286726048256761ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12800740219768681787ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18093986521617158207ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_conv1d_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5605152354158564857ull);
    }
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12749344895061858733ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12426919712857621833ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18371759342806028457ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12943631557546428383ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11827333975280149018ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17126735765742911239ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_conv1d_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[__Vi0] = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9167606449560285292ull);
    }
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17157440488791035730ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__cin_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3941778653558267611ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__ix_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16968107827879748126ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__kx_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11521137715344174079ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__cout_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13054088550140740580ull);
    vlSelf->tb_conv1d_core__DOT__dut__DOT__u_conv1d_pe__DOT__in_bounds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16807245073289669970ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_481 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_482 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_490 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_492 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_494 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__rst__v0 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__enable__v0 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__packet_in_valid__v0 = 0;
    vlSelf->__VdlyVal__tb_conv1d_core__DOT__packet_in_data__v0 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__packet_in_data__v0 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__packet_in_valid__v1 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__packet_in_data__v1 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__packet_in_valid__v2 = 0;
    vlSelf->__VdlyVal__tb_conv1d_core__DOT__packet_in_data__v2 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__packet_in_data__v2 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__packet_in_valid__v3 = 0;
    vlSelf->__VdlySet__tb_conv1d_core__DOT__packet_in_data__v3 = 0;
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
    vlSelf->__Vtrigprevexpr___TOP__tb_conv1d_core__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
