# Soft Core PIC16F84
## Project goals
### Create a very small soft-core processor / uController (not SOC)
* No timers / counters
* No VGA
* No Keyboard controller
* No built-in UART
### Written in Verilog
### Platform Independent (xilinx,altera,lattice)
* No megafunction blocks or platform specific macros.
### Synthesizable with low gate count.
### Compatable with open-source tools such as:
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
* gputils 
* * apt-get install gputils or install from [source](http://sourceforge.net/projects/gputils/files/gputils/)
* SDCC deps
* * sudo apt-get install bison flex g++ libboost-dev texinfo
* * sudo apt install git binutils binutils-dev subversion zlib1g zlib1g-dev libfl2 libfl-dev
-
* SDCC with non-free package for PIC (pic14:PIC16F)
* * svn checkout svn://svn.code.sf.net/p/sdcc/code/trunk/sdcc sdcc
* * ./configure
* * make -j all
* * sudo make install (installs to /usr/local/bin/sdcc)
* * sdcc -v ( SDCC : mcs51/z80/z180/r2k/r2ka/r3ka/sm83/tlcs90/ez80_z80/z80n/ds390/pic16/pic14/TININative/ds400/hc08/s08/stm8/pdk13/pdk14/pdk15 )
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
* original risc16f84 project on opencores : https://opencores.org/project,risc16f84
* SDCC code examples : https://github.com/diegoherranz/sdcc-examples
* PIC 16F627 datasheet : http://ww1.microchip.com/downloads/en/devicedoc/40044f.pdf

# History
### Motivation
I grew tired creating verilog state machines that were effecively "throw away code".  Anyone who has writtin this type of code to do things like handle UART ouptut or copy bytes from one unit to another probably know exactly what I'm talking about.  I found I was spending as much, if not more time on integration of IP's than I was writing them.
### Settling on PIC
I initially wanted to use PacoBlaze (PicoBlaze clone written in Verilog) for this project as it checked all the boxes for requirements.  However, after learning the core, wiring up the sim, learning the ISA and assembler tools I found it just didn't work as expected.  I have reached out to the developer to address this, but I'm not holding my breath seeing as the project hasn't been updated since 2007.  If anyone has any experience with PacoBlaze please don't hesitate to reach out to me.  I find Paco/Picoblaze to have a rich yet easy ISA, mature tools and large community support.
