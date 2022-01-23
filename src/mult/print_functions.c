#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pic16f84.h>
#include "main.h"
#include "datatypes.h"
#include "constants.h"

static void welcome(void)
{
    uart_print_nl();
    uart_print_string(WELCOME, strlen(WELCOME));
    uart_print_nl();
    print_prompt(); 
}

static void print_error()
{
    uart_print_string(ERROR, strlen(ERROR));
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
    uart_read_buffer.data_8 = atoi(uart_read_buffer.data_a);
}
static void int2asciihex(uint8_t val, uint8_t *retval, uint8_t size)
{
    // This function converts an integer to ASCII hex;
    // The callee must null terminate the string (if required)
	//unsigned char mapped[size+1]; // 16-bit + NULL
	for(uint8_t i=0; i<size; i++)
	{
		retval[size-i-1] = (unsigned char) hexmap[ (unsigned char) (val >> (i*4) & 0xF) ];
	}
}

