#ifndef __MODULE_LCD_LCD1602_H
#define __MODULE_LCD_LCD1602_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include "framework/delay.h"
#include "framework/wire.h"

#define LCD_CMD 0         // 写命令
#define LCD_DATA 1        // 写数据
#define LCD_COLUMN 15     // LCD 屏幕列数
#define LCD_ADDRESS 0x27  // LCD 屏幕地址

void LCD1602Init(void);
void LCD1602Clear(void);
void LCD1602Write(uint8_t x, uint8_t y, uint8_t dat);
void LCD1602Print(uint8_t x, uint8_t y, uint8_t* str);

#endif
