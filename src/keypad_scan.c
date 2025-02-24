/*----------------------------------------------------------------------------------
Beau Coburn & Aaron Foster
EELE 465
2/20/25
Project 3: Keypad LED Pattersn
Description:  In the below code, the logic for analyzing which key has been pressed
on the keypad is defined.

Pin Out
--------------
Rows : P1.0, P1.1, P1.2, P1.3 
Cols : P1.4, P1.5, P1.6, P1.7

//This line was added to fix git pushing
-------------------------------------------------------------------------------------*/
#include <msp430.h> 
#include "rgb_control.h"
 
// Keypad mapping
char keymap[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

char scan_keypad(void){
    unsigned int row, col;
    const char row_pin[4] = {BIT0, BIT1, BIT2, BIT3};
    const char col_pin[4] = {BIT4, BIT5, BIT6, BIT7};

    // Loop through all the columns
    for(col = 0; col < 4; col++) {
        // Set all columns low
        P1OUT &= ~(BIT4 | BIT5 | BIT6 | BIT7);  // Set all columns low
        
        // Set the current column to HIGH
        P1OUT |= col_pin[col];                             // Set the current column high

        // Check each row to see if any row is low (indicating a key press)
        for(row = 0; row < 4; row++) {
            if((P1IN & (row_pin[row])) != 0) {               // If the row is pulled low
            //P1OUT &= ~(BIT4 | BIT5 | BIT6 | BIT7);  // Set all columns low
                // Wait for key release to avoid multiple detections
                while((P1IN & (row_pin[row])) != 0);
                return keymap[row][col];                    // Return the key from the keymap
            }
        }
    }

    return 0; // No key pressed

}

int unlock_keypad(void){ 
    int i = 0;
    int equal = 1;
    int locked = 1;
    char key;                   
    char unlock_code[4];        
    char set_code[4] = {'6','9','6','9'};             
         // Collecting 4-digit unlock code
        i = 0;                                  // Reset index before input
        while (i < 4 && locked == 1) {
            key = scan_keypad();
            if (key != 0) {                     // Only store valid key presses
            rgb_control(4);
           // __delay_cycles(1500000);
                unlock_code[i] = key;
                i++;
            }
        }

        // Check if entered code matches set_code
        
        for (i = 0; i < 4; i++) {
            if (unlock_code[i] != set_code[i]) {
                equal = 0;                      // Codes do not match
                break;
            }
        }

        if (equal == 1) {
            locked = 0;                         // Unlock system
            
        } else {
            locked = 1;                         // Keep system locked
            
        }
        return locked;
    }

    char led_pattern(void){
       static int last_patt = 0;  // Store the last selected pattern (-1 initially)
        char key = 0;  // Variable to hold the key press

    
        key = scan_keypad();
    

    // Convert key from ASCII to an integer pattern
    if (key >= '0' && key <= '9') {
        last_patt = key - '0';  // Convert ASCII digit ('0' to '9') to integer (0-9)
    } else {
        switch (key) {
            case 'A': last_patt = 10; break;
            case 'B': last_patt = 11; break;
            case 'C': last_patt = 12; break;
            case 'D': last_patt = 13; break;
            case '*': last_patt = 14; break;
            case '#': last_patt = 15; break;
            default: break;  // Ignore invalid keys
        }
    }

    return last_patt;  // Always return the last valid pattern
    }