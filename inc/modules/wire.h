#ifndef __MODULE_WIRE__H
#define __MODULE_WIRE__H

#include <delay.h>
#include <digi.h>
#include <reg52.h>
#include <stdint.h>

#define SCL P10  // SCL 时钟线
#define SDA P11  // SDA 数据线

#define TIMEOUT 100  // 超时时间

// 产生 I2C 起始信号
void WireBegin(void);

#endif