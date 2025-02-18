#include <msp430.h>
#include "heartbeat.h"
#include "intrinsics.h"
#include "rgb_control.h"




volatile int heartcnt=0;                    //heartbeat counter
volatile int stepnum=0;                     //Counter for specifying pattern step
volatile int barflag=0;                     //ISR flag for lightbar
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

/*
* Notes for later:
* Need a pattern variable, current step variable, and trigger(overflow loop)

*/
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


    // Setup Timer B0 (for heartbeat 1s)
    TB0CTL |= TBCLR;                        // Clear timer
    TB0CTL |= TBSSEL__SMCLK;                // Select SMCLK (1 MHz)
    TB0CTL |= MC__CONTINUOUS;               // Set mode to continuous
    TB0CTL |= ID__4;                         // Divide clock by 8 (1MHz / 8 = 125kHz)
    TB0CCR0 = 62500;                       // Set overflow to 0.25s


    TB0CTL |= TBIE;                         // Enable Timer Overflow Interrupt

    TB0CTL &= ~TBIFG;

    __enable_interrupt();                   //Global

    while (1) {
        rgb_control(4);
        

if(barflag==1){

        stepnum=lightbar(stepnum);
        barflag=0;
}
    }
}


//------------------------------------------------------------------------------
//----------------------Start Timer Overflow ISR--------------------------------
//------------------------------------------------------------------------------
// quarter second overflow timer
//------------------------------------------------------------------------------
#pragma vector = TIMER0_B1_VECTOR
__interrupt void ISR_TB0_OVERFLOW(void)
{

//------------------Heartbeat Section-------------------------------------------
if(heartcnt < 2){
        heartbeat_toggle();                  // Call heartbeat function to toggle LED
        heartcnt++;
}else{
    heartcnt=0;
}
    TB0CTL &= ~TBIFG;                        // Clear interrupt flag
//--------------End Heartbeat Section-------------------------------------------
//------------------Start Lightbar counter--------------------------------------
if(stepnum <= 7){
    barflag=1;
}else{
    barflag=0;
    stepnum=0;
}

//-------------------End  Lightbar counter--------------------------------------
}
//------------------------------------------------------------------------------
//------------------------End Timer Overflow ISR--------------------------------
//------------------------------------------------------------------------------

