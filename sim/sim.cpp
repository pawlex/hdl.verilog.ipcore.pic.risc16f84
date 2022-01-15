// DESCRIPTION: Verilator: Verilog example module
//
// This file ONLY is placed into the Public Domain, for any use,
// without warranty, 2017 by Wilson Snyder.
//======================================================================

// Include common routines
#include <verilated.h>
#include <stdio.h>
#include <ncurses.h>

// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

// Current simulation time (64-bit unsigned)
vluint64_t main_time = 0;
// Called by $time in Verilog
double sc_time_stamp() {
    return main_time;  // Note does conversion to real, to match SystemC
}

int main(int argc, char** argv, char** env) {
    //putchar(0x40);

    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    Vtop* top = new Vtop;  // Or use a const unique_ptr, or the VL_UNIQUE_PTR wrapper

    // SETUP STUFF
    top->uart_prescale = (0x80); // Set a very low prescale for sim.
    //printf("Initial baud: 0x%04x\n", top->uart_prescale);


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


    int myinput = 0;
    int row,col;
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr,row,col);	
    scrollok(stdscr, TRUE);
    int myrow = 0;
    int mycol = 0;
    uint8_t counter = 0;
    int keypress;
    while (!Verilated::gotFinish()) {
        main_time++;  // Time passes...
        top->clk = !top->clk;
        if(counter)
        {
            // Spin here until it's time to deassert ready.
            //printf("!");
            counter--;
            top->eval();
            main_time++;
        }
        if(top->uart_rx_ready_i)
        {
            top->uart_rx_ready_i = 0;
            top->eval();
            top->eval();
            main_time++;
            main_time++;
        }

        if (main_time > 1 && main_time < 10) {
            top->reset_n = !1;  // Assert reset
        } else {
            top->reset_n = !0;  // Deassert reset
        }
        // Write the UART output
        if(top->uart_rx_valid_o)
        {
            char mychar = (char) top->uart_rx_data_o;
            printw("%c", mychar);
            refresh();
            top->uart_rx_ready_i = 1;
            counter = 20;
        }
        // Read the user input
        int keypress = getch();
        if(keypress != ERR && top->uart_tx_ready_o)
        {
            top->uart_tx_valid_i = 1;
            top->eval();
            top->eval();
            top->eval();
            top->eval();
            top->uart_tx_valid_i = 0;
            main_time += 4;
        }
        top->eval();
    }

    // Final model cleanup
    top->final();

    // Destroy model
    delete top; top = NULL;

    // Fin
    exit(0);
}
