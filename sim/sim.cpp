// DESCRIPTION: Verilator: Verilog example module
//
// This file ONLY is placed into the Public Domain, for any use,
// without warranty, 2017 by Wilson Snyder.
//======================================================================

// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

#include "uartsim.h"


// Current simulation time (64-bit unsigned)
vluint64_t main_time = 0;
// Called by $time in Verilog
double sc_time_stamp() {
    return main_time;  // Note does conversion to real, to match SystemC
}

int main(int argc, char** argv, char** env) {
    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    Vtop* top = new Vtop;  // Or use a const unique_ptr, or the VL_UNIQUE_PTR wrapper

    // SETUP STUFF
    UARTSIM *uart;
	unsigned	setup = 868, clocks = 0, baudclocks;
	top -> i_setup = setup;
	uart = new UARTSIM(0);
	uart->setup(top->i_setup);
	baudclocks = top->i_setup & 0xfffffff;
    top->uart_prescale = ((100000000 / (115200*8) / 2));
    printf("Initial baud: 0x%04x", top->uart_prescale);


    // Prevent unused variable warnings
    if (0 && argc && argv && env) {}

    // Set debug level, 0 is off, 9 is highest presently used
    // May be overridden by commandArgs
    Verilated::debug(0);

    // Randomization reset policy
    // May be overridden by commandArgs
    Verilated::randReset(2);

    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    // This needs to be called before you create any model
    Verilated::commandArgs(argc, argv);


    // Set some inputs
    top->reset_n = 1;
    top->clk = 0;

    printf("Starting up\n");
    // Simulate until $finish


    uint16_t mybaud = 0;
    while (!Verilated::gotFinish()) {
       // if((main_time % 0x40000) == 0) { 
       //     //printf("time: 0x%0000000000000000x\n", main_time); 
       //     mybaud++;
       //     top->uart_prescale = mybaud;
       //     printf("...0x%04x\n...", mybaud);
       // }
        main_time++;  // Time passes...
        top->clk = !top->clk;

        if (main_time > 1 && main_time < 10) {
            top->reset_n = !1;  // Assert reset
        } else {
            top->reset_n = !0;  // Deassert reset
        }
        top->eval();
        
        //if((main_time % 100000) == 0) { printf("0x%00000000000000000000x\n", main_time); }
		(*uart)(top->uart_tx);
    }

    // Final model cleanup
    top->final();

    // Destroy model
    delete top; top = NULL;

    // Fin
    exit(0);
}
