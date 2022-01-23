#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//#include <string.h>
#include <pic16f84.h>
#include "main.h"

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


static void welcome(void)
{
    uart_print_nl();
    uart_print_string(WELCOME, sizeof(WELCOME));
    uart_print_nl();
    print_prompt(); 
}

static void print_error()
{
    uart_print_string(ERROR, sizeof(ERROR));
    uart_print_nl();
    print_prompt();
}
static void print_uart_read_buffer()
{
    uart_print_nl();
    uart_print_string("COMMAND: ", 9); // 5
    uart_print_string(uart_read_buffer.command, sizeof(uart_read_buffer.command));
    uart_print_nl();
    uart_print_string("ADDRESS: ", 9); // 8
    uart_print_string(uart_read_buffer.address_a, sizeof(uart_read_buffer.address_a));
    uart_print_nl();
    uart_print_string("DATA   : ", 9); // 4
    uart_print_string(uart_read_buffer.data_a, sizeof(uart_read_buffer.data_a));
    uart_print_nl();
}
static void print_prompt() 
{
    uart_print_nl();
    //uart_print_string prints in ascending order.
    //so we allocate 4 bytes, write 0x to the low 2
    //and convert the upper 2 to hex.
    //then print all 4.
    //
    unsigned char hexdata[4];// = {0x30, 0x78, 0x55, 0x40};
    int2asciihex(uart_read_pointer, &hexdata[2], 2);
    hexdata[0] = 0x30; //0
    hexdata[1] = 0x78; //x
    uart_print_string(hexdata, 4);
    uart_print_string(PROMPT, 2);
}
static void uart_print_string(unsigned char *val, uint8_t len)
{
    for(uint8_t i=0; i<len; i++)
    {
        uart_put(val[i]);
    }
}

static void uart_print_nl(void) 
{
    uart_put(ASCII_LF);
    uart_put(ASCII_CR);
}

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

static void convert_addresses()
{
    //uart_read_buffer.data_8 = atoi(uart_read_buffer.data_a);
    //unsigned char odata[4] = {0x30, 0x31, 0x32, 0x33};
    //uint16_t idata = atoi(odata);
    //memcpy(&uart_read_buffer.data_16, idata, 2);
    //int2asciihex(idata, uart_read_buffer.data_a, 4);
    //int2asciihex(idata, odata, 4);
    uint16_t idata = atoi(uart_read_buffer.data_a);
    int2asciihex(idata, uart_read_buffer.data_a, 4);
}
static void int2asciihex(uint16_t val, uint8_t *retval, uint8_t size)
{
    // This function converts an integer to ASCII hex;
    // The callee must null terminate the string (if required)
	//unsigned char mapped[size+1]; // 16-bit + NULL
	for(uint8_t i=0; i<size; i++)
	{
		retval[size-i-1] = (unsigned char) hexmap[ (unsigned char) (val >> (i*4) & 0xF) ];
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
