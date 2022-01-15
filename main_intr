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

void io_data_write(uint8_t val, uint16_t sleep)
{
    EEDATA = val;
    if(sleep)
    {
        sleepn(sleep);
    }
}


uint8_t uart_status()
{
    uint8_t uart_status = UART_SR;
    return uart_status;
}

//void uart_intr(void) __interrupt (0)
//{
//    UART_BUFFER[uart_buffer_tail_ptr] = UART_RX;
//    uart_buffer_tail_ptr++;
//    UART_SR = uart_status() | 0x40;
//    UART_SR = uart_status() & ~0x40;
//}



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

void led_scan(uint16_t sleep)
{
    uint8_t shift = 1;
    do
    {
       shift = shift << 1;
       io_data_write(shift, sleep);
    } while (shift < 0x80);
    do
    {
       shift = shift >> 1;
       io_data_write(shift, sleep);
    } while (shift > 0x1);
}


const unsigned char mystring[] = "Hello World!\n";
unsigned char buf[sizeof(mystring)];

void main(void)
{
    while(1)
    {
        for(uint8_t i=0; i<sizeof(mystring)-1; i++)
        {
            put_uart(&mystring[i]);
            //get_uart(&buf[i]);
        }

       led_scan(0x800);
    }
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
