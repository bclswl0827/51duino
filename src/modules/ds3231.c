#include "modules/ds3231.h"

// BCD 转整数
uint8_t DS3231BcdToDec(uint8_t bcd) {
    return (bcd / 16 * 10) + (bcd % 16);
}

// 整数转 BCD
uint8_t DS3231DecToBcd(uint8_t dec) {
    return (dec / 10 * 16) + (dec % 10);
}

void DS3231Init() {
    Wire_begin();
}

// 取得时间
void DS3231GetTime(time_t* time) {
    Wire_beginTransmission(DS3231_ADDRESS);
    Wire_write(0x00);
    Wire_requestFrom(DS3231_ADDRESS, 7);
    time->second = DS3231BcdToDec(Wire_read() & 0x7F);
    time->minute = DS3231BcdToDec(Wire_read());
    time->hour = DS3231BcdToDec(Wire_read());
    time->week = DS3231BcdToDec(Wire_read());
    time->day = DS3231BcdToDec(Wire_read());
    time->month = DS3231BcdToDec(Wire_read());
    time->year = DS3231BcdToDec(Wire_read());

    Wire_endTransmission();
}

// 设定时间
void DS3231SetTime(time_t* time) {
    Wire_beginTransmission(DS3231_ADDRESS);
    Wire_write(0x00);

    Wire_write(DS3231DecToBcd(time->second));
    Wire_write(DS3231DecToBcd(time->minute));
    Wire_write(DS3231DecToBcd(time->hour));
    Wire_write(DS3231DecToBcd(time->week));
    Wire_write(DS3231DecToBcd(time->day));
    Wire_write(DS3231DecToBcd(time->month));
    Wire_write(DS3231DecToBcd(time->year));

    Wire_endTransmission();
}
