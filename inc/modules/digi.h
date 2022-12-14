#ifndef __MODULE_DIGI_H
#define __MODULE_DIGI_H

#include <reg52.h>
#include <stdint.h>

#define PORTS 3  // 端口组数，值为组数 - 1

#define LOW 0           // 低电平
#define HIGH 1          // 高电平
#define INPUT 0         // 输入模式
#define OUTPUT 1        // 输出模式
#define INPUT_PULLUP 2  // 输入上拉模式

#define LSBFIRST 0  // 最高有效位优先
#define MSBFIRST 1  // 最低有效位优先

// 透过 Macro 批量生成代码，参考
// https://zhou-yuxin.github.io/articles/2016/用C语言宏批量生成代码的思考与实现/index.html
#define MACRO_LOOP_0 MACRO_LOOP_CMD(0)
#define MACRO_LOOP_1 MACRO_LOOP_0 MACRO_LOOP_CMD(1)
#define MACRO_LOOP_2 MACRO_LOOP_1 MACRO_LOOP_CMD(2)
#define MACRO_LOOP_3 MACRO_LOOP_2 MACRO_LOOP_CMD(3)
#define MACRO_LOOP_4 MACRO_LOOP_3 MACRO_LOOP_CMD(4)
#define MACRO_LOOP_HELPER(n) MACRO_LOOP_##n
#define MACRO_LOOP(n) MACRO_LOOP_HELPER(n)

// 规范 port 名称
#define PORT_X_NAME(port) P##port
// 规范 port 和 write 函数名称
#define PORT_X_WRITE_FUNC_NAME(port) PORT_X_NAME(port)##_write
// 规范 port 和 read 函数名称
#define PORT_X_READ_FUNC_NAME(port) PORT_X_NAME(port)##_read
// 为每一个 port 定义对应函数
#define DEFINE_PORT_FUNC(port)                                             \
    static void PORT_X_WRITE_FUNC_NAME(port)(uint8_t pin, uint8_t level) { \
        if (level) {                                                       \
            PORT_X_NAME(port) |= 1 << pin;                                 \
        } else {                                                           \
            PORT_X_NAME(port) &= ~(1 << pin);                              \
        }                                                                  \
    }                                                                      \
    static uint8_t PORT_X_READ_FUNC_NAME(port)(uint8_t pin) {              \
        return (PORT_X_NAME(port) >> pin) & 1;                             \
    }

// 设置管脚模式
void pinMode(void);
// 设置管脚电平
void digitalWrite(uint8_t* pin, uint8_t level);
// 读取管脚电平
uint8_t digitalRead(uint8_t* pin);
// 一次一位移入一个字节数据
uint8_t shiftIn(uint8_t* dataPin, uint8_t* clockPin, uint8_t bitOrder);
// 一次移出一个字节数据
void shiftOut(uint8_t* dataPin,
              uint8_t* clockPin,
              uint8_t bitOrder,
              uint8_t val);

#endif
