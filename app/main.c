#include <msp430.h>
#include "heartbeat.h"


int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P6DIR |= BIT6;                          // Configure LED on P6.6
    P6OUT &= ~BIT6;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable GPIO high-impedance mode


    // Setup Timer B0 (for heartbeat 1s)
    TB0CTL |= TBCLR;                        // Clear timer
    TB0CTL |= TBSSEL__SMCLK;                // Select SMCLK (1 MHz)
    TB0CTL |= MC__CONTINUOUS;               // Set mode to continuous
    TB0CTL |= CNTL__16;                     // Use 16-bit counter(default)
    TB0CTL |= ID__8;                        // Divide clock by 8 (1MHz / 8 = 125kHz)
    TB0EX0 = TBIDEX__2;                     // Divide by 2(125 kHz /2 = 62.5 kHz)


    TB0CTL |= TBIE;                         // Enable Timer Overflow Interrupt

    TB0CTL &= ~TBIFG;

    __enable_interrupt();                   //Global

    while (1) {
    }
}


//------------------------------------------------------------------------------
//----------------------Start Timer Overflow ISR--------------------------------
//------------------------------------------------------------------------------
// 1 Second Functionality for several uses
//------------------------------------------------------------------------------
#pragma vector = TIMER0_B1_VECTOR
__interrupt void ISR_TB0_OVERFLOW(void)
{

        heartbeat_toggle();                  // Call heartbeat function to toggle LED
 

    TB0CTL &= ~TBIFG;                        // Clear interrupt flag
}
//------------------------------------------------------------------------------
//------------------------End Timer Overflow ISR--------------------------------
//------------------------------------------------------------------------------

