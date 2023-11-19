#include "modules/lcd1602.h"

void LCD1602WriteRegister(uint8_t dat, uint8_t type) {
    uint8_t msb = dat & 0xf0;
    uint8_t lsb = (dat & 0x0f) << 4;
    Wire_beginTransmission(LCD_ADDRESS);

    switch (type) {
        case LCD_CMD:
            Wire_write(0x00 + msb);
            Wire_write(0x04 + msb);
            Wire_write(0x00 + msb);
            Wire_write(0x00 + lsb);
            Wire_write(0x04 + lsb);
            Wire_write(0x00 + lsb);
            break;
        case LCD_DATA:
            Wire_write(0x01 + msb);
            Wire_write(0x05 + msb);
            Wire_write(0x01 + msb);
            Wire_write(0x01 + lsb);
            Wire_write(0x05 + lsb);
            Wire_write(0x01 + lsb);
            break;
    }

    Wire_endTransmission();
    delayMicroseconds(10);
}

void LCD1602Clear() {
    LCD1602WriteRegister(0x01, LCD_CMD);
}

void LCD1602Init() {
    Wire_begin();
    LCD1602WriteRegister(0x02, LCD_CMD);  // 设置四线发送数据
    LCD1602WriteRegister(0x0c, LCD_CMD);  // 设置显示模式
    LCD1602WriteRegister(0x28, LCD_CMD);  // 显示关闭
    LCD1602WriteRegister(0x0c, LCD_CMD);  // 设置光标开关
    LCD1602WriteRegister(0x06, LCD_CMD);  // 设置光标移动
}

void LCD1602Write(uint8_t x, uint8_t y, uint8_t dat) {
    y &= 0x01;
    x &= 0x0f;
    if (y) {
        x |= 0x40;
    }
    x |= 0x80;

    LCD1602WriteRegister(x, LCD_CMD);
    LCD1602WriteRegister(dat, LCD_DATA);
}

void LCD1602Print(uint8_t x, uint8_t y, uint8_t* str) {
    while (*str) {
        LCD1602Write(x++, y, *str++);
    }
}
