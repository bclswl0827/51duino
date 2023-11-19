#include "framework/delay.h"

// Set delay in milliseconds
void delay(uint16_t t) {
    uint8_t count = 70;

    if (t < 20) {
        count = 47;
    } else if (t < 10) {
        count = 1;
        t /= 2;
    }

    for (uint16_t i = 0; i < t; i++) {
        for (uint16_t j = 0; j < count; j++) {
            ;
        }
    }
}

// Set delay in microseconds
void delayMicroseconds(uint16_t t) {
    while (--t) {
        ;
    }
}
