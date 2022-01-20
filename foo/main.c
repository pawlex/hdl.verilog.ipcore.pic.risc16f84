#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pic16f84.h>
#include "constants.h"

#define NOP __asm nop __endasm

#define UART_RX_BUFFER_SIZE 8
volatile unsigned char uart_read_pointer;
volatile unsigned char uart_read_buffer[UART_RX_BUFFER_SIZE];

const unsigned char WELCOME[] = "Welcome to PIC!\n";
const unsigned char PROMPT[]  = "> ";
const unsigned char ERROR[]   = "ERROR!\n";

void uart_put(unsigned char val) __reentrant
{
    UART_TX = val;
    while (!(TX_READY))  { NOP; };
    TX_VALID=1;
    while (TX_READY)   { NOP; };
    TX_VALID = 0;
}

unsigned char uart_get(void) __reentrant
{
    if(RX_VALID)
    {
        RX_READY = 1;
        RX_READY = 0;
        return (unsigned char) UART_RX;
    } else {
        return 0xff;
    }
}

extern void uart_print_string(unsigned char *val, uint8_t len)
{
    for(uint8_t i=0; i<len; i++)
    {
        UART_TX = val[i];
        while (!(UART_SR & _TX_READY)) { NOP; };    // WAIT FOR TX READY
        UART_SR |= _TX_VALID;                       // set TX VALID
        while (UART_SR & _TX_READY) { NOP; };       // WAIT FOR TX NOT READY
        UART_SR &= ~_TX_VALID;                       // unset TX VALID
    }
}

extern void uart_print_nl(void)
{
    uart_put(ASCII_LF);
    uart_put(ASCII_CR);
}

extern unsigned char int2ascii(uint8_t val) __reentrant
{
    return ((val & 0xF) + 0x30);
}

extern void uart_int_handler() __reentrant
{
    if(uart_read_pointer > UART_RX_BUFFER_SIZE)
    {
        uart_print_nl();
        uart_print_string(ERROR, strlen(ERROR));
        uart_print_nl();
        uart_read_pointer = 0;
        uart_get();
    } else {
        unsigned char mychar = uart_get();
        if(( mychar == ASCII_CR ) || ( mychar == ASCII_LF ))
        {
            uart_print_nl();
            uart_put(int2ascii(sizeof(uart_read_buffer)));
            uart_put(0x2c); //,
            uart_put(int2ascii(uart_read_pointer));
            uart_print_string(PROMPT, strlen(PROMPT));
            uart_read_pointer = 0;
        } else {
            uart_read_buffer[uart_read_pointer] = mychar;
            uart_put(uart_read_buffer[uart_read_pointer]);
            uart_read_pointer++;
        }
    }
}

extern void welcome(void)
{
    for(uint8_t i=0; i<sizeof(uart_read_buffer); i++)
    {
        uart_read_buffer[i] = 0x21; //!
    }
    uart_print_nl();
    uart_print_string(WELCOME, sizeof(WELCOME));
    uart_print_nl();
    uart_print_string(PROMPT, sizeof(PROMPT));
    
    uart_read_pointer = 0;

}
