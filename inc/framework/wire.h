#ifndef __FRAMEWORK_WIRE__H
#define __FRAMEWORK_WIRE__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <reg52.h>
#include <stdint.h>

#include "framework/config.h"
#include "framework/delay.h"

// Continues transmission
#define WIRE_RESUME 0
// Start transmission
#define WIRE_START 1

void __wire_begin(void);
uint8_t __wire_read(void);
void __wire_write(uint8_t dat);
uint8_t __wire_endTransmission(void);
void __wire_beginTransmission(uint8_t addr);
uint8_t __wire_requestFrom(uint8_t addr, uint8_t len);

// Use macro to replace function call
#define Wire_begin() __wire_begin()
#define Wire_read() __wire_read()
#define Wire_write(dat) __wire_write(dat)
#define Wire_endTransmission() __wire_endTransmission()
#define Wire_requestFrom(addr, len) __wire_requestFrom(addr, len)
#define Wire_beginTransmission(addr) __wire_beginTransmission(addr)

// Create Wire object if WIRE_USE_CLASS is 1
#if defined(WIRE_USE_CLASS) && WIRE_USE_CLASS == 1
// Contains Wire related methods
static typedef struct {
    void (*begin)(void);
    uint8_t (*read)(void);
    void (*write)(uint8_t dat);
    uint8_t (*endTransmission)(void);
    void (*beginTransmission)(uint8_t addr);
    uint8_t (*requestFrom)(uint8_t addr, uint8_t len) __reentrant;
} wire_t;

// Export Wire object
wire_t Wire = {
    .begin = __wire_begin,
    .read = __wire_read,
    .write = __wire_write,
    .endTransmission = __wire_endTransmission,
    .beginTransmission = __wire_beginTransmission,
    .requestFrom = __wire_requestFrom,
};
#endif

#endif
