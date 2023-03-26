#ifndef __COMPONENT_RTC_H
#define __COMPONENT_RTC_H 1

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>
#include <wire.h>

// 时间数据结构
typedef struct TimeData {
    uint_least8_t year;
    uint_least8_t month;
    uint_least8_t day;
    uint_least8_t week;
    uint_least8_t hour;
    uint_least8_t minute;
    uint_least8_t second;
} TimeData;

uint_least8_t bcdToDec(uint_least8_t bcd);
uint_least8_t decToBcd(uint_least8_t dec);
uint_least8_t getNum(uint_least8_t ch);
uint_least8_t getSum(uint_least8_t part_1, uint_least8_t part_2);
void getTime(TimeData* time);
void setTime(uint_least8_t year,
             uint_least8_t month,
             uint_least8_t day,
             uint_least8_t hour,
             uint_least8_t minute,
             uint_least8_t second,
             uint_least8_t week);

#endif