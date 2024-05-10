#ifndef __MODULE_LCD_LCD1602_H
#define __MODULE_LCD_LCD1602_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include "framework/delay.h"
#include "framework/wire.h"

#define LCD1602_CMD 0
#define LCD1602_DATA 1

#define LCD1602_ADDRESS 0x20
#define LCD1602_BACKLIGHT 0x08
#define LCD1602_EN 0x04
#define LCD1602_RW 0x02
#define LCD1602_RS 0x01

void LCD1602Init(void);
void LCD1602Clear(void);
void LCD1602Write(uint8_t ch);
void LCD1602Print(uint8_t* str);
void LCD1602GotoXY(uint8_t x, uint8_t y);
void LCD1602Draw(uint8_t x, uint8_t y, uint8_t ch);

#endif
