#include "modules/pcf8591.h"

void PCF8591Init() {
    Wire_begin();
}

uint8_t PCF8591Read(enum PCF8591_CHANNEL channel) {
    Wire_beginTransmission(PCF8591_ADDRESS);
    Wire_write(0x40 | channel);
    Wire_requestFrom(PCF8591_ADDRESS, 1);
    uint8_t val = Wire_read();

    Wire_endTransmission();
    return val;
}

float PCF8591ToVoltage() {
    return PCF8591_VREF / 255.0;
}
