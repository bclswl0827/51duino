#include <rtc.h>

// BCD 转整数
uint_least8_t bcdToDec(uint_least8_t bcd) {
    return (bcd / 16 * 10) + (bcd % 16);
}

// 整数转 BCD
uint_least8_t decToBcd(uint_least8_t dec) {
    return (dec / 10 * 16) + (dec % 10);
}

// 将字符转为数字
uint_least8_t getNum(uint_least8_t ch) {
    return ch < 58 ? ch - '0' : 0;
}

// 获取两字符之和
uint_least8_t getSum(uint_least8_t part_1, uint_least8_t part_2) {
    return (part_1 - '0' < 58 && part_2 - '0' < 58)
               ? 10 * (part_1 - '0') + (part_2 - '0')
               : 0;
}

// 取得时间
void getTime(TimeData* time) {
    // 发送从机地址
    WireBeginTransmission(0x68);
    // 发送寄存器地址
    WireWrite(0x00);
    // 读取数据并转换
    time->second = bcdToDec(WireRead());
    time->minute = bcdToDec(WireRead());
    time->hour = bcdToDec(WireRead());
    time->week = bcdToDec(WireRead());
    time->day = bcdToDec(WireRead());
    time->month = bcdToDec(WireRead());
    time->year = bcdToDec(WireRead());
    // 结束 I2C 通信
    WireEndTransmission();
}

// 设定时间
void setTime(uint_least8_t year,
             uint_least8_t month,
             uint_least8_t day,
             uint_least8_t hour,
             uint_least8_t minute,
             uint_least8_t second,
             uint_least8_t week) {
    // 发送从机地址
    WireBeginTransmission(0x68);
    // 发送寄存器地址
    WireWrite(0x00);
    // 发送数据
    WireWrite(decToBcd(second));
    WireWrite(decToBcd(minute));
    WireWrite(decToBcd(hour));
    WireWrite(decToBcd(week));
    WireWrite(decToBcd(day));
    WireWrite(decToBcd(month));
    WireWrite(decToBcd(year));
    // 结束 I2C 通信
    WireEndTransmission();
}
