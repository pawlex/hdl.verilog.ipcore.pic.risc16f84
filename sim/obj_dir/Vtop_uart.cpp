// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop_uart.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop_uart) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_uart::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    _configure_coverage(vlSymsp, first);
}

Vtop_uart::~Vtop_uart() {
}

// Coverage
void Vtop_uart::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp);
}

void Vtop_uart::_initial__TOP__top__DOT__tb_uart__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_initial__TOP__top__DOT__tb_uart__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__uart_tx_inst__DOT__busy_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__busy_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__overrun_error_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__frame_error_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__rxd_reg = 1U;
    this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__bit_cnt = 0U;
    this->__PVT__uart_rx_inst__DOT__data_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__prescale_reg = 0U;
    this->__PVT__uart_tx_inst__DOT__txd_reg = 1U;
    this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
    this->__PVT__uart_tx_inst__DOT__bit_cnt = 0U;
    this->__PVT__uart_tx_inst__DOT__data_reg = 0U;
    this->__PVT__uart_tx_inst__DOT__prescale_reg = 0U;
}

VL_INLINE_OPT void Vtop_uart::_sequent__TOP__top__DOT__tb_uart__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_sequent__TOP__top__DOT__tb_uart__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg 
        = this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg;
    this->__Vdly__uart_tx_inst__DOT__bit_cnt = this->__PVT__uart_tx_inst__DOT__bit_cnt;
    this->__Vdly__uart_tx_inst__DOT__data_reg = this->__PVT__uart_tx_inst__DOT__data_reg;
    this->__Vdly__uart_tx_inst__DOT__prescale_reg = this->__PVT__uart_tx_inst__DOT__prescale_reg;
    this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg 
        = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    this->__Vdly__uart_rx_inst__DOT__bit_cnt = this->__PVT__uart_rx_inst__DOT__bit_cnt;
    this->__Vdly__uart_rx_inst__DOT__data_reg = this->__PVT__uart_rx_inst__DOT__data_reg;
    this->__Vdly__uart_rx_inst__DOT__prescale_reg = this->__PVT__uart_rx_inst__DOT__prescale_reg;
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[732]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[739]);
    }
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[772]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[785]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if (((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
             & (IData)(vlTOPp->uart_rx_ready_i))) {
            ++(vlSymsp->__Vcoverage[773]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U < this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            ++(vlSymsp->__Vcoverage[733]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U < this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            ++(vlSymsp->__Vcoverage[774]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                if ((1U < (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                    ++(vlSymsp->__Vcoverage[736]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[738]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[735]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                if ((1U >= (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                    if ((1U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                        ++(vlSymsp->__Vcoverage[737]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                if (vlTOPp->uart_tx_valid_i) {
                    ++(vlSymsp->__Vcoverage[734]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        ++(vlSymsp->__Vcoverage[778]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    ++(vlSymsp->__Vcoverage[777]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[782]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                            ++(vlSymsp->__Vcoverage[781]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[784]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U & (~ (IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg)))) {
                        ++(vlSymsp->__Vcoverage[775]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if (this->__PVT__uart_rx_inst__DOT__rxd_reg) {
                        ++(vlSymsp->__Vcoverage[776]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                            if (this->__PVT__uart_rx_inst__DOT__rxd_reg) {
                                ++(vlSymsp->__Vcoverage[779]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                            if ((1U & (~ (IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg)))) {
                                ++(vlSymsp->__Vcoverage[780]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((1U & (~ (IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg)))) {
                    ++(vlSymsp->__Vcoverage[783]);
                }
            }
        }
    }
    if (vlTOPp->top__DOT__reset) {
        this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg = 0U;
        this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
        this->__Vdly__uart_rx_inst__DOT__prescale_reg = 0U;
        this->__Vdly__uart_rx_inst__DOT__bit_cnt = 0U;
        this->__PVT__uart_rx_inst__DOT__busy_reg = 0U;
        this->__PVT__uart_rx_inst__DOT__overrun_error_reg = 0U;
        this->__PVT__uart_rx_inst__DOT__frame_error_reg = 0U;
    } else {
        this->__PVT__uart_rx_inst__DOT__overrun_error_reg = 0U;
        this->__PVT__uart_rx_inst__DOT__frame_error_reg = 0U;
        if (((IData)(this->output_axis_tvalid) & (IData)(vlTOPp->uart_rx_ready_i))) {
            this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
        }
        if ((0U < this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            this->__Vdly__uart_rx_inst__DOT__prescale_reg 
                = (0x7ffffU & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                               - (IData)(1U)));
        } else {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if (this->__PVT__uart_rx_inst__DOT__rxd_reg) {
                        this->__Vdly__uart_rx_inst__DOT__bit_cnt = 0U;
                        this->__Vdly__uart_rx_inst__DOT__prescale_reg = 0U;
                    } else {
                        this->__Vdly__uart_rx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        this->__Vdly__uart_rx_inst__DOT__prescale_reg 
                            = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                            << 3U) 
                                           - (IData)(1U)));
                    }
                } else {
                    if ((1U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        this->__Vdly__uart_rx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        this->__Vdly__uart_rx_inst__DOT__data_reg 
                            = (((IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg) 
                                << 7U) | (0x7fU & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                                                   >> 1U)));
                        this->__Vdly__uart_rx_inst__DOT__prescale_reg 
                            = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                            << 3U) 
                                           - (IData)(1U)));
                    } else {
                        if ((1U == (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                            this->__Vdly__uart_rx_inst__DOT__bit_cnt 
                                = (0xfU & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
                                           - (IData)(1U)));
                            if (this->__PVT__uart_rx_inst__DOT__rxd_reg) {
                                this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg 
                                    = this->__PVT__uart_rx_inst__DOT__data_reg;
                                this->__PVT__uart_rx_inst__DOT__overrun_error_reg 
                                    = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
                                this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg = 1U;
                            } else {
                                this->__PVT__uart_rx_inst__DOT__frame_error_reg = 1U;
                            }
                        }
                    }
                }
            } else {
                this->__PVT__uart_rx_inst__DOT__busy_reg = 0U;
                if ((1U & (~ (IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg)))) {
                    this->__Vdly__uart_rx_inst__DOT__data_reg = 0U;
                    this->__Vdly__uart_rx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 2U) - (IData)(2U)));
                    this->__Vdly__uart_rx_inst__DOT__bit_cnt = 0xaU;
                    this->__PVT__uart_rx_inst__DOT__busy_reg = 1U;
                }
            }
        }
    }
    this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg 
        = this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg;
    this->__PVT__uart_rx_inst__DOT__bit_cnt = this->__Vdly__uart_rx_inst__DOT__bit_cnt;
    this->__PVT__uart_rx_inst__DOT__data_reg = this->__Vdly__uart_rx_inst__DOT__data_reg;
    this->__PVT__uart_rx_inst__DOT__prescale_reg = this->__Vdly__uart_rx_inst__DOT__prescale_reg;
    if (((IData)(this->__PVT__uart_rx_inst__DOT__busy_reg) 
         ^ this->__Vtogcov__rx_busy)) {
        ++(vlSymsp->__Vcoverage[697]);
        this->__Vtogcov__rx_busy = this->__PVT__uart_rx_inst__DOT__busy_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__overrun_error_reg) 
         ^ this->__Vtogcov__rx_overrun_error)) {
        ++(vlSymsp->__Vcoverage[698]);
        this->__Vtogcov__rx_overrun_error = this->__PVT__uart_rx_inst__DOT__overrun_error_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__frame_error_reg) 
         ^ this->__Vtogcov__rx_frame_error)) {
        ++(vlSymsp->__Vcoverage[699]);
        this->__Vtogcov__rx_frame_error = this->__PVT__uart_rx_inst__DOT__frame_error_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
         ^ this->__Vtogcov__output_axis_tvalid)) {
        ++(vlSymsp->__Vcoverage[695]);
        this->__Vtogcov__output_axis_tvalid = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    }
    this->output_axis_tvalid = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[768]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[769]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[770]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[771]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[741]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfeU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[742]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfdU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[743]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfbU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[744]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xf7U & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[745]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xefU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[746]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xdfU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[747]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xbfU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[748]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0x7fU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[577]);
        this->__Vtogcov__output_axis_tdata = ((0xfeU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (1U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[578]);
        this->__Vtogcov__output_axis_tdata = ((0xfdU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (2U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[579]);
        this->__Vtogcov__output_axis_tdata = ((0xfbU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (4U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[580]);
        this->__Vtogcov__output_axis_tdata = ((0xf7U 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (8U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[581]);
        this->__Vtogcov__output_axis_tdata = ((0xefU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (0x10U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[582]);
        this->__Vtogcov__output_axis_tdata = ((0xdfU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (0x20U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[583]);
        this->__Vtogcov__output_axis_tdata = ((0xbfU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (0x40U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[584]);
        this->__Vtogcov__output_axis_tdata = ((0x7fU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (0x80U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((1U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[749]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((2U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[750]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((4U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[751]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((8U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[752]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[753]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[754]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[755]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[756]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[757]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[758]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[759]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[760]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[761]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[762]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[763]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[764]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[765]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[766]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[767]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    this->__PVT__uart_rx_inst__DOT__rxd_reg = ((IData)(vlTOPp->top__DOT__reset) 
                                               | (IData)(vlSymsp->TOP__top__DOT__pic__DOT__pic_uart.__PVT__uart_tx_inst__DOT__txd_reg));
    if (((IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg) 
         ^ this->uart_rx_inst__DOT____Vtogcov__rxd_reg)) {
        ++(vlSymsp->__Vcoverage[740]);
        this->uart_rx_inst__DOT____Vtogcov__rxd_reg 
            = this->__PVT__uart_rx_inst__DOT__rxd_reg;
    }
}

VL_INLINE_OPT void Vtop_uart::_sequent__TOP__top__DOT__tb_uart__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_sequent__TOP__top__DOT__tb_uart__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__reset) {
        this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
        this->__PVT__uart_tx_inst__DOT__txd_reg = 1U;
        this->__Vdly__uart_tx_inst__DOT__prescale_reg = 0U;
        this->__Vdly__uart_tx_inst__DOT__bit_cnt = 0U;
        this->__PVT__uart_tx_inst__DOT__busy_reg = 0U;
    } else {
        if ((0U < this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            this->__Vdly__uart_tx_inst__DOT__prescale_reg 
                = (0x7ffffU & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                               - (IData)(1U)));
            this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
        } else {
            if ((0U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg = 1U;
                this->__PVT__uart_tx_inst__DOT__busy_reg = 0U;
                if (vlTOPp->uart_tx_valid_i) {
                    this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg 
                        = (1U & (~ (IData)(this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg)));
                    this->__Vdly__uart_tx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 3U) - (IData)(1U)));
                    this->__Vdly__uart_tx_inst__DOT__bit_cnt = 9U;
                    this->__Vdly__uart_tx_inst__DOT__data_reg 
                        = (0x100U | (IData)(vlTOPp->uart_tx_data_i));
                    this->__PVT__uart_tx_inst__DOT__txd_reg = 0U;
                    this->__PVT__uart_tx_inst__DOT__busy_reg = 1U;
                }
            } else {
                if ((1U < (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                    this->__Vdly__uart_tx_inst__DOT__bit_cnt 
                        = (0xfU & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
                                   - (IData)(1U)));
                    this->__Vdly__uart_tx_inst__DOT__data_reg 
                        = (0x1ffU & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                                     >> 1U));
                    this->__Vdly__uart_tx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 3U) - (IData)(1U)));
                    this->__PVT__uart_tx_inst__DOT__txd_reg 
                        = (1U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg));
                } else {
                    if ((1U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                        this->__Vdly__uart_tx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        this->__Vdly__uart_tx_inst__DOT__prescale_reg 
                            = (0x7ffffU & ((IData)(vlTOPp->uart_prescale) 
                                           << 3U));
                        this->__PVT__uart_tx_inst__DOT__txd_reg = 1U;
                    }
                }
            }
        }
    }
    this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg 
        = this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg;
    this->__PVT__uart_tx_inst__DOT__bit_cnt = this->__Vdly__uart_tx_inst__DOT__bit_cnt;
    this->__PVT__uart_tx_inst__DOT__data_reg = this->__Vdly__uart_tx_inst__DOT__data_reg;
    this->__PVT__uart_tx_inst__DOT__prescale_reg = this->__Vdly__uart_tx_inst__DOT__prescale_reg;
    if (((IData)(this->__PVT__uart_tx_inst__DOT__busy_reg) 
         ^ this->__Vtogcov__tx_busy)) {
        ++(vlSymsp->__Vcoverage[696]);
        this->__Vtogcov__tx_busy = this->__PVT__uart_tx_inst__DOT__busy_reg;
    }
    if (((IData)(this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg) 
         ^ this->__Vtogcov__input_axis_tready)) {
        ++(vlSymsp->__Vcoverage[694]);
        this->__Vtogcov__input_axis_tready = this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg;
    }
    if ((1U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[728]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[729]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[730]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[731]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[700]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1feU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[701]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fdU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[702]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fbU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[703]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1f7U & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[704]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1efU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[705]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1dfU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[706]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1bfU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[707]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x17fU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x100U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                   ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[708]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0xffU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x100U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((1U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[709]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((2U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[710]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((4U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[711]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((8U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[712]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[713]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[714]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[715]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[716]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[717]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[718]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[719]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[720]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[721]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[722]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[723]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[724]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[725]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[726]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[727]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
}

void Vtop_uart::_settle__TOP__top__DOT__tb_uart__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_settle__TOP__top__DOT__tb_uart__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(this->__PVT__uart_tx_inst__DOT__busy_reg) 
         ^ this->__Vtogcov__tx_busy)) {
        ++(vlSymsp->__Vcoverage[696]);
        this->__Vtogcov__tx_busy = this->__PVT__uart_tx_inst__DOT__busy_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__busy_reg) 
         ^ this->__Vtogcov__rx_busy)) {
        ++(vlSymsp->__Vcoverage[697]);
        this->__Vtogcov__rx_busy = this->__PVT__uart_rx_inst__DOT__busy_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__overrun_error_reg) 
         ^ this->__Vtogcov__rx_overrun_error)) {
        ++(vlSymsp->__Vcoverage[698]);
        this->__Vtogcov__rx_overrun_error = this->__PVT__uart_rx_inst__DOT__overrun_error_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__frame_error_reg) 
         ^ this->__Vtogcov__rx_frame_error)) {
        ++(vlSymsp->__Vcoverage[699]);
        this->__Vtogcov__rx_frame_error = this->__PVT__uart_rx_inst__DOT__frame_error_reg;
    }
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[577]);
        this->__Vtogcov__output_axis_tdata = ((0xfeU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (1U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[578]);
        this->__Vtogcov__output_axis_tdata = ((0xfdU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (2U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[579]);
        this->__Vtogcov__output_axis_tdata = ((0xfbU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (4U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
               ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[580]);
        this->__Vtogcov__output_axis_tdata = ((0xf7U 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (8U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[581]);
        this->__Vtogcov__output_axis_tdata = ((0xefU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (0x10U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[582]);
        this->__Vtogcov__output_axis_tdata = ((0xdfU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (0x20U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[583]);
        this->__Vtogcov__output_axis_tdata = ((0xbfU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (0x40U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg) 
                  ^ this->__Vtogcov__output_axis_tdata))) {
        ++(vlSymsp->__Vcoverage[584]);
        this->__Vtogcov__output_axis_tdata = ((0x7fU 
                                               & (IData)(this->__Vtogcov__output_axis_tdata)) 
                                              | (0x80U 
                                                 & (IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg)));
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg) 
         ^ this->uart_rx_inst__DOT____Vtogcov__rxd_reg)) {
        ++(vlSymsp->__Vcoverage[740]);
        this->uart_rx_inst__DOT____Vtogcov__rxd_reg 
            = this->__PVT__uart_rx_inst__DOT__rxd_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
         ^ this->__Vtogcov__output_axis_tvalid)) {
        ++(vlSymsp->__Vcoverage[695]);
        this->__Vtogcov__output_axis_tvalid = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    }
    this->output_axis_tvalid = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[768]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[769]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[770]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[771]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[741]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfeU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[742]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfdU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[743]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfbU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[744]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xf7U & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[745]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xefU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[746]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xdfU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[747]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xbfU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[748]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0x7fU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((1U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[749]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((2U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[750]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((4U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[751]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((8U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[752]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[753]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[754]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[755]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[756]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[757]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[758]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[759]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[760]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[761]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[762]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[763]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[764]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[765]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[766]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[767]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if (((IData)(this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg) 
         ^ this->__Vtogcov__input_axis_tready)) {
        ++(vlSymsp->__Vcoverage[694]);
        this->__Vtogcov__input_axis_tready = this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg;
    }
    if ((1U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[728]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[729]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[730]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[731]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[700]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1feU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[701]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fdU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[702]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fbU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[703]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1f7U & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[704]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1efU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[705]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1dfU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[706]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1bfU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[707]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x17fU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x100U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                   ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[708]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0xffU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x100U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((1U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[709]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((2U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[710]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((4U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[711]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((8U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[712]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[713]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[714]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[715]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[716]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[717]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[718]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[719]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[720]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[721]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[722]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[723]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[724]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[725]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[726]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[727]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
}

VL_INLINE_OPT void Vtop_uart::_settle__TOP__top__DOT__pic__DOT__pic_uart__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_settle__TOP__top__DOT__pic__DOT__pic_uart__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 7U) ^ this->__Vtogcov__input_axis_tvalid))) {
        ++(vlSymsp->__Vcoverage[35]);
        this->__Vtogcov__input_axis_tvalid = (1U & 
                                              ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                                               >> 7U));
    }
    if ((1U & (((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 6U) ^ this->__Vtogcov__output_axis_tready))) {
        ++(vlSymsp->__Vcoverage[34]);
        this->__Vtogcov__output_axis_tready = (1U & 
                                               ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                                                >> 6U));
    }
}

void Vtop_uart::_initial__TOP__top__DOT__pic__DOT__pic_uart__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_initial__TOP__top__DOT__pic__DOT__pic_uart__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg = 0U;
    this->__PVT__uart_tx_inst__DOT__busy_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__busy_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__overrun_error_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__frame_error_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__rxd_reg = 1U;
    this->__PVT__uart_rx_inst__DOT__bit_cnt = 0U;
    this->__PVT__uart_rx_inst__DOT__data_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__prescale_reg = 0U;
    this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
    this->__PVT__uart_tx_inst__DOT__txd_reg = 1U;
    this->__PVT__uart_tx_inst__DOT__bit_cnt = 0U;
    this->__PVT__uart_tx_inst__DOT__data_reg = 0U;
    this->__PVT__uart_tx_inst__DOT__prescale_reg = 0U;
    this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
}

VL_INLINE_OPT void Vtop_uart::_sequent__TOP__top__DOT__pic__DOT__pic_uart__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_sequent__TOP__top__DOT__pic__DOT__pic_uart__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__Vdly__uart_rx_inst__DOT__bit_cnt = this->__PVT__uart_rx_inst__DOT__bit_cnt;
    this->__Vdly__uart_rx_inst__DOT__data_reg = this->__PVT__uart_rx_inst__DOT__data_reg;
    this->__Vdly__uart_rx_inst__DOT__prescale_reg = this->__PVT__uart_rx_inst__DOT__prescale_reg;
    this->__Vdly__uart_tx_inst__DOT__bit_cnt = this->__PVT__uart_tx_inst__DOT__bit_cnt;
    this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg 
        = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    this->__Vdly__uart_tx_inst__DOT__data_reg = this->__PVT__uart_tx_inst__DOT__data_reg;
    this->__Vdly__uart_tx_inst__DOT__prescale_reg = this->__PVT__uart_tx_inst__DOT__prescale_reg;
    this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg 
        = this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg;
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[732]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[739]);
    }
    if (vlTOPp->top__DOT__reset) {
        ++(vlSymsp->__Vcoverage[772]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        ++(vlSymsp->__Vcoverage[785]);
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U < this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            ++(vlSymsp->__Vcoverage[733]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U < this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            ++(vlSymsp->__Vcoverage[774]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                if ((1U < (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                    ++(vlSymsp->__Vcoverage[736]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[738]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[735]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U != (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                if ((1U >= (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                    if ((1U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                        ++(vlSymsp->__Vcoverage[737]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        ++(vlSymsp->__Vcoverage[778]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    ++(vlSymsp->__Vcoverage[777]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[782]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                            ++(vlSymsp->__Vcoverage[781]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                ++(vlSymsp->__Vcoverage[784]);
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U & (~ (IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg)))) {
                        ++(vlSymsp->__Vcoverage[775]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if (this->__PVT__uart_rx_inst__DOT__rxd_reg) {
                        ++(vlSymsp->__Vcoverage[776]);
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                            if (this->__PVT__uart_rx_inst__DOT__rxd_reg) {
                                ++(vlSymsp->__Vcoverage[779]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if ((1U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        if ((1U == (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                            if ((1U & (~ (IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg)))) {
                                ++(vlSymsp->__Vcoverage[780]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            if ((0U >= (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((1U & (~ (IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg)))) {
                    ++(vlSymsp->__Vcoverage[783]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if ((0U >= this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            if ((0U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                if ((0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff))) {
                    ++(vlSymsp->__Vcoverage[734]);
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__reset)))) {
        if (((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
             & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                >> 6U))) {
            ++(vlSymsp->__Vcoverage[773]);
        }
    }
    if (vlTOPp->top__DOT__reset) {
        this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg = 0U;
        this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
        this->__Vdly__uart_rx_inst__DOT__prescale_reg = 0U;
        this->__Vdly__uart_rx_inst__DOT__bit_cnt = 0U;
        this->__PVT__uart_rx_inst__DOT__busy_reg = 0U;
        this->__PVT__uart_rx_inst__DOT__overrun_error_reg = 0U;
        this->__PVT__uart_rx_inst__DOT__frame_error_reg = 0U;
    } else {
        this->__PVT__uart_rx_inst__DOT__overrun_error_reg = 0U;
        this->__PVT__uart_rx_inst__DOT__frame_error_reg = 0U;
        if (((IData)(this->output_axis_tvalid) & ((IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff) 
                                                  >> 6U))) {
            this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg = 0U;
        }
        if ((0U < this->__PVT__uart_rx_inst__DOT__prescale_reg)) {
            this->__Vdly__uart_rx_inst__DOT__prescale_reg 
                = (0x7ffffU & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                               - (IData)(1U)));
        } else {
            if ((0U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                if ((9U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                    if (this->__PVT__uart_rx_inst__DOT__rxd_reg) {
                        this->__Vdly__uart_rx_inst__DOT__bit_cnt = 0U;
                        this->__Vdly__uart_rx_inst__DOT__prescale_reg = 0U;
                    } else {
                        this->__Vdly__uart_rx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        this->__Vdly__uart_rx_inst__DOT__prescale_reg 
                            = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                            << 3U) 
                                           - (IData)(1U)));
                    }
                } else {
                    if ((1U < (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                        this->__Vdly__uart_rx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        this->__Vdly__uart_rx_inst__DOT__data_reg 
                            = (((IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg) 
                                << 7U) | (0x7fU & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                                                   >> 1U)));
                        this->__Vdly__uart_rx_inst__DOT__prescale_reg 
                            = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                            << 3U) 
                                           - (IData)(1U)));
                    } else {
                        if ((1U == (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt))) {
                            this->__Vdly__uart_rx_inst__DOT__bit_cnt 
                                = (0xfU & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
                                           - (IData)(1U)));
                            if (this->__PVT__uart_rx_inst__DOT__rxd_reg) {
                                this->__PVT__uart_rx_inst__DOT__output_axis_tdata_reg 
                                    = this->__PVT__uart_rx_inst__DOT__data_reg;
                                this->__PVT__uart_rx_inst__DOT__overrun_error_reg 
                                    = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
                                this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg = 1U;
                            } else {
                                this->__PVT__uart_rx_inst__DOT__frame_error_reg = 1U;
                            }
                        }
                    }
                }
            } else {
                this->__PVT__uart_rx_inst__DOT__busy_reg = 0U;
                if ((1U & (~ (IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg)))) {
                    this->__Vdly__uart_rx_inst__DOT__data_reg = 0U;
                    this->__Vdly__uart_rx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 2U) - (IData)(2U)));
                    this->__Vdly__uart_rx_inst__DOT__bit_cnt = 0xaU;
                    this->__PVT__uart_rx_inst__DOT__busy_reg = 1U;
                }
            }
        }
    }
    if (vlTOPp->top__DOT__reset) {
        this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
        this->__PVT__uart_tx_inst__DOT__txd_reg = 1U;
        this->__Vdly__uart_tx_inst__DOT__prescale_reg = 0U;
        this->__Vdly__uart_tx_inst__DOT__bit_cnt = 0U;
        this->__PVT__uart_tx_inst__DOT__busy_reg = 0U;
    } else {
        if ((0U < this->__PVT__uart_tx_inst__DOT__prescale_reg)) {
            this->__Vdly__uart_tx_inst__DOT__prescale_reg 
                = (0x7ffffU & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                               - (IData)(1U)));
            this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg = 0U;
        } else {
            if ((0U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg = 1U;
                this->__PVT__uart_tx_inst__DOT__busy_reg = 0U;
                if ((0x80U & (IData)(vlTOPp->top__DOT__pic__DOT__uart_sr_ff))) {
                    this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg 
                        = (1U & (~ (IData)(this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg)));
                    this->__Vdly__uart_tx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 3U) - (IData)(1U)));
                    this->__Vdly__uart_tx_inst__DOT__bit_cnt = 9U;
                    this->__Vdly__uart_tx_inst__DOT__data_reg 
                        = (0x100U | (IData)(vlTOPp->top__DOT__pic__DOT__uart_tx_data));
                    this->__PVT__uart_tx_inst__DOT__txd_reg = 0U;
                    this->__PVT__uart_tx_inst__DOT__busy_reg = 1U;
                }
            } else {
                if ((1U < (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                    this->__Vdly__uart_tx_inst__DOT__bit_cnt 
                        = (0xfU & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
                                   - (IData)(1U)));
                    this->__Vdly__uart_tx_inst__DOT__data_reg 
                        = (0x1ffU & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                                     >> 1U));
                    this->__Vdly__uart_tx_inst__DOT__prescale_reg 
                        = (0x7ffffU & (((IData)(vlTOPp->uart_prescale) 
                                        << 3U) - (IData)(1U)));
                    this->__PVT__uart_tx_inst__DOT__txd_reg 
                        = (1U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg));
                } else {
                    if ((1U == (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt))) {
                        this->__Vdly__uart_tx_inst__DOT__bit_cnt 
                            = (0xfU & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
                                       - (IData)(1U)));
                        this->__Vdly__uart_tx_inst__DOT__prescale_reg 
                            = (0x7ffffU & ((IData)(vlTOPp->uart_prescale) 
                                           << 3U));
                        this->__PVT__uart_tx_inst__DOT__txd_reg = 1U;
                    }
                }
            }
        }
    }
    this->__PVT__uart_rx_inst__DOT__bit_cnt = this->__Vdly__uart_rx_inst__DOT__bit_cnt;
    this->__PVT__uart_rx_inst__DOT__data_reg = this->__Vdly__uart_rx_inst__DOT__data_reg;
    this->__PVT__uart_rx_inst__DOT__prescale_reg = this->__Vdly__uart_rx_inst__DOT__prescale_reg;
    this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg 
        = this->__Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg;
    this->__PVT__uart_tx_inst__DOT__bit_cnt = this->__Vdly__uart_tx_inst__DOT__bit_cnt;
    this->__PVT__uart_tx_inst__DOT__data_reg = this->__Vdly__uart_tx_inst__DOT__data_reg;
    this->__PVT__uart_tx_inst__DOT__prescale_reg = this->__Vdly__uart_tx_inst__DOT__prescale_reg;
    this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg 
        = this->__Vdly__uart_tx_inst__DOT__input_axis_tready_reg;
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[768]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[769]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[770]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[771]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[741]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfeU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[742]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfdU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[743]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfbU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[744]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xf7U & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[745]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xefU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[746]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xdfU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[747]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xbfU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[748]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0x7fU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((1U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[749]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((2U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[750]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((4U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[751]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((8U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[752]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[753]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[754]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[755]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[756]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[757]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[758]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[759]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[760]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[761]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[762]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[763]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[764]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[765]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[766]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[767]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__busy_reg) 
         ^ this->__Vtogcov__rx_busy)) {
        ++(vlSymsp->__Vcoverage[697]);
        this->__Vtogcov__rx_busy = this->__PVT__uart_rx_inst__DOT__busy_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__overrun_error_reg) 
         ^ this->__Vtogcov__rx_overrun_error)) {
        ++(vlSymsp->__Vcoverage[698]);
        this->__Vtogcov__rx_overrun_error = this->__PVT__uart_rx_inst__DOT__overrun_error_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__frame_error_reg) 
         ^ this->__Vtogcov__rx_frame_error)) {
        ++(vlSymsp->__Vcoverage[699]);
        this->__Vtogcov__rx_frame_error = this->__PVT__uart_rx_inst__DOT__frame_error_reg;
    }
    this->__PVT__uart_rx_inst__DOT__rxd_reg = ((IData)(vlTOPp->top__DOT__reset) 
                                               | (IData)(vlSymsp->TOP__top__DOT__tb_uart.__PVT__uart_tx_inst__DOT__txd_reg));
    if (((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
         ^ this->__Vtogcov__output_axis_tvalid)) {
        ++(vlSymsp->__Vcoverage[695]);
        this->__Vtogcov__output_axis_tvalid = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    }
    this->output_axis_tvalid = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    if ((1U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[728]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[729]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[730]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[731]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[700]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1feU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[701]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fdU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[702]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fbU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[703]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1f7U & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[704]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1efU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[705]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1dfU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[706]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1bfU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[707]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x17fU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x100U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                   ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[708]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0xffU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x100U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((1U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[709]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((2U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[710]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((4U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[711]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((8U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[712]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[713]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[714]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[715]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[716]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[717]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[718]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[719]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[720]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[721]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[722]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[723]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[724]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[725]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[726]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[727]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if (((IData)(this->__PVT__uart_tx_inst__DOT__busy_reg) 
         ^ this->__Vtogcov__tx_busy)) {
        ++(vlSymsp->__Vcoverage[696]);
        this->__Vtogcov__tx_busy = this->__PVT__uart_tx_inst__DOT__busy_reg;
    }
    if (((IData)(this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg) 
         ^ this->__Vtogcov__input_axis_tready)) {
        ++(vlSymsp->__Vcoverage[694]);
        this->__Vtogcov__input_axis_tready = this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg) 
         ^ this->uart_rx_inst__DOT____Vtogcov__rxd_reg)) {
        ++(vlSymsp->__Vcoverage[740]);
        this->uart_rx_inst__DOT____Vtogcov__rxd_reg 
            = this->__PVT__uart_rx_inst__DOT__rxd_reg;
    }
}

void Vtop_uart::_settle__TOP__top__DOT__pic__DOT__pic_uart__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_settle__TOP__top__DOT__pic__DOT__pic_uart__8\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(this->__PVT__uart_tx_inst__DOT__busy_reg) 
         ^ this->__Vtogcov__tx_busy)) {
        ++(vlSymsp->__Vcoverage[696]);
        this->__Vtogcov__tx_busy = this->__PVT__uart_tx_inst__DOT__busy_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__busy_reg) 
         ^ this->__Vtogcov__rx_busy)) {
        ++(vlSymsp->__Vcoverage[697]);
        this->__Vtogcov__rx_busy = this->__PVT__uart_rx_inst__DOT__busy_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__overrun_error_reg) 
         ^ this->__Vtogcov__rx_overrun_error)) {
        ++(vlSymsp->__Vcoverage[698]);
        this->__Vtogcov__rx_overrun_error = this->__PVT__uart_rx_inst__DOT__overrun_error_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__frame_error_reg) 
         ^ this->__Vtogcov__rx_frame_error)) {
        ++(vlSymsp->__Vcoverage[699]);
        this->__Vtogcov__rx_frame_error = this->__PVT__uart_rx_inst__DOT__frame_error_reg;
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__rxd_reg) 
         ^ this->uart_rx_inst__DOT____Vtogcov__rxd_reg)) {
        ++(vlSymsp->__Vcoverage[740]);
        this->uart_rx_inst__DOT____Vtogcov__rxd_reg 
            = this->__PVT__uart_rx_inst__DOT__rxd_reg;
    }
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[768]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[769]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[770]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt) 
               ^ this->uart_rx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[771]);
        this->uart_rx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(this->uart_rx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(this->__PVT__uart_rx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[741]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfeU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[742]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfdU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[743]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xfbU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
               ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[744]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xf7U & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[745]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xefU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[746]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xdfU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[747]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0xbfU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_rx_inst__DOT__data_reg) 
                  ^ this->uart_rx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[748]);
        this->uart_rx_inst__DOT____Vtogcov__data_reg 
            = ((0x7fU & (IData)(this->uart_rx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(this->__PVT__uart_rx_inst__DOT__data_reg)));
    }
    if ((1U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[749]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((2U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[750]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((4U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[751]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((8U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
               ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[752]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[753]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[754]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[755]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                  ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[756]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[757]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[758]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[759]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                   ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[760]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[761]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[762]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[763]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                    ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[764]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[765]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[766]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (this->__PVT__uart_rx_inst__DOT__prescale_reg 
                     ^ this->uart_rx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[767]);
        this->uart_rx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & this->uart_rx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & this->__PVT__uart_rx_inst__DOT__prescale_reg));
    }
    if (((IData)(this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg) 
         ^ this->__Vtogcov__output_axis_tvalid)) {
        ++(vlSymsp->__Vcoverage[695]);
        this->__Vtogcov__output_axis_tvalid = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    }
    this->output_axis_tvalid = this->__PVT__uart_rx_inst__DOT__output_axis_tvalid_reg;
    if ((1U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[728]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xeU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (1U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((2U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[729]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xdU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (2U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((4U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[730]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((0xbU & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (4U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((8U & ((IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt) 
               ^ this->uart_tx_inst__DOT____Vtogcov__bit_cnt))) {
        ++(vlSymsp->__Vcoverage[731]);
        this->uart_tx_inst__DOT____Vtogcov__bit_cnt 
            = ((7U & (IData)(this->uart_tx_inst__DOT____Vtogcov__bit_cnt)) 
               | (8U & (IData)(this->__PVT__uart_tx_inst__DOT__bit_cnt)));
    }
    if ((1U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[700]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1feU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (1U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((2U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[701]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fdU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (2U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((4U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[702]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1fbU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (4U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((8U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
               ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[703]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1f7U & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (8U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x10U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[704]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1efU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x10U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x20U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[705]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1dfU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x20U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x40U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[706]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x1bfU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x40U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x80U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                  ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[707]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0x17fU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x80U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((0x100U & ((IData)(this->__PVT__uart_tx_inst__DOT__data_reg) 
                   ^ this->uart_tx_inst__DOT____Vtogcov__data_reg))) {
        ++(vlSymsp->__Vcoverage[708]);
        this->uart_tx_inst__DOT____Vtogcov__data_reg 
            = ((0xffU & (IData)(this->uart_tx_inst__DOT____Vtogcov__data_reg)) 
               | (0x100U & (IData)(this->__PVT__uart_tx_inst__DOT__data_reg)));
    }
    if ((1U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[709]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffeU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (1U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((2U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[710]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffdU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (2U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((4U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[711]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fffbU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (4U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((8U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
               ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[712]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fff7U & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (8U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[713]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffefU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[714]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffdfU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[715]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ffbfU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x80U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                  ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[716]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7ff7fU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x80U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x100U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[717]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7feffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x100U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x200U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[718]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fdffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x200U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x400U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[719]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7fbffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x400U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x800U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                   ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[720]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7f7ffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x800U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x1000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[721]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7efffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x1000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x2000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[722]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7dfffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x2000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x4000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[723]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x7bfffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x4000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x8000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                    ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[724]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x77fffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x8000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x10000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[725]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x6ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x10000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x20000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[726]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x5ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x20000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if ((0x40000U & (this->__PVT__uart_tx_inst__DOT__prescale_reg 
                     ^ this->uart_tx_inst__DOT____Vtogcov__prescale_reg))) {
        ++(vlSymsp->__Vcoverage[727]);
        this->uart_tx_inst__DOT____Vtogcov__prescale_reg 
            = ((0x3ffffU & this->uart_tx_inst__DOT____Vtogcov__prescale_reg) 
               | (0x40000U & this->__PVT__uart_tx_inst__DOT__prescale_reg));
    }
    if (((IData)(this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg) 
         ^ this->__Vtogcov__input_axis_tready)) {
        ++(vlSymsp->__Vcoverage[694]);
        this->__Vtogcov__input_axis_tready = this->__PVT__uart_tx_inst__DOT__input_axis_tready_reg;
    }
}

void Vtop_uart::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    input_axis_tdata = VL_RAND_RESET_I(8);
    input_axis_tvalid = VL_RAND_RESET_I(1);
    input_axis_tready = VL_RAND_RESET_I(1);
    output_axis_tdata = VL_RAND_RESET_I(8);
    output_axis_tvalid = VL_RAND_RESET_I(1);
    output_axis_tready = VL_RAND_RESET_I(1);
    rxd = VL_RAND_RESET_I(1);
    txd = VL_RAND_RESET_I(1);
    tx_busy = VL_RAND_RESET_I(1);
    rx_busy = VL_RAND_RESET_I(1);
    rx_overrun_error = VL_RAND_RESET_I(1);
    rx_frame_error = VL_RAND_RESET_I(1);
    prescale = VL_RAND_RESET_I(16);
    __Vtogcov__input_axis_tvalid = VL_RAND_RESET_I(1);
    __Vtogcov__input_axis_tready = VL_RAND_RESET_I(1);
    __Vtogcov__output_axis_tdata = VL_RAND_RESET_I(8);
    __Vtogcov__output_axis_tvalid = VL_RAND_RESET_I(1);
    __Vtogcov__output_axis_tready = VL_RAND_RESET_I(1);
    __Vtogcov__tx_busy = VL_RAND_RESET_I(1);
    __Vtogcov__rx_busy = VL_RAND_RESET_I(1);
    __Vtogcov__rx_overrun_error = VL_RAND_RESET_I(1);
    __Vtogcov__rx_frame_error = VL_RAND_RESET_I(1);
    __PVT__uart_tx_inst__DOT__input_axis_tready_reg = VL_RAND_RESET_I(1);
    __PVT__uart_tx_inst__DOT__txd_reg = VL_RAND_RESET_I(1);
    __PVT__uart_tx_inst__DOT__busy_reg = VL_RAND_RESET_I(1);
    __PVT__uart_tx_inst__DOT__data_reg = VL_RAND_RESET_I(9);
    __PVT__uart_tx_inst__DOT__prescale_reg = VL_RAND_RESET_I(19);
    __PVT__uart_tx_inst__DOT__bit_cnt = VL_RAND_RESET_I(4);
    uart_tx_inst__DOT____Vtogcov__data_reg = VL_RAND_RESET_I(9);
    uart_tx_inst__DOT____Vtogcov__prescale_reg = VL_RAND_RESET_I(19);
    uart_tx_inst__DOT____Vtogcov__bit_cnt = VL_RAND_RESET_I(4);
    __PVT__uart_rx_inst__DOT__output_axis_tdata_reg = VL_RAND_RESET_I(8);
    __PVT__uart_rx_inst__DOT__output_axis_tvalid_reg = VL_RAND_RESET_I(1);
    __PVT__uart_rx_inst__DOT__rxd_reg = VL_RAND_RESET_I(1);
    __PVT__uart_rx_inst__DOT__busy_reg = VL_RAND_RESET_I(1);
    __PVT__uart_rx_inst__DOT__overrun_error_reg = VL_RAND_RESET_I(1);
    __PVT__uart_rx_inst__DOT__frame_error_reg = VL_RAND_RESET_I(1);
    __PVT__uart_rx_inst__DOT__data_reg = VL_RAND_RESET_I(8);
    __PVT__uart_rx_inst__DOT__prescale_reg = VL_RAND_RESET_I(19);
    __PVT__uart_rx_inst__DOT__bit_cnt = VL_RAND_RESET_I(4);
    uart_rx_inst__DOT____Vtogcov__rxd_reg = VL_RAND_RESET_I(1);
    uart_rx_inst__DOT____Vtogcov__data_reg = VL_RAND_RESET_I(8);
    uart_rx_inst__DOT____Vtogcov__prescale_reg = VL_RAND_RESET_I(19);
    uart_rx_inst__DOT____Vtogcov__bit_cnt = VL_RAND_RESET_I(4);
    __Vdly__uart_tx_inst__DOT__input_axis_tready_reg = VL_RAND_RESET_I(1);
    __Vdly__uart_tx_inst__DOT__prescale_reg = VL_RAND_RESET_I(19);
    __Vdly__uart_tx_inst__DOT__bit_cnt = VL_RAND_RESET_I(4);
    __Vdly__uart_tx_inst__DOT__data_reg = VL_RAND_RESET_I(9);
    __Vdly__uart_rx_inst__DOT__output_axis_tvalid_reg = VL_RAND_RESET_I(1);
    __Vdly__uart_rx_inst__DOT__prescale_reg = VL_RAND_RESET_I(19);
    __Vdly__uart_rx_inst__DOT__bit_cnt = VL_RAND_RESET_I(4);
    __Vdly__uart_rx_inst__DOT__data_reg = VL_RAND_RESET_I(8);
}

void Vtop_uart::_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_uart::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../uart/uart.v", 32, 0, "", "v_toggle/uart", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../uart/uart.v", 33, 0, "", "v_toggle/uart", "rst");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[585]), first, "../uart/uart.v", 38, 0, "", "v_toggle/uart", "input_axis_tdata[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[586]), first, "../uart/uart.v", 38, 0, "", "v_toggle/uart", "input_axis_tdata[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[587]), first, "../uart/uart.v", 38, 0, "", "v_toggle/uart", "input_axis_tdata[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[588]), first, "../uart/uart.v", 38, 0, "", "v_toggle/uart", "input_axis_tdata[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[589]), first, "../uart/uart.v", 38, 0, "", "v_toggle/uart", "input_axis_tdata[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[590]), first, "../uart/uart.v", 38, 0, "", "v_toggle/uart", "input_axis_tdata[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[591]), first, "../uart/uart.v", 38, 0, "", "v_toggle/uart", "input_axis_tdata[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[592]), first, "../uart/uart.v", 38, 0, "", "v_toggle/uart", "input_axis_tdata[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "../uart/uart.v", 39, 0, "", "v_toggle/uart", "input_axis_tvalid");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[694]), first, "../uart/uart.v", 40, 0, "", "v_toggle/uart", "input_axis_tready");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[577]), first, "../uart/uart.v", 45, 0, "", "v_toggle/uart", "output_axis_tdata[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[578]), first, "../uart/uart.v", 45, 0, "", "v_toggle/uart", "output_axis_tdata[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[579]), first, "../uart/uart.v", 45, 0, "", "v_toggle/uart", "output_axis_tdata[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[580]), first, "../uart/uart.v", 45, 0, "", "v_toggle/uart", "output_axis_tdata[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[581]), first, "../uart/uart.v", 45, 0, "", "v_toggle/uart", "output_axis_tdata[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[582]), first, "../uart/uart.v", 45, 0, "", "v_toggle/uart", "output_axis_tdata[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[583]), first, "../uart/uart.v", 45, 0, "", "v_toggle/uart", "output_axis_tdata[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[584]), first, "../uart/uart.v", 45, 0, "", "v_toggle/uart", "output_axis_tdata[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[695]), first, "../uart/uart.v", 46, 0, "", "v_toggle/uart", "output_axis_tvalid");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "../uart/uart.v", 47, 0, "", "v_toggle/uart", "output_axis_tready");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "../uart/uart.v", 51, 0, "", "v_toggle/uart", "rxd");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "../uart/uart.v", 52, 0, "", "v_toggle/uart", "txd");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[696]), first, "../uart/uart.v", 57, 0, "", "v_toggle/uart", "tx_busy");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[697]), first, "../uart/uart.v", 58, 0, "", "v_toggle/uart", "rx_busy");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[698]), first, "../uart/uart.v", 59, 0, "", "v_toggle/uart", "rx_overrun_error");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[699]), first, "../uart/uart.v", 60, 0, "", "v_toggle/uart", "rx_frame_error");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "../uart/uart.v", 65, 0, "", "v_toggle/uart", "prescale[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../uart/uart_tx.v", 32, 0, ".uart_tx_inst", "v_toggle/uart_tx", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../uart/uart_tx.v", 33, 0, ".uart_tx_inst", "v_toggle/uart_tx", "rst");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[585]), first, "../uart/uart_tx.v", 38, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[586]), first, "../uart/uart_tx.v", 38, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[587]), first, "../uart/uart_tx.v", 38, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[588]), first, "../uart/uart_tx.v", 38, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[589]), first, "../uart/uart_tx.v", 38, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[590]), first, "../uart/uart_tx.v", 38, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[591]), first, "../uart/uart_tx.v", 38, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[592]), first, "../uart/uart_tx.v", 38, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tdata[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "../uart/uart_tx.v", 39, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tvalid");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[694]), first, "../uart/uart_tx.v", 40, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tready");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "../uart/uart_tx.v", 45, 0, ".uart_tx_inst", "v_toggle/uart_tx", "txd");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[696]), first, "../uart/uart_tx.v", 50, 0, ".uart_tx_inst", "v_toggle/uart_tx", "busy");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "../uart/uart_tx.v", 55, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[694]), first, "../uart/uart_tx.v", 58, 0, ".uart_tx_inst", "v_toggle/uart_tx", "input_axis_tready_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "../uart/uart_tx.v", 60, 0, ".uart_tx_inst", "v_toggle/uart_tx", "txd_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[696]), first, "../uart/uart_tx.v", 62, 0, ".uart_tx_inst", "v_toggle/uart_tx", "busy_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[700]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[701]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[702]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[703]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[704]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[705]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[706]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[707]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[708]), first, "../uart/uart_tx.v", 64, 0, ".uart_tx_inst", "v_toggle/uart_tx", "data_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[709]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[710]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[711]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[712]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[713]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[714]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[715]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[716]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[717]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[718]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[719]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[720]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[721]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[722]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[723]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[724]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[725]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[726]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[727]), first, "../uart/uart_tx.v", 65, 0, ".uart_tx_inst", "v_toggle/uart_tx", "prescale_reg[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[728]), first, "../uart/uart_tx.v", 66, 0, ".uart_tx_inst", "v_toggle/uart_tx", "bit_cnt[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[729]), first, "../uart/uart_tx.v", 66, 0, ".uart_tx_inst", "v_toggle/uart_tx", "bit_cnt[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[730]), first, "../uart/uart_tx.v", 66, 0, ".uart_tx_inst", "v_toggle/uart_tx", "bit_cnt[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[731]), first, "../uart/uart_tx.v", 66, 0, ".uart_tx_inst", "v_toggle/uart_tx", "bit_cnt[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[732]), first, "../uart/uart_tx.v", 74, 0, ".uart_tx_inst", "v_line/uart_tx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[733]), first, "../uart/uart_tx.v", 81, 0, ".uart_tx_inst", "v_line/uart_tx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[734]), first, "../uart/uart_tx.v", 88, 0, ".uart_tx_inst", "v_line/uart_tx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[735]), first, "../uart/uart_tx.v", 84, 0, ".uart_tx_inst", "v_line/uart_tx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[736]), first, "../uart/uart_tx.v", 97, 0, ".uart_tx_inst", "v_line/uart_tx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[737]), first, "../uart/uart_tx.v", 101, 0, ".uart_tx_inst", "v_line/uart_tx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[738]), first, "../uart/uart_tx.v", 96, 0, ".uart_tx_inst", "v_line/uart_tx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[739]), first, "../uart/uart_tx.v", 80, 0, ".uart_tx_inst", "v_line/uart_tx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../uart/uart_rx.v", 32, 0, ".uart_rx_inst", "v_toggle/uart_rx", "clk");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../uart/uart_rx.v", 33, 0, ".uart_rx_inst", "v_toggle/uart_rx", "rst");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[577]), first, "../uart/uart_rx.v", 38, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[578]), first, "../uart/uart_rx.v", 38, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[579]), first, "../uart/uart_rx.v", 38, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[580]), first, "../uart/uart_rx.v", 38, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[581]), first, "../uart/uart_rx.v", 38, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[582]), first, "../uart/uart_rx.v", 38, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[583]), first, "../uart/uart_rx.v", 38, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[584]), first, "../uart/uart_rx.v", 38, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[695]), first, "../uart/uart_rx.v", 39, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tvalid");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "../uart/uart_rx.v", 40, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tready");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "../uart/uart_rx.v", 45, 0, ".uart_rx_inst", "v_toggle/uart_rx", "rxd");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[697]), first, "../uart/uart_rx.v", 50, 0, ".uart_rx_inst", "v_toggle/uart_rx", "busy");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[698]), first, "../uart/uart_rx.v", 51, 0, ".uart_rx_inst", "v_toggle/uart_rx", "overrun_error");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[699]), first, "../uart/uart_rx.v", 52, 0, ".uart_rx_inst", "v_toggle/uart_rx", "frame_error");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "../uart/uart_rx.v", 57, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[577]), first, "../uart/uart_rx.v", 61, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[578]), first, "../uart/uart_rx.v", 61, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[579]), first, "../uart/uart_rx.v", 61, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[580]), first, "../uart/uart_rx.v", 61, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[581]), first, "../uart/uart_rx.v", 61, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[582]), first, "../uart/uart_rx.v", 61, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[583]), first, "../uart/uart_rx.v", 61, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[584]), first, "../uart/uart_rx.v", 61, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tdata_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[695]), first, "../uart/uart_rx.v", 62, 0, ".uart_rx_inst", "v_toggle/uart_rx", "output_axis_tvalid_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[740]), first, "../uart/uart_rx.v", 64, 0, ".uart_rx_inst", "v_toggle/uart_rx", "rxd_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[697]), first, "../uart/uart_rx.v", 66, 0, ".uart_rx_inst", "v_toggle/uart_rx", "busy_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[698]), first, "../uart/uart_rx.v", 67, 0, ".uart_rx_inst", "v_toggle/uart_rx", "overrun_error_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[699]), first, "../uart/uart_rx.v", 68, 0, ".uart_rx_inst", "v_toggle/uart_rx", "frame_error_reg");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[741]), first, "../uart/uart_rx.v", 70, 0, ".uart_rx_inst", "v_toggle/uart_rx", "data_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[742]), first, "../uart/uart_rx.v", 70, 0, ".uart_rx_inst", "v_toggle/uart_rx", "data_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[743]), first, "../uart/uart_rx.v", 70, 0, ".uart_rx_inst", "v_toggle/uart_rx", "data_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[744]), first, "../uart/uart_rx.v", 70, 0, ".uart_rx_inst", "v_toggle/uart_rx", "data_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[745]), first, "../uart/uart_rx.v", 70, 0, ".uart_rx_inst", "v_toggle/uart_rx", "data_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[746]), first, "../uart/uart_rx.v", 70, 0, ".uart_rx_inst", "v_toggle/uart_rx", "data_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[747]), first, "../uart/uart_rx.v", 70, 0, ".uart_rx_inst", "v_toggle/uart_rx", "data_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[748]), first, "../uart/uart_rx.v", 70, 0, ".uart_rx_inst", "v_toggle/uart_rx", "data_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[749]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[750]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[751]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[752]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[753]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[4]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[754]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[5]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[755]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[6]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[756]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[7]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[757]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[8]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[758]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[9]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[759]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[10]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[760]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[11]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[761]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[12]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[762]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[13]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[763]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[14]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[764]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[15]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[765]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[16]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[766]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[17]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[767]), first, "../uart/uart_rx.v", 71, 0, ".uart_rx_inst", "v_toggle/uart_rx", "prescale_reg[18]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[768]), first, "../uart/uart_rx.v", 72, 0, ".uart_rx_inst", "v_toggle/uart_rx", "bit_cnt[0]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[769]), first, "../uart/uart_rx.v", 72, 0, ".uart_rx_inst", "v_toggle/uart_rx", "bit_cnt[1]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[770]), first, "../uart/uart_rx.v", 72, 0, ".uart_rx_inst", "v_toggle/uart_rx", "bit_cnt[2]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[771]), first, "../uart/uart_rx.v", 72, 0, ".uart_rx_inst", "v_toggle/uart_rx", "bit_cnt[3]");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[772]), first, "../uart/uart_rx.v", 82, 0, ".uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[773]), first, "../uart/uart_rx.v", 96, 0, ".uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[774]), first, "../uart/uart_rx.v", 100, 0, ".uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[775]), first, "../uart/uart_rx.v", 104, 0, ".uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[776]), first, "../uart/uart_rx.v", 107, 0, ".uart_rx_inst", "v_line/uart_rx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[777]), first, "../uart/uart_rx.v", 103, 0, ".uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[778]), first, "../uart/uart_rx.v", 111, 0, ".uart_rx_inst", "v_line/uart_rx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[779]), first, "../uart/uart_rx.v", 117, 0, ".uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[780]), first, "../uart/uart_rx.v", 121, 0, ".uart_rx_inst", "v_line/uart_rx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[781]), first, "../uart/uart_rx.v", 115, 0, ".uart_rx_inst", "v_line/uart_rx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[782]), first, "../uart/uart_rx.v", 102, 0, ".uart_rx_inst", "v_line/uart_rx", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[783]), first, "../uart/uart_rx.v", 127, 0, ".uart_rx_inst", "v_line/uart_rx", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[784]), first, "../uart/uart_rx.v", 125, 0, ".uart_rx_inst", "v_line/uart_rx", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[785]), first, "../uart/uart_rx.v", 91, 0, ".uart_rx_inst", "v_line/uart_rx", "else");
}
