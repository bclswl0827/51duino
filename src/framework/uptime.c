#include <uptime.h>

// 记录运行时长
uint32_t _uptime = 0;

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
    _uptime++;
}

// 返回运行时长
uint32_t millis() {
    return _uptime / 10;
}