#ifndef __MODULE_TUNER_SI5351__H
#define __MODULE_TUNER_SI5351__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

#include "framework/wire.h"

#define SI5351_ADDRESS 0x60
#define SI5351_CRYSTAL_10PF 192

void SI5351Init(void);
void SI5351EnableOutputs(uint8_t enable);
void SI5351SetupRdiv(uint8_t output, uint8_t div);
void SI5351SetupPLL(uint8_t pll, uint8_t mult, uint32_t num, uint32_t denom);
void SI5351SetupMultiSynth(uint8_t output,
                           uint8_t pll,
                           uint32_t div,
                           uint32_t num,
                           uint32_t denom);
void SI5351SetRxFreq(uint32_t freq);

#endif