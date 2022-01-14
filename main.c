#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pic16f84.h>

#define NOP __asm nop __endasm
// external interrupt enable.
#define INTCON_INTE 0b00010000
// external interrupt flag.
#define INTCON_INTF 0b00000010
// global interrupt enable
#define INTCON_GIE  0b10000000


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
    //unsigned char retval = UART_RX;
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
    //led_scan(0x800);
}



const unsigned char mystring[] = "UHello World!\n";
void uart_loopback_test(void)
{
    //unsigned char buf[sizeof(mystring)];
    //for(uint8_t i=0; i<sizeof(mystring)-1; i++)
    //{
    //    put_uart(&mystring[i]);
    //    get_uart(&buf[i]);
    //}
}

void main(void)
{
    

    INTCON |= INTCON_GIE;
    INTCON |= INTCON_INTE;
    //put_uart_stk(mystring[0]);

    while(1)
    {
        //uart_loopback_test();
        //sleepn(0x100);
        //led_scan(0x1000);
    }
}

void interrupt_handler(void) __interrupt (0)
{
    // This CPU only has one interrupt and no interrupt flag.
    // It would probably be best to build an external interrupt
    // controller that can be controlled through the AUX bus.
    put_uart_stk(get_uart_stk());

    // For now, assume the interrupt is UART.
    //if( !(uart_status() & 0x10) )
    //{
    //    INTCON &= ~INTCON_INTF; // Clear the flag just cuz.
    //    return; // Not the UART.
    //}
    //unsigned char mychar = get_uart_stk();

    //if( (mychar < 0x20) || (mychar > 0x7f) ) // Character is not printable.
    //{
    //    INTCON &= ~INTCON_INTF; // Clear the flag just cuz.
    //    return;
    //}
    //
    ////mychar = mychar >= 0x5A ? 0x41 : mychar + 1;
    //put_uart_stk(mychar);
    //INTCON &= ~INTCON_INTF; // Clear the flag just cuz.
    //return;
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
