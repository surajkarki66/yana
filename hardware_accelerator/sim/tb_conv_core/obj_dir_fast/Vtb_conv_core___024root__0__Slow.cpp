// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_conv_core.h for the primary calling header

#include "Vtb_conv_core__pch.h"

VL_ATTR_COLD void Vtb_conv_core___024root___eval_static__TOP(Vtb_conv_core___024root* vlSelf);
void Vtb_conv_core___024root___timing_ready(Vtb_conv_core___024root* vlSelf);

VL_ATTR_COLD void Vtb_conv_core___024root___eval_static(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_static\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_conv_core___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_conv_core__DOT__clk__0 = 0U;
    Vtb_conv_core___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv_core___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_conv_core___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vtb_conv_core___024root___stl_sequent__TOP__0(Vtb_conv_core___024root* vlSelf);

VL_ATTR_COLD bool Vtb_conv_core___024root___eval_stl(Vtb_conv_core___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_stl\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_conv_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_conv_core___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtb_conv_core___024root___stl_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtb_conv_core___024root___eval_dump_triggers__stl(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_dump_triggers__stl\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv_core___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv_core___024root___eval_dump_triggers__ico(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_dump_triggers__ico\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv_core___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv_core___024root___eval_dump_triggers__act(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_dump_triggers__act\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtb_conv_core___024root___eval_dump_triggers__nba(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_dump_triggers__nba\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_conv_core___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtb_conv_core___024root___eval_dump_triggers__obs(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_dump_triggers__obs\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_conv_core___024root___eval_dump_triggers__react(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_dump_triggers__react\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_conv_core___024root___eval_final(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_final\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_conv_core___024root___eval_static__TOP(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_static__TOP\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
    // Body
    vlSelfRef.tb_conv_core__DOT__clk = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_wren = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_rden = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_write_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_write_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__increment_buffer_read_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_buffer_read_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__insert = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove_normal = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__remove = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__output_leaving_idle = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__load_output_register = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__next_count = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__load_counter = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__clear_counter = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__next_count = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__load_counter = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__clear_counter = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_wrap_around_bit__DOT__new_value = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_wrap_around_bit__DOT__new_value = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_wren = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_rden = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_write_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_write_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__increment_buffer_read_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_buffer_read_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_write_addr_wrap_around = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__toggle_buffer_read_addr_wrap_around = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__insert = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove_normal = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__remove = 0U;
    tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__output_leaving_idle = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__load_output_register = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__next_count = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__load_counter = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__clear_counter = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__next_count = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__load_counter = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__clear_counter = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_wrap_around_bit__DOT__new_value = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_wrap_around_bit__DOT__new_value = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT__combine_words__DOT__per_bit__BRA__0__KET____DOT__bit_word = 0U;
}

VL_ATTR_COLD void Vtb_conv_core___024root___eval_initial__TOP(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___eval_initial__TOP\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ tb_conv_core__DOT__dut__DOT__rx_branch_out_valid;
    tb_conv_core__DOT__dut__DOT__rx_branch_out_valid = 0;
    CData/*0:0*/ tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready;
    tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready = 0;
    CData/*2:0*/ tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count = 0;
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
    // Body
    vlSelfRef.tb_conv_core__DOT__dut__DOT__charge_ready = 1U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr = 0U;
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around = 0U;
    vlSelfRef.tb_conv_core__DOT__packet_out_valid = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[0U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[1U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[2U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[3U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[4U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[5U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[6U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[7U] = 0U;
    tb_conv_core__DOT__dut__DOT__spike_fifo_in_ready = 1U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_data = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[0U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[1U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[2U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[3U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[4U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[5U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[6U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[7U] = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__2__KET____DOT__select_input__data_out = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__1__KET____DOT__select_input__data_out = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__ready_mux__DOT____Vcellout__per_word__BRA__0__KET____DOT__select_input__data_out = 0U;
    tb_conv_core__DOT__dut__DOT__rx_branch_out_valid = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__valid_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[0U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[1U] = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data[2U] = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__2__KET____DOT__output_gate__data_out = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__1__KET____DOT__output_gate__data_out = 0U;
    tb_conv_core__DOT__dut__DOT__u_rx_branch__DOT__data_demux__DOT____Vcellout__gen_no_broadcast__DOT__per_output__BRA__0__KET____DOT__output_gate__data_out = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected = 1U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected = 1U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected = 1U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected = 1U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset = 0U;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv_core___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv_core___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_conv_core___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtb_conv_core___024root___stl_sequent__TOP__0(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___stl_sequent__TOP__0\n"); );
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
    // Body
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__clear_counter 
        = vlSelfRef.tb_conv_core__DOT__rst;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_630 = (1U 
                                                  & ((~ (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q)) 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_618 = ((IData)(vlSelfRef.tb_conv_core__DOT__enable) 
                                                  & (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid));
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
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr) 
                 + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr) 
                 + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr) 
                 + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__calc_next_count__DOT__carry_in_selected)))));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count 
        = (7U & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr) 
                 + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__B_selected) 
                    + ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__negation_offset) 
                       + (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__calc_next_count__DOT__carry_in_selected)))));
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
    __VdfgRegularize_h6e95ff9d_0_624 = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr) 
                                        == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr));
    __VdfgRegularize_h6e95ff9d_0_625 = ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr) 
                                        == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr));
    tb_conv_core__DOT__dut__DOT__init_d = ((~ (IData)(vlSelfRef.tb_conv_core__DOT__enable)) 
                                           & (IData)(vlSelfRef.tb_conv_core__DOT__init));
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
    tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_max 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_624) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around) 
              != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__stored_items_zero 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_624) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around) 
              == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_zero 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_625) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around) 
              == (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__stored_items_max 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_625) 
           & ((IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around) 
              != (IData)(vlSelfRef.tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around)));
    tb_conv_core__DOT__dut__DOT____Vcellinp__u_rx_branch__selector 
        = ((IData)(tb_conv_core__DOT__dut__DOT__init_d)
            ? 4U : ((1U & vlSelfRef.tb_conv_core__DOT__packet_in_data)
                     ? 2U : 1U));
    vlSelfRef.tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__in_bounds 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_633) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_634));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_632 = ((IData)(__VdfgRegularize_h6e95ff9d_0_634) 
                                                  & (IData)(__VdfgRegularize_h6e95ff9d_0_633));
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

