#include "modules/rtc/ds3231.h"

// BCD 转整数
uint8_t DS3231BcdToDec(uint8_t bcd) {
    return (bcd / 16 * 10) + (bcd % 16);
}

// 整数转 BCD
uint8_t DS3231DecToBcd(uint8_t dec) {
    return (dec / 10 * 16) + (dec % 10);
}

void DS3231Init() {
    WireBegin();
}

// 取得时间
void DS3231GetTime(time_t* time) {
    WireBeginTransmission(DS3231_ADDRESS);
    WireWrite(0x00);
    WireEndTransmission();
    WireRequestFrom(DS3231_ADDRESS, 7);

    time->second = DS3231BcdToDec(WireRead() & 0x7F);
    time->minute = DS3231BcdToDec(WireRead());
    time->hour = DS3231BcdToDec(WireRead());
    time->week = DS3231BcdToDec(WireRead());
    time->day = DS3231BcdToDec(WireRead());
    time->month = DS3231BcdToDec(WireRead());
    time->year = DS3231BcdToDec(WireRead());
}

// 设定时间
void DS3231SetTime(time_t* time) {
    WireBeginTransmission(DS3231_ADDRESS);
    WireWrite(0x00);

    WireWrite(DS3231DecToBcd(time->second));
    WireWrite(DS3231DecToBcd(time->minute));
    WireWrite(DS3231DecToBcd(time->hour));
    WireWrite(DS3231DecToBcd(time->week));
    WireWrite(DS3231DecToBcd(time->day));
    WireWrite(DS3231DecToBcd(time->month));
    WireWrite(DS3231DecToBcd(time->year));

    WireEndTransmission();
}
