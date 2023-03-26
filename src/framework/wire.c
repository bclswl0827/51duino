#include <wire.h>

// 全局变量记录地址
uint_least8_t _address = 0x00;
// ACK / NACK 标志
uint_least8_t _ack = 0;

// 用于等待电平稳定和控制通讯速率
void _WireDelay() {
    ;
}

// 初始化 I2C 总线
void WireBegin() {
    PIN_WIRE_SDA = LOW;
    PIN_WIRE_SCL = LOW;
}

// 启动 I2C 传输
void WireBeginTransmission(uint_least8_t addr) {
    // 发出启动信号
    PIN_WIRE_SDA = HIGH;
    PIN_WIRE_SCL = HIGH;
    PIN_WIRE_SDA = LOW;
    PIN_WIRE_SCL = LOW;
    // 发送设备地址
    WireWrite(addr << 1);
    // 赋值到全局变量
    _address = addr;
}

// 结束 I2C 传输
uint_least8_t WireEndTransmission() {
    PIN_WIRE_SDA = LOW;
    PIN_WIRE_SCL = HIGH;
    PIN_WIRE_SDA = HIGH;
    return 1;
}

// I2C 读取 1 字节
uint_least8_t WireRead() {
    // 进入接收模式
    PIN_WIRE_SDA = HIGH;
    PIN_WIRE_SCL = HIGH;
    PIN_WIRE_SDA = LOW;
    PIN_WIRE_SCL = LOW;
    WireWrite(1 | _address << 1);
    // 循环 8 次将一个字节读出，先读高再传低位
    uint_least8_t dat = 0;
    for (uint_least8_t i = 0; i < 8; i++) {
        PIN_WIRE_SCL = LOW;
        _WireDelay();
        PIN_WIRE_SCL = HIGH;
        dat <<= 1;
        if (PIN_WIRE_SDA) {
            dat++;
        }
        _WireDelay();
    }
    if (_ack) {
        // 发出 ACK 信号
        PIN_WIRE_SCL = LOW;
        PIN_WIRE_SDA = LOW;
        _WireDelay();
        PIN_WIRE_SCL = HIGH;
        _WireDelay();
        PIN_WIRE_SCL = LOW;
        PIN_WIRE_SDA = HIGH;
    } else {
        // 发出 NACK 信号
        PIN_WIRE_SCL = LOW;
        PIN_WIRE_SDA = HIGH;
        _WireDelay();
        PIN_WIRE_SCL = HIGH;
        _WireDelay();
        PIN_WIRE_SCL = LOW;
    }
    return dat;
}

// I2C 发送 1 字节
void WireWrite(uint_least8_t dat) {
    PIN_WIRE_SCL = LOW;
    // 循环 8 次将一个字节传出，先传高位再传低位
    for (uint_least8_t j = 0; j < 8; j++) {
        if ((dat & 0x80) > 0) {
            PIN_WIRE_SDA = HIGH;
        } else {
            PIN_WIRE_SDA = LOW;
        }
        dat <<= 1;
        _WireDelay();
        PIN_WIRE_SCL = HIGH;
        _WireDelay();
        PIN_WIRE_SCL = LOW;
        _WireDelay();
    }
    // 等待 ACK / NACK 应答信号
    PIN_WIRE_SCL = HIGH;
    // 等待 SDA 为低电平
    for (uint_least16_t i = 0;; i++) {
        // 超时则强制结束 I2C 通信
        if (i > I2C_TIMEOUT) {
            WireEndTransmission();
            return;
        }
        // SDA 为低电平时跳出循环
        if (!PIN_WIRE_SDA) {
            break;
        }
    }
    PIN_WIRE_SCL = LOW;
}
