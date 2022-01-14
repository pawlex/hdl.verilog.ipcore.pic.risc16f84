`timescale 1ns/100ps

module tb();
reg reset_n=0;
reg clk=0;

initial begin
    forever #10 clk = ~clk;
end

initial begin
    reset_n = 0;
    #10;
    reset_n = 1;
    #1000 $finish;
end

initial begin
    $dumpfile ("dump.vcd");
    $dumpvars();
end

/* SOME EXAMPLES */
initial begin
    interrupt_vector = 8'h00;
    bus_address = 16'h0000;
    bus_data_ff = 8'h00;
    wr = 0;
    #10;
    repeat(4) @(posedge clk);
    interrupt_vector[0] = 1;
    repeat(4) @(posedge clk);
    interrupt_vector[0] =0;
    bus_address = 16'h00EF;
    repeat(4) @(posedge clk);
    bus_data_ff = 8'h00;
    wr = 1;
    bus_address = 16'h00FF;
    repeat(4) @(posedge clk);
    bus_address = 16'h0000;
    #10 wr=0;
end


reg [7:0] interrupt_vector;
reg [15:0] bus_address;
wire [7:0] bus_data_io;
reg [7:0] bus_data_ff;
reg wr;

assign bus_data_io = (wr) ? bus_data_ff : 8'hzz;

intctrl
    dut
    (
        .clk(clk),
        .reset_n(reset_n),
        .address_i(bus_address),
        .vector_i(interrupt_vector),
        .data_io(bus_data_io)
    );

endmodule

