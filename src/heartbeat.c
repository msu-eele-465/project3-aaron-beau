/*
This file simply toggles the onboard green LED to show that the program is still in operation.
*/

#include "heartbeat.h"

// Function to toggle LED (called from ISR in main.c)
void heartbeat_toggle(void) {
    
    P6OUT ^= BIT6;  // Toggle LED state
    
}
