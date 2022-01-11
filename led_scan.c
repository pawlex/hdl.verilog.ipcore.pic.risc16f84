/* Paul Komurka
 * test file for the soft-core pic16f84 (clk2x)
 * with ports A/B removed and replaced with a 
 * GPIO BUS.
 *
 * IO BUS:
 * ADDRESS [15:0] = { PORTB,PORTA }
 * DATA    [07:0] =   EEDATA
*/

//#include <pic16regs.h>
//#include "include/pic16regs.h"
#include "include/pic16f84.h"
#include <stdint.h>
#include <stdio.h>
//#include <unistd.h>

void halt(void)
{
    while(1)
    {
        __asm nop __endasm;
    }
}

// Until we get a proper timer, this is the best we can do.
// TODO: Profile how long the call/return/nop takes so this
// can be somewhat calibrated:  similar to usleep(100).
void nop_sleep(uint16_t target)
{
	for(uint16_t i=target; i>0; i--)
	{
		__asm nop __endasm;
	}
}

void io_data_write(uint8_t val, uint16_t sleep)
{
    EEDATA = val;
    if(sleep)
    {
        nop_sleep(sleep);
    }
}

void led_test(void)

{
    io_data_write(0x55, 0xF000);
    io_data_write(0xAA, 0xF000);
}

void led_scan(uint16_t sleep)
{
    uint8_t shift = 1;
    do
    {
       shift = shift << 1;
       io_data_write(shift, sleep);
    } while (shift < 0x80);
    do
    {
       shift = shift >> 1;
       io_data_write(shift, sleep);
    } while (shift > 0x1);
    nop_sleep(0x4000);
}

void main(void)
{
	while(1)
	{
	    //led_test();
        led_scan(0x800);
	}

    halt();
}



// LOAD GPIO RAM (RAM BACKED PORT)
// WITH DATA = ADDRESS
// for(uint16_t i=0;i<MAXVAL;i=i+STRIDE)
// {
//     //PORTA = i & 0xff; 
//     //PORTB = ((i >> 8) & 0xff);
//     EEDATA = i & 0xff;
// 	nopsleep();
// }
//
// READ BACK AND COMPARE
//for(i=0;i<MAXVAL;i=i+STRIDE)
//{
//    PORTA = i & 0xff; 
//    PORTB = ((i >> 8) & 0xff);
//    
//    // DEADLOOP IF MISMATCH
//    if(EEDATA != (i & 0xff))
//    {
//        halt();
//    }
//}
