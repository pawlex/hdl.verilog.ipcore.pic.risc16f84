#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pic16f84.h>

#define NOP __asm nop __endasm
#define ASCII_CR 13
#define ASCII_LF 10

//#define GPR0_SIZE 0x74 // max size 0x74
#define GPR0_SIZE 0x30
#ifdef GPR0_SIZE
volatile unsigned char gpr_0[GPR0_SIZE];
#endif

#ifndef DATA_TYPES
#define DATA_TYPES
const unsigned char WELCOME[] = "Welcome to PIC!\n";
const unsigned char PROMPT[]  = "> ";
const unsigned char ERROR[]   = "ERROR!\n";
const unsigned char INIT_DATA = 0x40; //@

#define UART_BUFFER_STRUCT sizeof(uart_read_buffer)
typedef struct UartReadBuffer {
   volatile unsigned char   command[4];
   volatile unsigned char   address_a[8];
   volatile unsigned char   data_a[4];
   volatile unsigned char   term[2]; // add padd so we don't overflow.
   volatile uint8_t         address_24;
   volatile uint8_t         address_16;
   volatile uint8_t         address_8;
   volatile uint8_t         data_16;
   volatile uint8_t         data_8;
} UartReadBuffer;
UartReadBuffer uart_read_buffer;
volatile unsigned char uart_read_pointer;


typedef uint8_t  BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

const unsigned char hexmap[] = 
{ 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46 }; // 0-F

#endif

static void uart_int_handler();
static void welcome(void);
static void print_error();
static void print_uart_read_buffer();
static void print_prompt();
static void uart_print_string(unsigned char *val, uint8_t len);
static void uart_print_nl(void);
static void uart_put(unsigned char val);
static unsigned char uart_get(void);
static void convert_addresses(void);
static void int2asciihex(uint16_t val, uint8_t *retval, uint8_t size);
static void sleepn(uint16_t target);
static void io_data_write(uint16_t address, uint8_t data);
static uint8_t io_data_read(uint16_t address);
static void enable_interrupts(void);
static void disable_interrupts(void);
static void clear_interrupt(void);
