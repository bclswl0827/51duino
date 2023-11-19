#include "modules/si5351.h"

float _floor(float x) {
    if (x >= 0) {
        return (int)x;
    } else {
        return (int)x - 1;
    }
}

// 向 SI5351 写入一个字节
void SI5351WriteRegister(uint8_t reg, uint8_t value) {
    // 传输到指定从机
    Wire_beginTransmission(SI5351_ADDRESS);
    Wire_write(reg);
    Wire_write(value & 0xff);
    Wire_endTransmission();
}

// 启动 SI5351
void SI5351Init() {
    Wire_begin();

    // 复位 SI5351
    SI5351WriteRegister(3, 0xFF);
    // 关闭所有输出驱动
    SI5351WriteRegister(16, 0x80);
    SI5351WriteRegister(17, 0x80);
    SI5351WriteRegister(18, 0x80);
    SI5351WriteRegister(19, 0x80);
    SI5351WriteRegister(20, 0x80);
    SI5351WriteRegister(21, 0x80);
    SI5351WriteRegister(22, 0x80);
    SI5351WriteRegister(23, 0x80);

    // 设定晶振起振电容值
    SI5351WriteRegister(183, SI5351_CRYSTAL_10PF);
}

// 启用或禁用所有时钟输出
void SI5351EnableOutputs(uint8_t enable) {
    // enable 为 0 时对应 false，关闭 CLK* 输出
    SI5351WriteRegister(3, enable ? 0x00 : 0xFF);
}

// 设置指定 PLL 的乘数
void SI5351SetupPLL(
    uint8_t pll,    // PLL 源编号，可选 0、1
    uint8_t mult,   // PLL 整数乘法器，范围 15 - 90
    uint32_t num,   // 小数输出的 20 位分子（0x00000 - 0xfffff）
                    // 将此设置为 0 以进行整数输出
    uint32_t denom  // 小数输出的 20 位分母 （0x00001 - 0xfffff）
                    // 将此设置为 1 或更高，避免除以零错误
) {
    // 对参数做校验
    if ((mult < 15 || mult > 90) || (denom < 1 || denom > 0xfffff) ||
        num > 0xfffff) {
        return;
    }
    // 声明 3 个变量用于对 PLL 寄存器配置做计算
    uint32_t P1 = 0,  // PLL 寄存器配置 P1
        P2 = 0,       // PLL 寄存器配置 P2
        P3 = 0;       // PLL 寄存器配置 P3
    // num 在分别在整数模式和小数模式的值
    if (!num) {
        P1 = 128 * mult - 512;
        P2 = num;
        P3 = denom;
    } else {
        P1 = (uint32_t)(128 * mult + _floor(128 * ((float)num / (float)denom)) -
                        512);
        P2 = (uint32_t)(128 * num -
                        denom * _floor(128 * ((float)num / (float)denom)));
        P3 = denom;
    }
    // 对指定 PLL 指定寄存器并写入数据
    uint8_t baseaddr = pll ? 34 : 26;  // A：26、B：34

    SI5351WriteRegister(baseaddr, (P3 & 0x0000FF00) >> 8);
    SI5351WriteRegister(baseaddr + 1, (P3 & 0x000000FF));
    SI5351WriteRegister(baseaddr + 2, (P1 & 0x00030000) >> 16);
    SI5351WriteRegister(baseaddr + 3, (P1 & 0x0000FF00) >> 8);
    SI5351WriteRegister(baseaddr + 4, (P1 & 0x000000FF));
    SI5351WriteRegister(baseaddr + 5,
                        ((P3 & 0x000F0000) >> 12) | ((P2 & 0x000F0000) >> 16));
    SI5351WriteRegister(baseaddr + 6, (P2 & 0x0000FF00) >> 8);
    SI5351WriteRegister(baseaddr + 7, (P2 & 0x000000FF));

    // 对两个 PLL 复位
    SI5351WriteRegister(177, 0xA0);
}

