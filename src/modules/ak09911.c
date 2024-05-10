#include "modules/ak09911.h"

void AK09911WriteRegister(uint8_t reg, uint16_t value) {
    Wire_beginTransmission(AK09911_ADDRESS);
    Wire_write(reg);
    Wire_write(value);
    Wire_endTransmission();
}

uint8_t AK09911ReadRegister(uint8_t reg) {
    Wire_beginTransmission(AK09911_ADDRESS);
    Wire_write(reg);
    uint8_t val = Wire_read();

    Wire_endTransmission();
    return val;
}

uint8_t AK09911IsDataReady() {
    uint8_t dat = AK09911ReadRegister(AK09911_REG_ST1);
    AK09911ReadRegister(AK09911_REG_ST2);
    return (dat & 0x01) != 0;
}

void AK09911Init() {
    Wire_begin();
    AK09911Reset();
}

void AK09911PowerDown() {
    AK09911WriteRegister(AK09911_REG_CNTL2, 0x00);
}

void AK09911Start(uint8_t mode) {
    AK09911PowerDown();
    AK09911WriteRegister(AK09911_REG_CNTL2, mode);
}

void AK09911Reset() {
    AK09911WriteRegister(AK09911_REG_CNTL3, 0x01);
}

void AK09911ReadROM(magnetometer_t* magnetometer) {
    AK09911Start(AK09911_MODE_FUSE_ROM);
    Wire_beginTransmission(AK09911_ADDRESS);
    Wire_write(AK09911_REG_ASAX);
    Wire_requestFrom(AK09911_ADDRESS, 3);
    magnetometer->coef[0] = Wire_read();
    magnetometer->coef[1] = Wire_read();
    magnetometer->coef[2] = Wire_read();
    Wire_endTransmission();

    AK09911ReadRegister(AK09911_REG_ST2);
}

void AK09911ReadCompass(magnetometer_t* magnetometer) {
    while (!AK09911IsDataReady()) {
        ;
    }

    Wire_beginTransmission(AK09911_ADDRESS);
    Wire_write(AK09911_REG_HXL);
    Wire_requestFrom(AK09911_ADDRESS, 6);
    magnetometer->x = Wire_read() | (Wire_read() << 8);
    magnetometer->y = Wire_read() | (Wire_read() << 8);
    magnetometer->z = Wire_read() | (Wire_read() << 8);
    Wire_endTransmission();

    AK09911ReadRegister(AK09911_REG_ST2);
}
