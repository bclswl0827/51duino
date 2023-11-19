#ifndef __MODULE_ADC_ADS1256_H
#define __MODULE_ADC_ADS1256_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

#include "framework/delay.h"
#include "framework/spi.h"

#define ADS1256_RST_PIN P15
#define ADS1256_DRDY_PIN P14

#define VREF 2.5
#define SPEED 1920000

#define ENABLE 1
#define DISABLE 0

// typedef enum {
//     ANALOG_INPUT_AIN1 = 0x00,
//     ANALOG_INPUT_AIN2 = 0x01,
//     ANALOG_INPUT_AIN3 = 0x02,
//     ANALOG_INPUT_AIN4 = 0x03,
//     ANALOG_INPUT_AIN5 = 0x04,
//     ANALOG_INPUT_AIN6 = 0x05,
//     ANALOG_INPUT_AIN7 = 0x06,
//     ANALOG_INPUT_AIN8 = 0x07,
//     ANALOG_INPUT_AINCOM = 0x08,
// } AnalogInputChannel;

typedef enum {
    ANALOG_INPUT_AIN8 = 0x00,
    ANALOG_INPUT_AIN1 = 0x01,
    ANALOG_INPUT_AIN2 = 0x02,
    ANALOG_INPUT_AIN3 = 0x03,
    ANALOG_INPUT_AIN4 = 0x04,
    ANALOG_INPUT_AIN5 = 0x05,
    ANALOG_INPUT_AIN6 = 0x06,
    ANALOG_INPUT_AIN7 = 0x07,
    ANALOG_INPUT_AINCOM = 0x08,
} AnalogInputChannel;

typedef enum {
    DEVICE_COMMAND_WAKEUP = 0x00,
    DEVICE_COMMAND_RDATA = 0x01,
    DEVICE_COMMAND_RDATAC = 0x03,
    DEVICE_COMMAND_SDATAC = 0x0F,
    DEVICE_COMMAND_RREG = 0x10,
    DEVICE_COMMAND_WREG = 0x50,
    DEVICE_COMMAND_SELFCAL = 0xF0,
    DEVICE_COMMAND_SELFOCAL = 0xF1,
    DEVICE_COMMAND_SELFGCAL = 0xF2,
    DEVICE_COMMAND_SYSOCAL = 0xF3,
    DEVICE_COMMAND_SYSGCAL = 0xF4,
    DEVICE_COMMAND_SYNC = 0xFC,
    DEVICE_COMMAND_STANDBY = 0xFD,
    DEVICE_COMMAND_RESET = 0xFE,
} DeviceCommand;

typedef enum {
    GAIN_RATE_1X = 0x00,
    GAIN_RATE_2X = 0x01,
    GAIN_RATE_4X = 0x02,
    GAIN_RATE_8X = 0x03,
    GAIN_RATE_16X = 0x04,
    GAIN_RATE_32X = 0x05,
    GAIN_RATE_64X = 0x06,
} GainRate;

typedef enum {
    ADC_MODE_ONESHOT = 0,
    ADC_MODE_CONTINUOUS,
} AdcMode;

typedef enum {
    ADC_REGISTER_STATUS = 0x00,
    ADC_REGISTER_MUX = 0x01,
    ADC_REGISTER_ADCON = 0x02,
    ADC_REGISTER_DRATE = 0x03,
    ADC_REGISTER_IO = 0x04,
    ADC_REGISTER_OFC0 = 0x05,
    ADC_REGISTER_OFC1 = 0x06,
    ADC_REGISTER_OFC2 = 0x07,
    ADC_REGISTER_FSC0 = 0x08,
    ADC_REGISTER_FSC1 = 0x09,
    ADC_REGISTER_FSC2 = 0x0A,
} AdcRegisters;

typedef enum {
    SAMPLE_RATE_30000_SPS = 0xF0,
    SAMPLE_RATE_15000_SPS = 0xE0,
    SAMPLE_RATE_7500_SPS = 0xD0,
    SAMPLE_RATE_3750_SPS = 0xC0,
    SAMPLE_RATE_2000_SPS = 0xB0,
    SAMPLE_RATE_1000_SPS = 0xA1,
    SAMPLE_RATE_500_SPS = 0x92,
    SAMPLE_RATE_100_SPS = 0x82,
    SAMPLE_RATE_60_SPS = 0x72,
    SAMPLE_RATE_50_SPS = 0x63,
    SAMPLE_RATE_30_SPS = 0x53,
    SAMPLE_RATE_25_SPS = 0x43,
    SAMPLE_RATE_15_SPS = 0x33,
    SAMPLE_RATE_10_SPS = 0x23,
    SAMPLE_RATE_5_SPS = 0x13,
    SAMPLE_RATE_2_5_SPS = 0x03,
} SampleRateSPS;

void ADS1256Begin();
void ADS1256Reset();
void ADS1256SetChannel(AnalogInputChannel channel);
AnalogInputChannel ADS1256GetChannel();
void ADS1256SetGain(GainRate gain);
GainRate ADS1256GetGain();
void ADS1256SetMode(AdcMode mode);
int32_t ADS1256GetSingleOneShot();
int32_t ADS1256GetSingleContinuous();
int32_t ADS1256GetDifferential(AnalogInputChannel positiveCh,
                               AnalogInputChannel negativeCh);
void ADS1256SetSample(SampleRateSPS rate);
SampleRateSPS ADS1256GetSample();
void ADS1256SetStatus(uint8_t buffer, uint8_t calibration);
void ADS1256GetStatus(uint8_t* buffer, uint8_t* calibration);
float ADS1256ToVoltage(int32_t value);

#endif
