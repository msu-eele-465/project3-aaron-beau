#include <msp430.h>
#include "heartbeat.h"

volatile unsigned int overflow_count = 0;   // Overflow counter

int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P6DIR |= BIT6;                          // Configure LED on P6.6
    P6OUT &= ~BIT6;

    //Columns
    P1DIR |= BIT4 | BIT5 | BIT6 | BIT7;     //set columns as outputs
    P1OUT &= ~(BIT4 | BIT5 | BIT6 | BIT7);     //initially set all low
    //Rows
    P1DIR &= ~(BIT0 | BIT1 | BIT2 | BIT3);
    P1REN |= BIT0 | BIT1 | BIT2 | BIT3;
    P1OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);

    P6OUT &= ~BIT6;                         // Clear P1.0 output
    P6DIR |= BIT6;                          // Set P1.0 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable GPIO high-impedance mode


    // Setup Timer B0 (for heartbeat)
    TB0CTL |= TBCLR;                        // Clear timer
    TB0CTL |= TBSSEL__SMCLK;                // Select SMCLK (1 MHz)
    TB0CTL |= MC__CONTINUOUS;               // Set mode to continuous
    TB0CTL |= ID_3;                         // Divide clock by 8 (1MHz / 8 = 125kHz)
    TB0CCR0 = 125000;                       // Set overflow to 1 second (125000 / 125kHz = 1s)

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

