#include <stdint.h>
#include <pic16f84.h>

#define NOP __asm nop __endasm
#define INTCON_INTE 0b00010000 //EXT INT EN
#define INTCON_INTF 0b00000010 //EXT INT FL
#define INTCON_GIE  0b10000000 //GLOBAL EN

// 38 bytes free;
volatile unsigned char BUFFER[35];
void main(void)
{
    for(uint8_t i=0; i<sizeof(BUFFER); i++)
    {
        BUFFER[i] = i;
    }
    for(uint8_t i=0; i<sizeof(BUFFER); i++)
    {
        EEDATA = BUFFER[i];
    }

    for(uint8_t i=0; i<sizeof(BUFFER); i++)
    {
        BUFFER[i] = EEDATA;
    }
    while(1) { NOP; }
}
