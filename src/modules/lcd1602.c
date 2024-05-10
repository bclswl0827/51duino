#include "modules/lcd1602.h"

uint8_t LCD1602ReadChip() {
    Wire_beginTransmission(LCD1602_ADDRESS);
    uint8_t dat = Wire_read();
    Wire_endTransmission();
    return dat;
}

void LCD1602WriteChip(uint8_t dat) {
    Wire_beginTransmission(LCD1602_ADDRESS);
    Wire_write(dat);
    Wire_endTransmission();
}

void LCD1602EnableLCD(uint8_t value) {
    LCD1602WriteChip(value | LCD1602_EN);
    LCD1602WriteChip(value & (~4));
}

void LCD1602WriteData(uint8_t type, uint8_t dat) {
    uint8_t high = dat & 0xF0 | LCD1602_BACKLIGHT;
    uint8_t low = (dat << 4) & 0xF0 | LCD1602_BACKLIGHT;

    uint8_t temp = LCD1602ReadChip() & 0xF0;
    LCD1602WriteChip(temp | LCD1602_BACKLIGHT);

    if (type == LCD1602_CMD) {
        LCD1602WriteChip(temp | LCD1602_BACKLIGHT);
    } else {
        LCD1602WriteChip(temp | LCD1602_RS | LCD1602_BACKLIGHT);
    }
    temp = LCD1602ReadChip() & 0x0F;

    LCD1602WriteChip(high | temp);
    LCD1602EnableLCD(high | temp);

    LCD1602WriteChip(low | temp);
    LCD1602EnableLCD(low | temp);
}

void LCD1602Init() {
    Wire_begin();
    delay(100);

    LCD1602WriteData(LCD1602_CMD, 0x30);
    LCD1602WriteData(LCD1602_CMD, 0x30);
    LCD1602WriteData(LCD1602_CMD, 0x30);
    LCD1602WriteData(LCD1602_CMD, 0x20);
    delay(10);

    LCD1602WriteData(LCD1602_CMD, 0x28);
    uint8_t temp = LCD1602ReadChip();
    LCD1602EnableLCD(temp);

    LCD1602WriteData(LCD1602_CMD, 0x28);
    LCD1602WriteData(LCD1602_CMD, 0X0C);
    LCD1602WriteData(LCD1602_CMD, 0x06);
    LCD1602WriteData(LCD1602_CMD, 0x01);
    delay(10);
}

void LCD1602Clear() {
    LCD1602WriteData(LCD1602_CMD, 0x01);
}

void LCD1602GotoXY(uint8_t x, uint8_t y) {
    if (x % 2 == 0) {
        LCD1602WriteData(LCD1602_CMD, 0x80 + y);
    } else {
        LCD1602WriteData(LCD1602_CMD, (0x80 + 0x40 + y));
    }
}

void LCD1602Write(uint8_t ch) {
    LCD1602WriteData(LCD1602_DATA, ch);
}

void LCD1602Print(uint8_t* str) {
    while (*str != '\0') {
        LCD1602WriteData(LCD1602_DATA, *str++);
    }
}

void LCD1602Draw(uint8_t x, uint8_t y, uint8_t ch) {
    y &= 0x01;
    x &= 0X0F;
    if (y) {
        x |= 0x40;
    }
    x |= 0x80;

    LCD1602WriteData(LCD1602_CMD, x);
    LCD1602WriteData(LCD1602_DATA, ch);
}
