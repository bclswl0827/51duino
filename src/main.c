#include <string.h>

// #include "framework/analog.h"
// #include "framework/delay.h"
// #include "framework/digital.h"
// #include "framework/spi.h"
#include "framework/stream.h"
#include "framework/wire.h"

#include "modules/adc/ads1115.h"
// #include "modules/adc/mcp3421.h"
// #include "modules/adc/pcf8591.h"
// #include "modules/lcd/lcd1602.h"
// #include "modules/oled/ssd1306.h"
// #include "modules/rtc/ds3231.h"
// #include "modules/temp/lm75a.h"
// #include "modules/tuner/si5351.h"

// 数据帧同步字节
#define SYNC_WORD 0x8A

// 传感器数据结构体
typedef struct {
    float AIN[4];
    uint8_t Checksum;
} sensor_t;

// 计算校验和
uint8_t getChecksum(float* dat) {
    uint8_t checksum = 0;

    for (uint8_t i = 0; i < 4; i++) {
        uint8_t* bytes = (uint8_t*)&dat[i];

        for (uint8_t j = 0; j < sizeof(float); j++) {
            checksum ^= bytes[j];
        }
    }

    return checksum;
}

// 发送传感器数据
void sendSensorData(sensor_t* dat) {
    uint8_t dataBytes[sizeof(sensor_t)];
    memcpy(dataBytes, dat, sizeof(sensor_t));

    for (uint8_t i = 0; i < sizeof(sensor_t); i++) {
        SerialWrite(dataBytes[i]);
    }
}

void main() {
    sensor_t dat;
    SerialBegin(19200);

    ADS1115Init();
    float f = ADS1115ToVoltage(ADS1115_PGA_4_096V);

    while (1) {
        dat.AIN[0] =
            f * ADS1115Read(ADS1115_MUX_SINGLE_0_GND, ADS1115_PGA_4_096V,
                            ADS1115_DATARATE_860, ADS1115_COMP_MODE_WINDOW,
                            ADS1115_COMP_POL_ACTIVE_LOW, ADS1115_COMP_NON_LATCH,
                            ADS1115_COMP_QUEUE_DISABLE);
        dat.AIN[1] =
            f * ADS1115Read(ADS1115_MUX_SINGLE_1_GND, ADS1115_PGA_4_096V,
                            ADS1115_DATARATE_860, ADS1115_COMP_MODE_WINDOW,
                            ADS1115_COMP_POL_ACTIVE_LOW, ADS1115_COMP_NON_LATCH,
                            ADS1115_COMP_QUEUE_DISABLE);
        dat.AIN[2] =
            f * ADS1115Read(ADS1115_MUX_SINGLE_2_GND, ADS1115_PGA_4_096V,
                            ADS1115_DATARATE_860, ADS1115_COMP_MODE_WINDOW,
                            ADS1115_COMP_POL_ACTIVE_LOW, ADS1115_COMP_NON_LATCH,
                            ADS1115_COMP_QUEUE_DISABLE);
        dat.AIN[3] =
            f * ADS1115Read(ADS1115_MUX_SINGLE_3_GND, ADS1115_PGA_4_096V,
                            ADS1115_DATARATE_860, ADS1115_COMP_MODE_WINDOW,
                            ADS1115_COMP_POL_ACTIVE_LOW, ADS1115_COMP_NON_LATCH,
                            ADS1115_COMP_QUEUE_DISABLE);
        dat.Checksum = getChecksum(dat.AIN);

        SerialWrite(SYNC_WORD);
        sendSensorData(&dat);
    }
}
