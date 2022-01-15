#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pic16f84.h>

#define NOP __asm nop __endasm

//volatile unsigned char UART_BUFFER[16];
//volatile uint8_t uart_buffer_tail_ptr = 0;

void halt(void)
{
    while(1)
    {
        __asm nop __endasm;
    }
}

void sleepn(uint16_t target)
{
    target = (target < 1) ? 10 : target; // sanity
    for(uint16_t i=0; i<target; i++)
    {
        __asm nop __endasm;
    }
}

uint8_t uart_status()
{
    uint8_t uart_status = UART_SR;
    return uart_status;
}

void put_uart(unsigned char *val)
{
    UART_TX = *val;
    while (!(uart_status() & 0x20)) { NOP; };    // WAIT FOR TX READY
    UART_SR = uart_status() | 0x80;                     // set TX VALID
    while (uart_status() & 0x20) { NOP; };       // WAIT FOR TX NOT READY
    UART_SR = uart_status() & ~0x80;                    // unset TX VALID
}

void get_uart(unsigned char *val)
{
    while (!(uart_status() & 0x10)) { NOP; };    // WAIT FOR RX VALID
    *val = UART_RX;
    UART_SR = uart_status() | 0x40;                     // set RX READY
    UART_SR = uart_status() & ~0x40;                    // unset RX READY
}

uint8_t uart_rx_valid()
{
    return (int8_t)(uart_status() & 0x10);
}

const unsigned char mystring[] = "Hello World!\n";

void main(void)
{
    while(1)
    {
        if(uart_rx_valid())
        {
            unsigned char foo;
            get_uart(&foo);
            put_uart(&foo);
            put_uart(&foo);
            put_uart(&foo);
            put_uart(&foo);
        }
        //for(uint8_t i=0; i<sizeof(mystring)-1; i++)
        //{
        //    put_uart(&mystring[i]);
        //    //get_uart(&buf[i]);
        //}
    }
}