// 对指定输出口配置分频参数
void SI5351SetupRdiv(uint8_t output,  // 输出口，可选 0、1、2
                     uint8_t div      // 分频值，n = 1...7
) {
    // 对指定输出口指定寄存器
    uint8_t reg = 0;
    switch (output) {
        case 0:
            reg = 44;
            break;
        case 1:
            reg = 52;
            break;
        case 2:
            reg = 60;
            break;
    }

    // 设定分频值
    div &= 0x07;
    div <<= 4;
    SI5351WriteRegister(reg, div);
}

// 设定分频器
void SI5351SetupMultiSynth(
    uint8_t output,  // 输出口，可选 0、1、2
    uint8_t pll,     // PLL 源编号，可选 0、1
    uint32_t div,  // 分频后输出整数除法器、可选 4、6 或范围 8 - 900
    uint32_t num,   // 小数输出的 20 位分子（0x00000 - 0xfffff）
                    // 将此设置为 0 以进行整数输出
    uint32_t denom  // 小数输出的 20 位分母 （0x00001 - 0xfffff）
                    // 将此设置为 1 或更高，避免除以零错误
) {
    // 对参数做校验
    if ((div < 4 || div > 900) || (denom < 1 || denom > 0xfffff) ||
        num > 0xfffff) {
        return;
    }
    // 声明 3 个变量用于对 PLL 寄存器配置做计算
    uint32_t P1 = 0,  // PLL 寄存器配置 P1
        P2 = 0,       // PLL 寄存器配置 P2
        P3 = 0;       // PLL 寄存器配置 P3
    // num 在分别在整数模式和小数模式的值
    if (!num) {
        P1 = 128 * div - 512;
        P2 = num;
        P3 = denom;
    } else {
        P1 = (uint32_t)(128 * div + _floor(128 * ((float)num / (float)denom)) -
                        512);
        P2 = (uint32_t)(128 * num -
                        denom * _floor(128 * ((float)num / (float)denom)));
        P3 = denom;
    }

    // 根据输出口对指定 PLL 指定寄存器并写入数据
    uint8_t baseaddr = 0;
    switch (output) {
        case 0:
            baseaddr = 42;
            break;
        case 1:
            baseaddr = 50;
            break;
        case 2:
            baseaddr = 58;
            break;
    }
    SI5351WriteRegister(baseaddr, (P3 & 0x0000FF00) >> 8);
    SI5351WriteRegister(baseaddr + 1, (P3 & 0x000000FF));
    SI5351WriteRegister(baseaddr + 2, (P1 & 0x00030000) >> 16);
    SI5351WriteRegister(baseaddr + 3, (P1 & 0x0000FF00) >> 8);
    SI5351WriteRegister(baseaddr + 4, (P1 & 0x000000FF));
    SI5351WriteRegister(baseaddr + 5,
                        ((P3 & 0x000F0000) >> 12) | ((P2 & 0x000F0000) >> 16));
    SI5351WriteRegister(baseaddr + 6, (P2 & 0x0000FF00) >> 8);
    SI5351WriteRegister(baseaddr + 7, (P2 & 0x000000FF));
    // 8mA 驱动强度，时钟未反转，上电
    uint8_t clock = 0x0f;
    // 若 PLL 源为 1，则输出口为 0x2F
    if (pll) {
        clock = 0x2f;
    }
    // 若为整数模式
    if (!num) {
        clock |= (1 << 6);
    }
    // 启动指定输出口
    switch (output) {
        case 0:
            SI5351WriteRegister(16, clock);
            break;
        case 1:
            SI5351WriteRegister(17, clock);
            break;
        case 2:
            SI5351WriteRegister(18, clock);
            break;
    }
}

// 设定接收频率
void SI5351SetRxFreq(uint32_t freq) {
    uint32_t div, num;
    uint8_t rdiv;
    if (freq) {
        freq = freq * 4 - 48;
        if (freq < 1000) {
            rdiv = 16;
            freq *= 16;
        } else {
            rdiv = 1;
        }
        div = 900000 / freq;
        num = 900000000 / freq - (div * 1000);

        SI5351SetupMultiSynth(1, 0, div, num, 1000);

        if (rdiv == 16) {
            SI5351SetupRdiv(1, 4);
        }

        if (rdiv == 1) {
            SI5351SetupRdiv(1, 0);
        }
    }
}
