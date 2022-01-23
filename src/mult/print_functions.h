#include <stdint.h>

static void welcome(void);
static void print_error();
static void print_uart_read_buffer();
static void print_prompt();
static void uart_print_string(unsigned char *val, uint8_t len);
static void uart_print_nl(void);
static void uart_put(unsigned char val);
static unsigned char uart_get(void);
static void convert_addresses();
static void int2asciihex(uint8_t val, uint8_t *retval, uint8_t size);
//
