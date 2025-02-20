/*
* This function declares basic control for the RGB LED
*/

#ifndef LIGHTBAR
#define LIGHTBAR

#include <msp430.h>
#include <stdint.h>

int lightbar(int count, int patt, uint8_t value);

#endif
