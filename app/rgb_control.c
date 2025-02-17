#include "rgb_control.h"

// Function to toggle LED (called from ISR in main.c)
void rgb_control(int color){        //1=red, 2=green, 3=blue

    if(color == 1){
        P4OUT |= BIT0;
        P2OUT &= ~BIT2;
        P2OUT &= ~BIT0;

    }else if (color == 2) {
        P2OUT |= BIT2;
        P4OUT &= ~BIT0;
        P2OUT &= ~BIT0;

    }else if (color == 3) {
        P2OUT |= BIT0;
        P4OUT &= ~BIT0;
        P2OUT &= ~BIT2;

    }
}
