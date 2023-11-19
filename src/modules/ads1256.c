#include "modules/ads1256.h"

void ADS1256Wait() {
    while (ADS1256_DRDY_PIN) {
        ;
    }
}

void ADS1256Select() {
    SS = 0;
}

void ADS1256Deselect() {
    SS = 1;
}

uint8_t ADS1256ReadRegister(uint8_t reg) {
    ADS1256Wait();
    SPI_beginTransaction(SPISettings(SPEED, MSBFIRST, SPI_MODE1));
    // Select chip
    ADS1256Select();
    // 0x10 = RREG
    SPI_transfer(DEVICE_COMMAND_RREG | reg);
    SPI_transfer(DEVICE_COMMAND_WAKEUP);
    // Get register value
    uint8_t result = SPI_transfer(0xFF);
    // Deselect chip
    ADS1256Deselect();
    SPI_endTransaction();

    return result;
}

void ADS1256WriteRegister(uint8_t reg, uint8_t value) {
    ADS1256Wait();
    SPI_beginTransaction(SPISettings(SPEED, MSBFIRST, SPI_MODE1));
    // Select chip
    ADS1256Select();
    // 0x50 = WREG
    SPI_transfer(DEVICE_COMMAND_WREG | reg);
    SPI_transfer(DEVICE_COMMAND_WAKEUP);
    SPI_transfer(value);
    // Deselect chip
    ADS1256Deselect();
    SPI_endTransaction();
}

void ADS1256Begin() {
    // Hard reset ADS1256
    ADS1256_RST_PIN = 0;
    delay(50);
    ADS1256_RST_PIN = 1;
    delay(50);
    // Initialize SPI
    SPI_begin();
    // Enable calibration
    ADS1256WriteRegister(ADC_REGISTER_STATUS, 0x04);
}

void ADS1256Reset() {
    SPI_beginTransaction(SPISettings(SPEED, MSBFIRST, SPI_MODE1));
    // Select chip
    ADS1256Select();
    // Send reset command
    SPI_transfer(DEVICE_COMMAND_RESET);
    // Wait for reset to complete
    delay(2);
    // Issue SDATAC
    SPI_transfer(DEVICE_COMMAND_SDATAC);
    // Deselect chip
    ADS1256Deselect();
    SPI_endTransaction();
}

void ADS1256SetChannel(AnalogInputChannel channel) {
    ADS1256WriteRegister(ADC_REGISTER_MUX,
                         (channel << 4) | ANALOG_INPUT_AINCOM);
}

AnalogInputChannel ADS1256GetChannel() {
    return (AnalogInputChannel)(ADS1256ReadRegister(ADC_REGISTER_MUX) >> 4);
}

void ADS1256SetGain(GainRate gain) {
    ADS1256WriteRegister(ADC_REGISTER_ADCON, gain & 0x07);
}

GainRate ADS1256GetGain() {
    return (GainRate)(ADS1256ReadRegister(ADC_REGISTER_ADCON) & 0x07);
}

void ADS1256SetMode(AdcMode mode) {
    SPI_beginTransaction(SPISettings(SPEED, MSBFIRST, SPI_MODE1));
    // Select chip
    ADS1256Select();
    if (mode != ADC_MODE_CONTINUOUS) {
        // Issue SDATAC command
        SPI_transfer(DEVICE_COMMAND_SDATAC);
    }
    // Issue RDATAC command
    SPI_transfer(DEVICE_COMMAND_RDATAC);
    // Deselect chip
    ADS1256Deselect();
    SPI_endTransaction();
}

void ADS1256SetSample(SampleRateSPS rate) {
    ADS1256WriteRegister(ADC_REGISTER_DRATE, rate);
}

SampleRateSPS ADS1256GetSample() {
    return (SampleRateSPS)ADS1256ReadRegister(ADC_REGISTER_DRATE);
}

void ADS1256SetStatus(uint8_t buffer, uint8_t calibration) {
    ADS1256WriteRegister(ADC_REGISTER_STATUS, (buffer << 1) | calibration << 2);
}

void ADS1256GetStatus(uint8_t* buffer, uint8_t* calibration) {
    uint8_t status = ADS1256ReadRegister(ADC_REGISTER_STATUS);
    *buffer = (status >> 1) & 0x01;
    *calibration = (status >> 2) & 0x01;
}

float ADS1256ToVoltage(int32_t value) {
    // if the 24th bit (sign) is not 0, the number is negative
    if (value >> 23) {
        // conversion for the negative sign "mirroring" around zero
        value -= 16777216;
    }

    // 2.5 = Vref; 8388607 = 2^{23} - 1
    float voltage = ((2 * VREF) / 8388607) * value;
    return voltage;
}

// One Shot single channel mode, use with setChannel()
int32_t ADS1256GetSingleOneShot() {
    ADS1256Wait();
    SPI_beginTransaction(SPISettings(SPEED, MSBFIRST, SPI_MODE1));

    // CS must stay LOW during the entire
    ADS1256Select();
    // Issue RDATA command
    SPI_transfer(DEVICE_COMMAND_RDATA);

    // Get the 24-bit result
    int32_t result = (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC) << 16 |
                     (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC) << 8 |
                     (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC);

    // Deselect the chip
    ADS1256Deselect();
    SPI_endTransaction();

    return result;
}

// Continuous resding mode (i.e. AIN0+COM)
int32_t ADS1256GetSingleContinuous() {
    ADS1256Wait();
    SPI_beginTransaction(SPISettings(SPEED, MSBFIRST, SPI_MODE1));

    // CS must stay LOW during the entire
    ADS1256Select();

    // Get the 24-bit result
    int32_t result = (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC) << 16 |
                     (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC) << 8 |
                     (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC);

    // Deselect the chip
    ADS1256Deselect();
    SPI_endTransaction();

    return result;
}

// Differential mode, also apply to single channel
int32_t ADS1256GetDifferential(AnalogInputChannel positiveCh,
                               AnalogInputChannel negativeCh) {
    ADS1256Wait();
    SPI_beginTransaction(SPISettings(SPEED, MSBFIRST, SPI_MODE1));

    // CS must stay LOW during the entire
    ADS1256Select();
    SPI_transfer(DEVICE_COMMAND_WREG | ADC_REGISTER_MUX);
    SPI_transfer(0x00);

    // Write the positive and negative channels to MUX
    SPI_transfer((positiveCh << 4) | negativeCh);

    // Request a conversion
    SPI_transfer(DEVICE_COMMAND_SYNC);
    SPI_transfer(DEVICE_COMMAND_WAKEUP);
    SPI_transfer(DEVICE_COMMAND_RDATA);

    // Get the 24-bit result
    int32_t result = (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC) << 16 |
                     (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC) << 8 |
                     (int32_t)SPI_transfer(DEVICE_COMMAND_SDATAC);

    // Deselect the chip
    ADS1256Deselect();
    SPI_endTransaction();

    return result;
}
