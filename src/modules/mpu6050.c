#include "modules/mpu6050.h"

void MPU6050Init() {
    Wire_begin();
    Wire_beginTransmission(MPU6050_ADDRESS);
    Wire_write(0x6B);
    Wire_write(0x00);
    Wire_endTransmission();
}

void MPU6050Read(motion_t* motion) {
    Wire_beginTransmission(MPU6050_ADDRESS);
    Wire_write(0x3B);
    Wire_requestFrom(MPU6050_ADDRESS, 14);
    motion->accX = Wire_read() << 8 | Wire_read();
    motion->accY = Wire_read() << 8 | Wire_read();
    motion->accZ = Wire_read() << 8 | Wire_read();
    motion->temp = Wire_read() << 8 | Wire_read();
    motion->gyroX = Wire_read() << 8 | Wire_read();
    motion->gyroY = Wire_read() << 8 | Wire_read();
    motion->gyroZ = Wire_read() << 8 | Wire_read();

    Wire_endTransmission();
}

float MPU6050GetAcc(int16_t dat) {
    return dat / 16384.0;
}

float MPU6050GetGyro(int16_t dat) {
    return dat / 131.0;
}

float MPU6050GetTemp(int16_t dat) {
    return (dat / 340.0) + 36.53;
}