bool Vtb_conv_core___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv_core___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv_core___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtb_conv_core___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_conv_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_conv_core___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_conv_core.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_conv_core___024root___ctor_var_reset(Vtb_conv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_conv_core___024root___ctor_var_reset\n"); );
    Vtb_conv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_conv_core__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15262756709025649773ull);
    vlSelf->tb_conv_core__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12676876047137568680ull);
    vlSelf->tb_conv_core__DOT__init = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15369539674181621037ull);
    vlSelf->tb_conv_core__DOT__core_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5835416856245947010ull);
    vlSelf->tb_conv_core__DOT__packet_in_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11258582529688378602ull);
    vlSelf->tb_conv_core__DOT__packet_in_data = VL_SCOPED_RAND_RESET_I(27, __VscopeHash, 5099963953069064641ull);
    vlSelf->tb_conv_core__DOT__packet_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17929818963136782851ull);
    vlSelf->tb_conv_core__DOT__packet_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15065034037946084446ull);
    VL_ZERO_RESET_W(81, vlSelf->tb_conv_core__DOT__dut__DOT____Vcellout__u_rx_branch__output_data);
    vlSelf->tb_conv_core__DOT__dut__DOT__spike_fifo_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7602454288762479583ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__spike_fifo_out_data = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9025819342581031549ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__charge_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15722608582471620368ull);
    vlSelf->tb_conv_core__DOT__dut__DOT____Vcellout__u_tx_fifo__output_data = 0;
    vlSelf->tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5523272286440128953ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12363128162183393922ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_write_addr_wrap_around = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9915428215040200600ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer_read_addr_wrap_around = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12002106486588823612ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__read_address__DOT__incremented_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4636121741100783117ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_conv_core__DOT__dut__DOT__u_tx_fifo__DOT__buffer__DOT__ram[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7250966793756486438ull);
    }
    vlSelf->tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15075404534794989187ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11611142508552497077ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_write_addr_wrap_around = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2819076079863003079ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer_read_addr_wrap_around = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 710785516059617638ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__read_address__DOT__incremented_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17309595179985310410ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__write_address__DOT__incremented_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10423538737814999645ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_conv_core__DOT__dut__DOT__u_spike_fifo__DOT__buffer__DOT__ram[__Vi0] = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 15734774645933458149ull);
    }
    vlSelf->tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13462947523918853888ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cin_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1609106077240138250ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__iy_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14343359086758199058ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ix_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15372131533131586388ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__ky_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5808119401217623276ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__kx_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10969886154267807041ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__cout_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 716781940840150844ull);
    vlSelf->tb_conv_core__DOT__dut__DOT__u_conv_pe__DOT__in_bounds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4234023016545371122ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_618 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_619 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_620 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_627 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_628 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_630 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_632 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__rst__v0 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__enable__v0 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__packet_in_valid__v0 = 0;
    vlSelf->__VdlyVal__tb_conv_core__DOT__packet_in_data__v0 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__packet_in_data__v0 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__packet_in_valid__v1 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__packet_in_data__v1 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__packet_in_valid__v2 = 0;
    vlSelf->__VdlyVal__tb_conv_core__DOT__packet_in_data__v2 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__packet_in_data__v2 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__packet_in_valid__v3 = 0;
    vlSelf->__VdlySet__tb_conv_core__DOT__packet_in_data__v3 = 0;
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
    vlSelf->__Vtrigprevexpr___TOP__tb_conv_core__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
