#include "framework/digital.h"

#define GET_STATE(port, pin) (port >> pin) & 0x01
#define SET_STATE(port, pin, state) \
    (port = state ? (port | (1 << pin)) : (port & ~(1 << pin)))

// Set pin state
void digitalWrite(uint8_t pinNum, uint8_t state) {
    uint8_t port = pinNum / 10;
    uint8_t pin = pinNum % 10;

    switch (port) {
        case 0:
            SET_STATE(P0, pin, state);
            break;
        case 1:
            SET_STATE(P1, pin, state);
            break;
        case 2:
            SET_STATE(P2, pin, state);
            break;
        case 3:
            SET_STATE(P3, pin, state);
            break;
        default:
            return;
    }
}

// Read pin state
uint8_t digitalRead(uint8_t pinNum) {
    uint8_t port = pinNum / 10;
    uint8_t pin = pinNum % 10;

    switch (port) {
        case 0:
            return GET_STATE(P0, pin);
        case 1:
            return GET_STATE(P1, pin);
        case 2:
            return GET_STATE(P2, pin);
        case 3:
            return GET_STATE(P3, pin);
    }

    return 0;
}

// Set pin mode
void pinMode(uint8_t pinNum, uint8_t mode) {
    switch (mode) {
        case OUTPUT:
        case INPUT:
            digitalWrite(pinNum, LOW);
            break;
        case INPUT_PULLUP:
            digitalWrite(pinNum, HIGH);
            break;
    }
}

// Shifts out a byte of data one bit at a time
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
    uint8_t value = 0;
    for (uint8_t i = 0; i < 8; ++i) {
        digitalWrite(clockPin, HIGH);
        if (bitOrder == LSBFIRST) {
            value |= digitalRead(dataPin) << i;
        } else {
            value |= digitalRead(dataPin) << (7 - i);
        }

        digitalWrite(clockPin, LOW);
    }

    return value;
}

// Shifts in a byte of data one bit at a time
void shiftOut(uint8_t dataPin,
              uint8_t clockPin,
              uint8_t bitOrder,
              uint8_t val) {
    for (uint8_t i = 0; i < 8; i++) {
        if (bitOrder == LSBFIRST) {
            digitalWrite(dataPin, !!(val & (1 << i)));
        } else {
            digitalWrite(dataPin, !!(val & (1 << (7 - i))));
        }

        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);
    }
}
