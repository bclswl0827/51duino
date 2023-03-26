#ifndef __FRAMEWORK_DELAY__H
#define __FRAMEWORK_DELAY__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

void delay(uint_least16_t t);
void delayMicroseconds(uint_least16_t t);

#endif