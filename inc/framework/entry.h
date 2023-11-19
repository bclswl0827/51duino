#ifndef __FRAMEWORK_ENTRY__H
#define __FRAMEWORK_ENTRY__H

#include <reg52.h>

void setup(void);
void loop(void);

void main() {
    setup();
    while (1) {
        loop();
    }
}

#endif
