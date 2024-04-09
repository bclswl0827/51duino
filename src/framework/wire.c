#include "framework/wire.h"

// Slave address
static uint8_t __wire_address = 0x00;
// Bytes remaining
static uint8_t __wire_remain = 0;
// Transmission status
static uint8_t __wire_status = WIRE_START;

// Set SDA pin state
void __wire_setSDA(uint8_t val) {
    SDA = val ? 1 : 0;
}

// Get SDA pin state
uint8_t __wire_getSDA() {
    return SDA;
}

// Set SCL pin state
void __wire_setSCL(uint8_t val) {
    SCL = val ? 1 : 0;
}

// Get SCL pin state
uint8_t __wire_getSCL() {
    return SCL;
}

// Initialize I2C bus
void __wire_begin() {
    __wire_setSDA(0);
    __wire_setSCL(0);
}

// Begin I2C transmission
void __wire_beginTransmission(uint8_t addr) {
    __wire_address = addr;
    // Start signal
    __wire_setSDA(1);
    __wire_setSCL(1);
    delayMicroseconds(5);
    __wire_setSDA(0);
    delayMicroseconds(5);
    __wire_setSCL(0);
    // Send slave address
    __wire_write(addr << 1);
}

// End I2C transmission
uint8_t __wire_endTransmission() {
    __wire_setSDA(0);
    __wire_setSCL(1);
    delayMicroseconds(5);
    __wire_setSDA(1);
    delayMicroseconds(5);
    return 1;
}

// I2C read one byte
uint8_t __wire_read() {
    uint8_t dat = 0;

    if (__wire_status == WIRE_START) {
        // Receive mode
        __wire_setSDA(1);
        __wire_setSCL(1);
        delayMicroseconds(5);
        __wire_setSDA(0);
        delayMicroseconds(5);
        __wire_setSCL(0);
        // Send slave read address
        __wire_write((__wire_address << 1) | 1);
    }

    // Reset status if all bytes have been read
    if (!--__wire_remain) {
        __wire_status = WIRE_START;
    }

    // Read one byte
    for (uint8_t i = 0; i < 8; i++) {
        __wire_setSCL(0);
        delayMicroseconds(5);
        __wire_setSCL(1);
        dat <<= 1;
        dat |= __wire_getSDA();
        delayMicroseconds(5);
    }

    // ACK if more bytes are to be read
    if (!!__wire_remain) {
        __wire_setSDA(0);
    } else {
        __wire_setSDA(1);
    }
    delayMicroseconds(5);
    __wire_setSCL(1);
    delayMicroseconds(5);
    __wire_setSCL(0);
    if (!!__wire_remain) {
        __wire_setSDA(1);
    }

    return dat;
}

// I2C Send one byte
void __wire_write(uint8_t dat) {
    // Send one byte
    __wire_setSCL(0);
    for (uint8_t i = 0; i < 8; i++) {
        if (dat & 0x80) {
            __wire_setSDA(1);
        } else {
            __wire_setSDA(0);
        }
        dat <<= 1;
        __wire_setSCL(1);
        delayMicroseconds(5);
        __wire_setSCL(0);
        delayMicroseconds(5);
    }

    __wire_setSCL(1);
    delayMicroseconds(5);
    __wire_setSCL(0);
    delayMicroseconds(5);
}

// Read specified length of data from specified address
uint8_t __wire_requestFrom(uint8_t addr, uint8_t len) __reentrant {
    if (len < 2) {
        return 0;
    }

    // Receive mode
    __wire_setSDA(1);
    __wire_setSCL(1);
    delayMicroseconds(5);
    __wire_setSDA(0);
    delayMicroseconds(5);
    __wire_setSCL(0);
    // Send slave read address
    __wire_write((__wire_address << 1) | 1);

    __wire_address = addr;
    __wire_remain = len;
    __wire_status = WIRE_RESUME;

    return len;
}
