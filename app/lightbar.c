#include "lightbar.h"
#include "intrinsics.h"

int lightbar(int count, int patt){        //function to carry through each pattern
 if (patt==1){
    if(count ==0){
    P2OUT |= BIT4;               //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT |= BIT4;               //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT |= BIT2;               //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT |= BIT0;               //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==1) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT |= BIT7;               //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT |= BIT3;               //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT |= BIT1;               //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT |= BIT1;               //Light 3
    count++;
    }else if (count ==2) {
    P2OUT |= BIT4;               //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT |= BIT4;               //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT |= BIT2;               //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT |= BIT0;               //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++; 
    }else if (count ==3) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT |= BIT7;               //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT |= BIT3;               //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT |= BIT1;               //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT |= BIT1;               //Light 3
    count++; 
    }else if (count ==4) {
    P2OUT |= BIT4;               //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT |= BIT4;               //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT |= BIT2;               //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT |= BIT0;               //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==5) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT |= BIT7;               //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT |= BIT3;               //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT |= BIT1;               //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT |= BIT1;               //Light 3
    count++;
    }else if (count ==6) {
    P2OUT |= BIT4;               //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT |= BIT4;               //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT |= BIT2;               //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT |= BIT0;               //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==7) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT |= BIT7;               //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT |= BIT3;               //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT |= BIT1;               //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT |= BIT1;               //Light 3
    count=0;
    }
}else if (patt==2){
    if(count ==0){
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT |= BIT3;               //Light 7
    P6OUT |= BIT2;               //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==1) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT |= BIT4;               //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT |= BIT1;               //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==2) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT |= BIT7;               //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT |= BIT0;               //Light 4
    P2OUT &= ~BIT1;              //Light 3 
    count++;  
    }else if (count ==3) {
    P2OUT |= BIT4;               //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT |= BIT1;               //Light 3 
    count++;
    }else if (count ==4) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT |= BIT7;               //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT |= BIT1;               //Light 3 
    count++;
    }else if (count ==5) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT |= BIT4;               //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT |= BIT1;               //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count=0;
   

    }
}else if (patt==3){
    if(count ==0){
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT |= BIT1;               //Light 3
    count++;
    }else if (count ==1) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT |= BIT0;               //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==2) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT |= BIT1;               //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++; 
    }else if (count ==3) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT |= BIT2;               //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++; 
    }else if (count ==4) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT |= BIT3;               //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==5) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT |= BIT4;               //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==6) {
    P2OUT &= ~BIT4;              //Light 10
    P3OUT |= BIT7;               //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count++;
    }else if (count ==7) {
    P2OUT |= BIT4;               //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;              //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;              //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;              //Light 4
    P2OUT &= ~BIT1;              //Light 3
    count=0;
    }
}


    return count;
}
