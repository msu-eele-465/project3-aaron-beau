#include "lightbar.h"
#include "intrinsics.h"

void lightbar(int count){        //1=red, 2=green, 3=blue, 4=yellow
    P2OUT |= BIT4;              //Light 10

    P3OUT |= BIT7;              //Light 9

    P6OUT |= BIT4;              //Light 8

    P6OUT |= BIT3;              //Light 7

    P6OUT |= BIT2;              //Light 6

    P6OUT |= BIT1;              //Light 5

    P6OUT |= BIT0;              //Light 4

    P2OUT |= BIT1;              //Light 3
}
