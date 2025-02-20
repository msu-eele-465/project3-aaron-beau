/*----------------------------------------------------------------------------------
Beau Coburn & Aaron Foster
EELE 465
2/20/25
Project 3: Keypad LED Pattersn
Description:  In the below code, the logic for analyzing which key has been pressed
on the keypad is defined.

Pin Out
--------------
Rows : P1.4-7
Cols : P6.0-3

//This line was added to fix git pushing
-------------------------------------------------------------------------------------*/
#include <msp430.h>

// Keypad mapping
char keymap[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

char scan_keypad(void){
    int row, col;

    // Loop through all the columns
    for(col = 0; col < 4; col++) {
        // Set all columns low
        P6OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);  // Set all columns low
        
        // Set the current column to HIGH
        P6OUT |= (BIT0 << col);                             // Set the current column high

        // Check each row to see if any row is low (indicating a key press)
        for(row = 0; row < 4; row++) {
            if((P1IN & (BIT4 << row)) == 0) {               // If the row is pulled low
                // Wait for key release to avoid multiple detections
                while((P1IN & (BIT4 << row)) == 0);
                return keymap[row][col];                    // Return the key from the keymap
            }
        }
    }

    return 0; // No key pressed

}

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    //Columns
    P6DIR |= BIT0 | BIT1 | BIT2 | BIT3;     //set columns as outputs
    P6OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);     //initially set all low
    //Rows
    P1DIR &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    P1REN |= BIT4 | BIT5 | BIT6 | BIT7;
    P1OUT |= BIT4 | BIT5 | BIT6 | BIT7;

    P1OUT &= ~BIT0;                         // Clear P1.0 output
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    char key;                                        

    while(1){
        P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
        __delay_cycles(100000); 
                   // Delay for 100000*(1/MCLK)=0.1s
        key = scan_keypad();
    }

}
