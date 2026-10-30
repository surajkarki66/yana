// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_CONV1D_PE__SYMS_H_
#define VERILATED_VTB_CONV1D_PE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_conv1d_pe.h"

// INCLUDE MODULE CLASSES
#include "Vtb_conv1d_pe___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_conv1d_pe__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_conv1d_pe* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    Vtb_conv1d_pe___024root        TOP;

    // CONSTRUCTORS
    Vtb_conv1d_pe__Syms(VerilatedContext* contextp, const char* namep, Vtb_conv1d_pe* modelp);
    ~Vtb_conv1d_pe__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
