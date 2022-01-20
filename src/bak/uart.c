#include <stdio.h>
#include <stdint.h>
//#include <stdio.h>
//#include <stdarg.h>
//#include <string.h>
#include <pic16f84.h>

#define NOP __asm nop __endasm

uint8_t uart_status()
{
    uint8_t uart_status = UART_SR;
    return uart_status;
}

void put_uart_stk(unsigned char val)
{
    UART_TX = val;
    while (!(uart_status() & 0x20)) { NOP; };    // WAIT FOR TX READY
    UART_SR = uart_status() | 0x80;                     // set TX VALID
    while (uart_status() & 0x20) { NOP; };       // WAIT FOR TX NOT READY
    UART_SR = uart_status() & ~0x80;                    // unset TX VALID
}

unsigned char get_uart_stk(void)
{
    while (!(uart_status() & 0x10)) { NOP; };    // WAIT FOR RX VALID
    UART_SR = uart_status() | 0x40;                     // set RX READY
    UART_SR = uart_status() & ~0x40;                    // unset RX READY
    return (unsigned char) UART_RX;
}

void put_uart(unsigned char *val)
{
    UART_TX = *val;
    while (!(uart_status() & 0x20)) { NOP; };    // WAIT FOR TX READY
    UART_SR = uart_status() | 0x80;                     // set TX VALID
    while (uart_status() & 0x20) { NOP; };       // WAIT FOR TX NOT READY
    UART_SR = uart_status() & ~0x80;                    // unset TX VALID
}

const unsigned char WELCOME[] = "Welcome to PIC!\n";
const unsigned char PROMPT[] = "> ";

void uart_print_string(unsigned char *val, uint8_t len)
{
    for(uint8_t i=0; i<len; i++)
    {
        put_uart(&val[i]);
    }
}

void uart_print_nl(void)
{
    put_uart_stk((unsigned char)10);
    put_uart_stk((unsigned char)13);
}
