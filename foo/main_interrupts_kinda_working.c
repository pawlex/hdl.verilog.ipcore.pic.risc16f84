#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pic16f84.h>
#include "constants.h"

#define NOP __asm nop __endasm

#define UART_RX_BUFFER_SIZE 5
volatile unsigned char uart_read_pointer;
volatile unsigned char uart_read_buffer[UART_RX_BUFFER_SIZE];

volatile unsigned char COMMAND[5]; // RIR
//volatile unsigned char ADDRESS[8];
//volatile unsigned char DATA[4];

const unsigned char WELCOME[] = "Welcome to PIC!\n";
const unsigned char PROMPT[]  = "> ";
const unsigned char ERROR[]   = "ERROR!\n";

static void uart_put(unsigned char val)
{
    UART_TX = val;
    while (!(TX_READY))  { NOP; };
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
        UART_TX = val[i];
        while (!(TX_READY))  { NOP; };
        TX_VALID=1;
        while (TX_READY)   { NOP; };
        TX_VALID = 0;

        //UART_TX = val[i];
        //while (!(UART_SR & _TX_READY)) { NOP; };    // WAIT FOR TX READY
        //UART_SR |= _TX_VALID;                       // set TX VALID
        //while (UART_SR & _TX_READY) { NOP; };       // WAIT FOR TX NOT READY
        //UART_SR &= ~_TX_VALID;                       // unset TX VALID
    }
}

static void uart_print_nl(void) 
{
    uart_put(ASCII_LF);
    uart_put(ASCII_CR);
}

static unsigned char int2ascii(uint8_t val)
{
    return ((val & 0xF) + 0x30);
}

static void print_prompt() 
{
    uart_print_nl();
    //uart_put(int2ascii(strlen(uart_read_buffer)));
    //uart_put(0x2c); //,
    uart_put(int2ascii(uart_read_pointer));
    uart_print_string(PROMPT, strlen(PROMPT));
}
/*
                   COMMAND[] ARG[1]
    RD INTERNAL RAM : RDIR : 0000 16-bits
    RD INTERNAL ROM : RDIO
    RD EXTERNAL RAM : RDXR
    RD IO BUS       : RDIO :
    WR IO BUS       : WRIO
    WR INTERNAL RAM : WRIR : 0000_ABCD DEFG
    WR EXTERNAL RAM : WRXR : ADDRESS DATA
*/

static void write_uart_buffer(unsigned char idx, unsigned char data)
{
    uart_read_buffer[idx] = data;
    uart_print_string("idx ", 5);
    uart_put( int2ascii(idx) );
    uart_print_nl();
    uart_print_string("data ", 5);
    uart_put(data);
    uart_print_nl();
    return;
}
static void uart_int_handler()
{
    if(uart_read_pointer > UART_RX_BUFFER_SIZE)
    {
        uart_print_nl();
        uart_print_string(ERROR, strlen(ERROR));
        uart_print_nl();
        print_prompt();
        uart_read_pointer = 0;
        uart_get();
    } else {
        unsigned char mychar = uart_get();
        if(( mychar == ASCII_CR ) || ( mychar == ASCII_LF ))
        {
            uart_print_nl();
            //uart_print_string("COMMAND:", 8);
            ////void *memcpy(void *dest, const void * src, size_t n)
            ////memcpy(&COMMAND, &uart_read_buffer, 4);
            //COMMAND[0] = uart_read_buffer[0];
            //COMMAND[1] = uart_read_buffer[1];
            //COMMAND[2] = uart_read_buffer[2];
            //COMMAND[3] = uart_read_buffer[3];
            //uart_print_string(COMMAND, 4);
            //uart_print_nl();
            //uart_print_string(uart_read_buffer, 4);
            //uart_print_nl();
            print_prompt();
            uart_read_pointer = 0;
        } else {
            uart_read_buffer[uart_read_pointer] = mychar;
            write_uart_buffer(uart_read_pointer, mychar);
            uart_put(uart_read_buffer[uart_read_pointer]);
            uart_read_pointer++;
        }
    }
}

static void welcome(void)
{
    for(uint8_t i=0; i<sizeof(uart_read_buffer)-1; i++)
    {
        uart_read_buffer[i] = (unsigned char)0x30+i; //!
    }
    uart_read_buffer[sizeof(uart_read_buffer)-1] = 0;
    uart_print_nl();
    uart_print_string(uart_read_buffer, strlen(uart_read_buffer));
    uart_print_nl();
    uart_print_string(uart_read_buffer, sizeof(uart_read_buffer));
    uart_print_nl();
    uart_print_string(WELCOME, strlen(WELCOME));
    uart_print_nl();
    print_prompt(); 
    uart_read_pointer = 0;

}


static void halt(void)
{
    while(1)
    {
        __asm nop __endasm;
    }
}

static void sleepn(uint16_t target)
{
    target = (target < 1) ? 10 : target; // sanity
    for(uint16_t i=0; i<target; i++)
    {
        __asm nop __endasm;
    }
}

static void io_data_write(uint8_t val, uint16_t sleep)
{
    EEDATA = val;
    if(sleep)
    {
        sleepn(sleep);
    }
}



static void enable_interrupts(void)
{
    INTCON |= INTCON_INTE;
    INTCON |= INTCON_GIE;
}
static void disable_interrupts(void)
{
    INTCON = 0;
}
static void clear_interrupt(void)
{
    INTCON &= ~INTCON_INTF; // Clear the flag just cuz.
}

static void interrupt_handler(void) __interrupt (0)
{
    disable_interrupts();
    uart_int_handler();
    clear_interrupt();
    enable_interrupts();
}


void main(void)
{
    welcome();
    enable_interrupts();
    uart_read_pointer = 0;
    while(1)
    {
        NOP;
    }
}

