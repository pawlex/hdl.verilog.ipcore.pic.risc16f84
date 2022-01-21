#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pic16f84.h>
#include "main.h"

//#define GPR0_SIZE 32
#ifdef GPR0_SIZE
volatile unsigned char gpr_0[GPR0_SIZE];
#endif

#define UART_BUFFER_STRUCT
#ifdef UART_BUFFER_STRUCT
typedef struct UartReadBuffer {
   volatile unsigned char command[4];
   volatile unsigned char       wsp0;
   volatile unsigned char address[8];
   volatile unsigned char       wsp1;
   volatile unsigned char    data[4];
   volatile unsigned char      term0;
} UartReadBuffer;
UartReadBuffer uart_read_buffer = { {0x55,0x55,0x55,0x55}, 0x20, {0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55}, 0x20, {0x55, 0x55, 0x55,0x55}, 0};
//UartReadBuffer uart_read_buffer = {}
//const uint8_t UART_RX_BUFFER_SIZE = sizeof(struct UartReadBuffer);
#define UART_RX_BUFFER_SIZE 18
#else
#define UART_RX_BUFFER_SIZE 19
volatile unsigned char uart_read_buffer[UART_RX_BUFFER_SIZE];
volatile unsigned char COMMAND[4];
volatile unsigned char ADDRESS[8];
volatile unsigned char DATA[4];
#endif

volatile unsigned char uart_read_pointer;

const unsigned char WELCOME[] = "Welcome to PIC!\n\0";
const unsigned char PROMPT[]  = "> \0";
const unsigned char ERROR[]   = "ERROR!\n\0";

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
        uart_put(val[i]);
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
    uart_put(int2ascii(uart_read_pointer));
    uart_print_string(PROMPT, strlen(PROMPT));
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
        const unsigned char mychar = uart_get();
        if(( mychar == ASCII_CR ) || ( mychar == ASCII_LF ))
        {
        #ifdef UART_BUFFER_STRUCT
            uart_print_nl();
            uart_print_string("COMMAND: ", 9); // 5
            uart_print_string(uart_read_buffer.command, sizeof(uart_read_buffer.command));
            uart_print_nl();
            uart_print_string("ADDRESS: ", 9); // 8
            uart_print_string(uart_read_buffer.address, sizeof(uart_read_buffer.address));
            uart_print_nl();
            uart_print_string("DATA   : ", 9); // 4
            uart_print_string(uart_read_buffer.data, sizeof(uart_read_buffer.data));
            uart_print_nl();
        #else
            memcpy(&COMMAND, &uart_read_buffer   , 4);
            memcpy(&ADDRESS, &uart_read_buffer+5 , 8);
            memcpy(&DATA,    &uart_read_buffer+14, 4);
            uart_print_nl();
            uart_print_string("COMMAND: ", 9); // 5
            uart_print_string(COMMAND, sizeof(COMMAND));
            uart_print_nl();
            uart_print_string("ADDRESS: ", 9); // 8
            uart_print_string(ADDRESS, sizeof(ADDRESS));
            uart_print_nl();
            uart_print_string("DATA   : ", 9); // 4
            uart_print_string(DATA, sizeof(DATA));
            uart_print_nl();
        #endif
            ////void *memcpy(void *dest, const void * src, size_t n)
            print_prompt();
            uart_read_pointer = 0;
        } else {
            UartReadBuffer *p = &uart_read_buffer;
            p = (UartReadBuffer*)(((uint8_t*)p) + uart_read_pointer);
            memcpy(p, &mychar, 1);
            //ptr+=uart_read_pointer;
            //UartReadBuffer *ptr = &uart_read_buffer;
            //ptr += uart_read_pointer;
            //memcpy(ptr, &mychar, 1);
            //uint8_t curloc = uart_read_pointer;
            //curloc += &uart_read_buffer;
            //memcpy((uint8_t*)curloc, &mychar, 1);
            //*uart_read_buffer+uart_read_pointer = mychar;
            //uart_put(&uart_read_buffer[uart_read_pointer]);
            uart_put(mychar);
            uart_read_pointer++;
        }
    }
}

static void welcome(void)
{
    uart_print_nl();
    uart_print_string(WELCOME, strlen(WELCOME));
    uart_print_nl();
    print_prompt(); 
}
//static void sleepn(uint16_t target)
//{
//    target = (target < 1) ? 10 : target; // sanity
//    for(uint16_t i=0; i<target; i++)
//    {
//        __asm nop __endasm;
//    }
//}
//static void io_data_write(uint16_t address, uint8_t data)
//{
//    PORTA  = (address & 0xff);
//    PORTB  = (address >> 8);
//    EEDATA = data;
//}
//static uint8_t io_data_read(uint16_t address)
//{
//    PORTA  = (address & 0xff);
//    PORTB  = (address >> 8);
//    return (uint8_t) EEDATA;
//}
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
    for(uint8_t i=0;i<UART_RX_BUFFER_SIZE;i++)
    {
        //uart_read_buffer[i] = 0;
    }
    uart_read_pointer = 0;

    #ifdef GPR0_SIZE
    for(uint8_t i=0;i<GPR0_SIZE;i++)
    {
        gpr_0[i] = i;
        EEDATA = i;
    }
    #endif


    welcome();
    enable_interrupts();
    while(1)
    {
        NOP;
    }
}

