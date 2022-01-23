#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pic16f84.h>
#include "main.h"
#include "constants.h"
#include "print_functions.h"

static void uart_int_handler()
{
    if(uart_read_pointer >= UART_BUFFER_STRUCT)
    {
        print_error();
        print_prompt();
        uart_read_pointer = 0;
        uart_get(); // Throw away anything waiting in the UART just in case.
    } else {
        const unsigned char mychar = uart_get();
        if( mychar == 0x20 ) 
        { 
            // skip if space
            uart_put(mychar);
            return; 
        }
        if(( mychar == ASCII_CR ) || ( mychar == ASCII_LF ))
        {
            convert_addresses();
            print_uart_read_buffer();
            print_prompt();
            uart_read_pointer = 0;
        } else {
            // Some pointer magic to allow writing to our struct as it were an array
            ////void *memcpy(void *dest, const void * src, size_t n)
            UartReadBuffer *p = &uart_read_buffer;
            p = (UartReadBuffer*)(((uint8_t*)p) + uart_read_pointer);
            memcpy(p, &mychar, 1);
            // write the current character to the UART. 
            uart_put(mychar);
            uart_read_pointer++;
        }
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
static void io_data_write(uint16_t address, uint8_t data)
{
    PORTA  = (address & 0xff);
    PORTB  = (address >> 8);
    EEDATA = data;
}
static uint8_t io_data_read(uint16_t address)
{
    PORTA  = (address & 0xff);
    PORTB  = (address >> 8);
    return (uint8_t) EEDATA;
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
    uart_int_handler();
    clear_interrupt();
    enable_interrupts();
}
extern void main(void)
{
    // ZERO the READ buffer;
    for(uint8_t i=0;i<UART_BUFFER_STRUCT;i++)
    {
        UartReadBuffer *p = &uart_read_buffer;
        p = (UartReadBuffer*)(((uint8_t*)p) + i);
        memcpy(p, &INIT_DATA, 1);
        io_data_write((uint16_t)i, 0x55);
    }
    uart_read_pointer = 0;

    #ifdef GPR0_SIZE
    for(uint8_t i=0;i<GPR0_SIZE;i++)
    {
        gpr_0[i] = i;
        io_data_write((uint16_t)i, 0xAA);
    }
    #endif


    welcome();
    enable_interrupts();
    while(1)
    {
        NOP;
    }
}

