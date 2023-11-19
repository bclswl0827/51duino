#include "framework/serial.h"

uint16_t __stream_timeout = 10000;

// Initialize serial port
void __serial_begin(uint32_t baud) {
    TMOD = 0x20;
    SCON = 0x50;
    TH1 = 256 - FOSC / 16 / 12 / baud;
    TL1 = TH1;
    PCON = 0x80;
    TR1 = 0x01;
    EA = 0x01;
    ES = 0x01;
}

// Disable serial port
void __serial_end() {
    // Disable serial interrupt
    EA = ES = 0;
}

// Set the serial timeout in milliseconds
void __serial_setTimeout(uint16_t t) {
    __stream_timeout = t;
}

// Clear the serial port
void __serial_flush() {
    while (!TI) {
        ;
    }

    // Clear interrupt flag
    TI = 0;
}

// Send a byte
void __serial_write(uint8_t ch) {
    // Disable serial interrupt
    ES = 0;

    // Send the character
    SBUF = ch;
    // Wait for data to be sent
    while (!TI) {
        ;
    }

    // Clear interrupt flag
    TI = 0;
    // Enable serial interrupt
    ES = !TI;
}

// Send a string
void __serial_print(uint8_t* str) {
    while (*str) {
        __serial_write(*str++);
    }
}

// Send a string and a newline
void __serial_println(uint8_t* str) {
    __serial_print(str);
    __serial_print("\r\n");
}

// Read a byte from the serial port
uint8_t __serial_read() {
    // Wait for data to be received until timeout
    for (uint16_t i = 0; i < __stream_timeout; i++) {
        if (RI) {
            break;
        }
    }

    // Clear the interrupt flag and return
    RI = 0;
    return SBUF;
}

// Find character in the serial stream until timeout
uint8_t __serial_find(uint8_t ch) {
    uint16_t t = __stream_timeout;

    while (t--) {
        if (__serial_read() == ch) {
            return 1;
        }
    }

    return 0;
}

// Read bytes from the serial port into a buffer
void __serial_readBytes(uint8_t* buf, uint8_t len) __reentrant {
    // Dump first byte in the buffer
    __serial_read();
    while (len--) {
        *buf++ = __serial_read();
    }
}

// Check if there is data available to read in the serial port
uint8_t __serial_available() {
    return RI;
}
