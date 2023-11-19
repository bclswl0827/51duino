#include "modules/pcf8591.h"

void PCF8591Init() {
    Wire_begin();
}

uint8_t PCF8591Read(enum PCF8591_CHANNEL channel) {
    Wire_beginTransmission(PCF8591_ADDRESS);
    Wire_write(0x40 | channel);
    Wire_endTransmission();

    Wire_requestFrom(PCF8591_ADDRESS, 1);
    return Wire_read();
}

float PCF8591ToVoltage() {
    return PCF8591_VREF / 255.0;
}
