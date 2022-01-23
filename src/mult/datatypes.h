#include <stdint.h>
#ifndef DATA_TYPES
#define DATA_TYPES
#define UART_BUFFER_STRUCT sizeof(uart_read_buffer)
typedef struct UartReadBuffer {
   volatile unsigned char   command[4];
   volatile unsigned char   address_a[8];
   volatile unsigned char   data_a[4];
   volatile unsigned char   term[2]; // add padd so we don't overflow.
   volatile uint8_t         address_24;
   volatile uint8_t         address_16;
   volatile uint8_t         address_8;
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
