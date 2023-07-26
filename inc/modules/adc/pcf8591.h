#ifndef __MODULE_ADC_PCF8591_H
#define __MODULE_ADC_PCF8591_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

#include "framework/wire.h"

#define PCF8591_VREF 5.0
#define PCF8591_ADDRESS 0x48

enum PCF8591_CHANNEL {
    PCF8591_CHANNEL_0 = 0x01,
    PCF8591_CHANNEL_1 = 0x02,
    PCF8591_CHANNEL_2 = 0x03,
    PCF8591_CHANNEL_3 = 0x00,
};

void PCF8591Init(void);
uint8_t PCF8591Read(enum PCF8591_CHANNEL channel);
float PCF8591ToVoltage(void);

#endif
