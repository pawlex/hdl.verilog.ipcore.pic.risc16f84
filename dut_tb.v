// vim:set softtabstop=4 shiftwidth=4 expandtab tabstop=4 autoindent
///////////////////////////////////////////////////////////////////////////////
`timescale 100ns/100ns

module dut_tb(
           input clk,
           input reset
       );
// BEGIN ROM SECTION.
parameter ROM_DATA_WIDTH = 14; //{DATA_WIDTH{1'b1}};
parameter ROM_ADDR_WIDTH = 13;
reg [ROM_DATA_WIDTH-1:0] rom [1<<ROM_ADDR_WIDTH];
initial begin
    $readmemh("main.rom", rom);
end
wire [ROM_ADDR_WIDTH-1:0] rom_addr;
wire [ROM_DATA_WIDTH-1:0] rom_data;
assign rom_data = rom[rom_addr];

// BEGIN RAM SECTION.
parameter RAM_DATA_WIDTH = 8;
parameter RAM_ADDR_WIDTH = 7;
reg  [RAM_DATA_WIDTH-1:0] ram [1<<RAM_ADDR_WIDTH];
wire [RAM_ADDR_WIDTH-1:0] ram_addr;
wire [RAM_DATA_WIDTH-1:0] ram_data_rd;
wire [RAM_DATA_WIDTH-1:0] ram_data_wr;
//initial begin
//        for(i=0;i<(1<<RAM_ADDR_WIDTH);i=i+1) for(n=0;(1<<RAM_DATA_WIDTH);n=n+1)
//        initial $dumpvars(0,ram[i][n]);
//end
integer i;
initial begin
    //for(i=0;i<(1<<RAM_ADDR_WIDTH);i=i+1) $dumpvars(0,ram[i]);
end

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

// BEGIN INTERRUPT (Not tested as per the notes).
wire int0;
assign int0 = 0;

// BEGIN CLOCK ENABLE
wire clken;
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
                    .clk_i(clk)
                );

endmodule







    // [13:0] ROM read data
    // [12:0] ROM address
    // [7:0] RAM read data
    // [7:0] RAM write data
    // [8:0] RAM address; ram_adr[8:7] indicates RAM-BANK
    // RAM write strobe (H active)
    // [15:0] Auxiliary address bus
    // [7:0] Auxiliary data bus (tri-state bidirectional)
    // Auxiliary write strobe (H active)
    // PORT-B(0) INT
    // Power-on reset (H active)
    // Clock enable for all clocked logic
    // Clock inputZ
