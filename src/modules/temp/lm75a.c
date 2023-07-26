#include "modules/temp/lm75a.h"

void LM75AInit() {
    WireBegin();
}

float LM75ARead() {
    WireBeginTransmission(LM75A_ADDRESS);
    WireWrite(0x00);
    WireEndTransmission();

    WireRequestFrom(LM75A_ADDRESS, 2);
    uint8_t msb = WireRead();
    uint8_t lsb = WireRead();

    int16_t temp = ((msb << 8) | lsb) >> 5;
    return (float)temp * 0.125;
}
