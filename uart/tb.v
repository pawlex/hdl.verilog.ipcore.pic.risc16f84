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
    wait(!reset_n) #100 $finish;
end

initial begin
    $dumpfile ("dump.vcd");
    $dumpvars();
    repeat(100000) @(posedge clk); $finish; // max 100k clocks
end

initial begin
    tx_data  <= 0;
    rx_ready <= 0;
    tx_valid <= 0;
    wait(reset_n);
    rx_ready <= 0;
    repeat(10) @(posedge clk);
    tx_data <= 8'h55;
    tx_valid <= 1;
    @(posedge clk);
    tx_valid <= 0;
    wait(rx_valid);
    tx_data <= 8'hAA;
    wait(tx_ready);
    tx_valid <= 1;
    repeat(100) @(posedge clk);
    rx_ready <= 1;
    repeat(30) @(posedge clk)
        rx_ready <= 0;
    wait(rx_valid);
    repeat(30) @(posedge clk)
        reset_n = 0;
end


/* SOME EXAMPLES */
//initial begin
//    repeat(4) @(posedge clk);
//    reset <= 0;
//end
//
//
//integer my_address = 0;
//initial begin
//    repeat(4) @(posedge clk);
//    wait(wait_req == 0)
//        repeat(100) @(posedge clk)
//            while (my_address < 'h100) @(posedge clk) begin
//            @(posedge clk);
//        end
//    #10000 $finish;
//end

wire loopback;
reg  [7:0] tx_data;
wire [7:0] rx_data;
reg  tx_valid, rx_ready;
wire rx_valid, tx_ready;

uart uart
     (
         .clk(clk),
         .rst(~reset_n),
         .input_axis_tdata(tx_data),
         .input_axis_tvalid(tx_valid),
         .input_axis_tready(tx_ready),
         .output_axis_tdata(rx_data),
         .output_axis_tvalid(rx_valid),
         .output_axis_tready(rx_ready),
         .rxd(loopback),
         .txd(loopback),
         .tx_busy(),
         .rx_busy(),
         .rx_overrun_error(),
         .rx_frame_error(),
         .prescale(2)
     );

endmodule

