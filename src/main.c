#include <51duino.h>
#include <stdint.h>

#define dat PIN_P15
#define latch PIN_P16
#define clock PIN_P17

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Hello World!");
    code uint8_t lights[] = {
        0b00000000, 0b00000001, 0b00000011, 0b00000111, 0b00001111, 0b00011111,
        0b00111111, 0b01111111, 0b11111111, 0b01111111, 0b00111111, 0b00011111,
        0b00001111, 0b00000111, 0b00000011, 0b00000001, 0b10000000, 0b11000000,
        0b11100000, 0b11110000, 0b11111000, 0b11111100, 0b11111110, 0b11111111,
        0b11111110, 0b11111100, 0b11111000, 0b11110000, 0b11100000, 0b11000000};
    for (uint8_t i = 0; i < sizeof(lights) / sizeof(lights[0]); i++) {
        delay(50);
        digitalWrite(latch, LOW);
        shiftOut(dat, clock, MSBFIRST, lights[i]);
        digitalWrite(latch, HIGH);
    }
}
