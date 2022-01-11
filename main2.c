#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pic16f84.h>

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

int check_uart_status()
{
    uint8_t uart_status = UART_SR;
    PORTB = 0xBE;
    PORTA = 0xEF;
    EEDATA = uart_status;
    PORTB = 0xBE;
    PORTA = 0xEF;
    sleepn(0x100);
}


void main(void)
{


    check_uart_status();
    check_uart_status();
    check_uart_status();
    check_uart_status();

    halt();
}

//UART_SR.TX_BUSY        = 0x1
//UART_SR.RX_BUSY        = 0x1
//UART_SR.RX_OVERRUN     = 0x1
//UART_SR.RX_FRAME_ERROR = 0x1
//UART_SR.TX_READY       = 0x1
//UART_SR.TX_VALID       = 0x1
//UART_SR.RX_READY       = 0x1
//UART_SR.RX_VALID       = 0x1

