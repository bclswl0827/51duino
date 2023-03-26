#ifndef __FRAMEWORK_STREAM__H
#define __FRAMEWORK_STREAM__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <config.h>
#include <reg52.h>
#include <stdint.h>

#ifdef USE_STDIO
#include <stdio.h>
#endif

void SerialBegin(uint_least16_t b);
void SerialEnd();
void SerialSetTimeout(uint_least16_t t);
void SerialFlush();
void SerialWrite(uint_least8_t c);
void SerialPrint(uint_least8_t* s);
void SerialPrintln(uint_least8_t* s);
uint_least8_t SerialRead();
uint_least8_t SerialFind(uint_least8_t c);
void SerialReadBytes(uint_least8_t* buf, uint_least8_t length) __reentrant;
uint_least8_t SerialAvailable();
#ifdef USE_STDIO
uint_least8_t putchar(uint_least8_t c);
#endif

#endif