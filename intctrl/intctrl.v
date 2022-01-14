/*
* Very simple interrupt controller (mux)
* Paul Komurka
*/
module intctrl
       (
           input clk,
           input reset_n,
           input [15:0] address_i,
           input  [NUM_VECTORS-1:0] vector_i,
           inout  [NUM_VECTORS-1:0] data_io,
           output int_o
       );

parameter NUM_VECTORS = 8;
parameter RD_ADDRESS = 16'h00EF;
parameter WR_ADDRESS = 16'h00FF;
reg [NUM_VECTORS-1:0]vector_ff; // The latched vector

// LOGIC //
assign data_io = (address_i == RD_ADDRESS) ? vector_ff : 8'hzz;
assign int_o = (vector_ff);

always @* begin
    if(!reset_n) vector_ff = 0; else
        if(address_i == WR_ADDRESS) vector_ff = data_io;
        else vector_ff = vector_i | vector_ff; // keep the vector asserted until it's cleared.
end

endmodule
