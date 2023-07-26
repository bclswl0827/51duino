#ifndef __FRAMEWORK_ANALOG__H
#define __FRAMEWORK_ANALOG__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <reg52.h>
#include <stdint.h>

#include "config.h"

// 设定 PWM 管脚
#define PIN_PWM07 0  // P07
#define PIN_PWM17 1  // P17
#define PIN_PWM27 2  // P27
#define PIN_PWM37 3  // P37

// 设定延时 0.01 ms，即 10us
#define PERIOD (uint_least16_t)(CYCLE * 0.00001)
#define _TH0 (65536 - PERIOD) / 256
#define _TL0 (65536 - PERIOD) % 256

void pwmInit(void);
void analogWrite(uint8_t pin, uint8_t value);

#endif
