#ifndef __MODULE_MAGNETOMETER_AK09911_H
#define __MODULE_MAGNETOMETER_AK09911_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

#include "framework/wire.h"

#define AK09911_ADDRESS 0x0D
#define AK09911_REG_WIA1 0x00
#define AK09911_REG_WIA2 0x01
#define AK09911_REG_INFO1 0x02
#define AK09911_REG_INFO2 0x03
#define AK09911_REG_ST1 0x10
#define AK09911_REG_HXL 0x11
#define AK09911_REG_HXH 0x12
#define AK09911_REG_HYL 0x13
#define AK09911_REG_HYH 0x14
#define AK09911_REG_HZL 0x15
#define AK09911_REG_HZH 0x16
#define AK09911_REG_TMPS 0x17
#define AK09911_REG_ST2 0x18
#define AK09911_REG_CNTL1 0x30
#define AK09911_REG_CNTL2 0x31
#define AK09911_REG_CNTL3 0x32
#define AK09911_REG_TS1 0x33
#define AK09911_REG_ASAX 0x60
#define AK09911_REG_ASAY 0x61
#define AK09911_REG_ASAZ 0x62

#define AK09911_MODE_POWER_DOWN 0
#define AK09911_MODE_SINGLE 1
#define AK09911_MODE_CONT_10HZ 2
#define AK09911_MODE_CONT_20HZ 4
#define AK09911_MODE_CONT_50HZ 6
#define AK09911_MODE_CONT_100HZ 8
#define AK09911_MODE_SELF_TEST 16
#define AK09911_MODE_FUSE_ROM 31

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
    int8_t coef[3];
} magnetometer_t;

void AK09911Init(void);
void AK09911PowerDown(void);
void AK09911Start(uint8_t mode);
void AK09911Reset(void);
void AK09911ReadROM(magnetometer_t* magnetometer);
void AK09911ReadCompass(magnetometer_t* magnetometer);

#endif
