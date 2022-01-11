#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pic16f84.h>

/* Paul Komurka
 * test file for the soft-core pic16f84 (clk2x)
 * with ports A/B removed and replaced with a 
 * GPIO BUS.
 *
 * IO BUS:
 * ADDRESS [15:0] = { PORTB,PORTA }
 * DATA    [7:0 ] =   EEDATA
 * UART_TX [7:0]
 * UART_RX [7:0]
 * UART_SR
 * UART_SRbits.TX_BUSY
 * UART_SRbits.RX_BUSY    
 * UART_SRbits.RX_OVERRUN     
 * UART_SRbits.RX_FRAME_ERROR     
 * UART_SRbits.TX_READY
 * UART_SRbits.TX_VALID
 * UART_SRbits.RX_READY
 * UART_SRbits.RX_VALID
 */

void halt(void)
{
    while(1)
    {
        __asm nop __endasm;
    }
}

void main(void)
{
    uint8_t foo = 0x55;
    UART_SR = 0xFF;
    UART_SR = 0x00;
    UART_SR = 0xFF;
    UART_SR = 0x00;
    UART_SR = 0xFF;
    UART_SR = 0x00;
    UART_SR = 0xFF;
     //UART_SR.TX_BUSY        = 0x1
     //UART_SR.RX_BUSY        = 0x1
     //UART_SR.RX_OVERRUN     = 0x1
     //UART_SR.RX_FRAME_ERROR = 0x1
     //UART_SR.TX_READY       = 0x1
     //UART_SR.TX_VALID       = 0x1
     //UART_SR.RX_READY       = 0x1
     //UART_SR.RX_VALID       = 0x1

    for(uint8_t i=0;i<0xFF; i++)
    {
        PORTA = i; 
        EEDATA = i;
    }
    for(uint8_t i=0;i<0xFF; i++)
    {
        PORTB = i; 
        EEDATA = i;
    }
    halt();
}

