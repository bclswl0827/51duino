#ifndef __51DUINO_CONFIG__H
#define __51DUINO_CONFIG__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <reg52.h>

// 设定晶振频率，以 Hz 为单位
#define CRYSTAL 11059200L
// 1 个时钟周期为 12 个机器周期
#define CYCLE (CRYSTAL / 12)

// 设定 PWM 管脚
#define PIN_PWM07 0  // P07
#define PIN_PWM17 1  // P17
#define PIN_PWM27 2  // P27
#define PIN_PWM37 3  // P37

// 设定软件 I2C
#define I2C_TIMEOUT 500  // 超时倍数
#define PIN_WIRE_SDA P21
#define PIN_WIRE_SCL P20
#define SDA PIN_WIRE_SDA
#define SCL PIN_WIRE_SCL

#define LOW 0           // 低电平
#define HIGH 1          // 高电平
#define INPUT 0         // 输入模式
#define OUTPUT 1        // 输出模式
#define INPUT_PULLUP 2  // 输入上拉模式

#endif