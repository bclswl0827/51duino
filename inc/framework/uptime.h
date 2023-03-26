#ifndef __FRAMEWORK_UPTIME__H
#define __FRAMEWORK_UPTIME__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <config.h>
#include <reg52.h>
#include <stdint.h>

// 设定延时 0.1ms
#define PERIOD (uint16_t)(CYCLE * 0.0001)

void millisInit();
uint32_t millis();

#endif