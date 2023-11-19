#ifndef __FRAMEWORK_CONFIG__H
#define __FRAMEWORK_CONFIG__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <reg52.h>

// Define built-in LED pin
#define LED_BUILTIN 13
// Define oscillator frequency in Hz
#define FOSC 11059200L
// Define I2C SDA pin
#define SDA P20
// Define I2C SCL pin
#define SCL P21
// Define SPI SCK pin
#define SCK P10
// Define SPI MOSI pin
#define MOSI P11
// Define SPI MISO pin
#define MISO P12
// Chip select pin
#define SS P13

// Define whether to use class
#define SERIAL_USE_CLASS 0
#define SPI_USE_CLASS 0
#define WIRE_USE_CLASS 0

// Define bit order
#define LSBFIRST 0
#define MSBFIRST 1

#endif
