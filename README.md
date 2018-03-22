# Soft Core PIC16F84
## Project goals
Create a small synthesizable soft core uController modeled in VERILOG that can be simulated with open-source tools such as:
* icarus verilog (compile / simulate)
* gtkwave (waveform viewer)
* sdcc (c compiler)
* gputils (Development utilities for Microchip (TM) PIC (TM) microcontrollers)

# FPGA
## STATUS
Untested

# Simulation
## STATUS
All functions working as expected. Interrupts not tested yet.

## Requirements
* Linux desktop environment
* SDCC with non-free package for PIC
* icarus verilog
```
Icarus Verilog version 0.10.0 
Icarus Verilog Preprocessor
Icarus Verilog Parser/Elaborator
vvp.tgt: Icarus Verilog VVP Code Generator
```
* gtkwave (3.3.79)
* SDCC : pic16/pic14/8 3.4.0 #8981 (Oct 25 2014) (Linux)
* gputils 1.4.2

## Getting started
build the C source (main.c)

``` $ make ```

compile the verilog model

``` $ compile ```

## Resources
* top_tb.v -- Top level simulation
* dut_tb.v -- Device under test simulation env.
* risc16f84_clk2x.v -- device under test.
* main.c -- soft-core firmware writtin in C.
* Makefile -- for building soft-core firmware
* compile -- for compiling / executing / simulating HDL.
* intel2readmemh -- utility for converting between intel hex to $readmemh format.

# Resources
original risc16f84 project on opencores : https://opencores.org/project,risc16f84
SDCC code examples : https://github.com/diegoherranz/sdcc-examples
PIC 16F627 datasheet : http://ww1.microchip.com/downloads/en/devicedoc/40044f.pdf
