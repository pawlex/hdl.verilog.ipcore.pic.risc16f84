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

Vtop* top = new Vtop;  // Or use a const unique_ptr, or the VL_UNIQUE_PTR wrapper

void toggle_clock(void)
{
    top->clk = !top->clk;
    top->eval();
    top->clk = !top->clk;
    top->eval();
    main_time += 2;
}


int main(int argc, char** argv, char** env) {
    //putchar(0x40);

    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    //Vtop* top = new Vtop;  // Or use a const unique_ptr, or the VL_UNIQUE_PTR wrapper

    // SETUP STUFF
    top->uart_prescale = (0x10); // Set a very low prescale for sim.
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


    // Simple reset logic
    top->reset_n = 0;
    top->clk = 0;
    toggle_clock();
    toggle_clock();
    toggle_clock();
    toggle_clock();
    top->reset_n = 1;


    int myinput = 0;
    int row,col;
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    //timeout(0);
    getmaxyx(stdscr,row,col);	
    scrollok(stdscr, TRUE);
    int myrow = 0;
    int mycol = 0;
    int keypress = ERR;

    int rx_counter = 0;
    while (!Verilated::gotFinish()) {
        // Handle the input first, because the lag gets nasty.
        keypress = getch();
        if(top->uart_tx_ready_o)
        {
            if(keypress != ERR)
            {
                top->uart_tx_data_i = keypress;
                top->uart_tx_valid_i = 1;
                toggle_clock();
                top->uart_tx_valid_i = 0;
                keypress = ERR;
            }
        } else {
            // Uart was busy so let's throw it back on the stack;
            ungetch(keypress);
        }


        if(rx_counter == 0)
        {
            top->uart_rx_ready_i = 0;

            // Write the UART output
            if(top->uart_rx_valid_o)
            {
                char mychar = (char) top->uart_rx_data_o;
                printw("%c", mychar);
                refresh();
                top->uart_rx_ready_i = 1;
                rx_counter = 2;
            }

        } else {
            rx_counter--;
        }
        
        main_time++;
        top->clk = !top->clk;
        top->eval();
    }

    // Final model cleanup
    top->final();

    // Destroy model
    delete top; top = NULL;

    // Fin
    exit(0);
}
