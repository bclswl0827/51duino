#ifndef __FRAMEWORK_SPI__H
#define __FRAMEWORK_SPI__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>
#include <stdlib.h>

#include "config.h"

#define PIN_SPI_SCK P30   // SCK 引脚
#define PIN_SPI_MOSI P31  // MOSI 引脚
#define PIN_SPI_MISO P32  // MISO 引脚

#define LSBFIRST 0  // 最低有效位优先
#define MSBFIRST 1  // 最高有效位优先

#define SPI_MODE0 0  // CPOL=0, CPHA=0
#define SPI_MODE1 1  // CPOL=0, CPHA=1
#define SPI_MODE2 2  // CPOL=1, CPHA=0
#define SPI_MODE3 3  // CPOL=1, CPHA=1

typedef struct {
    uint32_t speed;
    uint8_t bitOrder;
    uint8_t dataMode;
} spi_t;

void SPIBegin(void);
void SPIEnd(void);
void SPISetDataMode(uint8_t mode);
void SPISetBitOrder(uint8_t order);
spi_t* SPISettings(uint32_t speed, uint8_t bitOrder, uint8_t dataMode);
void SPIBeginTransaction(spi_t* settings);
uint8_t SPITransfer(uint8_t dat);
void SPIEndTransaction(void);

#endif
