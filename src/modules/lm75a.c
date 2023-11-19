#include "modules/lm75a.h"

void LM75AInit() {
    Wire_begin();
}

float LM75ARead() {
    Wire_beginTransmission(LM75A_ADDRESS);
    Wire_write(0x00);
    Wire_endTransmission();

    Wire_requestFrom(LM75A_ADDRESS, 2);
    uint8_t msb = Wire_read();
    uint8_t lsb = Wire_read();

    int16_t temp = ((msb << 8) | lsb) >> 5;
    return (float)temp * 0.125;
}
