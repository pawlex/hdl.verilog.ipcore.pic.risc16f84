#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pic16f84.h>
#include "constants.h"

#define NOP __asm nop __endasm
#define UART_RX_BUFFER_SIZE 8
void uart_put(unsigned char val) __reentrant;
unsigned char uart_get(void);
void uart_print_string(unsigned char *val, uint8_t len) __reentrant;
void uart_print_nl(void);
unsigned char int2ascii(uint8_t val) __reentrant;
void uart_int_handler(void);
void welcome(void);
