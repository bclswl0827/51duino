#include <lcd.h>

// LCD 屏幕地址
#define LCD_ADDRESS 0x27
// LCD 屏幕列数
#define LCD_COLUMN 15
// 写命令
#define LCD_CMD 0
// 写数据
#define LCD_DATA 1

// 向 LCD 显示屏写入一个字节
void LcdWriteByte(uint_least8_t dat, uint_least8_t type) {
    uint_least8_t high = dat & 0xf0,  // 取高四位
        low = (dat & 0x0f) << 4;      // 取低四位
    // 传输到指定从机
    WireBeginTransmission(LCD_ADDRESS);
    // 按位发送寄存器地址
    switch (type) {
        // 命令模式
        case LCD_CMD:
            WireWrite(0x00 + high);
            WireWrite(0x04 + high);
            WireWrite(0x00 + high);
            WireWrite(0x00 + low);
            WireWrite(0x04 + low);
            WireWrite(0x00 + low);
            break;
        // 数据模式
        case LCD_DATA:
            WireWrite(0x01 + high);
            WireWrite(0x05 + high);
            WireWrite(0x01 + high);
            WireWrite(0x01 + low);
            WireWrite(0x05 + low);
            WireWrite(0x01 + low);
            break;
    }
    // 结束传输
    WireEndTransmission();
}

// LCD 内容清零
void LcdClear() {
    LcdWriteByte(0x01, LCD_CMD);
}

// 初始化 LCD 模块
void LcdInit() {
    LcdWriteByte(0x02, LCD_CMD);  // 设置四线发送数据
    LcdWriteByte(0x0c, LCD_CMD);  // 设置显示模式
    LcdWriteByte(0x28, LCD_CMD);  // 显示关闭
    LcdWriteByte(0x0c, LCD_CMD);  // 设置光标开关
    LcdWriteByte(0x06, LCD_CMD);  // 设置光标移动
    LcdClear();
}

// LCD 显示单个字符
void LcdChar(uint_least8_t x, uint_least8_t y, uint_least8_t dat) {
    y &= 0x01;
    x &= 0x0f;
    if (y) {
        x |= 0x40;
    }
    x |= 0x80;
    LcdWriteByte(x, LCD_CMD);
    LcdWriteByte(dat, LCD_DATA);
}

// LCD 显示字符串
void LcdString(uint_least8_t x, uint_least8_t y, uint_least8_t* str) {
    while (*str) {
        LcdChar(x, y, *str++);
        x += 1;
    }
}
