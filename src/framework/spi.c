#include "framework/spi.h"

uint8_t _spi_bit_order = MSBFIRST;   // 位顺序
uint8_t _spi_data_mode = SPI_MODE0;  // 数据模式

void SPIBegin() {
    PIN_SPI_MOSI = LOW;
    PIN_SPI_MISO = LOW;
}

void SPIEnd() {
    ;
}

void SPISetDataMode(uint8_t mode) {
    _spi_data_mode = mode;
}

void SPISetBitOrder(uint8_t order) {
    _spi_bit_order = order;
}

spi_t* SPISettings(uint32_t speed, uint8_t bitOrder, uint8_t dataMode) {
    spi_t* settings = (spi_t*)malloc(sizeof(spi_t));
    settings->speed = speed;
    settings->bitOrder = bitOrder;
    settings->dataMode = dataMode;

    return settings;
}

void SPIBeginTransaction(spi_t* settings) {
    _spi_bit_order = settings->bitOrder;
    _spi_data_mode = settings->dataMode;
}

uint8_t SPITransfer(uint8_t dat) {
    uint8_t rx_dat = 0;

    switch (_spi_data_mode) {
        case SPI_MODE0:
            PIN_SPI_SCK = LOW;
            for (uint8_t i = 0; i < 8; i++) {
                rx_dat = _spi_bit_order == MSBFIRST ? rx_dat << 1 : rx_dat >> 1;
                rx_dat |= _spi_bit_order == MSBFIRST ? PIN_SPI_MISO
                                                     : PIN_SPI_MISO << 7;

                PIN_SPI_MOSI =
                    _spi_bit_order == MSBFIRST ? dat & 0x80 : (dat & 0x01) << 7;
                dat = _spi_bit_order == MSBFIRST ? dat << 1 : dat >> 1;

                PIN_SPI_SCK = HIGH;
                PIN_SPI_SCK = LOW;
            }
            break;
        case SPI_MODE1:
            PIN_SPI_SCK = LOW;
            for (uint8_t i = 0; i < 8; i++) {
                PIN_SPI_MOSI =
                    _spi_bit_order == MSBFIRST ? dat & 0x80 : (dat & 0x01) << 7;
                dat = _spi_bit_order == MSBFIRST ? dat << 1 : dat >> 1;

                PIN_SPI_SCK = HIGH;
                rx_dat = _spi_bit_order == MSBFIRST ? rx_dat << 1 : rx_dat >> 1;
                rx_dat |= _spi_bit_order == MSBFIRST ? PIN_SPI_MISO
                                                     : PIN_SPI_MISO << 7;

                PIN_SPI_SCK = LOW;
            }
            break;
        case SPI_MODE2:
            PIN_SPI_SCK = HIGH;
            for (uint8_t i = 0; i < 8; i++) {
                rx_dat = _spi_bit_order == MSBFIRST ? rx_dat << 1 : rx_dat >> 1;
                rx_dat |= _spi_bit_order == MSBFIRST ? PIN_SPI_MISO
                                                     : PIN_SPI_MISO << 7;

                PIN_SPI_MOSI =
                    _spi_bit_order == MSBFIRST ? dat & 0x80 : (dat & 0x01) << 7;
                dat = _spi_bit_order == MSBFIRST ? dat << 1 : dat >> 1;

                PIN_SPI_SCK = LOW;
                PIN_SPI_SCK = HIGH;
            }
            break;
        case SPI_MODE3:
            PIN_SPI_SCK = HIGH;
            for (uint8_t i = 0; i < 8; i++) {
                PIN_SPI_MOSI =
                    _spi_bit_order == MSBFIRST ? dat & 0x80 : (dat & 0x01) << 7;
                dat = _spi_bit_order == MSBFIRST ? dat << 1 : dat >> 1;

                PIN_SPI_SCK = LOW;
                rx_dat = _spi_bit_order == MSBFIRST ? rx_dat << 1 : rx_dat >> 1;
                rx_dat |= _spi_bit_order == MSBFIRST ? PIN_SPI_MISO
                                                     : PIN_SPI_MISO << 7;

                PIN_SPI_SCK = HIGH;
            }
            break;
    }

    return rx_dat;
}

void SPIEndTransaction() {
    ;
}
