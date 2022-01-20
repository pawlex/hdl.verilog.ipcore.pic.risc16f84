#include <stdio.h>
#include <stdint.h>
#include <pic16f84.h>

#define NOP __asm nop __endasm
#define ASCII_CR 13
#define ASCII_LF 10

// external interrupt enable.
//#define INTCON_INTE 0b00010000
// external interrupt flag.
//#define INTCON_INTF 0b00000010
// global interrupt enable
//#define INTCON_GIE  0b10000000


