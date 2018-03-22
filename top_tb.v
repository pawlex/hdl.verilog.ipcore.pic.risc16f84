////////////////////////////////////////////////////////////////////////////
// vim:set softtabstop=4 shiftwidth=4 expandtab tabstop=4 autoindent
////////////////////////////////////////////////////////////////////////////
`timescale 1ns/100ps

module top_tb();
    // TB Params
    localparam CLOCK_PERIOD = 16.6667; // 60MHz
    localparam MAX_CYCLES = 200000;
    localparam DUMP_FILE = "dump.vcd";

    // Generate the clock and reset signals.
    reg clk,reset;
    initial begin
        clk=1;
        reset=0;
        #40;
        reset=1;
        forever #(CLOCK_PERIOD/2) clk = ~clk;
    end

    initial  begin
        $dumpfile (DUMP_FILE); 
        $dumpvars(); 
    end

    initial begin
        repeat(4) @(posedge clk);
        reset <= 0;
    end

    initial begin
        #MAX_CYCLES $finish_and_return(0);
        //#MAX_CYCLES $finish;
    end

    //`include "dut_tb.v"
    dut_tb dut_tb(clk,reset);

endmodule

