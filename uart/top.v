module top
       (
           clk,
           reset_n
       );
// IO
input clk;
input reset_n;

// LOGIC

always @(posedge clk or negedge reset_n)
begin
    if(!reset_n) begin
        // DO SOME RESET STUFF
    end else
    begin
        // DO SOME OTHER STUFF
    end
end

endmodule
