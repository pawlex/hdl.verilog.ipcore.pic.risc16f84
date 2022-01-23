#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pic16f84.h>
#include "datatypes.h"


static void uart_int_handler();
static void sleepn(uint16_t target);
static void io_data_write(uint16_t address, uint8_t data);
static uint8_t io_data_read(uint16_t address);
static void enable_interrupts(void);
static void disable_interrupts(void);
static void clear_interrupt(void);
