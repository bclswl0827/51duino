#ifndef __FRAMEWORK_SPI__H
#define __FRAMEWORK_SPI__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <reg52.h>
#include <stdint.h>
#include "framework/config.h"

// CPOL=0, CPHA=0
#define SPI_MODE0 0
// CPOL=0, CPHA=1
#define SPI_MODE1 1
// CPOL=1, CPHA=0
#define SPI_MODE2 2
// CPOL=1, CPHA=1
#define SPI_MODE3 3

// SPI configuration
typedef struct {
    uint32_t speed;
    uint8_t bitOrder;
    uint8_t dataMode;
} spi_settings_t;

void __spi_end(void);
void __spi_begin(void);
void __spi_endTransaction(void);
uint8_t __spi_transfer(uint8_t dat);
void __spi_setDataMode(uint8_t mode);
void __spi_setBitOrder(uint8_t order);
void __spi_beginTransaction(spi_settings_t* settings);
spi_settings_t* SPISettings(uint32_t speed, uint8_t bitOrder, uint8_t dataMode);

// Use macro to replace function call
#define SPI_end() __spi_end()
#define SPI_begin() __spi_begin()
#define SPI_endTransaction() __spi_endTransaction()
#define SPI_transfer(dat) __spi_transfer(dat)
#define SPI_setDataMode(mode) __spi_setDataMode(mode)
#define SPI_setBitOrder(order) __spi_setBitOrder(order)
#define SPI_beginTransaction(settings) __spi_beginTransaction(settings)

// Create SPI object if SPI_USE_CLASS is 1
#if defined(SPI_USE_CLASS) && SPI_USE_CLASS == 1
// Contains Wire related methods
static typedef struct {
    void (*begin)(void);
    void (*end)(void);
    void (*endTransaction)(void);
    uint8_t (*transfer)(uint8_t dat);
    void (*setDataMode)(uint8_t mode);
    void (*setBitOrder)(uint8_t order);
    void (*beginTransaction)(spi_settings_t* settings);
} spi_t;

// Export Wire object
spi_t SPI = {
    .begin = __spi_begin,
    .end = __spi_end,
    .endTransaction = __spi_endTransaction,
    .transfer = __spi_transfer,
    .setDataMode = __spi_setDataMode,
    .setBitOrder = __spi_setBitOrder,
    .beginTransaction = __spi_beginTransaction,
};
#endif

#endif
