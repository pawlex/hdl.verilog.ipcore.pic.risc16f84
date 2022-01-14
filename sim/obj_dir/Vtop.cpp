// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    _configure_coverage(vlSymsp, first);
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

// Coverage
void Vtop::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp);
}

void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 7, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 7, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_settle__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (~ vlTOPp->top__DOT____Vtogcov__clken))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->top__DOT____Vtogcov__clken = 1U;
    }
    if (vlTOPp->top__DOT____Vtogcov__int0) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->top__DOT____Vtogcov__int0 = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__reset) ^ vlTOPp->top__DOT____Vtogcov__reset)) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->top__DOT____Vtogcov__reset = vlTOPp->top__DOT__reset;
    }
    if (((IData)(vlTOPp->clk) ^ vlTOPp->top__DOT____Vtogcov__clk)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->top__DOT____Vtogcov__clk = vlTOPp->clk;
    }
    if (((IData)(vlTOPp->reset_n) ^ vlTOPp->top__DOT____Vtogcov__reset_n)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->top__DOT____Vtogcov__reset_n = vlTOPp->reset_n;
    }
    if (((IData)(vlTOPp->uart_rx) ^ vlTOPp->top__DOT____Vtogcov__uart_rx)) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->top__DOT____Vtogcov__uart_rx = vlTOPp->uart_rx;
    }
    if ((1U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfffeU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (1U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((2U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfffdU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (2U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((4U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfffbU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (4U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((8U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfff7U & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (8U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x10U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xffefU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x10U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x20U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xffdfU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x20U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x40U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xffbfU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x40U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x80U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xff7fU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x80U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x100U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfeffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x100U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x200U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfdffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x200U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x400U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfbffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x400U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x800U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xf7ffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x800U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x1000U & ((IData)(vlTOPp->uart_prescale) 
                    ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xefffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x1000U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x2000U & ((IData)(vlTOPp->uart_prescale) 
                    ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xdfffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x2000U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x4000U & ((IData)(vlTOPp->uart_prescale) 
                    ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xbfffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x4000U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x8000U & ((IData)(vlTOPp->uart_prescale) 
                    ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0x7fffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x8000U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((1U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffffeU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (1U 
                                                   & vlTOPp->i_setup));
    }
    if ((2U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffffdU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (2U 
                                                   & vlTOPp->i_setup));
    }
    if ((4U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffffbU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (4U 
                                                   & vlTOPp->i_setup));
    }
    if ((8U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffff7U 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (8U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x10U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffffefU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x10U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x20U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffffdfU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x20U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x40U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffffbfU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x40U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x80U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffff7fU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x80U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x100U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffeffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x100U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x200U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffdffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x200U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x400U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffbffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x400U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x800U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffff7ffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x800U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x1000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffefffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x1000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x2000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffdfffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x2000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x4000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffbfffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x4000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x8000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fff7fffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x8000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x10000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffeffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x10000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x20000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffdffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x20000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x40000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffbffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x40000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x80000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ff7ffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x80000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x100000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fefffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x100000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x200000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fdfffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x200000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x400000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fbfffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x400000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x800000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7f7fffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x800000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x1000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7effffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x1000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x2000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7dffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x2000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x4000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7bffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x4000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x8000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x77ffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x8000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x10000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x6fffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x10000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x20000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x5fffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x20000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x40000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x3fffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x40000000U 
                                                   & vlTOPp->i_setup));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__intrise_reg) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intrise_reg)) {
        ++(vlSymsp->__Vcoverage[354]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intrise_reg 
            = vlTOPp->top__DOT__pic__DOT__intrise_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__inte_sync_reg) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inte_sync_reg)) {
        ++(vlSymsp->__Vcoverage[355]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inte_sync_reg 
            = vlTOPp->top__DOT__pic__DOT__inte_sync_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__aux_re_reg) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_re_reg)) {
        ++(vlSymsp->__Vcoverage[402]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_re_reg 
            = vlTOPp->top__DOT__pic__DOT__aux_re_reg;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg))) {
        ++(vlSymsp->__Vcoverage[336]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg 
            = ((6U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg))) {
        ++(vlSymsp->__Vcoverage[337]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg 
            = ((5U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg))) {
        ++(vlSymsp->__Vcoverage[338]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg 
            = ((3U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0x1eU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0x1dU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0x1bU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0x17U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0xfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [0U]))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [0U]))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [0U]))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [0U]))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [1U]))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [1U]))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [1U]))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [1U]))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [2U]))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [2U]))) {
        ++(vlSymsp->__Vcoverage[259]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [2U]))) {
        ++(vlSymsp->__Vcoverage[260]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [2U]))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [2U]))) {
        ++(vlSymsp->__Vcoverage[270]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [3U]))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [3U]))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [3U]))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [3U]))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [3U]))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [4U]))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [4U]))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [4U]))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [4U]))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[293]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[294]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[295]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [4U]))) {
        ++(vlSymsp->__Vcoverage[296]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [5U]))) {
        ++(vlSymsp->__Vcoverage[297]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [5U]))) {
        ++(vlSymsp->__Vcoverage[298]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [5U]))) {
        ++(vlSymsp->__Vcoverage[299]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [5U]))) {
        ++(vlSymsp->__Vcoverage[300]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[301]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[302]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[303]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[304]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[305]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[306]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[307]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[308]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [5U]))) {
        ++(vlSymsp->__Vcoverage[309]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [6U]))) {
        ++(vlSymsp->__Vcoverage[310]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [6U]))) {
        ++(vlSymsp->__Vcoverage[311]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [6U]))) {
        ++(vlSymsp->__Vcoverage[312]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [6U]))) {
        ++(vlSymsp->__Vcoverage[313]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[314]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[315]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[316]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[317]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[318]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[319]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[320]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[321]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [6U]))) {
        ++(vlSymsp->__Vcoverage[322]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [7U]))) {
        ++(vlSymsp->__Vcoverage[323]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [7U]))) {
        ++(vlSymsp->__Vcoverage[324]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [7U]))) {
        ++(vlSymsp->__Vcoverage[325]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [7U]))) {
        ++(vlSymsp->__Vcoverage[326]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[327]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[328]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[329]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[330]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[331]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[332]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[333]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[334]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [7U]))) {
        ++(vlSymsp->__Vcoverage[335]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    vlTOPp->top__DOT__pic__DOT__stack_top = vlTOPp->top__DOT__pic__DOT__stack_reg
        [vlTOPp->top__DOT__pic__DOT__stack_pnt_reg];
    vlTOPp->top__DOT__aux_addr = (((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                                   << 8U) | (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg) 
         ^ vlTOPp->top__DOT____Vtogcov__aux_wr_stb)) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->top__DOT____Vtogcov__aux_wr_stb = vlTOPp->top__DOT__pic__DOT__aux_we_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__ram_we_reg) 
         ^ vlTOPp->top__DOT____Vtogcov__ram_we)) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->top__DOT____Vtogcov__ram_we = vlTOPp->top__DOT__pic__DOT__ram_we_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__c_subtract_zero) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__c_subtract_zero)) {
        ++(vlSymsp->__Vcoverage[449]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__c_subtract_zero 
            = vlTOPp->top__DOT__pic__DOT__c_subtract_zero;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__c_dig_subtract_zero) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__c_dig_subtract_zero)) {
        ++(vlSymsp->__Vcoverage[450]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__c_dig_subtract_zero 
            = vlTOPp->top__DOT__pic__DOT__c_dig_subtract_zero;
    }
    if ((1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 7U) ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tvalid))) {
        ++(vlSymsp->__Vcoverage[572]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tvalid 
            = (1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                     >> 7U));
    }
    if ((1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 6U) ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tready))) {
        ++(vlSymsp->__Vcoverage[575]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tready 
            = (1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                     >> 6U));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[463]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[464]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[465]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[466]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[467]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[468]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[469]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[470]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[471]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[472]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[473]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[474]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[475]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[476]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[477]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[478]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1ffeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1ffdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1ffbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1ff7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1fefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1fdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1fbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1f7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1effU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1dffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x200U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1bffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x400U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x17ffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x800U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0xfffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x1000U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    vlTOPp->top__DOT__pic__DOT__addlow_node = (0x1fU 
                                               & ((0xfU 
                                                   & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)) 
                                                  + 
                                                  (0xfU 
                                                   & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg))));
    vlTOPp->top__DOT__pic__DOT__add_node = (0x1ffU 
                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                               + (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__exec_stall_reg)) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__exec_stall_reg 
            = vlTOPp->top__DOT__pic__DOT__exec_stall_reg;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1ffeU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1ffdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1ffbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1ff7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1fefU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1fdfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1fbfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1f7fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1effU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x100U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1dffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x200U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1bffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x17ffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x800U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                    ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0xfffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x1000U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    vlTOPp->top__DOT__pic__DOT__int_condition = (((IData)(vlTOPp->top__DOT__pic__DOT__inte_sync_reg) 
                                                  & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg))) 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                                                    >> 7U));
    if (((((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 7U))) | (4U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU)))) 
          | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 0xaU)))) | (3U == (0x7fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 7U))))) {
        ++(vlSymsp->__Vcoverage[507]);
    }
    if ((1U & (~ ((((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 7U))) | (4U 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 0xaU)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 0xaU)))) | 
                  (3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 7U))))))) {
        if ((1U & (~ ((((((((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU))) 
                            | (0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 9U)))) 
                           | (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 9U)))) 
                          | (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                         | (0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U)))) 
                        | (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U)))) 
                       | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 0xaU)))) 
                      | (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))))))) {
            if (((((((((((((((8U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U))) 
                             | (0xeU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                            | (7U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U)))) 
                           | (2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U)))) 
                          | (5U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                         | (4U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                        | (6U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 8U)))) 
                       | (3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 8U)))) 
                      | (0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 8U)))) 
                     | (0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 8U)))) 
                    | (0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 8U)))) 
                   | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                        >> 8U)))) | 
                  (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) | (9U 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U))))) {
                ++(vlSymsp->__Vcoverage[509]);
            }
        }
    }
    if ((1U & (~ ((((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 7U))) | (4U 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 0xaU)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 0xaU)))) | 
                  (3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 7U))))))) {
        if (((((((((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 0xaU))) | (0x1fU 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                       >> 9U)))) 
                  | (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                        >> 9U)))) | 
                 (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) | (0x38U 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
               | (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) | (0xdU 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 0xaU)))) 
             | (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                >> 7U))))) {
            ++(vlSymsp->__Vcoverage[508]);
        }
    }
    if ((1U & (~ ((((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 7U))) | (4U 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 0xaU)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 0xaU)))) | 
                  (3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 7U))))))) {
        if ((1U & (~ ((((((((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU))) 
                            | (0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 9U)))) 
                           | (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 9U)))) 
                          | (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                         | (0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U)))) 
                        | (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U)))) 
                       | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 0xaU)))) 
                      | (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))))))) {
            if ((1U & (~ ((((((((((((((8U == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))) 
                                      | (0xeU == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                     | (7U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (2U == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                   | (5U == (0x3fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                                  | (4U == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                                 | (6U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                | (3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                               | (0xaU == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                              | (0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                             | (0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                            | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                           | (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                          | (9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))))))) {
                ++(vlSymsp->__Vcoverage[510]);
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((((((0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))) 
                            | (5U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U)))) 
                           | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU)))) 
                          | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 0xaU)))) 
                         | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 0xaU))))) {
                        ++(vlSymsp->__Vcoverage[515]);
                    }
                }
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((1U & (~ (((((0x39U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                     | (5U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (6U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (7U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))))) {
                        if ((1U & (~ (((5U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU))) 
                                       | (0x38U == 
                                          (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                      | (4U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((1U & (~ ((0x3aU == 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                          | (6U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                                if (((((((((0x1fU == 
                                            (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 9U))) 
                                           | (7U == 
                                              (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                          | (0x1eU 
                                             == (0x1fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 9U)))) 
                                         | (2U == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                        | (3U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                       | (0xbU == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                      | (0xaU == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                     | (0xfU == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U))))) {
                                    ++(vlSymsp->__Vcoverage[518]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((1U & (~ (((((0x39U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                     | (5U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (6U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (7U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))))) {
                        if ((1U & (~ (((5U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU))) 
                                       | (0x38U == 
                                          (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                      | (4U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if (((0x3aU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                 | (6U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U))))) {
                                ++(vlSymsp->__Vcoverage[517]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                ++(vlSymsp->__Vcoverage[513]);
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    ++(vlSymsp->__Vcoverage[514]);
                }
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            ++(vlSymsp->__Vcoverage[512]);
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((1U & (~ (((((0x39U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                     | (5U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (6U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (7U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))))) {
                        if ((((5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU))) 
                              | (0x38U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                             | (4U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))))) {
                            ++(vlSymsp->__Vcoverage[516]);
                        }
                    }
                }
            }
        }
    }
    if ((0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        ++(vlSymsp->__Vcoverage[511]);
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((1U & (~ (((((0x39U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                     | (5U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (6U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (7U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))))) {
                        if ((1U & (~ (((5U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU))) 
                                       | (0x38U == 
                                          (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                      | (4U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((1U & (~ ((0x3aU == 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                          | (6U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x1fU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 9U))) 
                                                    | (7U 
                                                       == 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 8U)))) 
                                                   | (0x1eU 
                                                      == 
                                                      (0x1fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 9U)))) 
                                                  | (2U 
                                                     == 
                                                     (0x3fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 8U)))) 
                                                 | (3U 
                                                    == 
                                                    (0x3fU 
                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                        >> 8U)))) 
                                                | (0xbU 
                                                   == 
                                                   (0x3fU 
                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                       >> 8U)))) 
                                               | (0xaU 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                              | (0xfU 
                                                 == 
                                                 (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U))))))) {
                                    ++(vlSymsp->__Vcoverage[519]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
         & (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
             | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 0xaU)))) | (9U 
                                                == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))) {
        ++(vlSymsp->__Vcoverage[500]);
    }
    if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                  & (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                      | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                     | (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))))) {
        if (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
             & ((5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xbU))) | (4U == (7U 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 0xbU)))))) {
            ++(vlSymsp->__Vcoverage[501]);
        }
    }
    if (((0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 9U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_addlw)) {
        ++(vlSymsp->__Vcoverage[360]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_addlw 
            = (0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 9U)));
    }
    if (((7U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_addwf)) {
        ++(vlSymsp->__Vcoverage[361]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_addwf 
            = (7U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_andlw)) {
        ++(vlSymsp->__Vcoverage[362]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_andlw 
            = (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 8U)));
    }
    if (((5U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_andwf)) {
        ++(vlSymsp->__Vcoverage[363]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_andwf 
            = (5U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((4U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                         >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_bcf)) {
        ++(vlSymsp->__Vcoverage[364]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_bcf 
            = (4U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xaU)));
    }
    if (((5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                         >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_bsf)) {
        ++(vlSymsp->__Vcoverage[365]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_bsf 
            = (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xaU)));
    }
    if (((6U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                         >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_btfsc)) {
        ++(vlSymsp->__Vcoverage[366]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_btfsc 
            = (6U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xaU)));
    }
    if (((7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                         >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_btfss)) {
        ++(vlSymsp->__Vcoverage[367]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_btfss 
            = (7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xaU)));
    }
    if (((4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                       >> 0xbU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_call)) {
        ++(vlSymsp->__Vcoverage[368]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_call 
            = (4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 0xbU)));
    }
    if (((3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_clrf)) {
        ++(vlSymsp->__Vcoverage[369]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_clrf 
            = (3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 7U)));
    }
    if (((2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_clrw)) {
        ++(vlSymsp->__Vcoverage[370]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_clrw 
            = (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 7U)));
    }
    if (((9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_comf)) {
        ++(vlSymsp->__Vcoverage[371]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_comf 
            = (9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_decf)) {
        ++(vlSymsp->__Vcoverage[372]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_decf 
            = (3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_decfsz)) {
        ++(vlSymsp->__Vcoverage[373]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_decfsz 
            = (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                       >> 0xbU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_goto)) {
        ++(vlSymsp->__Vcoverage[374]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_goto 
            = (5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 0xbU)));
    }
    if (((0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_incf)) {
        ++(vlSymsp->__Vcoverage[375]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_incf 
            = (0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_incfsz)) {
        ++(vlSymsp->__Vcoverage[376]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_incfsz 
            = (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_iorlw)) {
        ++(vlSymsp->__Vcoverage[377]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_iorlw 
            = (0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 8U)));
    }
    if (((4U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_iorwf)) {
        ++(vlSymsp->__Vcoverage[378]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_iorwf 
            = (4U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movlw)) {
        ++(vlSymsp->__Vcoverage[379]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movlw 
            = (0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                >> 0xaU)));
    }
    if (((8U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movf)) {
        ++(vlSymsp->__Vcoverage[380]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movf 
            = (8U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movwf)) {
        ++(vlSymsp->__Vcoverage[381]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movwf 
            = (1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 7U)));
    }
    if (((9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_retfie)) {
        ++(vlSymsp->__Vcoverage[382]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_retfie 
            = (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg));
    }
    if (((0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_retlw)) {
        ++(vlSymsp->__Vcoverage[383]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_retlw 
            = (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                >> 0xaU)));
    }
    if (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_ret)) {
        ++(vlSymsp->__Vcoverage[384]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_ret 
            = (8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg));
    }
    if (((0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_rlf)) {
        ++(vlSymsp->__Vcoverage[385]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_rlf 
            = (0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_rrf)) {
        ++(vlSymsp->__Vcoverage[386]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_rrf 
            = (0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0x63U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_sleep)) {
        ++(vlSymsp->__Vcoverage[387]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_sleep 
            = (0x63U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg));
    }
    if (((0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 9U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_sublw)) {
        ++(vlSymsp->__Vcoverage[388]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_sublw 
            = (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 9U)));
    }
    if (((2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_subwf)) {
        ++(vlSymsp->__Vcoverage[389]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_subwf 
            = (2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((0xeU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_swapf)) {
        ++(vlSymsp->__Vcoverage[390]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_swapf 
            = (0xeU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_xorlw)) {
        ++(vlSymsp->__Vcoverage[391]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_xorlw 
            = (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 8U)));
    }
    if (((6U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_xorwf)) {
        ++(vlSymsp->__Vcoverage[392]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_xorwf 
            = (6U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    vlTOPp->top__DOT__pic__DOT__writew_node = ((~ (
                                                   (((1U 
                                                      == 
                                                      (0x7fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 7U))) 
                                                     | (4U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                            >> 0xaU)))) 
                                                    | (5U 
                                                       == 
                                                       (0xfU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 0xaU)))) 
                                                   | (3U 
                                                      == 
                                                      (0x7fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 7U))))) 
                                               & (((((((((0xcU 
                                                          == 
                                                          (0xfU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 0xaU))) 
                                                         | (0x1fU 
                                                            == 
                                                            (0x1fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 9U)))) 
                                                        | (0x1eU 
                                                           == 
                                                           (0x1fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 9U)))) 
                                                       | (0x39U 
                                                          == 
                                                          (0x3fU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 8U)))) 
                                                      | (0x38U 
                                                         == 
                                                         (0x3fU 
                                                          & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                             >> 8U)))) 
                                                     | (0x3aU 
                                                        == 
                                                        (0x3fU 
                                                         & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                            >> 8U)))) 
                                                    | (0xdU 
                                                       == 
                                                       (0xfU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 0xaU)))) 
                                                   | (2U 
                                                      == 
                                                      (0x7fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 7U)))) 
                                                  | (((((((((((((((8U 
                                                                   == 
                                                                   (0x3fU 
                                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                       >> 8U))) 
                                                                  | (0xeU 
                                                                     == 
                                                                     (0x3fU 
                                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                         >> 8U)))) 
                                                                 | (7U 
                                                                    == 
                                                                    (0x3fU 
                                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                        >> 8U)))) 
                                                                | (2U 
                                                                   == 
                                                                   (0x3fU 
                                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                       >> 8U)))) 
                                                               | (5U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                      >> 8U)))) 
                                                              | (4U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                     >> 8U)))) 
                                                             | (6U 
                                                                == 
                                                                (0x3fU 
                                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                    >> 8U)))) 
                                                            | (3U 
                                                               == 
                                                               (0x3fU 
                                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                   >> 8U)))) 
                                                           | (0xaU 
                                                              == 
                                                              (0x3fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 8U)))) 
                                                          | (0xdU 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (0xcU 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U)))) 
                                                        | (0xbU 
                                                           == 
                                                           (0x3fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 8U)))) 
                                                       | (0xfU 
                                                          == 
                                                          (0x3fU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 8U)))) 
                                                      | (9U 
                                                         == 
                                                         (0x3fU 
                                                          & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                             >> 8U)))) 
                                                     & (~ 
                                                        ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 7U)))));
    if ((1U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[411]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (1U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U)))));
    }
    if ((2U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[412]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (2U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U)))));
    }
    if ((4U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[413]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (4U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U)))));
    }
    if ((8U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[414]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (8U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U)))));
    }
    if ((0x10U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[415]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (0x10U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U)))));
    }
    if ((0x20U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[416]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (0x20U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U)))));
    }
    if ((0x40U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[417]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (0x40U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U)))));
    }
    if ((0x80U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[418]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (0x80U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U)))));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3ffeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3ffdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3ffbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3ff7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3fefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3fdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3fbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3f7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3effU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3dffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x200U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3bffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x400U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x37ffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x800U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x2fffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x1000U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x2000U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x1fffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x2000U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    vlTOPp->top__DOT__pic__DOT__writeram_node = (((
                                                   ((1U 
                                                     == 
                                                     (0x7fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 7U))) 
                                                    | (4U 
                                                       == 
                                                       (0xfU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 0xaU)))) 
                                                   | (5U 
                                                      == 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 0xaU)))) 
                                                  | (3U 
                                                     == 
                                                     (0x7fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 7U)))) 
                                                 | ((~ 
                                                     ((((((((0xcU 
                                                             == 
                                                             (0xfU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 0xaU))) 
                                                            | (0x1fU 
                                                               == 
                                                               (0x1fU 
                                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                   >> 9U)))) 
                                                           | (0x1eU 
                                                              == 
                                                              (0x1fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 9U)))) 
                                                          | (0x39U 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (0x38U 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U)))) 
                                                        | (0x3aU 
                                                           == 
                                                           (0x3fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 8U)))) 
                                                       | (0xdU 
                                                          == 
                                                          (0xfU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 0xaU)))) 
                                                      | (2U 
                                                         == 
                                                         (0x7fU 
                                                          & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                             >> 7U))))) 
                                                    & (((((((((((((((8U 
                                                                     == 
                                                                     (0x3fU 
                                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                         >> 8U))) 
                                                                    | (0xeU 
                                                                       == 
                                                                       (0x3fU 
                                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                           >> 8U)))) 
                                                                   | (7U 
                                                                      == 
                                                                      (0x3fU 
                                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                          >> 8U)))) 
                                                                  | (2U 
                                                                     == 
                                                                     (0x3fU 
                                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                         >> 8U)))) 
                                                                 | (5U 
                                                                    == 
                                                                    (0x3fU 
                                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                        >> 8U)))) 
                                                                | (4U 
                                                                   == 
                                                                   (0x3fU 
                                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                       >> 8U)))) 
                                                               | (6U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                      >> 8U)))) 
                                                              | (3U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                     >> 8U)))) 
                                                             | (0xaU 
                                                                == 
                                                                (0x3fU 
                                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                    >> 8U)))) 
                                                            | (0xdU 
                                                               == 
                                                               (0x3fU 
                                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                   >> 8U)))) 
                                                           | (0xcU 
                                                              == 
                                                              (0x3fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 8U)))) 
                                                          | (0xbU 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (0xfU 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U)))) 
                                                        | (9U 
                                                           == 
                                                           (0x3fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 8U)))) 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 7U))));
    vlTOPp->top__DOT__pic__DOT__ram_adr_node = ((0U 
                                                 == 
                                                 (0x7fU 
                                                  & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))
                                                 ? 
                                                ((0x100U 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg))
                                                 : 
                                                ((0x180U 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                                                     << 2U)) 
                                                 | (0x7fU 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))));
    vlTOPp->top__DOT__reset = (1U & (~ (IData)(vlTOPp->reset_n)));
    if ((2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
            ++(vlSymsp->__Vcoverage[559]);
        }
    }
    if ((2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            ++(vlSymsp->__Vcoverage[562]);
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
            ++(vlSymsp->__Vcoverage[555]);
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            ++(vlSymsp->__Vcoverage[558]);
        }
    }
    if ((2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__inte_sync_reg)))) {
                ++(vlSymsp->__Vcoverage[561]);
            }
        }
    }
    if ((2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if (vlTOPp->top__DOT__pic__DOT__inte_sync_reg) {
                ++(vlSymsp->__Vcoverage[560]);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                 & (0x63U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))) {
                ++(vlSymsp->__Vcoverage[556]);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                          & (0x63U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))))) {
                ++(vlSymsp->__Vcoverage[557]);
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg))) {
        ++(vlSymsp->__Vcoverage[356]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg 
            = ((2U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg))) {
        ++(vlSymsp->__Vcoverage[357]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg 
            = ((1U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[339]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1ffeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[340]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1ffdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[341]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1ffbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[342]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1ff7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[343]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1fefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[344]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1fdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[345]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1fbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[346]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1f7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[347]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1effU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[348]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1dffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x200U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[349]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1bffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x400U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[350]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x17ffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x800U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[351]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0xfffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x1000U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__aux_addr) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfffeU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__aux_addr) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfffdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__aux_addr) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfffbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__aux_addr) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfff7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xffefU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xffdfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xffbfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xff7fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                   ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfeffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x100U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                   ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfdffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x200U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                   ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfbffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                   ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xf7ffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x800U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                    ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xefffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x1000U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x2000U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                    ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xdfffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x2000U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x4000U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                    ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xbfffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x4000U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x8000U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                    ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0x7fffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x8000U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[428]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0x1eU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[429]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0x1dU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[430]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0x1bU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[431]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0x17U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[432]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0xfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[419]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1feU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[420]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1fdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[421]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1fbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[422]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1f7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[423]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1efU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[424]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1dfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[425]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1bfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[426]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x17fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[427]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0xffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    vlTOPp->top__DOT__pic__DOT__aluout = (0xffU & (
                                                   (0xdU 
                                                    == 
                                                    (0x3fU 
                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                        >> 8U)))
                                                    ? 
                                                   ((0xfeU 
                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                        << 1U)) 
                                                    | (1U 
                                                       & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)))
                                                    : 
                                                   ((0xcU 
                                                     == 
                                                     (0x3fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 8U)))
                                                     ? 
                                                    ((0x80U 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                                                         << 7U)) 
                                                     | (0x7fU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                           >> 1U)))
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 8U)))
                                                      ? 
                                                     ((0xf0U 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                          << 4U)) 
                                                      | (0xfU 
                                                         & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                            >> 4U)))
                                                      : 
                                                     ((9U 
                                                       == 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 8U)))
                                                       ? 
                                                      (~ (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg))
                                                       : 
                                                      ((((((0x39U 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U))) 
                                                           | (5U 
                                                              == 
                                                              (0x3fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 8U)))) 
                                                          | (4U 
                                                             == 
                                                             (0xfU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 0xaU)))) 
                                                         | (6U 
                                                            == 
                                                            (0xfU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 0xaU)))) 
                                                        | (7U 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xaU))))
                                                        ? 
                                                       ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg))
                                                        : 
                                                       ((((5U 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xaU))) 
                                                          | (0x38U 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (4U 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U))))
                                                         ? 
                                                        ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                         | (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg))
                                                         : 
                                                        (((0x3aU 
                                                           == 
                                                           (0x3fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 8U))) 
                                                          | (6U 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U))))
                                                          ? 
                                                         ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                          ^ (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg))
                                                          : 
                                                         (((((((((0x1fU 
                                                                  == 
                                                                  (0x1fU 
                                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                      >> 9U))) 
                                                                 | (7U 
                                                                    == 
                                                                    (0x3fU 
                                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                        >> 8U)))) 
                                                                | (0x1eU 
                                                                   == 
                                                                   (0x1fU 
                                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                       >> 9U)))) 
                                                               | (2U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                      >> 8U)))) 
                                                              | (3U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                     >> 8U)))) 
                                                             | (0xbU 
                                                                == 
                                                                (0x3fU 
                                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                    >> 8U)))) 
                                                            | (0xaU 
                                                               == 
                                                               (0x3fU 
                                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                   >> 8U)))) 
                                                           | (0xfU 
                                                              == 
                                                              (0x3fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 8U))))
                                                           ? (IData)(vlTOPp->top__DOT__pic__DOT__add_node)
                                                           : (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg))))))))));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__int_condition) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__int_condition)) {
        ++(vlSymsp->__Vcoverage[352]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__int_condition 
            = vlTOPp->top__DOT__pic__DOT__int_condition;
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
            if (vlTOPp->top__DOT__pic__DOT__int_condition) {
                ++(vlSymsp->__Vcoverage[553]);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__int_condition)))) {
                ++(vlSymsp->__Vcoverage[554]);
            }
        }
    }
    vlTOPp->top__DOT__pic__DOT__next_state_node = (
                                                   (2U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__pic__DOT__inte_sync_reg)
                                                      ? 0U
                                                      : 3U)
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))
                                                     ? 
                                                    (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                                                      & (0x63U 
                                                         == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))
                                                      ? 3U
                                                      : 0U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__pic__DOT__int_condition)
                                                      ? 2U
                                                      : 1U)));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__writew_node) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__writew_node)) {
        ++(vlSymsp->__Vcoverage[447]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__writew_node 
            = vlTOPp->top__DOT__pic__DOT__writew_node;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__writeram_node)) {
        ++(vlSymsp->__Vcoverage[448]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__writeram_node 
            = vlTOPp->top__DOT__pic__DOT__writeram_node;
    }
    if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                  & (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                      | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                     | (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))))) {
        if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                      & ((5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                       >> 0xbU))) | 
                         (4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                       >> 0xbU)))))))) {
            if (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                 & ((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
                    & (2U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))))) {
                ++(vlSymsp->__Vcoverage[502]);
            }
        }
    }
    if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                  & (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                      | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                     | (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))))) {
        if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                      & ((5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                       >> 0xbU))) | 
                         (4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                       >> 0xbU)))))))) {
            if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                          & ((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
                             & (2U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))))))) {
                ++(vlSymsp->__Vcoverage[503]);
            }
        }
    }
    if (((2U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_pcl)) {
        ++(vlSymsp->__Vcoverage[393]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_pcl 
            = (2U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((3U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_stat)) {
        ++(vlSymsp->__Vcoverage[394]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_stat 
            = (3U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((4U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_fsr)) {
        ++(vlSymsp->__Vcoverage[395]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_fsr 
            = (4U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((0xaU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_pclath)) {
        ++(vlSymsp->__Vcoverage[396]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_pclath 
            = (0xaU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((0xbU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_intcon)) {
        ++(vlSymsp->__Vcoverage[397]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_intcon 
            = (0xbU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((5U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_adr_lo)) {
        ++(vlSymsp->__Vcoverage[398]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_adr_lo 
            = (5U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((6U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_adr_hi)) {
        ++(vlSymsp->__Vcoverage[399]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_adr_hi 
            = (6U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((8U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_dat)) {
        ++(vlSymsp->__Vcoverage[400]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_dat 
            = (8U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((0xbU < (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_sram)) {
        ++(vlSymsp->__Vcoverage[401]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_sram 
            = (0xbU < (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((0x87U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_rx_data)) {
        ++(vlSymsp->__Vcoverage[452]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_rx_data 
            = (0x87U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((7U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_tx_data)) {
        ++(vlSymsp->__Vcoverage[453]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_tx_data 
            = (7U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((9U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_sr)) {
        ++(vlSymsp->__Vcoverage[454]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_sr 
            = (9U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    vlTOPp->top__DOT__aux_rd_stb = ((IData)(vlTOPp->top__DOT__pic__DOT__aux_re_reg) 
                                    & (8U == (0xffU 
                                              & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1feU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1fdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1fbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1f7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1efU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1dfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1bfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x17fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                   ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0xffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x100U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    vlTOPp->top__DOT__ram_data_rd = vlTOPp->top__DOT__ram
        [vlTOPp->top__DOT__pic__DOT__ram_adr_node];
    if ((1U & (((0U == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                 ? 1U : 0U) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluout_zero_node))) {
        ++(vlSymsp->__Vcoverage[433]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluout_zero_node 
            = ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                ? 1U : 0U);
    }
    vlTOPp->top__DOT__pic__DOT__next_exec_stall = (
                                                   (((((((5U 
                                                          == 
                                                          (7U 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 0xbU))) 
                                                         | (4U 
                                                            == 
                                                            (7U 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 0xbU)))) 
                                                        | (8U 
                                                           == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))) 
                                                       | (0xdU 
                                                          == 
                                                          (0xfU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 0xaU)))) 
                                                      | (9U 
                                                         == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))) 
                                                     | ((((6U 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xaU))) 
                                                          | (0xbU 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (0xfU 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U)))) 
                                                        & ((0U 
                                                            == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                                                            ? 1U
                                                            : 0U))) 
                                                    | ((7U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                            >> 0xaU))) 
                                                       & (~ 
                                                          ((0U 
                                                            == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                                                            ? 1U
                                                            : 0U)))) 
                                                   | ((2U 
                                                       == 
                                                       (0x7fU 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
                                                      & (IData)(vlTOPp->top__DOT__pic__DOT__writeram_node)));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xfeU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xfdU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xfbU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xf7U & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xefU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xdfU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xbfU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0x7fU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    vlTOPp->top__DOT__pic__DOT__next_pc_node = (0x1fffU 
                                                & (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                                                    & (((8U 
                                                         == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                                                        | (0xdU 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xaU)))) 
                                                       | (9U 
                                                          == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))
                                                    ? (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)
                                                    : 
                                                   (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                                                     & ((5U 
                                                         == 
                                                         (7U 
                                                          & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                             >> 0xbU))) 
                                                        | (4U 
                                                           == 
                                                           (7U 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xbU)))))
                                                     ? 
                                                    ((0x1800U 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
                                                         << 8U)) 
                                                     | (0x7ffU 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))
                                                     : 
                                                    (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
                                                         & (2U 
                                                            == 
                                                            (0x7fU 
                                                             & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))))
                                                      ? 
                                                     (((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
                                                       << 8U) 
                                                      | (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                                                      : 
                                                     ((IData)(1U) 
                                                      + (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg))))));
    vlTOPp->top__DOT__aux_data = (((((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                      ? (IData)(vlTOPp->top__DOT__pic__DOT__aluout)
                                      : 0U) & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                                ? 0xffU
                                                : 0U)) 
                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                       ? 0xffU : 0U)) 
                                  | (((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                       ? 0U : vlTOPp->top__DOT__aux_ram
                                      [vlTOPp->top__DOT__aux_addr]) 
                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                         ? 0U : 0xffU)));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_state_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node))) {
        ++(vlSymsp->__Vcoverage[358]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node 
            = ((2U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__next_state_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_state_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node))) {
        ++(vlSymsp->__Vcoverage[359]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node 
            = ((1U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__next_state_node)));
    }
    if (((IData)(vlTOPp->top__DOT__aux_rd_stb) ^ vlTOPp->top__DOT____Vtogcov__aux_rd_stb)) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->top__DOT____Vtogcov__aux_rd_stb = vlTOPp->top__DOT__aux_rd_stb;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xfeU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (1U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xfdU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (2U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xfbU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (4U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xf7U & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (8U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xefU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (0x10U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xdfU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (0x20U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xbfU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (0x40U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0x7fU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (0x80U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__next_exec_stall) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_exec_stall)) {
        ++(vlSymsp->__Vcoverage[451]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_exec_stall 
            = vlTOPp->top__DOT__pic__DOT__next_exec_stall;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[434]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1ffeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[435]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1ffdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[436]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1ffbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[437]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1ff7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[438]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1fefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[439]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1fdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[440]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1fbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[441]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1f7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[442]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1effU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[443]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1dffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x200U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[444]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1bffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x400U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[445]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x17ffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x800U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[446]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0xfffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x1000U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__aux_data) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xfeU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__aux_data) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xfdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__aux_data) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xfbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__aux_data) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xf7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__aux_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xefU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__aux_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xdfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__aux_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xbfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__aux_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0x7fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->top__DOT__reset) ^ vlTOPp->top__DOT____Vtogcov__reset)) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->top__DOT____Vtogcov__reset = vlTOPp->top__DOT__reset;
    }
    if (((IData)(vlTOPp->clk) ^ vlTOPp->top__DOT____Vtogcov__clk)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->top__DOT____Vtogcov__clk = vlTOPp->clk;
    }
    if (((IData)(vlTOPp->reset_n) ^ vlTOPp->top__DOT____Vtogcov__reset_n)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->top__DOT____Vtogcov__reset_n = vlTOPp->reset_n;
    }
    if (((IData)(vlTOPp->uart_rx) ^ vlTOPp->top__DOT____Vtogcov__uart_rx)) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->top__DOT____Vtogcov__uart_rx = vlTOPp->uart_rx;
    }
    if ((1U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfffeU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (1U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((2U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfffdU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (2U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((4U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfffbU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (4U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((8U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfff7U & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (8U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x10U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xffefU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x10U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x20U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xffdfU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x20U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x40U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xffbfU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x40U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x80U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xff7fU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x80U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x100U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfeffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x100U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x200U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfdffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x200U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x400U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xfbffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x400U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x800U & ((IData)(vlTOPp->uart_prescale) ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xf7ffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x800U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x1000U & ((IData)(vlTOPp->uart_prescale) 
                    ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xefffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x1000U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x2000U & ((IData)(vlTOPp->uart_prescale) 
                    ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xdfffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x2000U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x4000U & ((IData)(vlTOPp->uart_prescale) 
                    ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0xbfffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x4000U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((0x8000U & ((IData)(vlTOPp->uart_prescale) 
                    ^ vlTOPp->top__DOT____Vtogcov__uart_prescale))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->top__DOT____Vtogcov__uart_prescale 
            = ((0x7fffU & (IData)(vlTOPp->top__DOT____Vtogcov__uart_prescale)) 
               | (0x8000U & (IData)(vlTOPp->uart_prescale)));
    }
    if ((1U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffffeU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (1U 
                                                   & vlTOPp->i_setup));
    }
    if ((2U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffffdU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (2U 
                                                   & vlTOPp->i_setup));
    }
    if ((4U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffffbU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (4U 
                                                   & vlTOPp->i_setup));
    }
    if ((8U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffff7U 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (8U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x10U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffffefU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x10U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x20U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffffdfU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x20U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x40U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffffbfU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x40U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x80U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffff7fU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x80U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x100U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffeffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x100U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x200U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffdffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x200U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x400U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffffbffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x400U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x800U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffff7ffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x800U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x1000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffefffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x1000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x2000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffdfffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x2000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x4000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fffbfffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x4000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x8000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fff7fffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x8000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x10000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffeffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x10000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x20000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffdffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x20000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x40000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ffbffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x40000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x80000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7ff7ffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x80000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x100000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fefffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x100000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x200000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fdfffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x200000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x400000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7fbfffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x400000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x800000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7f7fffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x800000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x1000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7effffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x1000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x2000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7dffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x2000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x4000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x7bffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x4000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x8000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x77ffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x8000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x10000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x6fffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x10000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x20000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x5fffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x20000000U 
                                                   & vlTOPp->i_setup));
    }
    if ((0x40000000U & (vlTOPp->i_setup ^ vlTOPp->top__DOT____Vtogcov__i_setup))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->top__DOT____Vtogcov__i_setup = ((0x3fffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__i_setup) 
                                                | (0x40000000U 
                                                   & vlTOPp->i_setup));
    }
}

void Vtop::_initial__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg = 1U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg = 0U;
    VL_READMEM_N(true, 14, 8192, 0, std::string("main.rom")
                 , vlTOPp->top__DOT__rom, 0, ~VL_ULL(0));
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg = 1U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg;
    CData/*3:0*/ __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt;
    CData/*0:0*/ __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    CData/*3:0*/ __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt;
    CData/*7:0*/ __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg;
    SData/*8:0*/ __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg;
    IData/*18:0*/ __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg;
    IData/*18:0*/ __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg;
    // Body
    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt;
    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg;
    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg;
    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt;
    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg;
    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg;
    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg;
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[567]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[568]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[569]);
    }
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[613]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[620]);
    }
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[653]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[666]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U < vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg)) {
            ++(vlSymsp->__Vcoverage[614]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U < vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            ++(vlSymsp->__Vcoverage[655]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                if ((1U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                    ++(vlSymsp->__Vcoverage[617]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[619]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[616]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                if ((1U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                        ++(vlSymsp->__Vcoverage[618]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                        ++(vlSymsp->__Vcoverage[659]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                    ++(vlSymsp->__Vcoverage[658]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[663]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                            ++(vlSymsp->__Vcoverage[662]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[665]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg)))) {
                        ++(vlSymsp->__Vcoverage[656]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                    if (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg) {
                        ++(vlSymsp->__Vcoverage[657]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                            if (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg) {
                                ++(vlSymsp->__Vcoverage[660]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg)))) {
                                ++(vlSymsp->__Vcoverage[661]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U >= (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg)))) {
                    ++(vlSymsp->__Vcoverage[664]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                if ((0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff))) {
                    ++(vlSymsp->__Vcoverage[615]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
             & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 6U))) {
            ++(vlSymsp->__Vcoverage[654]);
        }
    }
    vlTOPp->top__DOT__pic__DOT__intrise_reg = (1U & 
                                               ((~ (IData)(vlTOPp->top__DOT__reset)) 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                                                   >> 4U)));
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg = 0U;
        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg = 0U;
        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt = 0U;
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg = 0U;
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg = 0U;
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg = 0U;
    } else {
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg = 0U;
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg = 0U;
        if (((IData)(vlTOPp->top__DOT__pic__DOT____Vcellout__pic_uart__output_axis_tvalid) 
             & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 6U))) {
            __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
        }
        if ((0U < vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg)) {
            __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                = (0x7ffffU & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                               - (IData)(1U)));
        } else {
            if ((0U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                    if (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg) {
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt = 0U;
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg = 0U;
                    } else {
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                            = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                            << 3U) 
                                           - (IData)(1U)));
                    }
                } else {
                    if ((1U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg 
                            = (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg) 
                                << 7U) | (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                                                   >> 1U)));
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                            = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                            << 3U) 
                                           - (IData)(1U)));
                    } else {
                        if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt))) {
                            __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt 
                                = (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
                                           - (IData)(1U)));
                            if (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg) {
                                vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg 
                                    = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg;
                                vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg 
                                    = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg;
                                __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg = 1U;
                            } else {
                                vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg = 1U;
                            }
                        }
                    }
                }
            } else {
                vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg = 0U;
                if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg)))) {
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg = 0U;
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 2U) - (IData)(2U)));
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt = 0xaU;
                    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg = 1U;
                }
            }
        }
    }
    if (vlTOPp->top__DOT__reset) {
        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg = 1U;
        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg = 0U;
        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt = 0U;
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg = 0U;
    } else {
        if ((0U < vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg)) {
            __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                = (0x7ffffU & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                               - (IData)(1U)));
            __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
        } else {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg = 1U;
                vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg = 0U;
                if ((0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff))) {
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg 
                        = (1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg)));
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 3U) - (IData)(1U)));
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt = 9U;
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg 
                        = (0x100U | (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data));
                    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg = 0U;
                    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg = 1U;
                }
            } else {
                if ((1U < (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt 
                        = (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
                                   - (IData)(1U)));
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg 
                        = (0x1ffU & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                                     >> 1U));
                    __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 3U) - (IData)(1U)));
                    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg 
                        = (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg));
                } else {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt))) {
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                            = (0x7ffffU & ((IData)(vlTOPp->uart_prescale) 
                                           << 3U));
                        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt 
        = __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg 
        = __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
        = __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg 
        = __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt 
        = __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg 
        = __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
        = __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg;
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg 
        = __Vdly__top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg;
    if (((IData)(vlTOPp->top__DOT__pic__DOT__intrise_reg) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intrise_reg)) {
        ++(vlSymsp->__Vcoverage[354]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intrise_reg 
            = vlTOPp->top__DOT__pic__DOT__intrise_reg;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[649]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[650]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[651]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[652]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt)));
    }
    vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg 
        = ((IData)(vlTOPp->top__DOT__reset) | (IData)(vlTOPp->uart_rx));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[622]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[623]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[624]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[625]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[626]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[627]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[628]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[629]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[455]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[456]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[457]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[458]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[459]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[460]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[461]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[462]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[630]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[631]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[632]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[633]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[634]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[635]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[636]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[637]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[638]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[639]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[640]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[641]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[642]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[643]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[644]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[645]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[646]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[647]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[648]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_busy)) {
        ++(vlSymsp->__Vcoverage[577]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_busy 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_overrun_error)) {
        ++(vlSymsp->__Vcoverage[578]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_overrun_error 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_frame_error)) {
        ++(vlSymsp->__Vcoverage[579]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_frame_error 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tvalid)) {
        ++(vlSymsp->__Vcoverage[574]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tvalid 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    }
    vlTOPp->top__DOT__pic__DOT____Vcellout__pic_uart__output_axis_tvalid 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    vlTOPp->top__DOT__pic__DOT__uart_sr = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)) 
                                           | ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
                                              << 4U));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__txd_reg)) {
        ++(vlSymsp->__Vcoverage[580]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__txd_reg 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg;
    }
    vlTOPp->uart_tx = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg;
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[609]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[610]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[611]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[612]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[581]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1feU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[582]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fdU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[583]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fbU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[584]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1f7U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[585]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1efU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[586]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1dfU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[587]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1bfU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[588]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x17fU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[589]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[590]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[591]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[592]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[593]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[594]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[595]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[596]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[597]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[598]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[599]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[600]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[601]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[602]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[603]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[604]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[605]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[606]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[607]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[608]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__tx_busy)) {
        ++(vlSymsp->__Vcoverage[576]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__tx_busy 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg;
    }
    vlTOPp->top__DOT__pic__DOT__uart_sr = ((0xf0U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)) 
                                           | (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg) 
                                               << 3U) 
                                              | (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg)))));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tready)) {
        ++(vlSymsp->__Vcoverage[573]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tready 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg;
    }
    vlTOPp->top__DOT__pic__DOT__uart_sr = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)) 
                                           | ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg) 
                                              << 5U));
    if (((IData)(vlTOPp->uart_tx) ^ vlTOPp->top__DOT____Vtogcov__uart_tx)) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->top__DOT____Vtogcov__uart_tx = vlTOPp->uart_tx;
    }
    if ((1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                >> 4U) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__int_combined))) {
        ++(vlSymsp->__Vcoverage[566]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__int_combined 
            = (1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                     >> 4U));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[479]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[480]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[481]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[482]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[483]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[484]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[485]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[486]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__rxd_reg)) {
        ++(vlSymsp->__Vcoverage[621]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__rxd_reg 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__top__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__aux_ram__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__aux_ram__v0;
    CData/*0:0*/ __Vdly__top__DOT__pic__DOT__exec_stall_reg;
    CData/*2:0*/ __Vdly__top__DOT__pic__DOT__stack_pnt_reg;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__pic__DOT__stack_reg__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__pic__DOT__stack_reg__v0;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__pic__DOT__stack_reg__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__pic__DOT__stack_reg__v1;
    SData/*8:0*/ __Vdlyvdim0__top__DOT__ram__v0;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__aux_ram__v0;
    SData/*12:0*/ __Vdlyvval__top__DOT__pic__DOT__stack_reg__v0;
    SData/*12:0*/ __Vdlyvval__top__DOT__pic__DOT__stack_reg__v1;
    // Body
    __Vdly__top__DOT__pic__DOT__exec_stall_reg = vlTOPp->top__DOT__pic__DOT__exec_stall_reg;
    __Vdlyvset__top__DOT__aux_ram__v0 = 0U;
    __Vdlyvset__top__DOT__ram__v0 = 0U;
    __Vdly__top__DOT__pic__DOT__stack_pnt_reg = vlTOPp->top__DOT__pic__DOT__stack_pnt_reg;
    __Vdlyvset__top__DOT__pic__DOT__stack_reg__v0 = 0U;
    __Vdlyvset__top__DOT__pic__DOT__stack_reg__v1 = 0U;
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[495]);
    }
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[497]);
    }
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[504]);
    }
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[520]);
    }
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[564]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[565]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            ++(vlSymsp->__Vcoverage[496]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            ++(vlSymsp->__Vcoverage[498]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                ++(vlSymsp->__Vcoverage[499]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            ++(vlSymsp->__Vcoverage[505]);
        }
    }
    if (((IData)(vlTOPp->top__DOT__reset) | (2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
        ++(vlSymsp->__Vcoverage[570]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            ++(vlSymsp->__Vcoverage[552]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    ++(vlSymsp->__Vcoverage[533]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        ++(vlSymsp->__Vcoverage[551]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                ++(vlSymsp->__Vcoverage[532]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writew_node) {
                            ++(vlSymsp->__Vcoverage[539]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            ++(vlSymsp->__Vcoverage[548]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if ((3U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                            ++(vlSymsp->__Vcoverage[549]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((0xaU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                ++(vlSymsp->__Vcoverage[542]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((9U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                ++(vlSymsp->__Vcoverage[547]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((6U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                ++(vlSymsp->__Vcoverage[545]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((3U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                ++(vlSymsp->__Vcoverage[540]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((4U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                ++(vlSymsp->__Vcoverage[541]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((0xbU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                ++(vlSymsp->__Vcoverage[543]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((5U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                ++(vlSymsp->__Vcoverage[544]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((7U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                ++(vlSymsp->__Vcoverage[546]);
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__pic__DOT__ram_we_reg) {
        ++(vlSymsp->__Vcoverage[104]);
    }
    if (vlTOPp->top__DOT__pic__DOT__aux_we_reg) {
        ++(vlSymsp->__Vcoverage[130]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if (((0x63U != (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                 & (1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
                ++(vlSymsp->__Vcoverage[506]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if ((1U & (~ ((((0x1fU == (0x1fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 9U))) 
                                        | (7U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                       | (0x1eU == 
                                          (0x1fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 9U)))) 
                                      | (2U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) {
                                ++(vlSymsp->__Vcoverage[537]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (((((0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 9U))) 
                               | (7U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                              | (0x1eU == (0x1fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 9U)))) 
                             | (2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))))) {
                            ++(vlSymsp->__Vcoverage[536]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if ((9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))) {
                            ++(vlSymsp->__Vcoverage[535]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if ((4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xbU)))) {
                            ++(vlSymsp->__Vcoverage[534]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((1U & (~ ((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U))) 
                              | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                    if ((1U & (~ ((0xaU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                  | (0xfU == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                        if ((1U & (~ ((0x1eU == (0x1fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 9U))) 
                                      | (2U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((4U != (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 0xaU)))) {
                                if ((((6U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU))) 
                                      | (7U == (0xfU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 0xaU)))) 
                                     | (5U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU))))) {
                                    ++(vlSymsp->__Vcoverage[529]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((1U & (~ ((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U))) 
                              | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                    if ((1U & (~ ((0xaU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                  | (0xfU == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                        if ((1U & (~ ((0x1eU == (0x1fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 9U))) 
                                      | (2U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((4U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 0xaU)))) {
                                ++(vlSymsp->__Vcoverage[528]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((1U & (~ ((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U))) 
                              | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                    if (((0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U))) 
                         | (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U))))) {
                        ++(vlSymsp->__Vcoverage[526]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((1U & (~ ((((((((((((((((((8U == 
                                               (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                              | (0xeU 
                                                 == 
                                                 (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                             | (7U 
                                                == 
                                                (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                            | (2U == 
                                               (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                                           | (5U == 
                                              (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                          | (4U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                         | (6U == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                        | (3U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                       | (0xaU == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                      | (0xdU == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                     | (0xcU == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (5U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (6U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU)))) 
                                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 0xaU)))) 
                                | (0xbU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                               | (0xfU == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                              | (9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                    if ((1U & (~ (((((((0xcU == (0xfU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 0xaU))) 
                                       | (0x1fU == 
                                          (0x1fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 9U)))) 
                                      | (0x1eU == (0x1fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 9U)))) 
                                     | (0x39U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                    | (0x38U == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                   | (0x3aU == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                                  | (0xdU == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU))))))) {
                        if ((1U & (~ ((3U == (0x7fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U))) 
                                      | (2U == (0x7fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 7U))))))) {
                            ++(vlSymsp->__Vcoverage[524]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if (((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 8U))) | (0xbU 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U))))) {
                    ++(vlSymsp->__Vcoverage[525]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                      | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                     | (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))) {
                    ++(vlSymsp->__Vcoverage[531]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((1U & (~ ((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U))) 
                              | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                    if ((1U & (~ ((0xaU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                  | (0xfU == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                        if (((0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 9U))) 
                             | (2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))))) {
                            ++(vlSymsp->__Vcoverage[527]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((1U & (~ ((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U))) 
                              | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                    if ((1U & (~ ((0xaU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                  | (0xfU == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                        if ((1U & (~ ((0x1eU == (0x1fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 9U))) 
                                      | (2U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((4U != (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 0xaU)))) {
                                if ((1U & (~ (((6U 
                                                == 
                                                (0xfU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 0xaU))) 
                                               | (7U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 0xaU)))) 
                                              | (5U 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 0xaU))))))) {
                                    ++(vlSymsp->__Vcoverage[530]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if (((((((((((((((((((8U == (0x3fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))) 
                                     | (0xeU == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                    | (7U == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                   | (2U == (0x3fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                                  | (5U == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                                 | (4U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                | (6U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                               | (3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                              | (0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                             | (0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                            | (0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                           | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU)))) 
                          | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 0xaU)))) 
                         | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 0xaU)))) 
                        | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                       | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                      | (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 8U)))) 
                     | (9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                        >> 8U))))) {
                    ++(vlSymsp->__Vcoverage[521]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((1U & (~ ((((((((((((((((((8U == 
                                               (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                              | (0xeU 
                                                 == 
                                                 (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                             | (7U 
                                                == 
                                                (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                            | (2U == 
                                               (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                                           | (5U == 
                                              (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                          | (4U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                         | (6U == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                        | (3U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                       | (0xaU == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                      | (0xdU == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                     | (0xcU == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (5U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (6U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU)))) 
                                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 0xaU)))) 
                                | (0xbU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                               | (0xfU == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                              | (9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                    if ((((((((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 0xaU))) 
                              | (0x1fU == (0x1fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 9U)))) 
                             | (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 9U)))) 
                            | (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                           | (0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                          | (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                         | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))) {
                        ++(vlSymsp->__Vcoverage[522]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((1U & (~ ((((((((((((((((((8U == 
                                               (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                              | (0xeU 
                                                 == 
                                                 (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                             | (7U 
                                                == 
                                                (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                            | (2U == 
                                               (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                                           | (5U == 
                                              (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                          | (4U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                         | (6U == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                        | (3U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                       | (0xaU == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                      | (0xdU == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                     | (0xcU == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (5U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (6U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU)))) 
                                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 0xaU)))) 
                                | (0xbU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                               | (0xfU == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                              | (9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                    if ((1U & (~ (((((((0xcU == (0xfU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 0xaU))) 
                                       | (0x1fU == 
                                          (0x1fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 9U)))) 
                                      | (0x1eU == (0x1fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 9U)))) 
                                     | (0x39U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                    | (0x38U == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                   | (0x3aU == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                                  | (0xdU == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU))))))) {
                        if (((3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U))) 
                             | (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 7U))))) {
                            ++(vlSymsp->__Vcoverage[523]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if ((1U & (~ ((((0x1fU == (0x1fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 9U))) 
                                        | (7U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                       | (0x1eU == 
                                          (0x1fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 9U)))) 
                                      | (2U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) {
                                if ((0xcU == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) {
                                    ++(vlSymsp->__Vcoverage[538]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if ((3U != (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                            if (((((((((((((((((0x1fU 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 9U))) 
                                               | (7U 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                              | (0x39U 
                                                 == 
                                                 (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                             | (5U 
                                                == 
                                                (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                            | (3U == 
                                               (0x7fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 7U)))) 
                                           | (2U == 
                                              (0x7fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 7U)))) 
                                          | (9U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                         | (3U == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                        | (0xaU == 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                                       | (8U == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                      | (0x1eU == (0x1fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 9U)))) 
                                     | (2U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (0x3aU == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                   | (6U == (0x3fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                                  | (0x38U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                 | (4U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U))))) {
                                ++(vlSymsp->__Vcoverage[550]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__reset) 
                  | (2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))))) {
        if (((IData)(vlTOPp->top__DOT__pic__DOT__intrise) 
             & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                >> 4U))) {
            ++(vlSymsp->__Vcoverage[571]);
        }
    }
    if (vlTOPp->top__DOT__reset) {
        __Vdly__top__DOT__pic__DOT__exec_stall_reg = 0U;
    } else {
        if ((2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            __Vdly__top__DOT__pic__DOT__exec_stall_reg = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                __Vdly__top__DOT__pic__DOT__exec_stall_reg 
                    = ((IData)(vlTOPp->top__DOT__pic__DOT__next_exec_stall) 
                       & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)));
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                vlTOPp->top__DOT__pic__DOT__aux_re_reg 
                    = ((~ (IData)(vlTOPp->top__DOT__pic__DOT__writeram_node)) 
                       & (8U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))));
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((7U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                vlTOPp->top__DOT__pic__DOT__uart_tx_data 
                                    = vlTOPp->top__DOT__pic__DOT__aluout;
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__uart_sr_ff = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((9U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                vlTOPp->top__DOT__pic__DOT__uart_sr_ff 
                                    = vlTOPp->top__DOT__pic__DOT__aluout;
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__pclath_reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((0xaU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                vlTOPp->top__DOT__pic__DOT__pclath_reg 
                                    = (0x1fU & (IData)(vlTOPp->top__DOT__pic__DOT__aluout));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__pic__DOT__aux_we_reg) {
        __Vdlyvval__top__DOT__aux_ram__v0 = vlTOPp->top__DOT__aux_data;
        __Vdlyvset__top__DOT__aux_ram__v0 = 1U;
        __Vdlyvdim0__top__DOT__aux_ram__v0 = vlTOPp->top__DOT__aux_addr;
    }
    if (vlTOPp->top__DOT__pic__DOT__ram_we_reg) {
        __Vdlyvval__top__DOT__ram__v0 = vlTOPp->top__DOT__pic__DOT__aluout;
        __Vdlyvset__top__DOT__ram__v0 = 1U;
        __Vdlyvdim0__top__DOT__ram__v0 = vlTOPp->top__DOT__pic__DOT__ram_adr_node;
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((6U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg 
                                    = vlTOPp->top__DOT__pic__DOT__aluout;
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((5U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg 
                                    = vlTOPp->top__DOT__pic__DOT__aluout;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((4U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                vlTOPp->top__DOT__pic__DOT__fsr_reg 
                                    = vlTOPp->top__DOT__pic__DOT__aluout;
                            }
                        }
                    }
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__reset) | (2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
        vlTOPp->top__DOT__pic__DOT__inte_sync_reg = 0U;
    } else {
        if (((IData)(vlTOPp->top__DOT__pic__DOT__intrise) 
             & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                >> 4U))) {
            vlTOPp->top__DOT__pic__DOT__inte_sync_reg = 1U;
        }
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__status_reg = (0x1fU 
                                                  & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg));
        vlTOPp->top__DOT__pic__DOT__status_reg = (0x10U 
                                                  | (IData)(vlTOPp->top__DOT__pic__DOT__status_reg));
        vlTOPp->top__DOT__pic__DOT__status_reg = (8U 
                                                  | (IData)(vlTOPp->top__DOT__pic__DOT__status_reg));
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (((((0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 9U))) 
                               | (7U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                              | (0x1eU == (0x1fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 9U)))) 
                             | (2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))))) {
                            vlTOPp->top__DOT__pic__DOT__status_reg 
                                = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)) 
                                   | (2U & ((0x1ffffffeU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
                                                >> 3U)) 
                                            | ((IData)(vlTOPp->top__DOT__pic__DOT__c_dig_subtract_zero) 
                                               << 1U))));
                            vlTOPp->top__DOT__pic__DOT__status_reg 
                                = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)) 
                                   | (1U & (((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                                             >> 8U) 
                                            | (IData)(vlTOPp->top__DOT__pic__DOT__c_subtract_zero))));
                        } else {
                            if ((0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) {
                                vlTOPp->top__DOT__pic__DOT__status_reg 
                                    = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)) 
                                       | (1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                >> 7U)));
                            } else {
                                if ((0xcU == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) {
                                    vlTOPp->top__DOT__pic__DOT__status_reg 
                                        = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)) 
                                           | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
                                }
                            }
                        }
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((3U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                vlTOPp->top__DOT__pic__DOT__status_reg 
                                    = ((0x1fU & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)) 
                                       | (0xe0U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
                                vlTOPp->top__DOT__pic__DOT__status_reg 
                                    = ((0xfcU & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)) 
                                       | (3U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
                            }
                        }
                        if ((3U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                            vlTOPp->top__DOT__pic__DOT__status_reg 
                                = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)) 
                                   | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
                        } else {
                            if (((((((((((((((((0x1fU 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 9U))) 
                                               | (7U 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                              | (0x39U 
                                                 == 
                                                 (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                             | (5U 
                                                == 
                                                (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                            | (3U == 
                                               (0x7fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 7U)))) 
                                           | (2U == 
                                              (0x7fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 7U)))) 
                                          | (9U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                         | (3U == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                        | (0xaU == 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                                       | (8U == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                      | (0x1eU == (0x1fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 9U)))) 
                                     | (2U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (0x3aU == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                   | (6U == (0x3fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                                  | (0x38U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                 | (4U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U))))) {
                                vlTOPp->top__DOT__pic__DOT__status_reg 
                                    = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)) 
                                       | (((0U == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                                            ? 1U : 0U) 
                                          << 2U));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__reset) {
        __Vdly__top__DOT__pic__DOT__stack_pnt_reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                      | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                     | (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))) {
                    __Vdly__top__DOT__pic__DOT__stack_pnt_reg 
                        = (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg) 
                                 - (IData)(1U)));
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    __Vdlyvval__top__DOT__pic__DOT__stack_reg__v0 
                        = vlTOPp->top__DOT__pic__DOT__old_pc_reg;
                    __Vdlyvset__top__DOT__pic__DOT__stack_reg__v0 = 1U;
                    __Vdlyvdim0__top__DOT__pic__DOT__stack_reg__v0 
                        = vlTOPp->top__DOT__pic__DOT__stack_pnt_reg;
                    __Vdly__top__DOT__pic__DOT__stack_pnt_reg 
                        = (7U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg)));
                } else {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if ((4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xbU)))) {
                            __Vdlyvval__top__DOT__pic__DOT__stack_reg__v1 
                                = vlTOPp->top__DOT__pic__DOT__pc_reg;
                            __Vdlyvset__top__DOT__pic__DOT__stack_reg__v1 = 1U;
                            __Vdlyvdim0__top__DOT__pic__DOT__stack_reg__v1 
                                = vlTOPp->top__DOT__pic__DOT__stack_pnt_reg;
                            __Vdly__top__DOT__pic__DOT__stack_pnt_reg 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg)));
                        }
                    }
                }
            }
        }
    }
    if (__Vdlyvset__top__DOT__aux_ram__v0) {
        vlTOPp->top__DOT__aux_ram[__Vdlyvdim0__top__DOT__aux_ram__v0] 
            = __Vdlyvval__top__DOT__aux_ram__v0;
    }
    if (__Vdlyvset__top__DOT__ram__v0) {
        vlTOPp->top__DOT__ram[__Vdlyvdim0__top__DOT__ram__v0] 
            = __Vdlyvval__top__DOT__ram__v0;
    }
    vlTOPp->top__DOT__pic__DOT__stack_pnt_reg = __Vdly__top__DOT__pic__DOT__stack_pnt_reg;
    if (__Vdlyvset__top__DOT__pic__DOT__stack_reg__v0) {
        vlTOPp->top__DOT__pic__DOT__stack_reg[__Vdlyvdim0__top__DOT__pic__DOT__stack_reg__v0] 
            = __Vdlyvval__top__DOT__pic__DOT__stack_reg__v0;
    }
    if (__Vdlyvset__top__DOT__pic__DOT__stack_reg__v1) {
        vlTOPp->top__DOT__pic__DOT__stack_reg[__Vdlyvdim0__top__DOT__pic__DOT__stack_reg__v1] 
            = __Vdlyvval__top__DOT__pic__DOT__stack_reg__v1;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__aux_re_reg) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_re_reg)) {
        ++(vlSymsp->__Vcoverage[402]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_re_reg 
            = vlTOPp->top__DOT__pic__DOT__aux_re_reg;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[463]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[464]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[465]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[466]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[467]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[468]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[469]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data))) {
        ++(vlSymsp->__Vcoverage[470]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_tx_data)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data)));
    }
    if ((1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 7U) ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tvalid))) {
        ++(vlSymsp->__Vcoverage[572]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tvalid 
            = (1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                     >> 7U));
    }
    if ((1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 6U) ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tready))) {
        ++(vlSymsp->__Vcoverage[575]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tready 
            = (1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                     >> 6U));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[471]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[472]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[473]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[474]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[475]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[476]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[477]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff))) {
        ++(vlSymsp->__Vcoverage[478]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_ff)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0x1eU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0x1dU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0x1bU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0x17U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg 
            = ((0xfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__pclath_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)));
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                vlTOPp->top__DOT__pic__DOT__aux_we_reg 
                    = ((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
                       & (8U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))));
            } else {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        vlTOPp->top__DOT__pic__DOT__aux_we_reg = 0U;
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__ram_we_reg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                vlTOPp->top__DOT__pic__DOT__ram_we_reg 
                    = ((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
                       & (0xbU < (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))));
            } else {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        vlTOPp->top__DOT__pic__DOT__ram_we_reg = 0U;
                    }
                }
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)));
    }
    vlTOPp->top__DOT__aux_addr = (((IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg) 
                                   << 8U) | (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__fsr_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__inte_sync_reg) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inte_sync_reg)) {
        ++(vlSymsp->__Vcoverage[355]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inte_sync_reg 
            = vlTOPp->top__DOT__pic__DOT__inte_sync_reg;
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__intcon_reg = (1U 
                                                  & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg));
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    vlTOPp->top__DOT__pic__DOT__intcon_reg 
                        = (2U | (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg));
                    vlTOPp->top__DOT__pic__DOT__intcon_reg 
                        = (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg));
                } else {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if ((9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))) {
                            vlTOPp->top__DOT__pic__DOT__intcon_reg 
                                = (0x80U | (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg));
                        }
                        if (vlTOPp->top__DOT__pic__DOT__writeram_node) {
                            if ((0xbU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))) {
                                vlTOPp->top__DOT__pic__DOT__intcon_reg 
                                    = vlTOPp->top__DOT__pic__DOT__aluout;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__status_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)));
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                vlTOPp->top__DOT__pic__DOT__aluinp1_reg 
                    = (0xffU & (((((((((((((((((((8U 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U))) 
                                                 | (0xeU 
                                                    == 
                                                    (0x3fU 
                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                        >> 8U)))) 
                                                | (7U 
                                                   == 
                                                   (0x3fU 
                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                       >> 8U)))) 
                                               | (2U 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                              | (5U 
                                                 == 
                                                 (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                             | (4U 
                                                == 
                                                (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U)))) 
                                            | (6U == 
                                               (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                                           | (3U == 
                                              (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                          | (0xaU == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                         | (0xdU == 
                                            (0x3fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                                        | (0xcU == 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                                       | (4U == (0xfU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 0xaU)))) 
                                      | (5U == (0xfU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 0xaU)))) 
                                     | (6U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU)))) 
                                    | (7U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (0xbU == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                  | (0xfU == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                 | (9U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U))))
                                 ? (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)
                                 : ((((((((0xcU == 
                                           (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))) 
                                          | (0x1fU 
                                             == (0x1fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 9U)))) 
                                         | (0x1eU == 
                                            (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 9U)))) 
                                        | (0x39U == 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                                       | (0x38U == 
                                          (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                      | (0x3aU == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                     | (0xdU == (0xfU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 0xaU))))
                                     ? (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)
                                     : (((3U == (0x7fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 7U))) 
                                         | (2U == (0x7fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 7U))))
                                         ? 0U : (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)))));
                vlTOPp->top__DOT__pic__DOT__c_subtract_zero = 0U;
                vlTOPp->top__DOT__pic__DOT__c_dig_subtract_zero = 0U;
                if (((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 8U))) | (0xbU 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U))))) {
                    vlTOPp->top__DOT__pic__DOT__aluinp2_reg = 0xffU;
                } else {
                    if (((0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U))) 
                         | (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U))))) {
                        vlTOPp->top__DOT__pic__DOT__aluinp2_reg = 1U;
                    } else {
                        if (((0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 9U))) 
                             | (2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))))) {
                            vlTOPp->top__DOT__pic__DOT__aluinp2_reg 
                                = (0xffU & ((IData)(1U) 
                                            + (~ (IData)(vlTOPp->top__DOT__pic__DOT__w_reg))));
                            vlTOPp->top__DOT__pic__DOT__c_subtract_zero 
                                = (0U == (IData)(vlTOPp->top__DOT__pic__DOT__w_reg));
                            vlTOPp->top__DOT__pic__DOT__c_dig_subtract_zero 
                                = (0U == (0xfU & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
                        } else {
                            vlTOPp->top__DOT__pic__DOT__aluinp2_reg 
                                = (0xffU & ((4U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))
                                             ? (~ ((IData)(1U) 
                                                   << 
                                                   (7U 
                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                       >> 7U))))
                                             : ((((6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                       >> 0xaU))) 
                                                  | (7U 
                                                     == 
                                                     (0xfU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 0xaU)))) 
                                                 | (5U 
                                                    == 
                                                    (0xfU 
                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                        >> 0xaU))))
                                                 ? 
                                                ((IData)(1U) 
                                                 << 
                                                 (7U 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 7U)))
                                                 : (IData)(vlTOPp->top__DOT__pic__DOT__w_reg))));
                        }
                    }
                }
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg))) {
        ++(vlSymsp->__Vcoverage[336]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg 
            = ((6U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg))) {
        ++(vlSymsp->__Vcoverage[337]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg 
            = ((5U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg))) {
        ++(vlSymsp->__Vcoverage[338]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg 
            = ((3U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_pnt_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_pnt_reg)));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [0U]))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [0U]))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [0U]))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [0U]))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [0U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[0U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [0U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [0U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [1U]))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [1U]))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [1U]))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [1U]))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [1U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[1U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [1U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [1U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [2U]))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [2U]))) {
        ++(vlSymsp->__Vcoverage[259]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [2U]))) {
        ++(vlSymsp->__Vcoverage[260]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [2U]))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [2U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [2U]))) {
        ++(vlSymsp->__Vcoverage[270]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[2U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [2U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [2U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [3U]))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [3U]))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [3U]))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [3U]))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [3U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [3U]))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[3U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [3U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [3U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [4U]))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [4U]))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [4U]))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [4U]))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[293]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[294]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[295]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [4U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [4U]))) {
        ++(vlSymsp->__Vcoverage[296]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[4U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [4U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [4U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [5U]))) {
        ++(vlSymsp->__Vcoverage[297]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [5U]))) {
        ++(vlSymsp->__Vcoverage[298]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [5U]))) {
        ++(vlSymsp->__Vcoverage[299]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [5U]))) {
        ++(vlSymsp->__Vcoverage[300]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[301]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[302]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[303]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[304]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[305]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[306]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[307]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[308]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [5U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [5U]))) {
        ++(vlSymsp->__Vcoverage[309]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[5U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [5U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [5U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [6U]))) {
        ++(vlSymsp->__Vcoverage[310]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [6U]))) {
        ++(vlSymsp->__Vcoverage[311]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [6U]))) {
        ++(vlSymsp->__Vcoverage[312]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [6U]))) {
        ++(vlSymsp->__Vcoverage[313]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[314]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[315]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[316]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[317]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[318]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[319]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[320]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[321]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [6U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [6U]))) {
        ++(vlSymsp->__Vcoverage[322]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[6U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [6U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [6U]));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [7U]))) {
        ++(vlSymsp->__Vcoverage[323]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1ffeU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (1U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [7U]))) {
        ++(vlSymsp->__Vcoverage[324]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1ffdU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (2U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [7U]))) {
        ++(vlSymsp->__Vcoverage[325]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1ffbU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (4U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__stack_reg
               [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
               [7U]))) {
        ++(vlSymsp->__Vcoverage[326]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1ff7U & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (8U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[327]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1fefU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x10U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[328]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1fdfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x20U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[329]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1fbfU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x40U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                  [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[330]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1f7fU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x80U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[331]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1effU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x100U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[332]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1dffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x200U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[333]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x1bffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x400U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                   [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[334]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0x17ffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x800U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__stack_reg
                    [7U] ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                    [7U]))) {
        ++(vlSymsp->__Vcoverage[335]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg[7U] 
            = ((0xfffU & vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_reg
                [7U]) | (0x1000U & vlTOPp->top__DOT__pic__DOT__stack_reg
                         [7U]));
    }
    vlTOPp->top__DOT__pic__DOT__stack_top = vlTOPp->top__DOT__pic__DOT__stack_reg
        [vlTOPp->top__DOT__pic__DOT__stack_pnt_reg];
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__old_pc_reg = 0U;
    } else {
        if ((2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            vlTOPp->top__DOT__pic__DOT__old_pc_reg 
                = vlTOPp->top__DOT__pic__DOT__pc_reg;
        } else {
            if (((0x63U != (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                 & (1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
                vlTOPp->top__DOT__pic__DOT__old_pc_reg 
                    = vlTOPp->top__DOT__pic__DOT__pc_reg;
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__aux_addr) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfffeU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__aux_addr) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfffdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__aux_addr) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfffbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__aux_addr) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfff7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xffefU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xffdfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xffbfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xff7fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                   ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfeffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x100U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                   ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfdffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x200U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                   ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xfbffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                   ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xf7ffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x800U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                    ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xefffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x1000U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x2000U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                    ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xdfffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x2000U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x4000U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                    ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0xbfffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x4000U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((0x8000U & ((IData)(vlTOPp->top__DOT__aux_addr) 
                    ^ vlTOPp->top__DOT____Vtogcov__aux_addr))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->top__DOT____Vtogcov__aux_addr = ((0x7fffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_addr)) 
                                                 | (0x8000U 
                                                    & (IData)(vlTOPp->top__DOT__aux_addr)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[339]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1ffeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[340]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1ffdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[341]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1ffbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[342]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1ff7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[343]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1fefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[344]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1fdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[345]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1fbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[346]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1f7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[347]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1effU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[348]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1dffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x200U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[349]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x1bffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x400U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[350]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0x17ffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x800U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__stack_top) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top))) {
        ++(vlSymsp->__Vcoverage[351]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top 
            = ((0xfffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__stack_top)) 
               | (0x1000U & (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg) 
         ^ vlTOPp->top__DOT____Vtogcov__aux_wr_stb)) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->top__DOT____Vtogcov__aux_wr_stb = vlTOPp->top__DOT__pic__DOT__aux_we_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__ram_we_reg) 
         ^ vlTOPp->top__DOT____Vtogcov__ram_we)) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->top__DOT____Vtogcov__ram_we = vlTOPp->top__DOT__pic__DOT__ram_we_reg;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__intcon_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__c_subtract_zero) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__c_subtract_zero)) {
        ++(vlSymsp->__Vcoverage[449]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__c_subtract_zero 
            = vlTOPp->top__DOT__pic__DOT__c_subtract_zero;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__c_dig_subtract_zero) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__c_dig_subtract_zero)) {
        ++(vlSymsp->__Vcoverage[450]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__c_dig_subtract_zero 
            = vlTOPp->top__DOT__pic__DOT__c_dig_subtract_zero;
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)))) {
            if ((0U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                if ((2U != (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                    if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
                        if (vlTOPp->top__DOT__pic__DOT__writew_node) {
                            vlTOPp->top__DOT__pic__DOT__w_reg 
                                = vlTOPp->top__DOT__pic__DOT__aluout;
                        }
                    }
                }
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp1_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__aluinp2_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    }
    vlTOPp->top__DOT__pic__DOT__addlow_node = (0x1fU 
                                               & ((0xfU 
                                                   & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg)) 
                                                  + 
                                                  (0xfU 
                                                   & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg))));
    vlTOPp->top__DOT__pic__DOT__add_node = (0x1ffU 
                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                               + (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg)));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1ffeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1ffdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1ffbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1ff7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1fefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1fdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1fbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1f7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1effU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1dffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x200U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x1bffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x400U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0x17ffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x800U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg 
            = ((0xfffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__old_pc_reg)) 
               | (0x1000U & (IData)(vlTOPp->top__DOT__pic__DOT__old_pc_reg)));
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__pc_reg = 0U;
    } else {
        if ((2U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            vlTOPp->top__DOT__pic__DOT__pc_reg = 4U;
        } else {
            if (((0x63U != (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                 & (1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
                vlTOPp->top__DOT__pic__DOT__pc_reg 
                    = vlTOPp->top__DOT__pic__DOT__next_pc_node;
            }
        }
    }
    vlTOPp->top__DOT__pic__DOT__exec_stall_reg = __Vdly__top__DOT__pic__DOT__exec_stall_reg;
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[428]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0x1eU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[429]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0x1dU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[430]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0x1bU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[431]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0x17U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__addlow_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node))) {
        ++(vlSymsp->__Vcoverage[432]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node 
            = ((0xfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__addlow_node)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__addlow_node)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[419]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1feU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[420]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1fdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[421]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1fbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[422]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1f7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[423]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1efU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[424]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1dfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[425]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x1bfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[426]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0x17fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__add_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node))) {
        ++(vlSymsp->__Vcoverage[427]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node 
            = ((0xffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__add_node)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__add_node)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__w_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__w_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__w_reg)));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__exec_stall_reg)) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__exec_stall_reg 
            = vlTOPp->top__DOT__pic__DOT__exec_stall_reg;
    }
    vlTOPp->top__DOT__pic__DOT__int_condition = (((IData)(vlTOPp->top__DOT__pic__DOT__inte_sync_reg) 
                                                  & (~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg))) 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg) 
                                                    >> 7U));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1ffeU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1ffdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1ffbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1ff7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1fefU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1fdfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1fbfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1f7fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1effU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x100U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1dffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x200U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x1bffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0x17ffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x800U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__pc_reg) 
                    ^ vlTOPp->top__DOT____Vtogcov__rom_addr))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->top__DOT____Vtogcov__rom_addr = ((0xfffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_addr)) 
                                                 | (0x1000U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)));
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__pic__DOT__inst_reg = 0U;
    } else {
        if ((1U == (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            vlTOPp->top__DOT__pic__DOT__inst_reg = vlTOPp->top__DOT__rom_data;
        }
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__int_condition) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__int_condition)) {
        ++(vlSymsp->__Vcoverage[352]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__int_condition 
            = vlTOPp->top__DOT__pic__DOT__int_condition;
    }
    vlTOPp->top__DOT__rom_data = vlTOPp->top__DOT__rom
        [vlTOPp->top__DOT__pic__DOT__pc_reg];
    vlTOPp->top__DOT__pic__DOT__state_reg = ((IData)(vlTOPp->top__DOT__reset)
                                              ? 0U : (IData)(vlTOPp->top__DOT__pic__DOT__next_state_node));
    if ((1U & ((IData)(vlTOPp->top__DOT__rom_data) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3ffeU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__rom_data) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3ffdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__rom_data) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3ffbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__rom_data) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3ff7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__rom_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3fefU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__rom_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3fdfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__rom_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3fbfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__rom_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3f7fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__rom_data) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3effU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x100U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__rom_data) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3dffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x200U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__rom_data) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3bffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__rom_data) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x37ffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x800U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__rom_data) 
                    ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x2fffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x1000U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x2000U & ((IData)(vlTOPp->top__DOT__rom_data) 
                    ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x1fffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x2000U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if (((((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 7U))) | (4U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU)))) 
          | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 0xaU)))) | (3U == (0x7fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 7U))))) {
        ++(vlSymsp->__Vcoverage[507]);
    }
    if ((1U & (~ ((((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 7U))) | (4U 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 0xaU)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 0xaU)))) | 
                  (3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 7U))))))) {
        if ((1U & (~ ((((((((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU))) 
                            | (0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 9U)))) 
                           | (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 9U)))) 
                          | (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                         | (0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U)))) 
                        | (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U)))) 
                       | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 0xaU)))) 
                      | (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))))))) {
            if (((((((((((((((8U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U))) 
                             | (0xeU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                            | (7U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U)))) 
                           | (2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U)))) 
                          | (5U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                         | (4U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                        | (6U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 8U)))) 
                       | (3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 8U)))) 
                      | (0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 8U)))) 
                     | (0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 8U)))) 
                    | (0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 8U)))) 
                   | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                        >> 8U)))) | 
                  (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) | (9U 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U))))) {
                ++(vlSymsp->__Vcoverage[509]);
            }
        }
    }
    if ((1U & (~ ((((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 7U))) | (4U 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 0xaU)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 0xaU)))) | 
                  (3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 7U))))))) {
        if (((((((((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 0xaU))) | (0x1fU 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                       >> 9U)))) 
                  | (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                        >> 9U)))) | 
                 (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) | (0x38U 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
               | (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) | (0xdU 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 0xaU)))) 
             | (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                >> 7U))))) {
            ++(vlSymsp->__Vcoverage[508]);
        }
    }
    if ((1U & (~ ((((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 7U))) | (4U 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 0xaU)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 0xaU)))) | 
                  (3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 7U))))))) {
        if ((1U & (~ ((((((((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU))) 
                            | (0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 9U)))) 
                           | (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 9U)))) 
                          | (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                         | (0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U)))) 
                        | (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 8U)))) 
                       | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 0xaU)))) 
                      | (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))))))) {
            if ((1U & (~ ((((((((((((((8U == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))) 
                                      | (0xeU == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                     | (7U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (2U == (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                                   | (5U == (0x3fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                                  | (4U == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U)))) 
                                 | (6U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                | (3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                               | (0xaU == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                              | (0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U)))) 
                             | (0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                            | (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U)))) 
                           | (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U)))) 
                          | (9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))))))) {
                ++(vlSymsp->__Vcoverage[510]);
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((((((0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))) 
                            | (5U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                               >> 8U)))) 
                           | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU)))) 
                          | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 0xaU)))) 
                         | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                           >> 0xaU))))) {
                        ++(vlSymsp->__Vcoverage[515]);
                    }
                }
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((1U & (~ (((((0x39U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                     | (5U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (6U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (7U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))))) {
                        if ((1U & (~ (((5U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU))) 
                                       | (0x38U == 
                                          (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                      | (4U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((1U & (~ ((0x3aU == 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                          | (6U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                                if (((((((((0x1fU == 
                                            (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 9U))) 
                                           | (7U == 
                                              (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                          | (0x1eU 
                                             == (0x1fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 9U)))) 
                                         | (2U == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                        | (3U == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                       | (0xbU == (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                      | (0xaU == (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U)))) 
                                     | (0xfU == (0x3fU 
                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                    >> 8U))))) {
                                    ++(vlSymsp->__Vcoverage[518]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((1U & (~ (((((0x39U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                     | (5U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (6U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (7U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))))) {
                        if ((1U & (~ (((5U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU))) 
                                       | (0x38U == 
                                          (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                      | (4U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if (((0x3aU == (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                 | (6U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U))))) {
                                ++(vlSymsp->__Vcoverage[517]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                ++(vlSymsp->__Vcoverage[513]);
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    ++(vlSymsp->__Vcoverage[514]);
                }
            }
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            ++(vlSymsp->__Vcoverage[512]);
        }
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((1U & (~ (((((0x39U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                     | (5U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (6U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (7U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))))) {
                        if ((((5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU))) 
                              | (0x38U == (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                             | (4U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                >> 8U))))) {
                            ++(vlSymsp->__Vcoverage[516]);
                        }
                    }
                }
            }
        }
    }
    if ((0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        ++(vlSymsp->__Vcoverage[511]);
    }
    if ((0xdU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 8U)))) {
        if ((0xcU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)))) {
            if ((0xeU != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                   >> 8U)))) {
                if ((9U != (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                     >> 8U)))) {
                    if ((1U & (~ (((((0x39U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))) 
                                     | (5U == (0x3fU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 8U)))) 
                                    | (4U == (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 0xaU)))) 
                                   | (6U == (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 0xaU)))) 
                                  | (7U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 0xaU))))))) {
                        if ((1U & (~ (((5U == (0xfU 
                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                  >> 0xaU))) 
                                       | (0x38U == 
                                          (0x3fU & 
                                           ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                            >> 8U)))) 
                                      | (4U == (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                   >> 8U))))))) {
                            if ((1U & (~ ((0x3aU == 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                             >> 8U))) 
                                          | (6U == 
                                             (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 8U))))))) {
                                if ((1U & (~ ((((((
                                                   ((0x1fU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 9U))) 
                                                    | (7U 
                                                       == 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 8U)))) 
                                                   | (0x1eU 
                                                      == 
                                                      (0x1fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 9U)))) 
                                                  | (2U 
                                                     == 
                                                     (0x3fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 8U)))) 
                                                 | (3U 
                                                    == 
                                                    (0x3fU 
                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                        >> 8U)))) 
                                                | (0xbU 
                                                   == 
                                                   (0x3fU 
                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                       >> 8U)))) 
                                               | (0xaU 
                                                  == 
                                                  (0x3fU 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 8U)))) 
                                              | (0xfU 
                                                 == 
                                                 (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                     >> 8U))))))) {
                                    ++(vlSymsp->__Vcoverage[519]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
         & (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
             | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 0xaU)))) | (9U 
                                                == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))) {
        ++(vlSymsp->__Vcoverage[500]);
    }
    if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                  & (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                      | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                     | (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))))) {
        if (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
             & ((5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xbU))) | (4U == (7U 
                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                      >> 0xbU)))))) {
            ++(vlSymsp->__Vcoverage[501]);
        }
    }
    if (((0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 9U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_addlw)) {
        ++(vlSymsp->__Vcoverage[360]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_addlw 
            = (0x1fU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 9U)));
    }
    if (((7U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_addwf)) {
        ++(vlSymsp->__Vcoverage[361]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_addwf 
            = (7U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_andlw)) {
        ++(vlSymsp->__Vcoverage[362]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_andlw 
            = (0x39U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 8U)));
    }
    if (((5U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_andwf)) {
        ++(vlSymsp->__Vcoverage[363]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_andwf 
            = (5U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((4U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                         >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_bcf)) {
        ++(vlSymsp->__Vcoverage[364]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_bcf 
            = (4U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xaU)));
    }
    if (((5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                         >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_bsf)) {
        ++(vlSymsp->__Vcoverage[365]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_bsf 
            = (5U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xaU)));
    }
    if (((6U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                         >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_btfsc)) {
        ++(vlSymsp->__Vcoverage[366]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_btfsc 
            = (6U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xaU)));
    }
    if (((7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                         >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_btfss)) {
        ++(vlSymsp->__Vcoverage[367]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_btfss 
            = (7U == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                              >> 0xaU)));
    }
    if (((4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                       >> 0xbU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_call)) {
        ++(vlSymsp->__Vcoverage[368]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_call 
            = (4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 0xbU)));
    }
    if (((3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_clrf)) {
        ++(vlSymsp->__Vcoverage[369]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_clrf 
            = (3U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 7U)));
    }
    if (((2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_clrw)) {
        ++(vlSymsp->__Vcoverage[370]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_clrw 
            = (2U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 7U)));
    }
    if (((9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_comf)) {
        ++(vlSymsp->__Vcoverage[371]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_comf 
            = (9U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_decf)) {
        ++(vlSymsp->__Vcoverage[372]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_decf 
            = (3U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_decfsz)) {
        ++(vlSymsp->__Vcoverage[373]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_decfsz 
            = (0xbU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                       >> 0xbU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_goto)) {
        ++(vlSymsp->__Vcoverage[374]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_goto 
            = (5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 0xbU)));
    }
    if (((0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_incf)) {
        ++(vlSymsp->__Vcoverage[375]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_incf 
            = (0xaU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_incfsz)) {
        ++(vlSymsp->__Vcoverage[376]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_incfsz 
            = (0xfU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_iorlw)) {
        ++(vlSymsp->__Vcoverage[377]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_iorlw 
            = (0x38U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 8U)));
    }
    if (((4U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_iorwf)) {
        ++(vlSymsp->__Vcoverage[378]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_iorwf 
            = (4U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movlw)) {
        ++(vlSymsp->__Vcoverage[379]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movlw 
            = (0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                >> 0xaU)));
    }
    if (((8U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movf)) {
        ++(vlSymsp->__Vcoverage[380]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movf 
            = (8U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movwf)) {
        ++(vlSymsp->__Vcoverage[381]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_movwf 
            = (1U == (0x7fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 7U)));
    }
    if (((9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_retfie)) {
        ++(vlSymsp->__Vcoverage[382]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_retfie 
            = (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg));
    }
    if (((0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                           >> 0xaU))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_retlw)) {
        ++(vlSymsp->__Vcoverage[383]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_retlw 
            = (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                >> 0xaU)));
    }
    if (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_ret)) {
        ++(vlSymsp->__Vcoverage[384]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_ret 
            = (8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg));
    }
    if (((0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_rlf)) {
        ++(vlSymsp->__Vcoverage[385]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_rlf 
            = (0xdU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_rrf)) {
        ++(vlSymsp->__Vcoverage[386]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_rrf 
            = (0xcU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0x63U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_sleep)) {
        ++(vlSymsp->__Vcoverage[387]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_sleep 
            = (0x63U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg));
    }
    if (((0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 9U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_sublw)) {
        ++(vlSymsp->__Vcoverage[388]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_sublw 
            = (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 9U)));
    }
    if (((2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_subwf)) {
        ++(vlSymsp->__Vcoverage[389]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_subwf 
            = (2U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    if (((0xeU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                            >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_swapf)) {
        ++(vlSymsp->__Vcoverage[390]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_swapf 
            = (0xeU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                 >> 8U)));
    }
    if (((0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                             >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_xorlw)) {
        ++(vlSymsp->__Vcoverage[391]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_xorlw 
            = (0x3aU == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                  >> 8U)));
    }
    if (((6U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                          >> 8U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_xorwf)) {
        ++(vlSymsp->__Vcoverage[392]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_xorwf 
            = (6U == (0x3fU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                               >> 8U)));
    }
    vlTOPp->top__DOT__pic__DOT__writew_node = ((~ (
                                                   (((1U 
                                                      == 
                                                      (0x7fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 7U))) 
                                                     | (4U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                            >> 0xaU)))) 
                                                    | (5U 
                                                       == 
                                                       (0xfU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 0xaU)))) 
                                                   | (3U 
                                                      == 
                                                      (0x7fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 7U))))) 
                                               & (((((((((0xcU 
                                                          == 
                                                          (0xfU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 0xaU))) 
                                                         | (0x1fU 
                                                            == 
                                                            (0x1fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 9U)))) 
                                                        | (0x1eU 
                                                           == 
                                                           (0x1fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 9U)))) 
                                                       | (0x39U 
                                                          == 
                                                          (0x3fU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 8U)))) 
                                                      | (0x38U 
                                                         == 
                                                         (0x3fU 
                                                          & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                             >> 8U)))) 
                                                     | (0x3aU 
                                                        == 
                                                        (0x3fU 
                                                         & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                            >> 8U)))) 
                                                    | (0xdU 
                                                       == 
                                                       (0xfU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 0xaU)))) 
                                                   | (2U 
                                                      == 
                                                      (0x7fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 7U)))) 
                                                  | (((((((((((((((8U 
                                                                   == 
                                                                   (0x3fU 
                                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                       >> 8U))) 
                                                                  | (0xeU 
                                                                     == 
                                                                     (0x3fU 
                                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                         >> 8U)))) 
                                                                 | (7U 
                                                                    == 
                                                                    (0x3fU 
                                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                        >> 8U)))) 
                                                                | (2U 
                                                                   == 
                                                                   (0x3fU 
                                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                       >> 8U)))) 
                                                               | (5U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                      >> 8U)))) 
                                                              | (4U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                     >> 8U)))) 
                                                             | (6U 
                                                                == 
                                                                (0x3fU 
                                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                    >> 8U)))) 
                                                            | (3U 
                                                               == 
                                                               (0x3fU 
                                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                   >> 8U)))) 
                                                           | (0xaU 
                                                              == 
                                                              (0x3fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 8U)))) 
                                                          | (0xdU 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (0xcU 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U)))) 
                                                        | (0xbU 
                                                           == 
                                                           (0x3fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 8U)))) 
                                                       | (0xfU 
                                                          == 
                                                          (0x3fU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 8U)))) 
                                                      | (9U 
                                                         == 
                                                         (0x3fU 
                                                          & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                             >> 8U)))) 
                                                     & (~ 
                                                        ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 7U)))));
    if ((1U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[411]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (1U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U)))));
    }
    if ((2U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[412]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (2U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U)))));
    }
    if ((4U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[413]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (4U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U)))));
    }
    if ((8U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                      >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[414]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (8U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                              >> 7U)))));
    }
    if ((0x10U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[415]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (0x10U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U)))));
    }
    if ((0x20U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[416]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (0x20U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U)))));
    }
    if ((0x40U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[417]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (0x40U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U)))));
    }
    if ((0x80U & (((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                         >> 7U))) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node))) {
        ++(vlSymsp->__Vcoverage[418]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__mask_node)) 
               | (0x80U & ((IData)(1U) << (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                 >> 7U)))));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3ffeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3ffdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3ffbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3ff7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3fefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3fdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3fbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3f7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3effU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3dffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x200U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x3bffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x400U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x37ffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x800U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x2fffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x1000U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    if ((0x2000U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg 
            = ((0x1fffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__inst_reg)) 
               | (0x2000U & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)));
    }
    vlTOPp->top__DOT__pic__DOT__writeram_node = (((
                                                   ((1U 
                                                     == 
                                                     (0x7fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 7U))) 
                                                    | (4U 
                                                       == 
                                                       (0xfU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 0xaU)))) 
                                                   | (5U 
                                                      == 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 0xaU)))) 
                                                  | (3U 
                                                     == 
                                                     (0x7fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 7U)))) 
                                                 | ((~ 
                                                     ((((((((0xcU 
                                                             == 
                                                             (0xfU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 0xaU))) 
                                                            | (0x1fU 
                                                               == 
                                                               (0x1fU 
                                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                   >> 9U)))) 
                                                           | (0x1eU 
                                                              == 
                                                              (0x1fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 9U)))) 
                                                          | (0x39U 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (0x38U 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U)))) 
                                                        | (0x3aU 
                                                           == 
                                                           (0x3fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 8U)))) 
                                                       | (0xdU 
                                                          == 
                                                          (0xfU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 0xaU)))) 
                                                      | (2U 
                                                         == 
                                                         (0x7fU 
                                                          & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                             >> 7U))))) 
                                                    & (((((((((((((((8U 
                                                                     == 
                                                                     (0x3fU 
                                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                         >> 8U))) 
                                                                    | (0xeU 
                                                                       == 
                                                                       (0x3fU 
                                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                           >> 8U)))) 
                                                                   | (7U 
                                                                      == 
                                                                      (0x3fU 
                                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                          >> 8U)))) 
                                                                  | (2U 
                                                                     == 
                                                                     (0x3fU 
                                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                         >> 8U)))) 
                                                                 | (5U 
                                                                    == 
                                                                    (0x3fU 
                                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                        >> 8U)))) 
                                                                | (4U 
                                                                   == 
                                                                   (0x3fU 
                                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                       >> 8U)))) 
                                                               | (6U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                      >> 8U)))) 
                                                              | (3U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                     >> 8U)))) 
                                                             | (0xaU 
                                                                == 
                                                                (0x3fU 
                                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                    >> 8U)))) 
                                                            | (0xdU 
                                                               == 
                                                               (0x3fU 
                                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                   >> 8U)))) 
                                                           | (0xcU 
                                                              == 
                                                              (0x3fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 8U)))) 
                                                          | (0xbU 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (0xfU 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U)))) 
                                                        | (9U 
                                                           == 
                                                           (0x3fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 8U)))) 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 7U))));
    vlTOPp->top__DOT__pic__DOT__aluout = (0xffU & (
                                                   (0xdU 
                                                    == 
                                                    (0x3fU 
                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                        >> 8U)))
                                                    ? 
                                                   ((0xfeU 
                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                        << 1U)) 
                                                    | (1U 
                                                       & (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)))
                                                    : 
                                                   ((0xcU 
                                                     == 
                                                     (0x3fU 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                         >> 8U)))
                                                     ? 
                                                    ((0x80U 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                                                         << 7U)) 
                                                     | (0x7fU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                           >> 1U)))
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                          >> 8U)))
                                                      ? 
                                                     ((0xf0U 
                                                       & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                          << 4U)) 
                                                      | (0xfU 
                                                         & ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                            >> 4U)))
                                                      : 
                                                     ((9U 
                                                       == 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                           >> 8U)))
                                                       ? 
                                                      (~ (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg))
                                                       : 
                                                      ((((((0x39U 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U))) 
                                                           | (5U 
                                                              == 
                                                              (0x3fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 8U)))) 
                                                          | (4U 
                                                             == 
                                                             (0xfU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 0xaU)))) 
                                                         | (6U 
                                                            == 
                                                            (0xfU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 0xaU)))) 
                                                        | (7U 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xaU))))
                                                        ? 
                                                       ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg))
                                                        : 
                                                       ((((5U 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xaU))) 
                                                          | (0x38U 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (4U 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U))))
                                                         ? 
                                                        ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                         | (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg))
                                                         : 
                                                        (((0x3aU 
                                                           == 
                                                           (0x3fU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 8U))) 
                                                          | (6U 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U))))
                                                          ? 
                                                         ((IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg) 
                                                          ^ (IData)(vlTOPp->top__DOT__pic__DOT__aluinp2_reg))
                                                          : 
                                                         (((((((((0x1fU 
                                                                  == 
                                                                  (0x1fU 
                                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                      >> 9U))) 
                                                                 | (7U 
                                                                    == 
                                                                    (0x3fU 
                                                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                        >> 8U)))) 
                                                                | (0x1eU 
                                                                   == 
                                                                   (0x1fU 
                                                                    & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                       >> 9U)))) 
                                                               | (2U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                      >> 8U)))) 
                                                              | (3U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                     >> 8U)))) 
                                                             | (0xbU 
                                                                == 
                                                                (0x3fU 
                                                                 & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                    >> 8U)))) 
                                                            | (0xaU 
                                                               == 
                                                               (0x3fU 
                                                                & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                   >> 8U)))) 
                                                           | (0xfU 
                                                              == 
                                                              (0x3fU 
                                                               & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                  >> 8U))))
                                                           ? (IData)(vlTOPp->top__DOT__pic__DOT__add_node)
                                                           : (IData)(vlTOPp->top__DOT__pic__DOT__aluinp1_reg))))))))));
    vlTOPp->top__DOT__pic__DOT__ram_adr_node = ((0U 
                                                 == 
                                                 (0x7fU 
                                                  & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))
                                                 ? 
                                                ((0x100U 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg))
                                                 : 
                                                ((0x180U 
                                                  & ((IData)(vlTOPp->top__DOT__pic__DOT__status_reg) 
                                                     << 2U)) 
                                                 | (0x7fU 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__writew_node) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__writew_node)) {
        ++(vlSymsp->__Vcoverage[447]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__writew_node 
            = vlTOPp->top__DOT__pic__DOT__writew_node;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__writeram_node)) {
        ++(vlSymsp->__Vcoverage[448]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__writeram_node 
            = vlTOPp->top__DOT__pic__DOT__writeram_node;
    }
    if ((1U & (((0U == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                 ? 1U : 0U) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__aluout_zero_node))) {
        ++(vlSymsp->__Vcoverage[433]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__aluout_zero_node 
            = ((0U == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                ? 1U : 0U);
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xfeU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xfdU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xfbU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xf7U & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xefU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xdfU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0xbfU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__aluout) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_wr))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->top__DOT____Vtogcov__ram_data_wr = 
            ((0x7fU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_wr)) 
             | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__aluout)));
    }
    vlTOPp->top__DOT__aux_data = (((((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                      ? (IData)(vlTOPp->top__DOT__pic__DOT__aluout)
                                      : 0U) & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                                ? 0xffU
                                                : 0U)) 
                                   & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                       ? 0xffU : 0U)) 
                                  | (((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                       ? 0U : vlTOPp->top__DOT__aux_ram
                                      [vlTOPp->top__DOT__aux_addr]) 
                                     & ((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                         ? 0U : 0xffU)));
    if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                  & (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                      | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                     | (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))))) {
        if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                      & ((5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                       >> 0xbU))) | 
                         (4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                       >> 0xbU)))))))) {
            if (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                 & ((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
                    & (2U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))))) {
                ++(vlSymsp->__Vcoverage[502]);
            }
        }
    }
    if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                  & (((8U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                      | (0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                          >> 0xaU)))) 
                     | (9U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))))) {
        if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                      & ((5U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                       >> 0xbU))) | 
                         (4U == (7U & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                       >> 0xbU)))))))) {
            if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                          & ((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
                             & (2U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))))))) {
                ++(vlSymsp->__Vcoverage[503]);
            }
        }
    }
    if (((2U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_pcl)) {
        ++(vlSymsp->__Vcoverage[393]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_pcl 
            = (2U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((3U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_stat)) {
        ++(vlSymsp->__Vcoverage[394]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_stat 
            = (3U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((4U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_fsr)) {
        ++(vlSymsp->__Vcoverage[395]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_fsr 
            = (4U == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((0xaU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_pclath)) {
        ++(vlSymsp->__Vcoverage[396]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_pclath 
            = (0xaU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((0xbU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_intcon)) {
        ++(vlSymsp->__Vcoverage[397]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_intcon 
            = (0xbU == (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((5U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_adr_lo)) {
        ++(vlSymsp->__Vcoverage[398]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_adr_lo 
            = (5U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((6U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_adr_hi)) {
        ++(vlSymsp->__Vcoverage[399]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_adr_hi 
            = (6U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((8U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_dat)) {
        ++(vlSymsp->__Vcoverage[400]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_aux_dat 
            = (8U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((0xbU < (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_sram)) {
        ++(vlSymsp->__Vcoverage[401]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_sram 
            = (0xbU < (0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((0x87U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_rx_data)) {
        ++(vlSymsp->__Vcoverage[452]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_rx_data 
            = (0x87U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((7U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_tx_data)) {
        ++(vlSymsp->__Vcoverage[453]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_tx_data 
            = (7U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if (((9U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_sr)) {
        ++(vlSymsp->__Vcoverage[454]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__addr_uart_sr 
            = (9U == (0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    vlTOPp->top__DOT__aux_rd_stb = ((IData)(vlTOPp->top__DOT__pic__DOT__aux_re_reg) 
                                    & (8U == (0xffU 
                                              & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))));
    vlTOPp->top__DOT__pic__DOT__next_exec_stall = (
                                                   (((((((5U 
                                                          == 
                                                          (7U 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 0xbU))) 
                                                         | (4U 
                                                            == 
                                                            (7U 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 0xbU)))) 
                                                        | (8U 
                                                           == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))) 
                                                       | (0xdU 
                                                          == 
                                                          (0xfU 
                                                           & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                              >> 0xaU)))) 
                                                      | (9U 
                                                         == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))) 
                                                     | ((((6U 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xaU))) 
                                                          | (0xbU 
                                                             == 
                                                             (0x3fU 
                                                              & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                 >> 8U)))) 
                                                         | (0xfU 
                                                            == 
                                                            (0x3fU 
                                                             & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                                >> 8U)))) 
                                                        & ((0U 
                                                            == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                                                            ? 1U
                                                            : 0U))) 
                                                    | ((7U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                            >> 0xaU))) 
                                                       & (~ 
                                                          ((0U 
                                                            == (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                                                            ? 1U
                                                            : 0U)))) 
                                                   | ((2U 
                                                       == 
                                                       (0x7fU 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node))) 
                                                      & (IData)(vlTOPp->top__DOT__pic__DOT__writeram_node)));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1feU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1fdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1fbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1f7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1efU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1dfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x1bfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0x17fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node) 
                   ^ vlTOPp->top__DOT____Vtogcov__ram_addr))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->top__DOT____Vtogcov__ram_addr = ((0xffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__ram_addr)) 
                                                 | (0x100U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)));
    }
    vlTOPp->top__DOT__pic__DOT__next_pc_node = (0x1fffU 
                                                & (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                                                    & (((8U 
                                                         == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)) 
                                                        | (0xdU 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xaU)))) 
                                                       | (9U 
                                                          == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg))))
                                                    ? (IData)(vlTOPp->top__DOT__pic__DOT__stack_top)
                                                    : 
                                                   (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                                                     & ((5U 
                                                         == 
                                                         (7U 
                                                          & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                             >> 0xbU))) 
                                                        | (4U 
                                                           == 
                                                           (7U 
                                                            & ((IData)(vlTOPp->top__DOT__pic__DOT__inst_reg) 
                                                               >> 0xbU)))))
                                                     ? 
                                                    ((0x1800U 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
                                                         << 8U)) 
                                                     | (0x7ffU 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))
                                                     : 
                                                    (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                                                      & ((IData)(vlTOPp->top__DOT__pic__DOT__writeram_node) 
                                                         & (2U 
                                                            == 
                                                            (0x7fU 
                                                             & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))))
                                                      ? 
                                                     (((IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg) 
                                                       << 8U) 
                                                      | (IData)(vlTOPp->top__DOT__pic__DOT__aluout))
                                                      : 
                                                     ((IData)(1U) 
                                                      + (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg))))));
    vlTOPp->top__DOT__ram_data_rd = vlTOPp->top__DOT__ram
        [vlTOPp->top__DOT__pic__DOT__ram_adr_node];
    if ((2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
            ++(vlSymsp->__Vcoverage[559]);
        }
    }
    if ((2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            ++(vlSymsp->__Vcoverage[562]);
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
            ++(vlSymsp->__Vcoverage[555]);
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            ++(vlSymsp->__Vcoverage[558]);
        }
    }
    if ((2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__inte_sync_reg)))) {
                ++(vlSymsp->__Vcoverage[561]);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
            if (vlTOPp->top__DOT__pic__DOT__int_condition) {
                ++(vlSymsp->__Vcoverage[553]);
            }
        }
    }
    if ((2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if (vlTOPp->top__DOT__pic__DOT__inte_sync_reg) {
                ++(vlSymsp->__Vcoverage[560]);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__pic__DOT__int_condition)))) {
                ++(vlSymsp->__Vcoverage[554]);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                 & (0x63U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))) {
                ++(vlSymsp->__Vcoverage[556]);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
                  >> 1U)))) {
        if ((1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))) {
            if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                          & (0x63U == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))))) {
                ++(vlSymsp->__Vcoverage[557]);
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg))) {
        ++(vlSymsp->__Vcoverage[356]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg 
            = ((2U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__state_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg))) {
        ++(vlSymsp->__Vcoverage[357]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg 
            = ((1U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__state_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg)));
    }
    vlTOPp->top__DOT__pic__DOT__next_state_node = (
                                                   (2U 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__pic__DOT__inte_sync_reg)
                                                      ? 0U
                                                      : 3U)
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__pic__DOT__state_reg))
                                                     ? 
                                                    (((~ (IData)(vlTOPp->top__DOT__pic__DOT__exec_stall_reg)) 
                                                      & (0x63U 
                                                         == (IData)(vlTOPp->top__DOT__pic__DOT__inst_reg)))
                                                      ? 3U
                                                      : 0U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__pic__DOT__int_condition)
                                                      ? 2U
                                                      : 1U)));
    if ((1U & ((IData)(vlTOPp->top__DOT__aux_data) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xfeU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__aux_data) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xfdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__aux_data) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xfbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__aux_data) 
               ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xf7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__aux_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xefU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__aux_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xdfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__aux_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0xbfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__aux_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__aux_data))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->top__DOT____Vtogcov__aux_data = ((0x7fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__aux_data)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__aux_data)));
    }
    if (((IData)(vlTOPp->top__DOT__aux_rd_stb) ^ vlTOPp->top__DOT____Vtogcov__aux_rd_stb)) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->top__DOT____Vtogcov__aux_rd_stb = vlTOPp->top__DOT__aux_rd_stb;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__next_exec_stall) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_exec_stall)) {
        ++(vlSymsp->__Vcoverage[451]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_exec_stall 
            = vlTOPp->top__DOT__pic__DOT__next_exec_stall;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[434]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1ffeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[435]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1ffdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[436]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1ffbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[437]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1ff7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[438]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1fefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[439]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1fdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[440]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1fbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[441]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1f7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[442]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1effU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[443]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1dffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x200U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[444]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x1bffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x400U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                   ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[445]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0x17ffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x800U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node) 
                    ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node))) {
        ++(vlSymsp->__Vcoverage[446]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node 
            = ((0xfffU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_pc_node)) 
               | (0x1000U & (IData)(vlTOPp->top__DOT__pic__DOT__next_pc_node)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xfeU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (1U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xfdU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (2U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xfbU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (4U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
               ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xf7U & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (8U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xefU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (0x10U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xdfU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (0x20U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0xbfU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (0x40U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__ram_data_rd) 
                  ^ vlTOPp->top__DOT____Vtogcov__ram_data_rd))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->top__DOT____Vtogcov__ram_data_rd = 
            ((0x7fU & (IData)(vlTOPp->top__DOT____Vtogcov__ram_data_rd)) 
             | (0x80U & (IData)(vlTOPp->top__DOT__ram_data_rd)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_state_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node))) {
        ++(vlSymsp->__Vcoverage[358]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node 
            = ((2U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__next_state_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__next_state_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node))) {
        ++(vlSymsp->__Vcoverage[359]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node 
            = ((1U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__next_state_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__next_state_node)));
    }
}

void Vtop::_settle__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__txd_reg)) {
        ++(vlSymsp->__Vcoverage[580]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__txd_reg 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg;
    }
    vlTOPp->uart_tx = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg;
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[455]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[456]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[457]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[458]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[459]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[460]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[461]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data))) {
        ++(vlSymsp->__Vcoverage[462]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_rx_data)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    vlTOPp->top__DOT__rom_data = vlTOPp->top__DOT__rom
        [vlTOPp->top__DOT__pic__DOT__pc_reg];
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__tx_busy)) {
        ++(vlSymsp->__Vcoverage[576]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__tx_busy 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_busy)) {
        ++(vlSymsp->__Vcoverage[577]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_busy 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_overrun_error)) {
        ++(vlSymsp->__Vcoverage[578]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_overrun_error 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg;
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_frame_error)) {
        ++(vlSymsp->__Vcoverage[579]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_frame_error 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg;
    }
    vlTOPp->top__DOT__pic__DOT__uart_sr = ((0xf0U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)) 
                                           | (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg) 
                                               << 3U) 
                                              | (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg)))));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__rxd_reg)) {
        ++(vlSymsp->__Vcoverage[621]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__rxd_reg 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[609]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[610]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[611]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[612]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[649]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[650]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[651]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[652]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[622]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[623]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[624]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[625]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[626]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[627]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[628]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[629]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg)));
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[581]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1feU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[582]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fdU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[583]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fbU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[584]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1f7U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[585]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1efU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[586]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1dfU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[587]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1bfU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[588]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x17fU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg) 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[589]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0xffU & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x100U & (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg)));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[590]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[591]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[592]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[593]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[594]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[595]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[596]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[597]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[598]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[599]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[600]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[601]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[602]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[603]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[604]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[605]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[606]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[607]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[608]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((1U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[630]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((2U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[631]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((4U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[632]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((8U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
               ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[633]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[634]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[635]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[636]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                  ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[637]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[638]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[639]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[640]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                   ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[641]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[642]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[643]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[644]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                    ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[645]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[646]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[647]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg 
                     ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[648]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg));
    }
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tready)) {
        ++(vlSymsp->__Vcoverage[573]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tready 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg;
    }
    vlTOPp->top__DOT__pic__DOT__uart_sr = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)) 
                                           | ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg) 
                                              << 5U));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
         ^ vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tvalid)) {
        ++(vlSymsp->__Vcoverage[574]);
        vlTOPp->top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tvalid 
            = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    }
    vlTOPp->top__DOT__pic__DOT____Vcellout__pic_uart__output_axis_tvalid 
        = vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    vlTOPp->top__DOT__pic__DOT__uart_sr = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)) 
                                           | ((IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
                                              << 4U));
    if (((IData)(vlTOPp->uart_tx) ^ vlTOPp->top__DOT____Vtogcov__uart_tx)) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->top__DOT____Vtogcov__uart_tx = vlTOPp->uart_tx;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__rom_data) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3ffeU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__rom_data) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3ffdU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__rom_data) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3ffbU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__rom_data) 
               ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3ff7U 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__rom_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3fefU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__rom_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3fdfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__rom_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3fbfU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__rom_data) 
                  ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3f7fU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x80U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x100U & ((IData)(vlTOPp->top__DOT__rom_data) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3effU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x100U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x200U & ((IData)(vlTOPp->top__DOT__rom_data) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3dffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x200U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x400U & ((IData)(vlTOPp->top__DOT__rom_data) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x3bffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x800U & ((IData)(vlTOPp->top__DOT__rom_data) 
                   ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x37ffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x800U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x1000U & ((IData)(vlTOPp->top__DOT__rom_data) 
                    ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x2fffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x1000U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((0x2000U & ((IData)(vlTOPp->top__DOT__rom_data) 
                    ^ vlTOPp->top__DOT____Vtogcov__rom_data))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->top__DOT____Vtogcov__rom_data = ((0x1fffU 
                                                  & (IData)(vlTOPp->top__DOT____Vtogcov__rom_data)) 
                                                 | (0x2000U 
                                                    & (IData)(vlTOPp->top__DOT__rom_data)));
    }
    if ((1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                >> 4U) ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__int_combined))) {
        ++(vlSymsp->__Vcoverage[566]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__int_combined 
            = (1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                     >> 4U));
    }
    vlTOPp->top__DOT__pic__DOT__intrise = (1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                                                  >> 4U) 
                                                 & (~ (IData)(vlTOPp->top__DOT__pic__DOT__intrise_reg))));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[479]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[480]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[481]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[482]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[483]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[484]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[485]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr))) {
        ++(vlSymsp->__Vcoverage[486]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    }
    vlTOPp->top__DOT__pic__DOT__uart_sr_comb = ((0xc0U 
                                                 & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)) 
                                                | (0x3fU 
                                                   & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__intrise) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intrise)) {
        ++(vlSymsp->__Vcoverage[353]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intrise 
            = vlTOPp->top__DOT__pic__DOT__intrise;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[487]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[488]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[489]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[490]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[491]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[492]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[493]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[494]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    vlTOPp->top__DOT__pic__DOT__ram_i_node = ((((((
                                                   (((((((0x87U 
                                                          == 
                                                          (0xffU 
                                                           & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                          ? (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)
                                                          : 0U) 
                                                        & ((0x87U 
                                                            == 
                                                            (0xffU 
                                                             & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                            ? 0xffU
                                                            : 0U)) 
                                                       | (((9U 
                                                            == 
                                                            (0xffU 
                                                             & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                            ? (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)
                                                            : 0U) 
                                                          & ((9U 
                                                              == 
                                                              (0xffU 
                                                               & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                              ? 0xffU
                                                              : 0U))) 
                                                      | (((0xbU 
                                                           < 
                                                           (0x7fU 
                                                            & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                           ? (IData)(vlTOPp->top__DOT__ram_data_rd)
                                                           : 0U) 
                                                         & ((0xbU 
                                                             < 
                                                             (0x7fU 
                                                              & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                             ? 0xffU
                                                             : 0U))) 
                                                     | (((2U 
                                                          == 
                                                          (0x7fU 
                                                           & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                          ? (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)
                                                          : 0U) 
                                                        & ((2U 
                                                            == 
                                                            (0x7fU 
                                                             & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                            ? 0xffU
                                                            : 0U))) 
                                                    | (((3U 
                                                         == 
                                                         (0x7fU 
                                                          & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                         ? (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)
                                                         : 0U) 
                                                       & ((3U 
                                                           == 
                                                           (0x7fU 
                                                            & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                           ? 0xffU
                                                           : 0U))) 
                                                   | (((4U 
                                                        == 
                                                        (0x7fU 
                                                         & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                        ? (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)
                                                        : 0U) 
                                                      & ((4U 
                                                          == 
                                                          (0x7fU 
                                                           & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                          ? 0xffU
                                                          : 0U))) 
                                                  | (((8U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                       ? (IData)(vlTOPp->top__DOT__aux_data)
                                                       : 0U) 
                                                     & ((8U 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                         ? 
                                                        ((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                                          ? 0xffU
                                                          : 0U)
                                                         : 0U))) 
                                                 | (((0xaU 
                                                      == 
                                                      (0x7fU 
                                                       & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                      ? (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)
                                                      : 0U) 
                                                    & ((0xaU 
                                                        == 
                                                        (0x7fU 
                                                         & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                        ? 0xffU
                                                        : 0U))) 
                                                | (((0xbU 
                                                     == 
                                                     (0x7fU 
                                                      & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                     ? (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)
                                                     : 0U) 
                                                   & ((0xbU 
                                                       == 
                                                       (0x7fU 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                       ? 0xffU
                                                       : 0U))) 
                                               | (((5U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                    ? (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)
                                                    : 0U) 
                                                  & ((5U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                      ? 0xffU
                                                      : 0U))) 
                                              | (((6U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                   ? (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)
                                                   : 0U) 
                                                 & ((6U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                     ? 0xffU
                                                     : 0U)));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[403]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[404]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[405]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[406]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[407]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[408]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[409]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[410]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__pic__DOT__intrise = (1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr) 
                                                  >> 4U) 
                                                 & (~ (IData)(vlTOPp->top__DOT__pic__DOT__intrise_reg))));
    vlTOPp->top__DOT__pic__DOT__uart_sr_comb = ((0xc0U 
                                                 & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff)) 
                                                | (0x3fU 
                                                   & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr)));
    if (((IData)(vlTOPp->top__DOT__pic__DOT__intrise) 
         ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__intrise)) {
        ++(vlSymsp->__Vcoverage[353]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__intrise 
            = vlTOPp->top__DOT__pic__DOT__intrise;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[487]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[488]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[489]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[490]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[491]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[492]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[493]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb))) {
        ++(vlSymsp->__Vcoverage[494]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__uart_sr_comb)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)));
    }
    vlTOPp->top__DOT__pic__DOT__ram_i_node = ((((((
                                                   (((((((0x87U 
                                                          == 
                                                          (0xffU 
                                                           & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                          ? (IData)(vlTOPp->top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg)
                                                          : 0U) 
                                                        & ((0x87U 
                                                            == 
                                                            (0xffU 
                                                             & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                            ? 0xffU
                                                            : 0U)) 
                                                       | (((9U 
                                                            == 
                                                            (0xffU 
                                                             & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                            ? (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_comb)
                                                            : 0U) 
                                                          & ((9U 
                                                              == 
                                                              (0xffU 
                                                               & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                              ? 0xffU
                                                              : 0U))) 
                                                      | (((0xbU 
                                                           < 
                                                           (0x7fU 
                                                            & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                           ? (IData)(vlTOPp->top__DOT__ram_data_rd)
                                                           : 0U) 
                                                         & ((0xbU 
                                                             < 
                                                             (0x7fU 
                                                              & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                             ? 0xffU
                                                             : 0U))) 
                                                     | (((2U 
                                                          == 
                                                          (0x7fU 
                                                           & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                          ? (IData)(vlTOPp->top__DOT__pic__DOT__pc_reg)
                                                          : 0U) 
                                                        & ((2U 
                                                            == 
                                                            (0x7fU 
                                                             & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                            ? 0xffU
                                                            : 0U))) 
                                                    | (((3U 
                                                         == 
                                                         (0x7fU 
                                                          & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                         ? (IData)(vlTOPp->top__DOT__pic__DOT__status_reg)
                                                         : 0U) 
                                                       & ((3U 
                                                           == 
                                                           (0x7fU 
                                                            & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                           ? 0xffU
                                                           : 0U))) 
                                                   | (((4U 
                                                        == 
                                                        (0x7fU 
                                                         & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                        ? (IData)(vlTOPp->top__DOT__pic__DOT__fsr_reg)
                                                        : 0U) 
                                                      & ((4U 
                                                          == 
                                                          (0x7fU 
                                                           & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                          ? 0xffU
                                                          : 0U))) 
                                                  | (((8U 
                                                       == 
                                                       (0xffU 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                       ? (IData)(vlTOPp->top__DOT__aux_data)
                                                       : 0U) 
                                                     & ((8U 
                                                         == 
                                                         (0xffU 
                                                          & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                         ? 
                                                        ((IData)(vlTOPp->top__DOT__pic__DOT__aux_we_reg)
                                                          ? 0xffU
                                                          : 0U)
                                                         : 0U))) 
                                                 | (((0xaU 
                                                      == 
                                                      (0x7fU 
                                                       & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                      ? (IData)(vlTOPp->top__DOT__pic__DOT__pclath_reg)
                                                      : 0U) 
                                                    & ((0xaU 
                                                        == 
                                                        (0x7fU 
                                                         & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                        ? 0xffU
                                                        : 0U))) 
                                                | (((0xbU 
                                                     == 
                                                     (0x7fU 
                                                      & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                     ? (IData)(vlTOPp->top__DOT__pic__DOT__intcon_reg)
                                                     : 0U) 
                                                   & ((0xbU 
                                                       == 
                                                       (0x7fU 
                                                        & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                       ? 0xffU
                                                       : 0U))) 
                                               | (((5U 
                                                    == 
                                                    (0xffU 
                                                     & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                    ? (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_lo_reg)
                                                    : 0U) 
                                                  & ((5U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                      ? 0xffU
                                                      : 0U))) 
                                              | (((6U 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                   ? (IData)(vlTOPp->top__DOT__pic__DOT__aux_adr_hi_reg)
                                                   : 0U) 
                                                 & ((6U 
                                                     == 
                                                     (0xffU 
                                                      & (IData)(vlTOPp->top__DOT__pic__DOT__ram_adr_node)))
                                                     ? 0xffU
                                                     : 0U)));
    if ((1U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[403]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xfeU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (1U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((2U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[404]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xfdU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (2U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((4U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[405]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xfbU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (4U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((8U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
               ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[406]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xf7U & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (8U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((0x10U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[407]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xefU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (0x10U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((0x20U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[408]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xdfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (0x20U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((0x40U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[409]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0xbfU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (0x40U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
    if ((0x80U & ((IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node) 
                  ^ vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node))) {
        ++(vlSymsp->__Vcoverage[410]);
        vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__pic__DOT____Vtogcov__ram_i_node)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__ram_i_node)));
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__8\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__reset = (1U & (~ (IData)(vlTOPp->reset_n)));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    vlTOPp->_combo__TOP__8(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__reset 
        = vlTOPp->__VinpClk__TOP__top__DOT__reset;
    vlTOPp->__VinpClk__TOP__top__DOT__reset = vlTOPp->top__DOT__reset;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__3(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__reset 
        = vlTOPp->__VinpClk__TOP__top__DOT__reset;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__6(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->top__DOT__reset ^ vlTOPp->__Vchglast__TOP__top__DOT__reset));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__reset ^ vlTOPp->__Vchglast__TOP__top__DOT__reset))) VL_DBG_MSGF("        CHANGE: top.v:26: top.reset\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__reset = vlTOPp->top__DOT__reset;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((i_setup & 0x80000000U))) {
        Verilated::overWidthError("i_setup");}
    if (VL_UNLIKELY((uart_rx & 0xfeU))) {
        Verilated::overWidthError("uart_rx");}
}
#endif  // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    i_setup = VL_RAND_RESET_I(31);
    uart_rx = VL_RAND_RESET_I(1);
    uart_tx = VL_RAND_RESET_I(1);
    uart_prescale = VL_RAND_RESET_I(16);
    top__DOT__reset = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            top__DOT__rom[__Vi0] = VL_RAND_RESET_I(14);
    }}
    top__DOT__rom_data = VL_RAND_RESET_I(14);
    { int __Vi0=0; for (; __Vi0<512; ++__Vi0) {
            top__DOT__ram[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top__DOT__ram_data_rd = VL_RAND_RESET_I(8);
    top__DOT__aux_data = VL_RAND_RESET_I(8);
    top__DOT__aux_addr = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<65536; ++__Vi0) {
            top__DOT__aux_ram[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top__DOT__aux_rd_stb = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__clk = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__reset_n = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__i_setup = VL_RAND_RESET_I(31);
    top__DOT____Vtogcov__uart_rx = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__uart_tx = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__uart_prescale = VL_RAND_RESET_I(16);
    top__DOT____Vtogcov__reset = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__rom_addr = VL_RAND_RESET_I(13);
    top__DOT____Vtogcov__rom_data = VL_RAND_RESET_I(14);
    top__DOT____Vtogcov__ram_addr = VL_RAND_RESET_I(9);
    top__DOT____Vtogcov__ram_data_rd = VL_RAND_RESET_I(8);
    top__DOT____Vtogcov__ram_data_wr = VL_RAND_RESET_I(8);
    top__DOT____Vtogcov__aux_data = VL_RAND_RESET_I(8);
    top__DOT____Vtogcov__aux_addr = VL_RAND_RESET_I(16);
    top__DOT____Vtogcov__aux_wr_stb = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__clken = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__aux_rd_stb = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__ram_we = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__int0 = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__w_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__pc_reg = VL_RAND_RESET_I(13);
    top__DOT__pic__DOT__old_pc_reg = VL_RAND_RESET_I(13);
    top__DOT__pic__DOT__status_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__fsr_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__pclath_reg = VL_RAND_RESET_I(5);
    top__DOT__pic__DOT__intcon_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__aux_adr_hi_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__aux_adr_lo_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__inst_reg = VL_RAND_RESET_I(14);
    top__DOT__pic__DOT__aluinp1_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__aluinp2_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__exec_stall_reg = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            top__DOT__pic__DOT__stack_reg[__Vi0] = VL_RAND_RESET_I(13);
    }}
    top__DOT__pic__DOT__stack_pnt_reg = VL_RAND_RESET_I(3);
    top__DOT__pic__DOT__stack_top = VL_RAND_RESET_I(13);
    top__DOT__pic__DOT__int_condition = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__intrise = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__intrise_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__inte_sync_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__state_reg = VL_RAND_RESET_I(2);
    top__DOT__pic__DOT__next_state_node = VL_RAND_RESET_I(2);
    top__DOT__pic__DOT__ram_adr_node = VL_RAND_RESET_I(9);
    top__DOT__pic__DOT__ram_we_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__aux_we_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__aux_re_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__ram_i_node = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__add_node = VL_RAND_RESET_I(9);
    top__DOT__pic__DOT__addlow_node = VL_RAND_RESET_I(5);
    top__DOT__pic__DOT__next_pc_node = VL_RAND_RESET_I(13);
    top__DOT__pic__DOT__aluout = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__writew_node = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__writeram_node = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__c_subtract_zero = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__c_dig_subtract_zero = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__next_exec_stall = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__uart_tx_data = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__uart_sr_ff = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__uart_sr = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__uart_sr_comb = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vcellout__pic_uart__output_axis_tvalid = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__w_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__old_pc_reg = VL_RAND_RESET_I(13);
    top__DOT__pic__DOT____Vtogcov__status_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__fsr_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__pclath_reg = VL_RAND_RESET_I(5);
    top__DOT__pic__DOT____Vtogcov__intcon_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__inst_reg = VL_RAND_RESET_I(14);
    top__DOT__pic__DOT____Vtogcov__aluinp1_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__aluinp2_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__exec_stall_reg = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            top__DOT__pic__DOT____Vtogcov__stack_reg[__Vi0] = VL_RAND_RESET_I(13);
    }}
    top__DOT__pic__DOT____Vtogcov__stack_pnt_reg = VL_RAND_RESET_I(3);
    top__DOT__pic__DOT____Vtogcov__stack_top = VL_RAND_RESET_I(13);
    top__DOT__pic__DOT____Vtogcov__int_condition = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__intrise = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__intrise_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inte_sync_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__state_reg = VL_RAND_RESET_I(2);
    top__DOT__pic__DOT____Vtogcov__next_state_node = VL_RAND_RESET_I(2);
    top__DOT__pic__DOT____Vtogcov__inst_addlw = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_addwf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_andlw = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_andwf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_bcf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_bsf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_btfsc = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_btfss = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_call = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_clrf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_clrw = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_comf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_decf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_decfsz = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_goto = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_incf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_incfsz = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_iorlw = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_iorwf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_movlw = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_movf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_movwf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_retfie = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_retlw = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_ret = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_rlf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_rrf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_sleep = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_sublw = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_subwf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_swapf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_xorlw = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__inst_xorwf = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_pcl = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_stat = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_fsr = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_pclath = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_intcon = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_aux_adr_lo = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_aux_adr_hi = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_aux_dat = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_sram = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__aux_re_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__ram_i_node = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__mask_node = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__add_node = VL_RAND_RESET_I(9);
    top__DOT__pic__DOT____Vtogcov__addlow_node = VL_RAND_RESET_I(5);
    top__DOT__pic__DOT____Vtogcov__aluout_zero_node = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__next_pc_node = VL_RAND_RESET_I(13);
    top__DOT__pic__DOT____Vtogcov__writew_node = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__writeram_node = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__c_subtract_zero = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__c_dig_subtract_zero = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__next_exec_stall = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_uart_rx_data = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_uart_tx_data = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__addr_uart_sr = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT____Vtogcov__uart_rx_data = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__uart_tx_data = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__uart_sr_ff = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__uart_sr = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__uart_sr_comb = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT____Vtogcov__int_combined = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tvalid = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__input_axis_tready = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tvalid = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__output_axis_tready = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__tx_busy = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_busy = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_overrun_error = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT____Vtogcov__rx_frame_error = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__input_axis_tready_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__txd_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__busy_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__data_reg = VL_RAND_RESET_I(9);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__prescale_reg = VL_RAND_RESET_I(19);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT__bit_cnt = VL_RAND_RESET_I(4);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__txd_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__data_reg = VL_RAND_RESET_I(9);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__prescale_reg = VL_RAND_RESET_I(19);
    top__DOT__pic__DOT__pic_uart__DOT__uart_tx_inst__DOT____Vtogcov__bit_cnt = VL_RAND_RESET_I(4);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tdata_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__output_axis_tvalid_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__rxd_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__busy_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__overrun_error_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__frame_error_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__data_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__prescale_reg = VL_RAND_RESET_I(19);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT__bit_cnt = VL_RAND_RESET_I(4);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__rxd_reg = VL_RAND_RESET_I(1);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__data_reg = VL_RAND_RESET_I(8);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__prescale_reg = VL_RAND_RESET_I(19);
    top__DOT__pic__DOT__pic_uart__DOT__uart_rx_inst__DOT____Vtogcov__bit_cnt = VL_RAND_RESET_I(4);
    __VinpClk__TOP__top__DOT__reset = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__reset = VL_RAND_RESET_I(1);
}

void Vtop::_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "top.v", 8, 0, ".top", "v_toggle/top", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "top.v", 9, 0, ".top", "v_toggle/top", "reset_n");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[19]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[20]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[21]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[22]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[23]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[24]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[25]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[26]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[27]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[28]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[29]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "top.v", 10, 0, ".top", "v_toggle/top", "i_setup[30]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "top.v", 11, 0, ".top", "v_toggle/top", "uart_rx");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "top.v", 12, 0, ".top", "v_toggle/top", "uart_tx");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "top.v", 13, 0, ".top", "v_toggle/top", "uart_prescale[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "top.v", 26, 0, ".top", "v_toggle/top", "reset");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "top.v", 35, 0, ".top", "v_toggle/top", "rom_addr[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "top.v", 36, 0, ".top", "v_toggle/top", "rom_data[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "top.v", 43, 0, ".top", "v_toggle/top", "ram_addr[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "top.v", 44, 0, ".top", "v_toggle/top", "ram_data_rd[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "top.v", 44, 0, ".top", "v_toggle/top", "ram_data_rd[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "top.v", 44, 0, ".top", "v_toggle/top", "ram_data_rd[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "top.v", 44, 0, ".top", "v_toggle/top", "ram_data_rd[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "top.v", 44, 0, ".top", "v_toggle/top", "ram_data_rd[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "top.v", 44, 0, ".top", "v_toggle/top", "ram_data_rd[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "top.v", 44, 0, ".top", "v_toggle/top", "ram_data_rd[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "top.v", 44, 0, ".top", "v_toggle/top", "ram_data_rd[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "top.v", 45, 0, ".top", "v_toggle/top", "ram_data_wr[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "top.v", 45, 0, ".top", "v_toggle/top", "ram_data_wr[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "top.v", 45, 0, ".top", "v_toggle/top", "ram_data_wr[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[99]), first, "top.v", 45, 0, ".top", "v_toggle/top", "ram_data_wr[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[100]), first, "top.v", 45, 0, ".top", "v_toggle/top", "ram_data_wr[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[101]), first, "top.v", 45, 0, ".top", "v_toggle/top", "ram_data_wr[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[102]), first, "top.v", 45, 0, ".top", "v_toggle/top", "ram_data_wr[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[103]), first, "top.v", 45, 0, ".top", "v_toggle/top", "ram_data_wr[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[104]), first, "top.v", 48, 0, ".top", "v_line/top", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[105]), first, "top.v", 54, 0, ".top", "v_toggle/top", "aux_data[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[106]), first, "top.v", 54, 0, ".top", "v_toggle/top", "aux_data[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[107]), first, "top.v", 54, 0, ".top", "v_toggle/top", "aux_data[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[108]), first, "top.v", 54, 0, ".top", "v_toggle/top", "aux_data[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[109]), first, "top.v", 54, 0, ".top", "v_toggle/top", "aux_data[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[110]), first, "top.v", 54, 0, ".top", "v_toggle/top", "aux_data[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[111]), first, "top.v", 54, 0, ".top", "v_toggle/top", "aux_data[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[112]), first, "top.v", 54, 0, ".top", "v_toggle/top", "aux_data[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[113]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[114]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[115]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[116]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[117]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[118]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[119]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[120]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[121]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[122]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[123]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[124]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[125]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[126]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[127]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[128]), first, "top.v", 55, 0, ".top", "v_toggle/top", "aux_addr[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "top.v", 56, 0, ".top", "v_toggle/top", "aux_wr_stb");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[130]), first, "top.v", 61, 0, ".top", "v_line/top", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[131]), first, "top.v", 64, 0, ".top", "v_toggle/top", "clken");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[132]), first, "top.v", 64, 0, ".top", "v_toggle/top", "aux_rd_stb");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[133]), first, "top.v", 64, 0, ".top", "v_toggle/top", "ram_we");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[134]), first, "top.v", 65, 0, ".top", "v_toggle/top", "int0");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "../risc16f84_clk2x.v", 216, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "../risc16f84_clk2x.v", 217, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "../risc16f84_clk2x.v", 218, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_prescale[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "../risc16f84_clk2x.v", 227, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_dat_i[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "../risc16f84_clk2x.v", 228, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "prog_adr_o[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "../risc16f84_clk2x.v", 231, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_i[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "../risc16f84_clk2x.v", 231, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_i[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "../risc16f84_clk2x.v", 231, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_i[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "../risc16f84_clk2x.v", 231, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_i[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "../risc16f84_clk2x.v", 231, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_i[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "../risc16f84_clk2x.v", 231, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_i[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "../risc16f84_clk2x.v", 231, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_i[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "../risc16f84_clk2x.v", 231, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_i[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "../risc16f84_clk2x.v", 232, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_o[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "../risc16f84_clk2x.v", 232, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_o[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "../risc16f84_clk2x.v", 232, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_o[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[99]), first, "../risc16f84_clk2x.v", 232, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_o[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[100]), first, "../risc16f84_clk2x.v", 232, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_o[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[101]), first, "../risc16f84_clk2x.v", 232, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_o[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[102]), first, "../risc16f84_clk2x.v", 232, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_o[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[103]), first, "../risc16f84_clk2x.v", 232, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_dat_o[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "../risc16f84_clk2x.v", 233, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_o[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[133]), first, "../risc16f84_clk2x.v", 234, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_we_o");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[113]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[114]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[115]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[116]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[117]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[118]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[119]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[120]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[121]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[122]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[123]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[124]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[125]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[126]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[127]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[128]), first, "../risc16f84_clk2x.v", 237, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_o[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[105]), first, "../risc16f84_clk2x.v", 238, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_dat_io[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[106]), first, "../risc16f84_clk2x.v", 238, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_dat_io[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[107]), first, "../risc16f84_clk2x.v", 238, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_dat_io[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[108]), first, "../risc16f84_clk2x.v", 238, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_dat_io[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[109]), first, "../risc16f84_clk2x.v", 238, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_dat_io[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[110]), first, "../risc16f84_clk2x.v", 238, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_dat_io[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[111]), first, "../risc16f84_clk2x.v", 238, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_dat_io[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[112]), first, "../risc16f84_clk2x.v", 238, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_dat_io[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "../risc16f84_clk2x.v", 239, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_we_o");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[132]), first, "../risc16f84_clk2x.v", 240, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_re_o");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[134]), first, "../risc16f84_clk2x.v", 243, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "int0_i");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "../risc16f84_clk2x.v", 246, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "reset_i");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[131]), first, "../risc16f84_clk2x.v", 249, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "clk_en_i");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../risc16f84_clk2x.v", 250, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "clk_i");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[135]), first, "../risc16f84_clk2x.v", 256, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "w_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[136]), first, "../risc16f84_clk2x.v", 256, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "w_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[137]), first, "../risc16f84_clk2x.v", 256, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "w_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[138]), first, "../risc16f84_clk2x.v", 256, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "w_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[139]), first, "../risc16f84_clk2x.v", 256, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "w_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[140]), first, "../risc16f84_clk2x.v", 256, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "w_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[141]), first, "../risc16f84_clk2x.v", 256, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "w_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[142]), first, "../risc16f84_clk2x.v", 256, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "w_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "../risc16f84_clk2x.v", 257, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pc_reg[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[143]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[144]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[145]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[146]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[147]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[148]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[149]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[150]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[151]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[152]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[153]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[154]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[155]), first, "../risc16f84_clk2x.v", 258, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "old_pc_reg[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[156]), first, "../risc16f84_clk2x.v", 259, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "status_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[157]), first, "../risc16f84_clk2x.v", 259, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "status_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[158]), first, "../risc16f84_clk2x.v", 259, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "status_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[159]), first, "../risc16f84_clk2x.v", 259, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "status_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[160]), first, "../risc16f84_clk2x.v", 259, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "status_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[161]), first, "../risc16f84_clk2x.v", 259, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "status_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[162]), first, "../risc16f84_clk2x.v", 259, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "status_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[163]), first, "../risc16f84_clk2x.v", 259, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "status_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[164]), first, "../risc16f84_clk2x.v", 260, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "fsr_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[165]), first, "../risc16f84_clk2x.v", 260, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "fsr_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[166]), first, "../risc16f84_clk2x.v", 260, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "fsr_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[167]), first, "../risc16f84_clk2x.v", 260, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "fsr_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[168]), first, "../risc16f84_clk2x.v", 260, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "fsr_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[169]), first, "../risc16f84_clk2x.v", 260, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "fsr_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[170]), first, "../risc16f84_clk2x.v", 260, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "fsr_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[171]), first, "../risc16f84_clk2x.v", 260, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "fsr_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[172]), first, "../risc16f84_clk2x.v", 261, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pclath_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[173]), first, "../risc16f84_clk2x.v", 261, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pclath_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[174]), first, "../risc16f84_clk2x.v", 261, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pclath_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[175]), first, "../risc16f84_clk2x.v", 261, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pclath_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[176]), first, "../risc16f84_clk2x.v", 261, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "pclath_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[177]), first, "../risc16f84_clk2x.v", 262, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intcon_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[178]), first, "../risc16f84_clk2x.v", 262, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intcon_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[179]), first, "../risc16f84_clk2x.v", 262, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intcon_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[180]), first, "../risc16f84_clk2x.v", 262, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intcon_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[181]), first, "../risc16f84_clk2x.v", 262, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intcon_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[182]), first, "../risc16f84_clk2x.v", 262, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intcon_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[183]), first, "../risc16f84_clk2x.v", 262, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intcon_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[184]), first, "../risc16f84_clk2x.v", 262, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intcon_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[185]), first, "../risc16f84_clk2x.v", 263, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_hi_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[186]), first, "../risc16f84_clk2x.v", 263, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_hi_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[187]), first, "../risc16f84_clk2x.v", 263, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_hi_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[188]), first, "../risc16f84_clk2x.v", 263, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_hi_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[189]), first, "../risc16f84_clk2x.v", 263, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_hi_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[190]), first, "../risc16f84_clk2x.v", 263, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_hi_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[191]), first, "../risc16f84_clk2x.v", 263, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_hi_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[192]), first, "../risc16f84_clk2x.v", 263, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_hi_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[193]), first, "../risc16f84_clk2x.v", 264, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_lo_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[194]), first, "../risc16f84_clk2x.v", 264, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_lo_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[195]), first, "../risc16f84_clk2x.v", 264, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_lo_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[196]), first, "../risc16f84_clk2x.v", 264, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_lo_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[197]), first, "../risc16f84_clk2x.v", 264, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_lo_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[198]), first, "../risc16f84_clk2x.v", 264, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_lo_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[199]), first, "../risc16f84_clk2x.v", 264, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_lo_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[200]), first, "../risc16f84_clk2x.v", 264, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_adr_lo_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[201]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[202]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[203]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[204]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[205]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[206]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[207]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[208]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[209]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[210]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[211]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[212]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[213]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[214]), first, "../risc16f84_clk2x.v", 267, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_reg[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[215]), first, "../risc16f84_clk2x.v", 268, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp1_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[216]), first, "../risc16f84_clk2x.v", 268, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp1_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[217]), first, "../risc16f84_clk2x.v", 268, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp1_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[218]), first, "../risc16f84_clk2x.v", 268, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp1_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[219]), first, "../risc16f84_clk2x.v", 268, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp1_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[220]), first, "../risc16f84_clk2x.v", 268, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp1_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[221]), first, "../risc16f84_clk2x.v", 268, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp1_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[222]), first, "../risc16f84_clk2x.v", 268, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp1_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[223]), first, "../risc16f84_clk2x.v", 269, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp2_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[224]), first, "../risc16f84_clk2x.v", 269, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp2_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[225]), first, "../risc16f84_clk2x.v", 269, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp2_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[226]), first, "../risc16f84_clk2x.v", 269, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp2_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[227]), first, "../risc16f84_clk2x.v", 269, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp2_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[228]), first, "../risc16f84_clk2x.v", 269, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp2_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[229]), first, "../risc16f84_clk2x.v", 269, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp2_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[230]), first, "../risc16f84_clk2x.v", 269, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluinp2_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[231]), first, "../risc16f84_clk2x.v", 270, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "exec_stall_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[232]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[233]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[234]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[235]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[236]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[237]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[238]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[239]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[240]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[241]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[242]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[243]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[244]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[0][12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[245]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[246]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[247]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[248]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[249]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[250]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[251]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[252]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[253]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[254]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[255]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[256]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[257]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[1][12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[258]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[259]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[260]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[261]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[262]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[263]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[264]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[265]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[266]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[267]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[268]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[269]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[270]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[2][12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[271]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[272]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[273]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[274]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[275]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[276]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[277]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[278]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[279]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[280]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[281]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[282]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[283]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[3][12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[284]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[285]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[286]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[287]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[288]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[289]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[290]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[291]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[292]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[293]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[294]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[295]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[296]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[4][12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[297]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[298]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[299]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[300]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[301]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[302]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[303]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[304]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[305]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[306]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[307]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[308]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[309]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[5][12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[310]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[311]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[312]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[313]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[314]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[315]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[316]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[317]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[318]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[319]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[320]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[321]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[322]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[6][12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[323]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[324]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[325]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[326]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[327]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[328]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[329]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[330]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[331]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[332]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[333]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[334]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[335]), first, "../risc16f84_clk2x.v", 274, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_reg[7][12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[336]), first, "../risc16f84_clk2x.v", 276, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_pnt_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[337]), first, "../risc16f84_clk2x.v", 276, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_pnt_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[338]), first, "../risc16f84_clk2x.v", 276, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_pnt_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[339]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[340]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[341]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[342]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[343]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[344]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[345]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[346]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[347]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[348]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[349]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[350]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[351]), first, "../risc16f84_clk2x.v", 277, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "stack_top[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[352]), first, "../risc16f84_clk2x.v", 281, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "int_condition");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[353]), first, "../risc16f84_clk2x.v", 282, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intrise");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[354]), first, "../risc16f84_clk2x.v", 283, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "intrise_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[355]), first, "../risc16f84_clk2x.v", 285, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inte_sync_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[356]), first, "../risc16f84_clk2x.v", 288, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "state_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[357]), first, "../risc16f84_clk2x.v", 288, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "state_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[358]), first, "../risc16f84_clk2x.v", 289, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_state_node[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[359]), first, "../risc16f84_clk2x.v", 289, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_state_node[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[360]), first, "../risc16f84_clk2x.v", 292, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_addlw");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[361]), first, "../risc16f84_clk2x.v", 293, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_addwf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[362]), first, "../risc16f84_clk2x.v", 294, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_andlw");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[363]), first, "../risc16f84_clk2x.v", 295, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_andwf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[364]), first, "../risc16f84_clk2x.v", 296, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_bcf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[365]), first, "../risc16f84_clk2x.v", 297, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_bsf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[366]), first, "../risc16f84_clk2x.v", 298, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_btfsc");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[367]), first, "../risc16f84_clk2x.v", 299, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_btfss");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[368]), first, "../risc16f84_clk2x.v", 300, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_call");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[369]), first, "../risc16f84_clk2x.v", 301, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_clrf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[370]), first, "../risc16f84_clk2x.v", 302, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_clrw");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[371]), first, "../risc16f84_clk2x.v", 303, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_comf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[372]), first, "../risc16f84_clk2x.v", 304, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_decf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[373]), first, "../risc16f84_clk2x.v", 305, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_decfsz");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[374]), first, "../risc16f84_clk2x.v", 306, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_goto");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[375]), first, "../risc16f84_clk2x.v", 307, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_incf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[376]), first, "../risc16f84_clk2x.v", 308, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_incfsz");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[377]), first, "../risc16f84_clk2x.v", 309, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_iorlw");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[378]), first, "../risc16f84_clk2x.v", 310, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_iorwf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[379]), first, "../risc16f84_clk2x.v", 311, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_movlw");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[380]), first, "../risc16f84_clk2x.v", 312, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_movf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[381]), first, "../risc16f84_clk2x.v", 313, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_movwf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[382]), first, "../risc16f84_clk2x.v", 314, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_retfie");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[383]), first, "../risc16f84_clk2x.v", 315, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_retlw");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[384]), first, "../risc16f84_clk2x.v", 316, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_ret");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[385]), first, "../risc16f84_clk2x.v", 317, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_rlf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[386]), first, "../risc16f84_clk2x.v", 318, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_rrf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[387]), first, "../risc16f84_clk2x.v", 319, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_sleep");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[388]), first, "../risc16f84_clk2x.v", 320, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_sublw");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[389]), first, "../risc16f84_clk2x.v", 321, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_subwf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[390]), first, "../risc16f84_clk2x.v", 322, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_swapf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[391]), first, "../risc16f84_clk2x.v", 323, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_xorlw");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[392]), first, "../risc16f84_clk2x.v", 324, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "inst_xorwf");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "../risc16f84_clk2x.v", 327, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_adr_node[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[393]), first, "../risc16f84_clk2x.v", 331, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_pcl");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[394]), first, "../risc16f84_clk2x.v", 332, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_stat");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[395]), first, "../risc16f84_clk2x.v", 333, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_fsr");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[396]), first, "../risc16f84_clk2x.v", 334, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_pclath");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[397]), first, "../risc16f84_clk2x.v", 335, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_intcon");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[398]), first, "../risc16f84_clk2x.v", 336, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_aux_adr_lo");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[399]), first, "../risc16f84_clk2x.v", 337, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_aux_adr_hi");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[400]), first, "../risc16f84_clk2x.v", 338, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_aux_dat");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[401]), first, "../risc16f84_clk2x.v", 339, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_sram");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[133]), first, "../risc16f84_clk2x.v", 342, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_we_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "../risc16f84_clk2x.v", 343, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_we_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[402]), first, "../risc16f84_clk2x.v", 344, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aux_re_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[403]), first, "../risc16f84_clk2x.v", 349, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_i_node[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[404]), first, "../risc16f84_clk2x.v", 349, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_i_node[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[405]), first, "../risc16f84_clk2x.v", 349, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_i_node[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[406]), first, "../risc16f84_clk2x.v", 349, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_i_node[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[407]), first, "../risc16f84_clk2x.v", 349, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_i_node[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[408]), first, "../risc16f84_clk2x.v", 349, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_i_node[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[409]), first, "../risc16f84_clk2x.v", 349, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_i_node[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[410]), first, "../risc16f84_clk2x.v", 349, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "ram_i_node[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[411]), first, "../risc16f84_clk2x.v", 350, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "mask_node[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[412]), first, "../risc16f84_clk2x.v", 350, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "mask_node[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[413]), first, "../risc16f84_clk2x.v", 350, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "mask_node[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[414]), first, "../risc16f84_clk2x.v", 350, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "mask_node[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[415]), first, "../risc16f84_clk2x.v", 350, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "mask_node[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[416]), first, "../risc16f84_clk2x.v", 350, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "mask_node[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[417]), first, "../risc16f84_clk2x.v", 350, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "mask_node[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[418]), first, "../risc16f84_clk2x.v", 350, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "mask_node[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[419]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[420]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[421]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[422]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[423]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[424]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[425]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[426]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[427]), first, "../risc16f84_clk2x.v", 351, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "add_node[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[428]), first, "../risc16f84_clk2x.v", 352, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addlow_node[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[429]), first, "../risc16f84_clk2x.v", 352, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addlow_node[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[430]), first, "../risc16f84_clk2x.v", 352, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addlow_node[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[431]), first, "../risc16f84_clk2x.v", 352, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addlow_node[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[432]), first, "../risc16f84_clk2x.v", 352, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addlow_node[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[433]), first, "../risc16f84_clk2x.v", 353, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout_zero_node");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[434]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[435]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[436]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[437]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[438]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[439]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[440]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[441]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[442]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[443]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[444]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[445]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[446]), first, "../risc16f84_clk2x.v", 355, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_pc_node[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "../risc16f84_clk2x.v", 356, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "../risc16f84_clk2x.v", 356, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "../risc16f84_clk2x.v", 356, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[99]), first, "../risc16f84_clk2x.v", 356, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[100]), first, "../risc16f84_clk2x.v", 356, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[101]), first, "../risc16f84_clk2x.v", 356, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[102]), first, "../risc16f84_clk2x.v", 356, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[103]), first, "../risc16f84_clk2x.v", 356, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "aluout[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[447]), first, "../risc16f84_clk2x.v", 357, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "writew_node");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[448]), first, "../risc16f84_clk2x.v", 358, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "writeram_node");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[449]), first, "../risc16f84_clk2x.v", 359, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "c_subtract_zero");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[450]), first, "../risc16f84_clk2x.v", 360, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "c_dig_subtract_zero");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[451]), first, "../risc16f84_clk2x.v", 362, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "next_exec_stall");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[452]), first, "../risc16f84_clk2x.v", 369, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_uart_rx_data");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[453]), first, "../risc16f84_clk2x.v", 369, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_uart_tx_data");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[454]), first, "../risc16f84_clk2x.v", 369, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "addr_uart_sr");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[455]), first, "../risc16f84_clk2x.v", 372, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx_data[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[456]), first, "../risc16f84_clk2x.v", 372, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx_data[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[457]), first, "../risc16f84_clk2x.v", 372, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx_data[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[458]), first, "../risc16f84_clk2x.v", 372, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx_data[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[459]), first, "../risc16f84_clk2x.v", 372, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx_data[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[460]), first, "../risc16f84_clk2x.v", 372, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx_data[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[461]), first, "../risc16f84_clk2x.v", 372, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx_data[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[462]), first, "../risc16f84_clk2x.v", 372, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_rx_data[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[463]), first, "../risc16f84_clk2x.v", 376, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx_data[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[464]), first, "../risc16f84_clk2x.v", 376, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx_data[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[465]), first, "../risc16f84_clk2x.v", 376, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx_data[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[466]), first, "../risc16f84_clk2x.v", 376, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx_data[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[467]), first, "../risc16f84_clk2x.v", 376, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx_data[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[468]), first, "../risc16f84_clk2x.v", 376, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx_data[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[469]), first, "../risc16f84_clk2x.v", 376, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx_data[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[470]), first, "../risc16f84_clk2x.v", 376, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_tx_data[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[471]), first, "../risc16f84_clk2x.v", 380, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_ff[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[472]), first, "../risc16f84_clk2x.v", 380, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_ff[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[473]), first, "../risc16f84_clk2x.v", 380, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_ff[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[474]), first, "../risc16f84_clk2x.v", 380, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_ff[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[475]), first, "../risc16f84_clk2x.v", 380, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_ff[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[476]), first, "../risc16f84_clk2x.v", 380, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_ff[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[477]), first, "../risc16f84_clk2x.v", 380, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_ff[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[478]), first, "../risc16f84_clk2x.v", 380, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_ff[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[479]), first, "../risc16f84_clk2x.v", 381, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[480]), first, "../risc16f84_clk2x.v", 381, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[481]), first, "../risc16f84_clk2x.v", 381, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[482]), first, "../risc16f84_clk2x.v", 381, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[483]), first, "../risc16f84_clk2x.v", 381, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[484]), first, "../risc16f84_clk2x.v", 381, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[485]), first, "../risc16f84_clk2x.v", 381, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[486]), first, "../risc16f84_clk2x.v", 381, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[487]), first, "../risc16f84_clk2x.v", 382, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_comb[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[488]), first, "../risc16f84_clk2x.v", 382, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_comb[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[489]), first, "../risc16f84_clk2x.v", 382, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_comb[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[490]), first, "../risc16f84_clk2x.v", 382, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_comb[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[491]), first, "../risc16f84_clk2x.v", 382, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_comb[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[492]), first, "../risc16f84_clk2x.v", 382, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_comb[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[493]), first, "../risc16f84_clk2x.v", 382, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_comb[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[494]), first, "../risc16f84_clk2x.v", 382, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "uart_sr_comb[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[495]), first, "../risc16f84_clk2x.v", 445, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[496]), first, "../risc16f84_clk2x.v", 446, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[497]), first, "../risc16f84_clk2x.v", 544, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[498]), first, "../risc16f84_clk2x.v", 545, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[499]), first, "../risc16f84_clk2x.v", 546, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[500]), first, "../risc16f84_clk2x.v", 572, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[501]), first, "../risc16f84_clk2x.v", 574, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[502]), first, "../risc16f84_clk2x.v", 576, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[503]), first, "../risc16f84_clk2x.v", 580, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[504]), first, "../risc16f84_clk2x.v", 591, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[505]), first, "../risc16f84_clk2x.v", 595, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[506]), first, "../risc16f84_clk2x.v", 600, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[507]), first, "../risc16f84_clk2x.v", 666, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[508]), first, "../risc16f84_clk2x.v", 671, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[509]), first, "../risc16f84_clk2x.v", 677, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[510]), first, "../risc16f84_clk2x.v", 686, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[511]), first, "../risc16f84_clk2x.v", 733, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[512]), first, "../risc16f84_clk2x.v", 736, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[513]), first, "../risc16f84_clk2x.v", 739, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[514]), first, "../risc16f84_clk2x.v", 742, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[515]), first, "../risc16f84_clk2x.v", 745, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[516]), first, "../risc16f84_clk2x.v", 749, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[517]), first, "../risc16f84_clk2x.v", 752, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[518]), first, "../risc16f84_clk2x.v", 755, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[519]), first, "../risc16f84_clk2x.v", 759, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[520]), first, "../risc16f84_clk2x.v", 767, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[521]), first, "../risc16f84_clk2x.v", 786, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[522]), first, "../risc16f84_clk2x.v", 794, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[523]), first, "../risc16f84_clk2x.v", 798, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[524]), first, "../risc16f84_clk2x.v", 799, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[525]), first, "../risc16f84_clk2x.v", 804, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[526]), first, "../risc16f84_clk2x.v", 805, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[527]), first, "../risc16f84_clk2x.v", 807, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[528]), first, "../risc16f84_clk2x.v", 815, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[529]), first, "../risc16f84_clk2x.v", 818, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[530]), first, "../risc16f84_clk2x.v", 820, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[531]), first, "../risc16f84_clk2x.v", 823, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[532]), first, "../risc16f84_clk2x.v", 782, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[533]), first, "../risc16f84_clk2x.v", 840, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[534]), first, "../risc16f84_clk2x.v", 856, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[535]), first, "../risc16f84_clk2x.v", 862, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[536]), first, "../risc16f84_clk2x.v", 868, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[537]), first, "../risc16f84_clk2x.v", 878, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[538]), first, "../risc16f84_clk2x.v", 879, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[539]), first, "../risc16f84_clk2x.v", 884, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[540]), first, "../risc16f84_clk2x.v", 889, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[541]), first, "../risc16f84_clk2x.v", 895, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[542]), first, "../risc16f84_clk2x.v", 896, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[543]), first, "../risc16f84_clk2x.v", 897, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[544]), first, "../risc16f84_clk2x.v", 898, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[545]), first, "../risc16f84_clk2x.v", 899, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[546]), first, "../risc16f84_clk2x.v", 901, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[547]), first, "../risc16f84_clk2x.v", 902, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[548]), first, "../risc16f84_clk2x.v", 887, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[549]), first, "../risc16f84_clk2x.v", 906, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[550]), first, "../risc16f84_clk2x.v", 907, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[551]), first, "../risc16f84_clk2x.v", 853, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[552]), first, "../risc16f84_clk2x.v", 780, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[553]), first, "../risc16f84_clk2x.v", 934, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[554]), first, "../risc16f84_clk2x.v", 935, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[555]), first, "../risc16f84_clk2x.v", 934, 0, ".top.pic", "v_line/risc16f84_clk2x", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[556]), first, "../risc16f84_clk2x.v", 936, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[557]), first, "../risc16f84_clk2x.v", 937, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[558]), first, "../risc16f84_clk2x.v", 936, 0, ".top.pic", "v_line/risc16f84_clk2x", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[559]), first, "../risc16f84_clk2x.v", 938, 0, ".top.pic", "v_line/risc16f84_clk2x", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[560]), first, "../risc16f84_clk2x.v", 939, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[561]), first, "../risc16f84_clk2x.v", 940, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[562]), first, "../risc16f84_clk2x.v", 939, 0, ".top.pic", "v_line/risc16f84_clk2x", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[563]), first, "../risc16f84_clk2x.v", 943, 0, ".top.pic", "v_line/risc16f84_clk2x", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[564]), first, "../risc16f84_clk2x.v", 952, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[565]), first, "../risc16f84_clk2x.v", 953, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[566]), first, "../risc16f84_clk2x.v", 987, 0, ".top.pic", "v_toggle/risc16f84_clk2x", "int_combined");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[567]), first, "../risc16f84_clk2x.v", 989, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[568]), first, "../risc16f84_clk2x.v", 993, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[569]), first, "../risc16f84_clk2x.v", 990, 0, ".top.pic", "v_line/risc16f84_clk2x", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[570]), first, "../risc16f84_clk2x.v", 1005, 0, ".top.pic", "v_line/risc16f84_clk2x", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[571]), first, "../risc16f84_clk2x.v", 1006, 0, ".top.pic", "v_line/risc16f84_clk2x", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../uart/uart.v", 32, 0, ".top.pic.pic_uart", "v_toggle/uart", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "../uart/uart.v", 33, 0, ".top.pic.pic_uart", "v_toggle/uart", "rst");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[463]), first, "../uart/uart.v", 38, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tdata[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[464]), first, "../uart/uart.v", 38, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tdata[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[465]), first, "../uart/uart.v", 38, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tdata[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[466]), first, "../uart/uart.v", 38, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tdata[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[467]), first, "../uart/uart.v", 38, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tdata[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[468]), first, "../uart/uart.v", 38, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tdata[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[469]), first, "../uart/uart.v", 38, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tdata[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[470]), first, "../uart/uart.v", 38, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tdata[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[572]), first, "../uart/uart.v", 39, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tvalid");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[573]), first, "../uart/uart.v", 40, 0, ".top.pic.pic_uart", "v_toggle/uart", "input_axis_tready");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[455]), first, "../uart/uart.v", 45, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tdata[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[456]), first, "../uart/uart.v", 45, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tdata[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[457]), first, "../uart/uart.v", 45, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tdata[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[458]), first, "../uart/uart.v", 45, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tdata[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[459]), first, "../uart/uart.v", 45, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tdata[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[460]), first, "../uart/uart.v", 45, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tdata[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[461]), first, "../uart/uart.v", 45, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tdata[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[462]), first, "../uart/uart.v", 45, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tdata[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[574]), first, "../uart/uart.v", 46, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tvalid");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[575]), first, "../uart/uart.v", 47, 0, ".top.pic.pic_uart", "v_toggle/uart", "output_axis_tready");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "../uart/uart.v", 51, 0, ".top.pic.pic_uart", "v_toggle/uart", "rxd");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "../uart/uart.v", 52, 0, ".top.pic.pic_uart", "v_toggle/uart", "txd");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[576]), first, "../uart/uart.v", 57, 0, ".top.pic.pic_uart", "v_toggle/uart", "tx_busy");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[577]), first, "../uart/uart.v", 58, 0, ".top.pic.pic_uart", "v_toggle/uart", "rx_busy");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[578]), first, "../uart/uart.v", 59, 0, ".top.pic.pic_uart", "v_toggle/uart", "rx_overrun_error");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[579]), first, "../uart/uart.v", 60, 0, ".top.pic.pic_uart", "v_toggle/uart", "rx_frame_error");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "../uart/uart.v", 65, 0, ".top.pic.pic_uart", "v_toggle/uart", "prescale[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../uart/uart_tx.v", 32, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "../uart/uart_tx.v", 33, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "rst");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[463]), first, "../uart/uart_tx.v", 38, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[464]), first, "../uart/uart_tx.v", 38, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[465]), first, "../uart/uart_tx.v", 38, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[466]), first, "../uart/uart_tx.v", 38, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[467]), first, "../uart/uart_tx.v", 38, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[468]), first, "../uart/uart_tx.v", 38, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[469]), first, "../uart/uart_tx.v", 38, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[470]), first, "../uart/uart_tx.v", 38, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[572]), first, "../uart/uart_tx.v", 39, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tvalid");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[573]), first, "../uart/uart_tx.v", 40, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tready");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "../uart/uart_tx.v", 45, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "txd");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[576]), first, "../uart/uart_tx.v", 50, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "busy");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "../uart/uart_tx.v", 55, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[573]), first, "../uart/uart_tx.v", 58, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "input_axis_tready_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[580]), first, "../uart/uart_tx.v", 60, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "txd_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[576]), first, "../uart/uart_tx.v", 62, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "busy_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[581]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[582]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[583]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[584]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[585]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[586]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[587]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[588]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[589]), first, "../uart/uart_tx.v", 64, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "data_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[590]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[591]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[592]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[593]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[594]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[595]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[596]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[597]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[598]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[599]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[600]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[601]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[602]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[603]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[604]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[605]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[606]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[607]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[608]), first, "../uart/uart_tx.v", 65, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[609]), first, "../uart/uart_tx.v", 66, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "bit_cnt[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[610]), first, "../uart/uart_tx.v", 66, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "bit_cnt[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[611]), first, "../uart/uart_tx.v", 66, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "bit_cnt[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[612]), first, "../uart/uart_tx.v", 66, 0, ".top.pic.pic_uart.uart_tx_inst", "v_toggle/uart_tx", "bit_cnt[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[613]), first, "../uart/uart_tx.v", 74, 0, ".top.pic.pic_uart.uart_tx_inst", "v_line/uart_tx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[614]), first, "../uart/uart_tx.v", 81, 0, ".top.pic.pic_uart.uart_tx_inst", "v_line/uart_tx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[615]), first, "../uart/uart_tx.v", 88, 0, ".top.pic.pic_uart.uart_tx_inst", "v_line/uart_tx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[616]), first, "../uart/uart_tx.v", 84, 0, ".top.pic.pic_uart.uart_tx_inst", "v_line/uart_tx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[617]), first, "../uart/uart_tx.v", 97, 0, ".top.pic.pic_uart.uart_tx_inst", "v_line/uart_tx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[618]), first, "../uart/uart_tx.v", 101, 0, ".top.pic.pic_uart.uart_tx_inst", "v_line/uart_tx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[619]), first, "../uart/uart_tx.v", 96, 0, ".top.pic.pic_uart.uart_tx_inst", "v_line/uart_tx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[620]), first, "../uart/uart_tx.v", 80, 0, ".top.pic.pic_uart.uart_tx_inst", "v_line/uart_tx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../uart/uart_rx.v", 32, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "../uart/uart_rx.v", 33, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "rst");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[455]), first, "../uart/uart_rx.v", 38, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[456]), first, "../uart/uart_rx.v", 38, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[457]), first, "../uart/uart_rx.v", 38, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[458]), first, "../uart/uart_rx.v", 38, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[459]), first, "../uart/uart_rx.v", 38, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[460]), first, "../uart/uart_rx.v", 38, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[461]), first, "../uart/uart_rx.v", 38, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[462]), first, "../uart/uart_rx.v", 38, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[574]), first, "../uart/uart_rx.v", 39, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tvalid");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[575]), first, "../uart/uart_rx.v", 40, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tready");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "../uart/uart_rx.v", 45, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "rxd");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[577]), first, "../uart/uart_rx.v", 50, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "busy");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[578]), first, "../uart/uart_rx.v", 51, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "overrun_error");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[579]), first, "../uart/uart_rx.v", 52, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "frame_error");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "../uart/uart_rx.v", 57, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[455]), first, "../uart/uart_rx.v", 61, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[456]), first, "../uart/uart_rx.v", 61, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[457]), first, "../uart/uart_rx.v", 61, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[458]), first, "../uart/uart_rx.v", 61, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[459]), first, "../uart/uart_rx.v", 61, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[460]), first, "../uart/uart_rx.v", 61, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[461]), first, "../uart/uart_rx.v", 61, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[462]), first, "../uart/uart_rx.v", 61, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[574]), first, "../uart/uart_rx.v", 62, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "output_axis_tvalid_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[621]), first, "../uart/uart_rx.v", 64, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "rxd_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[577]), first, "../uart/uart_rx.v", 66, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "busy_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[578]), first, "../uart/uart_rx.v", 67, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "overrun_error_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[579]), first, "../uart/uart_rx.v", 68, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "frame_error_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[622]), first, "../uart/uart_rx.v", 70, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "data_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[623]), first, "../uart/uart_rx.v", 70, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "data_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[624]), first, "../uart/uart_rx.v", 70, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "data_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[625]), first, "../uart/uart_rx.v", 70, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "data_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[626]), first, "../uart/uart_rx.v", 70, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "data_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[627]), first, "../uart/uart_rx.v", 70, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "data_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[628]), first, "../uart/uart_rx.v", 70, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "data_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[629]), first, "../uart/uart_rx.v", 70, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "data_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[630]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[631]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[632]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[633]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[634]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[635]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[636]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[637]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[638]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[639]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[640]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[641]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[642]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[643]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[644]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[645]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[646]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[647]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[648]), first, "../uart/uart_rx.v", 71, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[649]), first, "../uart/uart_rx.v", 72, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "bit_cnt[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[650]), first, "../uart/uart_rx.v", 72, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "bit_cnt[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[651]), first, "../uart/uart_rx.v", 72, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "bit_cnt[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[652]), first, "../uart/uart_rx.v", 72, 0, ".top.pic.pic_uart.uart_rx_inst", "v_toggle/uart_rx", "bit_cnt[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[653]), first, "../uart/uart_rx.v", 82, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[654]), first, "../uart/uart_rx.v", 96, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[655]), first, "../uart/uart_rx.v", 100, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[656]), first, "../uart/uart_rx.v", 104, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[657]), first, "../uart/uart_rx.v", 107, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[658]), first, "../uart/uart_rx.v", 103, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[659]), first, "../uart/uart_rx.v", 111, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[660]), first, "../uart/uart_rx.v", 117, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[661]), first, "../uart/uart_rx.v", 121, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[662]), first, "../uart/uart_rx.v", 115, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[663]), first, "../uart/uart_rx.v", 102, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[664]), first, "../uart/uart_rx.v", 127, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[665]), first, "../uart/uart_rx.v", 125, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[666]), first, "../uart/uart_rx.v", 91, 0, ".top.pic.pic_uart.uart_rx_inst", "v_line/uart_rx", "else");
}
