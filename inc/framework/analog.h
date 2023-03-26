#ifndef __FRAMEWORK_ANALOG__H
#define __FRAMEWORK_ANALOG__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <config.h>
#include <reg52.h>
#include <stdint.h>

// 设定延时 0.01 ms，即 10us
#define PERIOD (uint_least16_t)(CYCLE * 0.00001)
#define _TH0 (65536 - PERIOD) / 256
#define _TL0 (65536 - PERIOD) % 256

void pwmInit();
void analogWrite(uint_least8_t pin, uint_least8_t value);

#endif
