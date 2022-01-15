// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"
#include "Vtop_uart.h"



// FUNCTIONS
Vtop__Syms::Vtop__Syms(Vtop* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__top__DOT__pic__DOT__pic_uart(Verilated::catName(topp->name(), "top.pic.pic_uart"))
    , TOP__top__DOT__tb_uart(Verilated::catName(topp->name(), "top.tb_uart"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT__top__DOT__pic__DOT__pic_uart = &TOP__top__DOT__pic__DOT__pic_uart;
    TOPp->__PVT__top__DOT__tb_uart = &TOP__top__DOT__tb_uart;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__top__DOT__pic__DOT__pic_uart.__Vconfigure(this, true);
    TOP__top__DOT__tb_uart.__Vconfigure(this, false);
}
