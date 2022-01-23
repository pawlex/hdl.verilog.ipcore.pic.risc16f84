#include <stdio.h>
#include <stdint.h>
#include <pic16f84.h>
#include "main.h"

static void uart_put(unsigned char val)
{
    while (TX_BUSY)  { NOP; };
    UART_TX = val;
    TX_VALID=1;
    while (TX_READY)   { NOP; };
    TX_VALID = 0;
}

static unsigned char uart_get(void)
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
static void uart_print_string(unsigned char *val, uint8_t len)
{
    for(uint8_t i=0; i<len; i++)
    {
        uart_put(val[i]);
    }
}

static void enable_interrupts(void)
{
    INTE = 1;
    GIE = 1;
}
static void disable_interrupts(void)
{
    INTCON = 0;
}
static void clear_interrupt(void)
{
    INTF=0; // Clear the flag just cuz.
}

static void interrupt_handler(void) __interrupt (0)
{
    disable_interrupts();
    clear_interrupt();
}

#define DATA_SIZE 0x50
unsigned char data0[DATA_SIZE];
unsigned char data1[DATA_SIZE];

extern void main(void)
{
    for(uint8_t i=0x30; i<0x7F; i++)
    {
        data0[i-0x30] = i;
        data1[i-0x30] = i;
    }
    while(1)
    {
        for(uint8_t j=0; j<DATA_SIZE; j++)
        {
            uart_put(data0[j]);
            uart_put(data1[j]);
        }
    }
}






