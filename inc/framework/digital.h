#ifndef __FRAMEWORK_DIGITAL__H
#define __FRAMEWORK_DIGITAL__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <config.h>
#include <reg52.h>
#include <stdint.h>

#define PORTS 3  // 端口组数，值为组数 - 1

#define LSBFIRST 0  // 最低有效位优先
#define MSBFIRST 1  // 最高有效位优先

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
#define DEFINE_PORT_FUNC(port)                                            \
    static void PORT_X_WRITE_FUNC_NAME(port)(uint_least8_t pin,           \
                                             uint_least8_t level) {       \
        if (level) {                                                      \
            PORT_X_NAME(port) |= 1 << pin;                                \
        } else {                                                          \
            PORT_X_NAME(port) &= ~(1 << pin);                             \
        }                                                                 \
    }                                                                     \
    static uint_least8_t PORT_X_READ_FUNC_NAME(port)(uint_least8_t pin) { \
        return (PORT_X_NAME(port) >> pin) & 1;                            \
    }

void digitalWrite(uint_least8_t _pin, uint_least8_t level);
uint_least8_t digitalRead(uint_least8_t _pin);
uint_least8_t shiftIn(uint_least8_t dataPin,
                      uint_least8_t clockPin,
                      uint_least8_t bitOrder);
void shiftOut(uint_least8_t dataPin,
              uint_least8_t clockPin,
              uint_least8_t bitOrder,
              uint_least8_t val);

#endif
