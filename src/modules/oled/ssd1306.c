#include "modules/oled/ssd1306.h"

void SSD1306WriteRegister(uint8_t dat, uint8_t type) {
    WireBeginTransmission(OLED_ADDRESS);
    switch (type) {
        case OLED_DATA:
            WireWrite(0x40);
            break;
        case OLED_CMD:
            WireWrite(0x00);
            break;
    }
    WireWrite(dat);
    WireEndTransmission();
}

void SSD1306SetPosition(uint8_t x, uint8_t y) {
    SSD1306WriteRegister(0xb0 + y, OLED_CMD);
    SSD1306WriteRegister(((x & 0xf0) >> 4) | 0x10, OLED_CMD);
    SSD1306WriteRegister((x & 0x0f), OLED_CMD);
}

// 屏幕初始化
void SSD1306Init() {
    WireBegin();
    // 设置显示关
    SSD1306WriteRegister(0xAE, OLED_CMD);
    // 设置低列地址
    SSD1306WriteRegister(0x00, OLED_CMD);
    // 设置高列地址
    SSD1306WriteRegister(0x10, OLED_CMD);
    // 设置显示开始行（0x40 - 0x7F）
    SSD1306WriteRegister(0x40, OLED_CMD);
    // 设定页地址
    SSD1306WriteRegister(0xB0, OLED_CMD);
    // 对比度控制
    SSD1306WriteRegister(0x81, OLED_CMD);
    SSD1306WriteRegister(0xFF, OLED_CMD);
    // 设置 Segment 重映射
    SSD1306WriteRegister(0xA1, OLED_CMD);
    // 正常 / 反转
    SSD1306WriteRegister(0xA6, OLED_CMD);
    // 设置复用率为 1/64
    SSD1306WriteRegister(0xA8, OLED_CMD);
    SSD1306WriteRegister(0x3F, OLED_CMD);
    // 设置 COM 输出扫描方向
    SSD1306WriteRegister(0xC8, OLED_CMD);
    // 设定显示偏移
    SSD1306WriteRegister(0xD3, OLED_CMD);
    SSD1306WriteRegister(0x00, OLED_CMD);
    // 设置显示时钟分频率、振荡器频率
    SSD1306WriteRegister(0xD5, OLED_CMD);
    SSD1306WriteRegister(0x80, OLED_CMD);
    // 关闭区域颜色模式
    SSD1306WriteRegister(0xD8, OLED_CMD);
    SSD1306WriteRegister(0x05, OLED_CMD);
    // 设置预充电周期
    SSD1306WriteRegister(0xD9, OLED_CMD);
    SSD1306WriteRegister(0xF1, OLED_CMD);
    // 设置 COM 引脚硬件配置
    SSD1306WriteRegister(0xDA, OLED_CMD);
    SSD1306WriteRegister(0x12, OLED_CMD);
    // 设定 Vcomh
    SSD1306WriteRegister(0xDB, OLED_CMD);
    SSD1306WriteRegister(0x30, OLED_CMD);
    // 升压允许
    SSD1306WriteRegister(0x8D, OLED_CMD);
    SSD1306WriteRegister(0x14, OLED_CMD);
    // 设置显示开
    SSD1306WriteRegister(0xAF, OLED_CMD);
}

// 开启 OLED 屏幕显示
void SSD1306Enable() {
    SSD1306WriteRegister(0x8D, OLED_CMD);
    SSD1306WriteRegister(0x14, OLED_CMD);
    // 打开显示
    SSD1306WriteRegister(0xAF, OLED_CMD);
}

// 关闭 OLED 屏幕显示
void SSD1306Disable() {
    SSD1306WriteRegister(0x8D, OLED_CMD);
    SSD1306WriteRegister(0x10, OLED_CMD);
    // 关闭显示
    SSD1306WriteRegister(0xAE, OLED_CMD);
}

// 清理屏幕
void SSD1306Clear() {
    for (uint8_t i = 0; i < 8; i++) {
        // 设置页地址（0 到 7）
        SSD1306WriteRegister(0xb0 + i, OLED_CMD);
        // 设置列低地址
        SSD1306WriteRegister(0x01, OLED_CMD);
        // 设置列高地址
        SSD1306WriteRegister(0x10, OLED_CMD);
        // 执行清零
        for (uint8_t j = 0; j < OLED_COLUMN; j++) {
            SSD1306WriteRegister(0x00, OLED_DATA);
        }
    }
}

// 显示单个字符
void SSD1306Write(uint8_t x, uint8_t y, uint8_t c) {
    // 得到偏移后的值
    uint8_t offset = c - ' ';
    // 设置显示位置
    SSD1306SetPosition(x, y);
    // 依次点亮对应点阵
    for (uint8_t i = 0; i < 6; i++) {
        SSD1306WriteRegister(F8X6[offset][i], OLED_DATA);
    }
}

// 打印一个字符串
void SSD1306Print(uint8_t x, uint8_t y, uint8_t* buf) {
    // 遍历字符串，直到遇到 '\0'
    for (uint8_t i = 0; buf[i] != '\0'; i++) {
        SSD1306Write(x, y, buf[i]);
        // 增加字符间隔
        x += 6;
        // 自动换行
        if (x > OLED_COLUMN - 8) {
            // x 轴归零
            x = 0;
            // y 轴往下提行
            y += 1;
        }
    }
}

void SSD1306Chinese(uint8_t offset,  // 从左往右偏移量
                    uint8_t y,       // y 轴坐标
                    uint8_t gap      // 文字间距
) {
    // 若文字间距小于 14 则按照 14 对待
    if (gap < 14) {
        gap = 14;
    }
    // 循环次数取决于 chinese 数组长度
    for (uint16_t x, i = 0; i < sizeof(chinese) / sizeof(chinese[0]) / 2; i++) {
        // 计算从左到右偏移量
        x = offset + gap * i;
        // 中文字上半部分
        SSD1306SetPosition(x, y);
        for (uint8_t j = 0; j < gap; j++) {
            SSD1306WriteRegister(chinese[2 * i][j], OLED_DATA);
        }
        // 中文字下半部分
        SSD1306SetPosition(x, y + 1);
        for (uint8_t j = 0; j < gap; j++) {
            SSD1306WriteRegister(chinese[2 * i + 1][j], OLED_DATA);
        }
    }
}
