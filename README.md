# Soft Core PIC16F84
## Project goals
Create a small synthesizable soft core uController modeled in VERILOG that can be simulated with open-source tools such as:
* icarus verilog (compile / simulate)
* gtkwave (waveform viewer)
* sdcc (c compiler)
* gputils (Development utilities for Microchip (TM) PIC (TM) microcontrollers)
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
