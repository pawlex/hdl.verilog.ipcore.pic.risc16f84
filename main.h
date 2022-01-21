#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pic16f84.h>

#define NOP __asm nop __endasm

#define ASCII_CR 13
#define ASCII_LF 10

typedef uint8_t  BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

////
