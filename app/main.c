#include <msp430.h>
#include "heartbeat.h"
#include "intrinsics.h"
#include "keypad_scan.h"
#include "rgb_control.h"
#include <stdint.h>
#include "lightbar.h"



//-------------------Variable Initialization -----------------------------------
/*Many of the variable are for counting, see description for each job*/
//------------------------------------------------------------------------------
volatile int heartcnt=0;                    //heartbeat counter
volatile int stepnum=0;                     //Counter for specifying pattern step
volatile int barflag=0;                     //ISR flag/trigger for lightbar
volatile int pattnum=0;                     //Specifier for the lightbar pattern

int pattnum1=0;                             //Specific step number variable
int pattnum3=0;                             //Both for memory
int temp;
int initial_state = 1;
                                            //(Keypad Modifiable)
volatile uint8_t lightbar_byte=0;           //8-bit counter for pattern 2
int locked=1;                               //1 when locked
int patt;                                   //variable to store desired pattern
int time_cntl=0;                            //Multiplier for base-transition 
                                            //control (default 1s)  
                                            //(Keypad Modifiable)
int base_time;                              //Base time specifier
int barcounter=0;                           //Step counter for ISR, compared to 
                                            //time_cntl for base-transition

int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
//------------------------------------------------------------------------------
//----------------------------Pin Initialization--------------------------------
//------------------------------------------------------------------------------
 
 //-----HEARTBEAT lED
    P6DIR |= BIT6;                          // Configure LED on P6.6
    P6OUT &= ~BIT6;


    

//------RGB LED                             1=red, 2=green, 3=blue, 4=yellow
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

  //Columns
    P1DIR |= BIT4 | BIT5 | BIT6 | BIT7;     //set columns as outputs
    P1OUT &= ~(BIT4 | BIT5 | BIT6 | BIT7);     //initially set all low
    //Rows
    P1DIR &= ~(BIT0 | BIT1 | BIT2 | BIT3);
    P1REN |= BIT0 | BIT1 | BIT2 | BIT3;
    P1OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);

    


   
//------------------------------------------------------------------------------
//------------------------End Pin Initialization--------------------------------
//------------------------------------------------------------------------------



    PM5CTL0 &= ~LOCKLPM5;                   // Disable GPIO high-impedance mode


//------Setup 0.25s Timer B0 (for heartbeat 1s)
    TB0CTL |= TBCLR;                        // Clear timer
    TB0CTL |= TBSSEL__SMCLK;                // Select SMCLK (1 MHz)
    TB0CTL |= MC__UP;               // Set mode to continuous
    TB0CTL |= ID__4;                        
    TB0CCR0 = 64472;                        // Set overflow to 0.25s


    TB0CTL |= TBIE;                         // Enable Timer Overflow Interrupt

    TB0CTL &= ~TBIFG;

    __enable_interrupt();                   // Global

    

    while (1) {
        while(locked == 1){
            P2OUT &= ~BIT4;                //Light 10
            P3OUT &= ~BIT7;                //Light 9
            P6OUT &= ~BIT4;                //Light 8
            P6OUT &= ~BIT3;                //Light 7
            P6OUT &= ~BIT2;                //Light 6
            P6OUT &= ~BIT1;                //Light 5
            P6OUT &= ~BIT0;                //Light 4
            P2OUT &= ~BIT1;                //Light 3
            rgb_control(1);
            locked = unlock_keypad();
            pattnum = 20;
            temp=1;
        }
        while(locked == 0){               //While system unlocked
           if(initial_state == 1){
             rgb_control(3);}               //Set LED blue

            pattnum = led_pattern();      //Call read fn
            switch(pattnum){              //Check for 'A' or 'B'
                                          //Inc if A, Dec if B
                case 10:
                    time_cntl++;
                    pattnum=temp;
                    break;
                case 11:               //vvv Fail safe for no overflow
                    if((base_time+time_cntl)==1){
                        pattnum=temp;
                        break;
                    }else{
                    time_cntl=time_cntl-1;
                    pattnum=temp;
                    break;
                    }
            }
        if(pattnum == 13){            //Locking again
            locked = 1;
            initial_state = 1;
        }else{
            locked = 0;
            initial_state = 0;
        }
            
    
        }
    }

}

//------------------------------------------------------------------------------
//----------------------Start Timer Overflow ISR--------------------------------
//------------------------------------------------------------------------------
/*This ISR implements a basic 0.25s overflow loop for toggling heartbeat 
* LED and the various LED bar patterns which can be scaled depending on
* inputs from the keypad*/
//------------------------------------------------------------------------------
#pragma vector = TIMER0_B1_VECTOR
__interrupt void ISR_TB0_OVERFLOW(void)
{

//------------------Heartbeat Section-------------------------------------------
if(heartcnt < 3){                        // Frequency timer for heartbeat (1s)
    heartcnt++;
}else{
    heartbeat_toggle();                  // Call heartbeat function to toggle LED
    heartcnt=0;
}
//--------------End Heartbeat Section-------------------------------------------
//------------------Start Lightbar flag call------------------------------------
/*Code counts every time ISR is called and sets flag to toggle lightbar() every 
* time_cntl times(base 1s) The else loop in this section contains every case for
* the LED bar patterns which is triggered when barcounter is greater than 
* time_cntl*/
//------------------------------------------------------------------------------
if(locked==0){                          // All patterns fall inside this loop
if(barcounter<(base_time+time_cntl)){   // Loop to control interation frequency
    barcounter++;                       // (time_cntl varies)
}else{                                  // Once counter reaches time limit start 
if(stepnum <= 7 && pattnum != 2){       // Checking for proper pattern
    barflag=1;
}else{
        barflag=0;
        stepnum=0;
    }
//-------------------End  Lightbar flag call------------------------------------
//-------------------Start pattern caller --------------------------------------
/*Section is still nestled in else loop ^^^ this logic is separate in order to
* properly call and pass in byte of data to lightbar()*/
//------------------------------------------------------------------------------
    if(pattnum == 2){                   // Individual logic to check for 
    barflag=1;                          // binary counter
        if (lightbar_byte>255){         // When all bits toggled reset to zeroes
            lightbar_byte=0;
        }else{                          //Else increment byte by 1
            lightbar_byte++;
        }
    }
    barcounter=0;

}                                       // End of big else loop

//When keypad_scan is changed to output 'locked', put this inside if(locked==0){}
//Assuming int locked=unlock_keypad()
    if(barflag==1 && pattnum==0){       // If flag set call lightbar 
            stepnum=lightbar( stepnum, pattnum, lightbar_byte);
            rgb_control(6);
            barflag=0;
            base_time=1;
            temp=pattnum;
    }else if(barflag==1 && pattnum==1){ // If flag set call lightbar 
            pattnum1=lightbar( pattnum1, pattnum, lightbar_byte);
            rgb_control(5);
            barflag=0;
            base_time=3;
            temp=pattnum;
    }if(barflag==1 && pattnum==2){     // If flag set call lightbar 
            stepnum=lightbar( stepnum, pattnum, lightbar_byte);
            rgb_control(2);
            barflag=0;
            base_time=1;
            temp=pattnum;
    }else if(barflag==1 && pattnum==3){// If flag set call lightbar 
            pattnum3=lightbar( pattnum3, pattnum, lightbar_byte);
            rgb_control(7);
            barflag=0;
            base_time=1;
            temp=pattnum;
    }

}

    TB0CTL &= ~TBIFG;                   // Clear interrupt flag
}
//------------------------------------------------------------------------------
//------------------------End Timer Overflow ISR--------------------------------
//------------------------------------------------------------------------------

