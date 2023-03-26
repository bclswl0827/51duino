#include <digital.h>

// 设定管脚电平
void digitalWrite(uint_least8_t _pin, uint_least8_t level) {
    uint_least8_t __hub = _pin / 10, __pin = _pin % 10;
    static uint_least8_t value;
#define GET_PORT_X_VALUE(port) \
    if (__hub == port) {       \
        value = P##port;       \
    }
#define MACRO_LOOP_CMD(n) GET_PORT_X_VALUE(n)
    MACRO_LOOP(PORTS)
#undef MACRO_LOOP_CMD
    if (level) {
        value |= 1 << __pin;
    } else {
        value &= ~(1 << __pin);
    }
#define SET_PORT_X_VALUE(port) \
    if (__hub == port) {       \
        P##port = value;       \
    }
#define MACRO_LOOP_CMD(n) SET_PORT_X_VALUE(n)
    MACRO_LOOP(PORTS)
#undef MACRO_LOOP_CMD
}

// 读取管脚电平
uint_least8_t digitalRead(uint_least8_t _pin) {
    uint_least8_t __hub = _pin / 10, __pin = _pin % 10;
    static uint_least8_t value;
#define GET_PORT_X_VALUE(port) \
    if (__hub == port) {       \
        value = P##port;       \
    }
#define MACRO_LOOP_CMD(n) GET_PORT_X_VALUE(n)
    MACRO_LOOP(PORTS)
#undef MACRO_LOOP_CMD
    return (value >> __pin) & 1;
}

// 一次一位移入一个字节数据
uint_least8_t shiftIn(uint_least8_t dataPin,
                      uint_least8_t clockPin,
                      uint_least8_t bitOrder) {
    uint_least8_t value = 0;
    for (uint_least8_t i = 0; i < 8; ++i) {
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

// 一次移出一个字节数据
void shiftOut(uint_least8_t dataPin,
              uint_least8_t clockPin,
              uint_least8_t bitOrder,
              uint_least8_t val) {
    for (uint_least8_t i = 0; i < 8; i++) {
        if (bitOrder == LSBFIRST) {
            digitalWrite(dataPin, !!(val & (1 << i)));
        } else {
            digitalWrite(dataPin, !!(val & (1 << (7 - i))));
        }
        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);
    }
}
