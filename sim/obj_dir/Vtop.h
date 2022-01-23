// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"
#include "verilated_cov.h"

//==========

class Vtop__Syms;
class Vtop_uart;


//----------

VL_MODULE(Vtop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop_uart* __PVT__top__DOT__tb_uart;
    Vtop_uart* __PVT__top__DOT__pic__DOT__pic_uart;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,0,0);
    VL_IN8(uart_tx_data_i,7,0);
    VL_OUT8(uart_rx_data_o,7,0);
    VL_IN8(uart_rx_ready_i,0,0);
    VL_IN8(uart_tx_valid_i,0,0);
    VL_OUT8(uart_rx_valid_o,0,0);
    VL_OUT8(uart_tx_ready_o,0,0);
    VL_IN16(uart_prescale,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top__DOT__reset;
    CData/*7:0*/ top__DOT__ram_addr;
    CData/*7:0*/ top__DOT__ram_data_rd;
    CData/*7:0*/ top__DOT__aux_data;
    CData/*0:0*/ top__DOT__aux_rd_stb;
    CData/*7:0*/ top__DOT__pic__DOT__w_reg;
    CData/*7:0*/ top__DOT__pic__DOT__status_reg;
    CData/*7:0*/ top__DOT__pic__DOT__fsr_reg;
    CData/*4:0*/ top__DOT__pic__DOT__pclath_reg;
    CData/*7:0*/ top__DOT__pic__DOT__intcon_reg;
    CData/*7:0*/ top__DOT__pic__DOT__aux_adr_hi_reg;
    CData/*7:0*/ top__DOT__pic__DOT__aux_adr_lo_reg;
    CData/*7:0*/ top__DOT__pic__DOT__aluinp1_reg;
    CData/*7:0*/ top__DOT__pic__DOT__aluinp2_reg;
    CData/*0:0*/ top__DOT__pic__DOT__exec_stall_reg;
    CData/*3:0*/ top__DOT__pic__DOT__stack_pnt_reg;
    CData/*0:0*/ top__DOT__pic__DOT__int_condition;
    CData/*0:0*/ top__DOT__pic__DOT__intrise;
    CData/*0:0*/ top__DOT__pic__DOT__intrise_reg;
    CData/*0:0*/ top__DOT__pic__DOT__inte_sync_reg;
    CData/*1:0*/ top__DOT__pic__DOT__state_reg;
    CData/*1:0*/ top__DOT__pic__DOT__next_state_node;
    CData/*0:0*/ top__DOT__pic__DOT__ram_we_reg;
    CData/*0:0*/ top__DOT__pic__DOT__aux_we_reg;
    CData/*0:0*/ top__DOT__pic__DOT__aux_re_reg;
    CData/*7:0*/ top__DOT__pic__DOT__ram_i_node;
    CData/*4:0*/ top__DOT__pic__DOT__addlow_node;
    CData/*7:0*/ top__DOT__pic__DOT__aluout;
    CData/*0:0*/ top__DOT__pic__DOT__writew_node;
    CData/*0:0*/ top__DOT__pic__DOT__writeram_node;
    CData/*0:0*/ top__DOT__pic__DOT__c_subtract_zero;
    CData/*0:0*/ top__DOT__pic__DOT__c_dig_subtract_zero;
    CData/*0:0*/ top__DOT__pic__DOT__next_exec_stall;
    CData/*7:0*/ top__DOT__pic__DOT__uart_tx_data;
    CData/*7:0*/ top__DOT__pic__DOT__uart_sr_ff;
    CData/*7:0*/ top__DOT__pic__DOT__uart_sr;
    CData/*7:0*/ top__DOT__pic__DOT__uart_sr_comb;
    SData/*13:0*/ top__DOT__rom_data;
    SData/*15:0*/ top__DOT__aux_addr;
    SData/*12:0*/ top__DOT__pic__DOT__pc_reg;
    SData/*12:0*/ top__DOT__pic__DOT__old_pc_reg;
    SData/*13:0*/ top__DOT__pic__DOT__inst_reg;
    SData/*12:0*/ top__DOT__pic__DOT__stack_top;
    SData/*8:0*/ top__DOT__pic__DOT__ram_adr_node;
    SData/*8:0*/ top__DOT__pic__DOT__add_node;
    SData/*12:0*/ top__DOT__pic__DOT__next_pc_node;
    SData/*13:0*/ top__DOT__rom[4096];
    CData/*7:0*/ top__DOT__ram[256];
    CData/*7:0*/ top__DOT__aux_ram[65536];
    SData/*12:0*/ top__DOT__pic__DOT__stack_reg[16];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT____Vtogcov__clk;
        CData/*0:0*/ top__DOT____Vtogcov__reset_n;
        CData/*7:0*/ top__DOT____Vtogcov__uart_tx_data_i;
        CData/*7:0*/ top__DOT____Vtogcov__uart_rx_data_o;
        CData/*0:0*/ top__DOT____Vtogcov__uart_rx_ready_i;
        CData/*0:0*/ top__DOT____Vtogcov__uart_tx_valid_i;
        CData/*0:0*/ top__DOT____Vtogcov__uart_rx_valid_o;
        CData/*0:0*/ top__DOT____Vtogcov__uart_tx_ready_o;
        CData/*0:0*/ top__DOT____Vtogcov__reset;
        CData/*7:0*/ top__DOT____Vtogcov__ram_addr;
        CData/*7:0*/ top__DOT____Vtogcov__ram_data_rd;
        CData/*7:0*/ top__DOT____Vtogcov__ram_data_wr;
        CData/*7:0*/ top__DOT____Vtogcov__aux_data;
        CData/*0:0*/ top__DOT____Vtogcov__aux_wr_stb;
        CData/*0:0*/ top__DOT____Vtogcov__clken;
        CData/*0:0*/ top__DOT____Vtogcov__aux_rd_stb;
        CData/*0:0*/ top__DOT____Vtogcov__ram_we;
        CData/*0:0*/ top__DOT____Vtogcov__int0;
        CData/*0:0*/ top__DOT____Vtogcov__uart_rx_i;
        CData/*0:0*/ top__DOT____Vtogcov__uart_tx_o;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__w_reg;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__status_reg;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__fsr_reg;
        CData/*4:0*/ top__DOT__pic__DOT____Vtogcov__pclath_reg;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__intcon_reg;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__aux_adr_hi_reg;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__aux_adr_lo_reg;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__aluinp1_reg;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__aluinp2_reg;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__exec_stall_reg;
        CData/*3:0*/ top__DOT__pic__DOT____Vtogcov__stack_pnt_reg;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__int_condition;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__intrise;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__intrise_reg;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inte_sync_reg;
        CData/*1:0*/ top__DOT__pic__DOT____Vtogcov__state_reg;
        CData/*1:0*/ top__DOT__pic__DOT____Vtogcov__next_state_node;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_addlw;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_addwf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_andlw;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_andwf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_bcf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_bsf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_btfsc;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_btfss;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_call;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_clrf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_clrw;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_comf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_decf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_decfsz;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_goto;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_incf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_incfsz;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_iorlw;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_iorwf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_movlw;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_movf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_movwf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_retfie;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_retlw;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_ret;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_rlf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_rrf;
    };
    struct {
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_sleep;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_sublw;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_subwf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_swapf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_xorlw;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_xorwf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_pcl;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_stat;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_fsr;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_indf;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_pclath;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_intcon;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_aux_adr_lo;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_aux_adr_hi;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_aux_dat;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_sram;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__aux_re_reg;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__ram_i_node;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__mask_node;
        CData/*4:0*/ top__DOT__pic__DOT____Vtogcov__addlow_node;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__aluout_zero_node;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__writew_node;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__writeram_node;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__c_subtract_zero;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__c_dig_subtract_zero;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__next_exec_stall;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_uart_rx_data;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_uart_tx_data;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__addr_uart_sr;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__uart_rx_data;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__uart_tx_data;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__uart_sr_ff;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__uart_sr;
        CData/*7:0*/ top__DOT__pic__DOT____Vtogcov__uart_sr_comb;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__int_combined;
        CData/*0:0*/ top__DOT__pic__DOT____Vtogcov__inst_nop;
        CData/*0:0*/ __Vdly__top__DOT__pic__DOT__exec_stall_reg;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__reset;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__reset;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__reset;
        SData/*15:0*/ top__DOT____Vtogcov__uart_prescale;
        SData/*11:0*/ top__DOT____Vtogcov__rom_addr;
        SData/*13:0*/ top__DOT____Vtogcov__rom_data;
        SData/*15:0*/ top__DOT____Vtogcov__aux_addr;
        SData/*12:0*/ top__DOT__pic__DOT____Vtogcov__pc_reg;
        SData/*12:0*/ top__DOT__pic__DOT____Vtogcov__old_pc_reg;
        SData/*13:0*/ top__DOT__pic__DOT____Vtogcov__inst_reg;
        SData/*12:0*/ top__DOT__pic__DOT____Vtogcov__stack_top;
        SData/*8:0*/ top__DOT__pic__DOT____Vtogcov__ram_adr_node;
        SData/*8:0*/ top__DOT__pic__DOT____Vtogcov__add_node;
        SData/*12:0*/ top__DOT__pic__DOT____Vtogcov__next_pc_node;
        SData/*12:0*/ top__DOT__pic__DOT____Vtogcov__stack_reg[16];
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
  private:
    // Coverage
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__10(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__2(Vtop__Syms* __restrict vlSymsp);
  private:
    void _configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__7(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
