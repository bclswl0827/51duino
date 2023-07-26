#ifndef __MODULE_ADC_MCP3421_H
#define __MODULE_ADC_MCP3421_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

#include "framework/delay.h"
#include "framework/wire.h"

#define MCP3421_VREF 2.048
#define MCP3421_ADDRESS 0x68

enum MCP3421_MODE {
    MCP3421_MODE_SINGLE = 0,
    MCP3421_MODE_CONTINUE = 1,
};

enum MCP3421_DATARATE {
    MCP3421_DATARATE_240 = 0,
    MCP3421_DATARATE_60 = 1,
    MCP3421_DATARATE_15 = 2,
    MCP3421_DATARATE_3_75 = 3,
};

enum MCP3421_PGA {
    MCP3421_PGA_X1 = 0,
    MCP3421_PGA_X2 = 1,
    MCP3421_PGA_X4 = 2,
    MCP3421_PGA_X8 = 3,
};

void MCP3421Init(enum MCP3421_MODE mode,
                 enum MCP3421_PGA pga,
                 enum MCP3421_DATARATE datarate);
int16_t MCP3421Read(enum MCP3421_MODE mode,
                    enum MCP3421_PGA pga,
                    enum MCP3421_DATARATE datarate);
float MCP3421ToVoltage(enum MCP3421_DATARATE datarate);

#endif
