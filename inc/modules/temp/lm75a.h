#ifndef __MODULE_TEMP_LM75A_H
#define __MODULE_TEMP_LM75A_H

#ifndef __SDCC
#error "This header file must be used for SDCC compiler !"
#endif

#include <stdint.h>

#include "framework/wire.h"

#define LM75A_ADDRESS 0x48

void LM75AInit(void);
float LM75ARead(void);

#endif
