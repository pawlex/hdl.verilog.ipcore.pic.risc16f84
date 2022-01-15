#include <pic16regs.h>
#include <stdint.h>

/* Paul Komurka
 * test file for the soft-core pic16f84 (clk2x)
 * with ports A/B removed and replaced with a 
 * GPIO BUS.
 *
 * IO BUS:
 * ADDRESS [15:0] = { PORTB,PORTA }
 * DATA    [7:0 ] =   EEDATA
 */

void halt(void)
{
    while(1)
    {
        __asm nop __endasm;
    }
}

#define STRIDE 0x40
#define MAXVAL 0xFF

uint16_t i=0;
void main(void)
{
    // LOAD GPIO RAM (RAM BACKED PORT)
    // WITH DATA = ADDRESS
    for(i=0;i<MAXVAL;i=i+STRIDE)
    {
        PORTA = i & 0xff; 
        PORTB = ((i >> 8) & 0xff);
        EEDATA = i & 0xff;
    }
    
    // READ BACK AND COMPARE
    for(i=0;i<MAXVAL;i=i+STRIDE)
    {
        PORTA = i & 0xff; 
        PORTB = ((i >> 8) & 0xff);
        
        // DEADLOOP IF MISMATCH
        if(EEDATA != (i & 0xff))
        {
            halt();
        }
    }

    halt();
}

