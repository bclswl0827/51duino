#include <wire.h>

// // 产生 ACK 应答
// void AckI2C(void) {
//     // SDA 为低电平
//     SCL = SDA = LOW;
//     delayMicroseconds(0);
//     SCL = HIGH;
//     delayMicroseconds(0);
//     SCL = LOW;
//     SDA = HIGH;
// }

// // 产生 NACK 非应答
// void NackI2C(void) {
//     // SDA 为高电平
//     SCL = LOW;
//     SDA = HIGH;
//     delayMicroseconds(0);
//     SCL = HIGH;
//     delayMicroseconds(0);
//     SCL = LOW;
// }

// // 等待应答信号到来
// uint8_t WaitAck(void) {
//     SCL = HIGH;
//     delayMicroseconds(0);
//     // 等待 SDA 为低电平
//     uint16_t t = 0;
//     while (I2C_SDA) {
//         t++;
//         delayMicroseconds(0);
//         // 超时则强制结束 I2C 通信
//         if (t > TIMEOUT) {
//             WireEnd();
//             return 1;
//         }
//     }
//     SCL = LOW;
//     return 0;
// }

// // I2C 发送一个字节
// void SendByte(uint8_t dat) {
//     SCL = LOW;
//     // 循环 8 次将一个字节传出，先传高位再传低位
//     for (int i = 0; i < 8; i++) {
//         if ((dat & 0x80) > 0) {
//             SDA = HIGH;
//         } else {
//             SDA = LOW;
//         }
//         dat <<= 1;
//         delayMicroseconds(0);
//         SCL = HIGH;
//         delayMicroseconds(0);
//         SCL = LOW;
//         delayMicroseconds(0);
//     }
// }

// // 产生 I2C 起始信号，作为主机
// void StartI2C(void) {
//     // SDA 和 SCL 同时高电平
//     SDA = SCL = HIGH;
//     // 当 SCL 为高电平时，SDA 由高变为低
//     SDA = LOW;
//     delayMicroseconds(0);
//     // 钳住 I2C 总线，准备发送或接收数据
//     SCL = LOW;
// }

// // 生成 I2C 停止信号
// void EndI2C(void) {
//     // SDA 低电平，SCL 高电平
//     SDA = LOW;
//     SCL = HIGH;
//     delayMicroseconds(0);
//     // 当 SCL 为高电平时，SDA 由低变为高
//     SDA = HIGH;
//     delayMicroseconds(0);
// }

// // 初始化 I2C 总线
// void WireBegin() {
//     // 无需实现
//     ;
// }

// // 使用指定的地址开始向 I2C 从设备进行传输
// void WireBeginTransmission(uint8_t address) {
//     // 发出起始信号
//     StartI2C();
//     // 传入 7 位地址
//     SendByte(address << 1);
//     // 等待应答信号
//     WaitAck();
// }

//

// // I2C 对指定器件、指定寄存器连续写入
// uint8_t WriteI2C(uint8_t device,  // 从机地址
//                  uint8_t memory,  // 寄存器地址
//                  uint8_t* dat,    // 数据指针
//                  uint8_t length   // 数据长度
// ) {
//     StartI2C();
//     SendByte(device << 1);
//     if (WaitAck()) {
//         return 1;
//     }
//     SendByte(memory);
//     if (WaitAck()) {
//         return 1;
//     }
//     while (length--) {
//         SendByte(*dat++);
//         if (WaitAck()) {
//             return 1;
//         }
//     }
//     StopI2C();
//     return 0;
// }
