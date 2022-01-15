#include <stdint.h>
//#include <stdio.h>
//#include <stdarg.h>
//#include <string.h>
#include <pic16f84.h>

#define NOP __asm nop __endasm
// external interrupt enable.
#define INTCON_INTE 0b00010000
// external interrupt flag.
#define INTCON_INTF 0b00000010
// global interrupt enable
#define INTCON_GIE  0b10000000


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

//const unsigned char WELCOME[] = "Welcome to PIC!\n";
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

void enable_interrupts(void)
{
    INTCON |= INTCON_INTE;
    INTCON |= INTCON_GIE;
}
void disable_interrupts(void)
{
    INTCON = 0;
}
void clear_interrupt(void)
{
    INTCON &= ~INTCON_INTF; // Clear the flag just cuz.
}

volatile unsigned char uart_read_buffer[8];
void main(void)
{
    for(uint8_t i=0; i<sizeof(uart_read_buffer); i++)
    {
        uart_read_buffer[i] = 0x0;
    }


    enable_interrupts(); 
    while(1)
    {
        NOP;
    }
}

const unsigned char ERROR[] = "ERROR!\n";

volatile int uart_read_pointer = -1;
void interrupt_handler(void) __interrupt (0)
{
    disable_interrupts();
    // This CPU only has one interrupt and no interrupt flag.
    // It would probably be best to build an external interrupt
    // controller that can be controlled through the AUX bus.
    unsigned char mychar = get_uart_stk();
    //char* str = mychar;
    //sprintf(str, "0x%p\n", mychar);
    if(( mychar == 13 ) || ( mychar == 10 )) //LF|NL
    {
        if(uart_read_pointer > -1)
        {
            uart_print_string(uart_read_buffer, uart_read_pointer);
        }
        uart_print_nl();
        //put_uart_stk(uart_read_pointer+0x30); // print as an ASCII number
        uart_print_string(PROMPT, sizeof(PROMPT));
        uart_read_pointer = -1;
    } else {
        uart_read_pointer++;
        uart_read_buffer[uart_read_pointer] = mychar;
        put_uart_stk(uart_read_buffer[uart_read_pointer]);
    } 
    clear_interrupt();
    enable_interrupts();
}


    // For now, assume the interrupt is UART.
    //if( !(uart_status() & 0x10) )
    //{
    //    clear_external_interrupt();
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
//}



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
//
//
//
//
//void get_uart(unsigned char *val)
//{
//    while (!(uart_status() & 0x10)) { NOP; };    // WAIT FOR RX VALID
//    *val = UART_RX;
//    UART_SR = uart_status() | 0x40;                     // set RX READY
//    UART_SR = uart_status() & ~0x40;                    // unset RX READY
//}

//void led_scan(uint16_t sleep)
//{
//    uint8_t shift = 1;
//    do
//    {
//       shift = shift << 1;
//       io_data_write(shift, sleep);
//    } while (shift < 0x80);
//    do
//    {
//       shift = shift >> 1;
//       io_data_write(shift, sleep);
//    } while (shift > 0x1);
//    //led_scan(0x800);
//}



