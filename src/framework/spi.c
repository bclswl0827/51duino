#include "framework/spi.h"

uint8_t __spi_bit_order = MSBFIRST;   // 位顺序
uint8_t __spi_data_mode = SPI_MODE0;  // 数据模式

void __spi_setSCK(uint8_t val) {
    SCK = val ? 1 : 0;
}

uint8_t __spi_getSCK() {
    return SCK;
}

void __spi_setMOSI(uint8_t val) {
    MOSI = val ? 1 : 0;
}

uint8_t __spi_getMOSI() {
    return MOSI;
}

void __spi_setMISO(uint8_t val) {
    MISO = val ? 1 : 0;
}

uint8_t __spi_getMISO() {
    return MISO;
}

spi_settings_t* SPISettings(uint32_t speed,
                            uint8_t bitOrder,
                            uint8_t dataMode) {
    spi_settings_t settings;
    settings.speed = speed;
    settings.bitOrder = bitOrder;
    settings.dataMode = dataMode;

    return &settings;
}

void __spi_begin() {
    __spi_setMOSI(0);
    __spi_setMISO(0);
}

void __spi_end() {
    ;
}

void __spi_setDataMode(uint8_t mode) {
    __spi_data_mode = mode;
}

void __spi_setBitOrder(uint8_t order) {
    __spi_bit_order = order;
}

void __spi_beginTransaction(spi_settings_t* settings) {
    __spi_bit_order = settings->bitOrder;
    __spi_data_mode = settings->dataMode;
}

uint8_t __spi_transfer(uint8_t dat) {
    uint8_t rx_dat = 0;

    switch (__spi_data_mode) {
        case SPI_MODE0:
            __spi_setSCK(0);

            for (uint8_t i = 0; i < 8; i++) {
                rx_dat =
                    __spi_bit_order == MSBFIRST ? rx_dat << 1 : rx_dat >> 1;

                uint8_t miso_state = __spi_getMISO();
                rx_dat |=
                    __spi_bit_order == MSBFIRST ? miso_state : miso_state << 7;

                __spi_setMOSI(__spi_bit_order == MSBFIRST ? dat & 0x80
                                                          : (dat & 0x01) << 7);
                dat = __spi_bit_order == MSBFIRST ? dat << 1 : dat >> 1;

                __spi_setSCK(1);
                __spi_setSCK(0);
            }

            break;
        case SPI_MODE1:
            __spi_setSCK(0);

            for (uint8_t i = 0; i < 8; i++) {
                __spi_setMOSI(__spi_bit_order == MSBFIRST ? dat & 0x80
                                                          : (dat & 0x01) << 7);

                dat = __spi_bit_order == MSBFIRST ? dat << 1 : dat >> 1;
                __spi_setSCK(1);

                rx_dat =
                    __spi_bit_order == MSBFIRST ? rx_dat << 1 : rx_dat >> 1;

                uint8_t miso_state = __spi_getMISO();
                rx_dat |=
                    __spi_bit_order == MSBFIRST ? miso_state : miso_state << 7;

                __spi_setSCK(0);
            }

            break;
        case SPI_MODE2:
            __spi_setSCK(1);

            for (uint8_t i = 0; i < 8; i++) {
                rx_dat =
                    __spi_bit_order == MSBFIRST ? rx_dat << 1 : rx_dat >> 1;

                uint8_t miso_state = __spi_getMISO();
                rx_dat |=
                    __spi_bit_order == MSBFIRST ? miso_state : miso_state << 7;

                __spi_setMOSI(__spi_bit_order == MSBFIRST ? dat & 0x80
                                                          : (dat & 0x01) << 7);

                dat = __spi_bit_order == MSBFIRST ? dat << 1 : dat >> 1;

                __spi_setSCK(0);
                __spi_setSCK(1);
            }

            break;
        case SPI_MODE3:
            __spi_setSCK(1);

            for (uint8_t i = 0; i < 8; i++) {
                __spi_setMOSI(__spi_bit_order == MSBFIRST ? dat & 0x80
                                                          : (dat & 0x01) << 7);

                dat = __spi_bit_order == MSBFIRST ? dat << 1 : dat >> 1;
                __spi_setSCK(0);

                rx_dat =
                    __spi_bit_order == MSBFIRST ? rx_dat << 1 : rx_dat >> 1;

                uint8_t miso_state = __spi_getMISO();
                rx_dat |=
                    __spi_bit_order == MSBFIRST ? miso_state : miso_state << 7;

                __spi_setSCK(1);
            }

            break;
    }

    return rx_dat;
}

void __spi_endTransaction() {
    ;
}
