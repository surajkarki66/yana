// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_conv_pe__pch.h"

//============================================================
// Constructors

Vtb_conv_pe::Vtb_conv_pe(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_conv_pe__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_conv_pe::Vtb_conv_pe(const char* _vcname__)
    : Vtb_conv_pe(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_conv_pe::~Vtb_conv_pe() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_conv_pe___024root___eval_debug_assertions(Vtb_conv_pe___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtb_conv_pe___024root___eval_static(Vtb_conv_pe___024root* vlSelf);
void Vtb_conv_pe___024root___eval_initial(Vtb_conv_pe___024root* vlSelf);
VL_ATTR_COLD bool Vtb_conv_pe___024root___eval_stl(Vtb_conv_pe___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vtb_conv_pe___024root___eval_sample(Vtb_conv_pe___024root* vlSelf);
bool Vtb_conv_pe___024root___eval_ico(Vtb_conv_pe___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vtb_conv_pe___024root___eval_act(Vtb_conv_pe___024root* vlSelf);
bool Vtb_conv_pe___024root___eval_inact(Vtb_conv_pe___024root* vlSelf);
bool Vtb_conv_pe___024root___eval_nba(Vtb_conv_pe___024root* vlSelf);
bool Vtb_conv_pe___024root___eval_obs(Vtb_conv_pe___024root* vlSelf);
bool Vtb_conv_pe___024root___eval_react(Vtb_conv_pe___024root* vlSelf);
void Vtb_conv_pe___024root___eval_postponed(Vtb_conv_pe___024root* vlSelf);
VL_ATTR_COLD void Vtb_conv_pe___024root___eval_final(Vtb_conv_pe___024root* vlSelf);
VL_ATTR_COLD void Vtb_conv_pe___024root___eval_dump_triggers__stl(Vtb_conv_pe___024root* vlSelf);
VL_ATTR_COLD void Vtb_conv_pe___024root___eval_dump_triggers__ico(Vtb_conv_pe___024root* vlSelf);
VL_ATTR_COLD void Vtb_conv_pe___024root___eval_dump_triggers__act(Vtb_conv_pe___024root* vlSelf);
VL_ATTR_COLD void Vtb_conv_pe___024root___eval_dump_triggers__nba(Vtb_conv_pe___024root* vlSelf);
VL_ATTR_COLD void Vtb_conv_pe___024root___eval_dump_triggers__obs(Vtb_conv_pe___024root* vlSelf);
VL_ATTR_COLD void Vtb_conv_pe___024root___eval_dump_triggers__react(Vtb_conv_pe___024root* vlSelf);

void Vtb_conv_pe::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_conv_pe::eval_step\n"); );
    m_evalLoop.eval();
}

void Vtb_conv_pe::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_conv_pe___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vtb_conv_pe::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vtb_conv_pe::evalStatic() {
    Vtb_conv_pe___024root___eval_static(&(vlSymsp->TOP));
}

void Vtb_conv_pe::evalInitial() {
    Vtb_conv_pe___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vtb_conv_pe::evalStl(bool firstIteration) {
    return Vtb_conv_pe___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vtb_conv_pe::evalSample() {
    Vtb_conv_pe___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vtb_conv_pe::evalIco(bool firstIteration) {
    return Vtb_conv_pe___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vtb_conv_pe::evalAct() {
    return Vtb_conv_pe___024root___eval_act(&(vlSymsp->TOP));
}

bool Vtb_conv_pe::evalInact() {
    return Vtb_conv_pe___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vtb_conv_pe::evalNba() {
    return Vtb_conv_pe___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vtb_conv_pe::evalObs() {
    return Vtb_conv_pe___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vtb_conv_pe::evalReact() {
    return Vtb_conv_pe___024root___eval_react(&(vlSymsp->TOP));
}

void Vtb_conv_pe::evalPostponed() {
    Vtb_conv_pe___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vtb_conv_pe::evalFinal() {
    Vtb_conv_pe___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_conv_pe::dumpTriggersStl() {
    Vtb_conv_pe___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_conv_pe::dumpTriggersIco() {
    Vtb_conv_pe___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_conv_pe::dumpTriggersAct() {
    Vtb_conv_pe___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_conv_pe::dumpTriggersNba() {
    Vtb_conv_pe___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_conv_pe::dumpTriggersObs() {
    Vtb_conv_pe___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_conv_pe::dumpTriggersReact() {
    Vtb_conv_pe___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vtb_conv_pe::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_conv_pe::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_conv_pe::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vtb_conv_pe::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_conv_pe::hierName() const { return vlSymsp->name(); }
const char* Vtb_conv_pe::modelName() const { return "Vtb_conv_pe"; }
unsigned Vtb_conv_pe::threads() const { return 1; }
void Vtb_conv_pe::prepareClone() const { contextp()->prepareClone(); }
void Vtb_conv_pe::atClone() const {
    contextp()->threadPoolpOnClone();
}
