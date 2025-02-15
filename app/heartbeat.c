#include "heartbeat.h"

// Function to toggle LED (called from ISR in main.c)
void heartbeat_toggle(void) {
    P6OUT ^= BIT6;  // Toggle LED state
}
