#include <wire.h>

// 设定管脚模式
void pinMode(void) {
    // 无需实现
    ;
}

// 设定管脚电平
void digitalWrite(uint8_t* _pin, uint8_t level) {
    static uint8_t value;
#define GET_PORT_X_VALUE(port) \
    if (_pin[0] == port) {     \
        value = P##port;       \
    }
#define MACRO_LOOP_CMD(n) GET_PORT_X_VALUE(n)
    MACRO_LOOP(PORTS)
#undef MACRO_LOOP_CMD
    if (level) {
        value |= 1 << _pin[1];
    } else {
        value &= ~(1 << _pin[1]);
    }
#define SET_PORT_X_VALUE(port) \
    if (_pin[0] == port) {     \
        P##port = value;       \
    }
#define MACRO_LOOP_CMD(n) SET_PORT_X_VALUE(n)
    MACRO_LOOP(PORTS)
#undef MACRO_LOOP_CMD
}

// 读取管脚电平
uint8_t digitalRead(uint8_t* _pin) {
    static uint8_t value;
#define GET_PORT_X_VALUE(port) \
    if (_pin[0] == port) {     \
        value = P##port;       \
    }
#define MACRO_LOOP_CMD(n) GET_PORT_X_VALUE(n)
    MACRO_LOOP(PORTS)
#undef MACRO_LOOP_CMD
    return (value >> _pin[1]) & 1;
}

// 一次一位移入一个字节数据
uint8_t shiftIn(uint8_t* dataPin, uint8_t* clockPin, uint8_t bitOrder) {
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

// 一次移出一个字节数据
void shiftOut(uint8_t* dataPin,
              uint8_t* clockPin,
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
