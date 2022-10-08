#ifndef __51DUINO_ENRTY__H
#define __51DUINO_ENRTY__H

#include <reg52.h>

#include <config.h>
#include <delay.h>
#include <digi.h>
#include <millis.h>
#include <ttl.h>

// 初始化程序
void setup(void);

// 循环程序
void loop(void);

// 主程序
void main() {
    // 启动计时器计时
    millisInit();
    // 设置所有管脚低电平
    P0 = P1 = P2 = P3 = LOW;
    // RX、TX 灯对应 P30、P31
    P30 = P31 = HIGH;
    // 执行初始化
    setup();
    // 循环执行 loop
    while (1) {
        loop();
    }
}

#endif