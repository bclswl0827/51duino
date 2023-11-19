#ifndef __MODULE_MPU6050_H
#define __MODULE_MPU6050_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

#include "framework/wire.h"

#define MPU6050_ADDRESS 0x68

typedef struct {
    int16_t accX;
    int16_t accY;
    int16_t accZ;
    int16_t gyroX;
    int16_t gyroY;
    int16_t gyroZ;
    int16_t temp;
} motion_t;

void MPU6050Init();
void MPU6050Read(motion_t* motion);
float MPU6050GetAcc(int16_t dat);
float MPU6050GetGyro(int16_t dat);
float MPU6050GetTemp(int16_t dat);

#endif
