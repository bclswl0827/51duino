#ifndef __MODULE_MILLIS__H
#define __MODULE_MILLIS__H

#include <millis.c>

// 初始化定时器 T0
void millisInit();
// 返回运行时长
uint32_t millis();

#endif