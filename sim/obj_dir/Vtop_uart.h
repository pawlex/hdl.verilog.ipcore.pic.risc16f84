// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef _VTOP_UART_H_
#define _VTOP_UART_H_  // guard

#include "verilated_heavy.h"
#include "verilated_cov.h"

//==========

class Vtop__Syms;

//----------

VL_MODULE(Vtop_uart) {
  public:
    
    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(input_axis_tdata,7,0);
    VL_IN8(input_axis_tvalid,0,0);
    VL_OUT8(input_axis_tready,0,0);
    VL_OUT8(output_axis_tdata,7,0);
    VL_OUT8(output_axis_tvalid,0,0);
    VL_IN8(output_axis_tready,0,0);
    VL_IN8(rxd,0,0);
    VL_OUT8(txd,0,0);
    VL_OUT8(tx_busy,0,0);
    VL_OUT8(rx_busy,0,0);
    VL_OUT8(rx_overrun_error,0,0);
    VL_OUT8(rx_frame_error,0,0);
    VL_IN16(prescale,15,0);
    
    // LOCAL SIGNALS
    CData/*0:0*/ __PVT__uart_tx_inst__DOT__input_axis_tready_reg;
    CData/*0:0*/ __PVT__uart_tx_inst__DOT__txd_reg;
    CData/*0:0*/ __PVT__uart_tx_inst__DOT__busy_reg;
    CData/*3:0*/ __PVT__uart_tx_inst__DOT__bit_cnt;
    CData/*7:0*/ __PVT__uart_rx_inst__DOT__output_axis_tdata_reg;
    CData/*0:0*/ __PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    CData/*0:0*/ __PVT__uart_rx_inst__DOT__rxd_reg;
    CData/*0:0*/ __PVT__uart_rx_inst__DOT__busy_reg;
    CData/*0:0*/ __PVT__uart_rx_inst__DOT__overrun_error_reg;
    CData/*0:0*/ __PVT__uart_rx_inst__DOT__frame_error_reg;
    CData/*7:0*/ __PVT__uart_rx_inst__DOT__data_reg;
    CData/*3:0*/ __PVT__uart_rx_inst__DOT__bit_cnt;
    SData/*8:0*/ __PVT__uart_tx_inst__DOT__data_reg;
    IData/*18:0*/ __PVT__uart_tx_inst__DOT__prescale_reg;
    IData/*18:0*/ __PVT__uart_rx_inst__DOT__prescale_reg;
    
    // LOCAL VARIABLES
    CData/*0:0*/ __Vtogcov__input_axis_tvalid;
    CData/*0:0*/ __Vtogcov__input_axis_tready;
    CData/*7:0*/ __Vtogcov__output_axis_tdata;
    CData/*0:0*/ __Vtogcov__output_axis_tvalid;
    CData/*0:0*/ __Vtogcov__output_axis_tready;
    CData/*0:0*/ __Vtogcov__tx_busy;
    CData/*0:0*/ __Vtogcov__rx_busy;
    CData/*0:0*/ __Vtogcov__rx_overrun_error;
    CData/*0:0*/ __Vtogcov__rx_frame_error;
    CData/*3:0*/ uart_tx_inst__DOT____Vtogcov__bit_cnt;
    CData/*0:0*/ uart_rx_inst__DOT____Vtogcov__rxd_reg;
    CData/*7:0*/ uart_rx_inst__DOT____Vtogcov__data_reg;
    CData/*3:0*/ uart_rx_inst__DOT____Vtogcov__bit_cnt;
    CData/*0:0*/ __Vdly__uart_tx_inst__DOT__input_axis_tready_reg;
    CData/*3:0*/ __Vdly__uart_tx_inst__DOT__bit_cnt;
    CData/*0:0*/ __Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg;
    CData/*3:0*/ __Vdly__uart_rx_inst__DOT__bit_cnt;
    CData/*7:0*/ __Vdly__uart_rx_inst__DOT__data_reg;
    SData/*8:0*/ uart_tx_inst__DOT____Vtogcov__data_reg;
    SData/*8:0*/ __Vdly__uart_tx_inst__DOT__data_reg;
    IData/*18:0*/ uart_tx_inst__DOT____Vtogcov__prescale_reg;
    IData/*18:0*/ uart_rx_inst__DOT____Vtogcov__prescale_reg;
    IData/*18:0*/ __Vdly__uart_tx_inst__DOT__prescale_reg;
    IData/*18:0*/ __Vdly__uart_rx_inst__DOT__prescale_reg;
    
    // INTERNAL VARIABLES
  private:
    Vtop__Syms* __VlSymsp;  // Symbol table
  public:
  private:
    // Coverage
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_uart);  ///< Copying not allowed
  public:
    Vtop_uart(const char* name = "TOP");
    ~Vtop_uart();
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    void _configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    void _initial__TOP__top__DOT__pic__DOT__pic_uart__3(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _initial__TOP__top__DOT__tb_uart__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _sequent__TOP__top__DOT__pic__DOT__pic_uart__5(Vtop__Syms* __restrict vlSymsp);
    void _sequent__TOP__top__DOT__tb_uart__4(Vtop__Syms* __restrict vlSymsp);
    void _sequent__TOP__top__DOT__tb_uart__6(Vtop__Syms* __restrict vlSymsp);
    void _settle__TOP__top__DOT__pic__DOT__pic_uart__1(Vtop__Syms* __restrict vlSymsp);
    void _settle__TOP__top__DOT__pic__DOT__pic_uart__8(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__top__DOT__tb_uart__7(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
