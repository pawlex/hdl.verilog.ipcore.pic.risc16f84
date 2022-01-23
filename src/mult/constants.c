#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pic16f84.h>
#include "main.h"
#include "datatypes.h"
#include "print_functions.h"

#ifndef CONSTANTS_DEFINED
#define CONSTANTS_DEFINED

#define NOP __asm nop __endasm
#define ASCII_CR 13
#define ASCII_LF 10

//#define GPR0_SIZE 0x74 // max size 0x74
//#define GPR0_SIZE 0x8
#ifdef GPR0_SIZE
volatile unsigned char gpr_0[GPR0_SIZE];
#endif

const unsigned char WELCOME[] = "Welcome to PIC!\n";
const unsigned char PROMPT[]  = "> ";
const unsigned char ERROR[]   = "ERROR!\n";
const unsigned char INIT_DATA = 0x40; //@

#endif
