#include <msp430.h>
#include "heartbeat.h"
#include "intrinsics.h"
#include "rgb_control.h"

volatile unsigned int overflow_count = 0;   // Overflow counter

int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
//------------------------------------------------------------------------------
//----------------------------Pin Initialization--------------------------------
//------------------------------------------------------------------------------
 
 //-----HEARTBEAT lED
    P6DIR |= BIT6;                          // Configure LED on P6.6
    P6OUT &= ~BIT6;

//------rgb LED
    P4DIR |= BIT0;                          // Configure red part
    P4OUT &= ~BIT0;

    P2DIR |= BIT2;                          // Configure green part
    P2OUT &= ~BIT2;

    P2DIR |= BIT0;                          // Configure blue part
    P2OUT &= ~BIT0;

//-----10 Segment Display Initialization
    P2DIR |= BIT4;                          // Configure pin 10
    P2OUT &= ~BIT4;

    P3DIR |= BIT7;                          // Configure pin 9
    P3OUT &= ~BIT7;

    P6DIR |= BIT4;                          // Configure pin 8
    P6OUT &= ~BIT4;

    P6DIR |= BIT3;                          // Configure pin 7
    P6OUT &= ~BIT3;

    P6DIR |= BIT2;                          // Configure pin 6
    P6OUT &= ~BIT2;

    P6DIR |= BIT1;                          // Configure pin 5
    P6OUT &= ~BIT1;

    P6DIR |= BIT0;                          // Configure pin 4
    P6OUT &= ~BIT0;

    P2DIR |= BIT1;                          // Configure pin 3
    P2OUT &= ~BIT1;

//------------------------------------------------------------------------------
//------------------------End Pin Initialization--------------------------------
//------------------------------------------------------------------------------


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
        rgb_control(1);
        __delay_cycles(100000);
        rgb_control(2);
        __delay_cycles(100000);
        rgb_control(3);
        __delay_cycles(100000);
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

