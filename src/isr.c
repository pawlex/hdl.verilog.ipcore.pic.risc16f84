/*
    isr.c
    (c) Micah Carrick - email@micahcarrick.com
    04.25.2005
    
    An example of using the interupt keyword with SDCC to handle an interrupt
    service routing (isr) in a basic PIC microcontroller program.  Also used
    as the example program on setting breakpoints and using the stopwatch 
    feature of GPSIM in the article at 
    http://www.micahcarrick.com/v2/content/view/15/4/
    
    This program is a 4-bit binary counter on the least significan 4 bits of
    PORTB.  It will increment every 1.638 mS when the TMR0 interrupt occurs.
    
    Compile:    sdcc --debug -mpic14 -p16f627 isr.c
    Simulate:   gpsim -pp16f627 -s isr.cod isr.asm
*/

/* Define processor and include header file. */

/* Setup chip configuration */
typedef unsigned int config;
config at 0x2007 __CONFIG = _CP_OFF & 
                            _WDT_OFF & 
                            _BODEN_OFF & 
                            _PWRTE_OFF & 
                            _ER_OSC_CLKOUT & 
                            _MCLRE_ON & 
                            _LVP_OFF &
                            _XT_OSC;

static void isr(void) interrupt 0 { 
    
    /*
    This is the interrupt service routine.  You'll find it at address
    0x004 in GPSIM just like if you were writing it in assembly. Since
    we're only using TMR0 interrup in this program, there is no need 
    to check which interrupt has occured.  
    
    Notice the use of 'interrupt 0' keyword in the function above.  This
    is how SDCC knows that this is the interrupt service routine.  We will
    only be using level '0' for PICs, therefore, you can use this same 
    function in all your PIC applications.
    */

    T0IF = 0;               /* Clear timer interrupt flag */     
    PORTB++;                /* increment PORTB */
}

void main(void) {

    CMCON = 0x07;           /* disable comparators */
    T0CS = 0;               /* clear to enable timer mode */
    PSA = 0;                /* clear to assign prescaller to TMRO */

    TRISB = 0xF0;           /* PORTB.0-3 Output, 4-7 Input */  
    
    /*
    The TMR0 interupt will occur when TMR0 overflows from 0xFF to
    0x00.  Without a prescaler, TMR0 will increment every clock
    cycle resulting in an interrupt every 256 cycles.  However, 
    using a prescaler, we can force that interrupt to occure at
    less frequent intervals.
    
    Each clock cycle is 1/4 the external clock.  Using that, and
    knowing the prescaler, we can determine the time interval for
    our interrupt.  
    
    PS2 PS1 PS0 Ratio   Cycles  4MHz        10MHz
    0   0   0   1:2     512      512.0 uS    204.8 uS    
    0   0   1   1:4     1024     1.024 mS    409.6 uS
    0   1   0   1:8     2048     2.048 mS    819.2 uS
    0   1   1   1:16    4096     4.096 mS    1.638 mS
    1   0   0   1:32    8192     8.192 mS    3.276 mS
    1   0   1   1:64    16384   16.384 mS    6.553 mS
    1   1   0   1:128   32768   32.768 mS   13.107 mS
    1   1   1   1:256   65536   65.536 mS   26.214 mS 
    */
    
    PS2 = 0;                /* 011 @ 10Mhz = 1.638 mS */
    PS1 = 1;  
    PS0 = 1;  

    INTCON = 0;             /* clear interrupt flag bits */
    GIE = 1;                /* global interrupt enable */
    T0IE = 1;               /* TMR0 overflow interrupt enable */
      
    TMR0 = 0;               /* clear the value in TMR0 */
    
    while(1) {              /* Loop forever */
    
        /* 
        We aren't doing anything in the main loop... we're just sittin'
        here like a jackass waiting for that TMR0 interrupt to occur.
        */                                 
    }
}

