#ifndef __MODULE_OLED_SSD1306__H
#define __MODULE_OLED_SSD1306__H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

#include "framework/wire.h"
#include "modules/oled/font.h"

#define OLED_CMD 0         // 写命令
#define OLED_DATA 1        // 写数据
#define OLED_COLUMN 128    // OLED 屏幕列数
#define OLED_ADDRESS 0x3c  // OLED 屏幕地址

void SSD1306Init(void);
void SSD1306Enable(void);
void SSD1306Disable(void);
void SSD1306Clear(void);
void SSD1306Write(uint8_t x, uint8_t y, uint8_t c);
void SSD1306Print(uint8_t x, uint8_t y, uint8_t* buf);
void SSD1306Chinese(uint8_t offset, uint8_t y, uint8_t gap);

#endif
