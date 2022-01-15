////////////////////////////////////////////////////////////////////////////
// vim:set softtabstop=4 shiftwidth=4 expandtab tabstop=4 autoindent
////////////////////////////////////////////////////////////////////////////
`timescale 100ns/100ns
`undef SIMULATION

module top(
    input clk, 
    input reset_n,
    //
    //input   wire    [30:0]  i_setup,
    //input uart_rx,
    //output uart_tx,
    //
    input [15:0] uart_prescale,
    input [7:0] uart_tx_data_i,
    output [7:0] uart_rx_data_o,
    input uart_rx_ready_i,
    input uart_tx_valid_i,
    output uart_rx_valid_o,
    output uart_tx_ready_o
);

//wire [7:0] uart_rx_data_i, uart_tx_data_o;
//wire uart_rx_valid_o, uart_tx_valid_i;
//wire uart_rx_ready_i, uart_tx_ready_o;



//`include "./dut_tb.v"
wire reset; assign reset = ~reset_n;

// BEGIN ROM SECTION.
parameter ROM_DATA_WIDTH = 14; //{DATA_WIDTH{1'b1}};
//parameter ROM_ADDR_WIDTH = 13;
parameter ROM_ADDR_WIDTH = 16;
reg [ROM_DATA_WIDTH-1:0] rom [1<<ROM_ADDR_WIDTH];
initial begin
    $readmemh("main.rom", rom);
end
wire [ROM_ADDR_WIDTH-1:0] rom_addr;
wire [ROM_DATA_WIDTH-1:0] rom_data;
assign rom_data = rom[rom_addr];

// BEGIN RAM SECTION.
parameter RAM_DATA_WIDTH = 8;
//parameter RAM_ADDR_WIDTH = 9;
parameter RAM_ADDR_WIDTH = 12;
reg  [RAM_DATA_WIDTH-1:0] ram [1<<RAM_ADDR_WIDTH];
wire [RAM_ADDR_WIDTH-1:0] ram_addr;
wire [RAM_DATA_WIDTH-1:0] ram_data_rd;
wire [RAM_DATA_WIDTH-1:0] ram_data_wr;

assign ram_data_rd = ram[ram_addr];
always @(posedge clk) if(ram_we)
        ram[ram_addr] <= ram_data_wr;

// BEGIN AUX BUS
parameter AUX_DATA_WIDTH = 8;
parameter AUX_ADDR_WIDTH = 16;
wire [AUX_DATA_WIDTH-1:0] aux_data;
wire [AUX_ADDR_WIDTH-1:0] aux_addr;
wire aux_wr_stb;

// CREATE A RAM TO TEST AUX BUS
reg [AUX_DATA_WIDTH-1:0] aux_ram [1<<AUX_ADDR_WIDTH];
assign aux_data = aux_wr_stb ? {AUX_DATA_WIDTH{1'bz}} : aux_ram[aux_addr];
always @(posedge clk) if(aux_wr_stb) aux_ram[aux_addr] <= aux_data;

// BEGIN CLOCK ENABLE
wire clken, aux_rd_stb, aux_wr_stb, ram_we;
reg int0 = 0;
assign clken = 1;

risc16f84_clk2x pic (
                    .prog_dat_i(rom_data),
                    .prog_adr_o(rom_addr),
                    .ram_dat_i(ram_data_rd),
                    .ram_dat_o(ram_data_wr),
                    .ram_adr_o(ram_addr),
                    .ram_we_o(ram_we),
                    .aux_adr_o(aux_addr),
                    .aux_dat_io(aux_data),
                    .aux_we_o(aux_wr_stb),
                    .aux_re_o(aux_rd_stb),
                    .int0_i(int0),
                    .reset_i(reset),
                    .clk_en_i(clken),
                    .clk_i(clk),
                    .uart_rx(uart_rx),
                    .uart_tx(uart_tx),
                    .uart_prescale(uart_prescale)
                );

// Instantiate the UART again, to give us console access
// to the test bench. :)
wire uart_rx_i, uart_tx_o, uart_rx, uart_tx;
assign uart_rx_i = uart_tx;
assign uart_rx = uart_tx_o;
/* verilator lint_off PINMISSING */
uart tb_uart
(
    .clk(clk),
    .rst(!reset_n),
    .input_axis_tdata(uart_tx_data_i),
    .input_axis_tvalid(uart_tx_valid_i),
    .input_axis_tready(uart_tx_ready_o),

    .output_axis_tdata(uart_rx_data_o),
    .output_axis_tvalid(uart_rx_valid_o),
    .output_axis_tready(uart_rx_ready_i),
    .rxd(uart_rx_i),
    .txd(uart_tx_o),
    .prescale(uart_prescale)
);
/* verilator lint_on PINMISSING */

endmodule
