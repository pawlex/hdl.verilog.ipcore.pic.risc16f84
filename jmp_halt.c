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

void main(void)
{
    halt();
}

