// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_conv_pe.h for the primary calling header

#include "Vtb_conv_pe__pch.h"

void Vtb_conv_pe___024root___ctor_var_reset(Vtb_conv_pe___024root* vlSelf);

Vtb_conv_pe___024root::Vtb_conv_pe___024root(Vtb_conv_pe__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_conv_pe___024root___ctor_var_reset(this);
}

Vtb_conv_pe___024root::~Vtb_conv_pe___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
