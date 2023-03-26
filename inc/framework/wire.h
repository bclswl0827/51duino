#ifndef __FRAMEWORK_WIRE__H
#define __FRAMEWORK_WIRE__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <config.h>
#include <stdint.h>

// 初始化 I2C 总线
void WireBegin();
void WireBeginTransmission(uint_least8_t addr);
uint_least8_t WireEndTransmission();
uint_least8_t WireRead();
void WireWrite(uint_least8_t dat);

#endif