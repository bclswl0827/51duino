#include <Arduino.h>
#include <string.h>
#include "modules/ads1115.h"

#include "modules/ads1256.h"

// ADC sampling rate (maximum SAMPLE_RATE_30000_SPS)
#define SAMPLE_RATE SAMPLE_RATE_2000_SPS
// ADC gain rate (maximum GAIN_RATE_64X)
#define GAIN_RATE GAIN_RATE_2X
// ADC analog input buffer
#define ADC_BUFFER ENABLE
// ADC analog input calibration
#define ADC_CALIBRATION ENABLE
// Serial baud rate
#define SERIAL_BAUD 57600
// Data packet size
#define PACKET_SIZE 6

// Reset word
#define RESET_WORD 0x61

// Syncing bytes
const uint8_t SYNC_WORD[] = {
    0xFC,
    0x1B,
};
// Responding bytes
const uint8_t ACK_WORD[] = {
    0xFC,
    0x2B,
};

typedef struct {
    int32_t EHZ[PACKET_SIZE];
    int32_t EHE[PACKET_SIZE];
    int32_t EHN[PACKET_SIZE];
    uint8_t Checksum[3];
} sensor_t;

uint8_t shouldReset() {
    uint8_t gain = ADS1256GetGain();
    uint8_t sample = ADS1256GetSample();
    if (gain != GAIN_RATE || sample != SAMPLE_RATE) {
        return 1;
    }

    uint8_t buffer, calibration;
    ADS1256GetStatus(&buffer, &calibration);
    if (buffer != ADC_BUFFER || calibration != ADC_CALIBRATION) {
        return 1;
    }

    return Serial_available() && Serial_read() == RESET_WORD;
}

int32_t getRawValue(int32_t value) {
    if (value >> 23) {
        value -= 16777216;
    }

    return value;
}

uint8_t getChecksum(int32_t* array, uint32_t size) {
    uint8_t checksum = 0;

    for (uint32_t i = 0; i < size; i++) {
        uint8_t* bytes = (uint8_t*)&array[i];

        for (uint8_t j = 0; j < sizeof(int32_t); j++) {
            checksum ^= bytes[j];
        }
    }

    return checksum;
}

void blinkLED(uint8_t times, uint16_t interval) {
    for (uint8_t i = 0; i < times; i++) {
        digitalWrite(20, HIGH);
        delay(interval);
        digitalWrite(20, LOW);
        delay(interval);
    }
}

void initADC() {
    ADS1256Begin();
    ADS1256Reset();
    ADS1256SetGain(GAIN_RATE);
    ADS1256SetSample(SAMPLE_RATE);
    ADS1256SetStatus(ADC_BUFFER, ADC_CALIBRATION);
}

void setup() {
    Serial_begin(SERIAL_BAUD);
    blinkLED(3, 50);

    initADC();
    blinkLED(5, 50);
}

void loop() {
    sensor_t sensor;

    for (uint16_t i = 0; i < PACKET_SIZE; i++) {
        // Support runtime reset
        if (shouldReset()) {
            initADC();
            blinkLED(1, 50);

            for (uint8_t i = 0; i < sizeof(ACK_WORD); i++) {
                Serial_write(ACK_WORD[i]);
            }
        }

        ADS1256GetDifferential(ANALOG_INPUT_AIN1, ANALOG_INPUT_AIN2);
        // Vertical geophone (EHZ)
        sensor.EHZ[i] = getRawValue(
            ADS1256GetDifferential(ANALOG_INPUT_AIN3, ANALOG_INPUT_AIN4));
        // East-West geophone (EHE)
        sensor.EHE[i] = getRawValue(
            ADS1256GetDifferential(ANALOG_INPUT_AIN5, ANALOG_INPUT_AIN6));
        // North-South geophone (EHN)
        sensor.EHN[i] = getRawValue(
            ADS1256GetDifferential(ANALOG_INPUT_AIN7, ANALOG_INPUT_AIN8));
    }

    // Get checksum
    sensor.Checksum[0] = getChecksum(sensor.EHZ, PACKET_SIZE);
    sensor.Checksum[1] = getChecksum(sensor.EHE, PACKET_SIZE);
    sensor.Checksum[2] = getChecksum(sensor.EHN, PACKET_SIZE);

    // Send SYNC_WORD
    for (uint8_t i = 0; i < sizeof(SYNC_WORD); i++) {
        Serial_write(SYNC_WORD[i]);
    }
    // Send EHZ channel data
    for (uint8_t i = 0; i < PACKET_SIZE; i++) {
        for (uint8_t j = 0; j < sizeof(int32_t); j++) {
            Serial_write(((uint8_t*)&sensor.EHZ[i])[j]);
        }
    }
    // Send EHE channel data
    for (uint8_t i = 0; i < PACKET_SIZE; i++) {
        for (uint8_t j = 0; j < sizeof(int32_t); j++) {
            Serial_write(((uint8_t*)&sensor.EHE[i])[j]);
        }
    }
    // Send EHN channel data
    for (uint8_t i = 0; i < PACKET_SIZE; i++) {
        for (uint8_t j = 0; j < sizeof(int32_t); j++) {
            Serial_write(((uint8_t*)&sensor.EHN[i])[j]);
        }
    }
    // Send channel checksum
    for (uint8_t i = 0; i < sizeof(sensor.Checksum); i++) {
        Serial_write(sensor.Checksum[i]);
    }
}
