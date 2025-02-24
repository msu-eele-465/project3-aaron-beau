#include "lightbar.h"
#include "intrinsics.h"
#include <stdint.h>

int lightbar(int count, int patt, uint8_t value){        //function to carry through each pattern
 if (patt == 0){
    P2OUT &= ~BIT4;               //Light 10
    P3OUT &= ~BIT7;              //Light 9
    P6OUT &= ~BIT4;               //Light 8
    P6OUT &= ~BIT3;              //Light 7
    P6OUT &= ~BIT2;               //Light 6
    P6OUT &= ~BIT1;              //Light 5
    P6OUT &= ~BIT0;               //Light 4
    P2OUT &= ~BIT1;              //Light 3
 }else if (patt==1){
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
    // Use bitwise operations to light up LEDs based on the 8-bit value
    if (value & BIT0){ 
        P2OUT |= BIT1;
    }else{
        P2OUT &= ~BIT1;
    }
    if (value & BIT1){
        P6OUT |= BIT0; 
    }else {
        P6OUT &= ~BIT0;
    }
    if (value & BIT2){ 
        P6OUT |= BIT1;  
    }else{ 
        P6OUT &= ~BIT1;
    }
    if (value & BIT3) {
        P6OUT |= BIT2; 
    }else{ 
        P6OUT &= ~BIT2;
    }
    if (value & BIT4) {
        P6OUT |= BIT3;
    }else{
        P6OUT &= ~BIT3;
    }
    if (value & BIT5) {
        P6OUT |= BIT4;
    }else{ 
        P6OUT &= ~BIT4;
    }
    if (value & BIT6) {
        P3OUT |= BIT7;
    }else{
        P3OUT &= ~BIT7;
    }
    if (value & BIT7) { 
        P2OUT |= BIT4;
    }else{
        P2OUT &= ~BIT4;
    }
}

else if (patt==3){
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
