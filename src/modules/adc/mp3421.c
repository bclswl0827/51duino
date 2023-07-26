#include "modules/adc/mcp3421.h"

void MCP3421Init(enum MCP3421_MODE mode,
                 enum MCP3421_PGA pga,
                 enum MCP3421_DATARATE datarate) {
    WireBegin();
    WireBeginTransmission(MCP3421_ADDRESS);
    WireWrite(0x80 | (mode << 4) | (datarate << 2) | pga);
    WireEndTransmission();
}

int16_t MCP3421Read(enum MCP3421_MODE mode,
                    enum MCP3421_PGA pga,
                    enum MCP3421_DATARATE datarate) {
    if (mode == MCP3421_MODE_SINGLE) {
        MCP3421Init(mode, pga, datarate);
    }

    WireRequestFrom(MCP3421_ADDRESS, 1);
    while (WireRead() & 0x80) {
        ;
    }

    WireRequestFrom(MCP3421_ADDRESS, 2);
    return (WireRead() << 8) | WireRead();
}

float MCP3421ToVoltage(enum MCP3421_DATARATE datarate) {
    switch (datarate) {
        case MCP3421_DATARATE_240:
            return MCP3421_VREF / 1024;
        case MCP3421_DATARATE_60:
            return MCP3421_VREF / 256;
        case MCP3421_DATARATE_15:
            return MCP3421_VREF / 64;
        case MCP3421_DATARATE_3_75:
            return MCP3421_VREF / 16;
        default:
            return 0;
    }
}
