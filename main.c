#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pic16f84.h>

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
    do{ sleepn(10); } while (!(uart_status() & 0x20)); // WAIT FOR TX READY
    UART_SR = uart_status() | 0x80; // set TX VALID
    do{ sleepn(10); } while (uart_status() & 0x20); // WAIT FOR TX NOT READY
    UART_SR = uart_status() & ~0x80; // unset TX VALID
}

unsigned char get_uart()
{
    do{ sleepn(10); } while (!(uart_status() & 0x10)); // WAIT FOR RX VALID
    sleepn(10);
    unsigned char retval = UART_RX;
    sleepn(10);
    UART_SR = uart_status() | 0x40; // set RX READY
    UART_SR = uart_status() & ~0x40; // unset RX READY
    return retval;
}
const unsigned char mystring[] = "Hello World!\n";
char buf[16];

void main(void)
{
    for(uint8_t i=0; i<sizeof(mystring); i++)
    {
        put_uart(&mystring[i]);
        buf[i] = get_uart();
    }
    halt();
}

//typedef struct
//  {
//  unsigned TX_BUSY         0x01 
//  unsigned RX_BUSY         0x02 
//  unsigned RX_OVERRUN      0x04 
//  unsigned RX_FRAME_ERROR  0x08 
//  unsigned RX_VALID        0x10 
//  unsigned TX_READY        0x20 
//  unsigned RX_READY        0x40 
//  unsigned TX_VALID        0x80 
//  } __UART_SRbits_t;
