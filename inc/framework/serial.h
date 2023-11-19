#ifndef __FRAMEWORK_STREAM__H
#define __FRAMEWORK_STREAM__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <reg52.h>
#include <stdint.h>
#include "framework/config.h"

void __serial_end(void);
void __serial_flush(void);
uint8_t __serial_read(void);
void __serial_write(uint8_t ch);
uint8_t __serial_available(void);
void __serial_print(uint8_t* str);
uint8_t __serial_find(uint8_t ch);
void __serial_println(uint8_t* str);
void __serial_begin(uint32_t baud);
void __serial_setTimeout(uint16_t t);
void __serial_readBytes(uint8_t* buf, uint8_t len) __reentrant;

// Use macro to replace function call
#define Serial_end() __serial_end()
#define Serial_read() __serial_read()
#define Serial_find(ch) __serial_find(ch)
#define Serial_begin(baud) __serial_begin(baud)
#define Serial_write(ch) __serial_write(ch)
#define Serial_print(str) __serial_print(str)
#define Serial_flush() __serial_flush()
#define Serial_println(str) __serial_println(str)
#define Serial_available() __serial_available()
#define Serial_readBytes(buf, len) __serial_readBytes(buf, len)
#define Serial_setTimeout(t) __serial_setTimeout(t)

// Create Serial object if SERIAL_USE_CLASS is 1
#if defined(SERIAL_USE_CLASS) && SERIAL_USE_CLASS == 1
// Contains Serial related methods
static typedef struct {
    void (*end)(void);
    void (*flush)(void);
    uint8_t (*read)(void);
    void (*write)(uint8_t ch);
    uint8_t (*available)(void);
    void (*print)(uint8_t* str);
    uint8_t (*find)(uint8_t ch);
    void (*println)(uint8_t* str);
    void (*begin)(uint32_t baud);
    void (*setTimeout)(uint16_t t);
    void(readBytes)(uint8_t* buf, uint8_t len) __reentrant;
} serial_t;

// Export Serial object
serial_t Serial = {
    .end = __serial_end,
    .read = __serial_read,
    .find = __serial_find,
    .begin = __serial_begin,
    .write = __serial_write,
    .print = __serial_print,
    .flush = __serial_flush,
    .println = __serial_println,
    .available = __serial_available,
    .readBytes = __serial_readBytes,
    .setTimeout = __serial_setTimeout,
};
#endif

#endif
