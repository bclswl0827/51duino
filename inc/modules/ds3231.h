#ifndef __MODULE_RTC_DS3231_H
#define __MODULE_RTC_DS3231_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>
#include "framework/wire.h"

#define DS3231_ADDRESS 0x68

typedef struct {
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t week;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} time_t;

void DS3231Init(void);
void DS3231GetTime(time_t* time);
void DS3231SetTime(time_t* time);

#endif
