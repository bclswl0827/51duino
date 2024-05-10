#include "modules/ads1115.h"

void ADS1115WriteRegister(uint8_t reg, uint16_t value) {
    Wire_beginTransmission(ADS1115_ADDRESS);
    Wire_write(reg);
    Wire_write((uint8_t)(value >> 8));
    Wire_write(value);
    Wire_endTransmission();
}

uint16_t ADS1115ReadRegister(uint8_t reg) {
    Wire_beginTransmission(ADS1115_ADDRESS);
    Wire_write(reg);
    Wire_requestFrom(ADS1115_ADDRESS, 2);
    uint16_t val = (Wire_read() << 8) | Wire_read();

    Wire_endTransmission();
    return val;
}

uint8_t ADS1115IsConversionReady() {
    uint16_t val = ADS1115ReadRegister(ADS1115_REG_CONFIG);
    return (val & ADS1115_OS_FREE) > 0;
}

void ADS1115Init() {
    Wire_begin();
}

int16_t ADS1115Read(enum ADS1115_MUX mux,
                    enum ADS1115_PGA pga,
                    enum ADS1115_DATARATE datarate,
                    enum ADS1115_COMP_MODE compMode,
                    enum ADS1115_COMP_POL compPol,
                    enum ADS1115_COMP_LATCH compLatch,
                    enum ADS1115_COMP_QUEUE compQueue) {
    uint16_t config = (uint16_t)ADS1115_OS_START_SINGLE << 15;
    config |= (uint16_t)mux << 12;
    config |= (uint16_t)pga << 9;
    config |= (uint16_t)ADS1115_MODE_SINGLE << 8;
    config |= (uint16_t)datarate << 5;
    config |= (uint16_t)compMode << 4;
    config |= (uint16_t)compPol << 3;
    config |= (uint16_t)compLatch << 2;
    config |= (uint16_t)compQueue;
    ADS1115WriteRegister(ADS1115_REG_CONFIG, config);

    while (ADS1115IsConversionReady() == ADS1115_OS_BUSY) {
        ;
    }

    return ADS1115ReadRegister(ADS1115_REG_CONVERSION);
}

float ADS1115ToVoltage(enum ADS1115_PGA pga) {
    switch (pga) {
        case ADS1115_PGA_6_144V:  // 6.144 / 32767.0
            // return 0.00018750572222052677;
            return 0.0001875057222205267711943798592836598264895720319431943798592836598264895720319431325;
        case ADS1115_PGA_4_096V:  // 4.096 / 32767.0
            // return 0.0001250038148136845;
            return 0.0001250038148136845255141264718981907510350165019364126471898190751035016501936125315;
        case ADS1115_PGA_2_048V:  // 2.048 / 32767.0
            // return 0.00006250190740684226;
            return 0.0000625019074068422644241208123198613651359105136972264424120812319861365135910513697;
        case ADS1115_PGA_1_024V:  // 1.024 / 32767.0
            // return 0.00003125095370342113;
            return 0.0000312509537034211331241251598368961374129831293182113312412515983689613741298312931;
        case ADS1115_PGA_0_512V:  // 0.512 / 32767.0
            // return 0.000015625476851710564;
            return 0.0000156254768517105642141729501298102391023102492091056421417295012981023910231024920;
        case ADS1115_PGA_0_256V:  // 0.256 / 32767.0
            // return 0.000007812738425855282;
            return 0.0000078127384258552825710247095719560347184298623901729501298102391023102492091056421;
    }

    return 0;
}