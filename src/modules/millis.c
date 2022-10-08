#include <config.h>
#include <reg52.h>
#include <stdint.h>

// 设定延时 1ms
#define PERIOD (uint16_t)(CYCLE * 0.001)

// 记录运行时长
uint32_t uptime = 0;

// 初始化定时器 T0
void millisInit() {
    // 设置定时器 T0 为工作模式 1
    TMOD = 0x01;
    // 除以 256 得到二进制高八位
    TH0 = (65536 - PERIOD) / 256;
    // 模除 256 得到二进制低八位
    TL0 = (65536 - PERIOD) % 256;
    EA = ET0 = TR0 = 1;
}

// 定时器 T0 中断
void millisInterrupt() interrupt 1 {
    // 除以 256 得到二进制高八位
    TH0 = (65536 - PERIOD) / 256;
    // 模除 256 得到二进制低八位
    TL0 = (65536 - PERIOD) % 256;
    // 每 1ms 自增一次
    uptime++;
}

// 返回运行时长
uint32_t millis() {
    return uptime;
}