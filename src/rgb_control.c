#include "rgb_control.h"
#include "intrinsics.h"

void rgb_control(int color){        //1=red, 2=green, 3=blue, 4=yellow

    if(color == 1){
        P4OUT |= BIT0;
        P2OUT &= ~BIT2;
        P2OUT &= ~BIT0;

    }else if (color == 2) {
        P4OUT &= ~BIT0;
        P2OUT |= BIT2;
        P2OUT &= ~BIT0;

    }else if (color == 3) {
        P4OUT &= ~BIT0;
        P2OUT &= ~BIT2;
        P2OUT |= BIT0;
    }else if (color ==4) {
        P4OUT |= BIT0;
        P2OUT |= BIT2;
        P2OUT &= ~BIT0;

        P4OUT |= BIT0;
        P2OUT |= BIT2;
    }else if(color == 5){
        P2OUT |= BIT2;
        P2OUT &= ~BIT0;
        P4OUT &= ~BIT0;
    }else if(color == 6){
        P4OUT |= BIT0;
        P2OUT |= BIT2;
        P2OUT &= ~BIT0;
    }else if(color == 7){
        P2OUT |= BIT0;
        P2OUT |= BIT2;
        P4OUT |= BIT0;
    }
}
