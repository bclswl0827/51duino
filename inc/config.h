#ifndef __51DUINO_CONFIG__H
#define __51DUINO_CONFIG__H

#include <reg52.h>
#include <stdint.h>

// 设定晶振频率，以 Hz 为单位
#define CRYSTAL 11059200L
// 1 个时钟周期为 12 个机器周期
#define CYCLE (CRYSTAL / 12)

// 第一组 port
const uint8_t PIN_P00[2] = {0, 0};
const uint8_t PIN_P01[2] = {0, 1};
const uint8_t PIN_P02[2] = {0, 2};
const uint8_t PIN_P03[2] = {0, 3};
const uint8_t PIN_P04[2] = {0, 4};
const uint8_t PIN_P05[2] = {0, 5};
const uint8_t PIN_P06[2] = {0, 6};
const uint8_t PIN_P07[2] = {0, 7};

// 第二组 port
const uint8_t PIN_P10[2] = {1, 0};
const uint8_t PIN_P11[2] = {1, 1};
const uint8_t PIN_P12[2] = {1, 2};
const uint8_t PIN_P13[2] = {1, 3};
const uint8_t PIN_P14[2] = {1, 4};
const uint8_t PIN_P15[2] = {1, 5};
const uint8_t PIN_P16[2] = {1, 6};
const uint8_t PIN_P17[2] = {1, 7};

// 第三组 port
const uint8_t PIN_P20[2] = {2, 0};
const uint8_t PIN_P21[2] = {2, 1};
const uint8_t PIN_P22[2] = {2, 2};
const uint8_t PIN_P23[2] = {2, 3};
const uint8_t PIN_P24[2] = {2, 4};
const uint8_t PIN_P25[2] = {2, 5};
const uint8_t PIN_P26[2] = {2, 6};
const uint8_t PIN_P27[2] = {2, 7};

// 第四组 port
const uint8_t PIN_P30[2] = {3, 0};
const uint8_t PIN_P31[2] = {3, 1};
const uint8_t PIN_P32[2] = {3, 2};
const uint8_t PIN_P33[2] = {3, 3};
const uint8_t PIN_P34[2] = {3, 4};
const uint8_t PIN_P35[2] = {3, 5};
const uint8_t PIN_P36[2] = {3, 6};
const uint8_t PIN_P37[2] = {3, 7};

#endif