#ifndef __COMPONENT_LCD_H
#define __COMPONENT_LCD_H 1

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <delay.h>
#include <wire.h>

void LcdClear();
void LcdInit();
void LcdWriteByte(uint_least8_t dat, uint_least8_t type);
void LcdChar(uint_least8_t x, uint_least8_t y, uint_least8_t dat);
void LcdString(uint_least8_t x, uint_least8_t y, uint_least8_t* str);

#endif