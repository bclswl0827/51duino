#include "modules/adc/pcf8591.h"

void PCF8591Init() {
    WireBegin();
}

uint8_t PCF8591Read(enum PCF8591_CHANNEL channel) {
    WireBeginTransmission(PCF8591_ADDRESS);
    WireWrite(0x40 | channel);
    WireEndTransmission();

    WireRequestFrom(PCF8591_ADDRESS, 1);
    return WireRead();
}

float PCF8591ToVoltage() {
    return PCF8591_VREF / 255.0;
}
