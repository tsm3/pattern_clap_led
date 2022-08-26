#include "main.h"

uint8_t readDigitalSound() {
    uint8_t val = digitalRead(SOUND_DO); // Do I actually need this temp var? probably not?
    return val;
}

uint8_t readDigitalSound(uint8_t *boolAddr) {
    *boolAddr = digitalRead(SOUND_DO);
    return 0;
}

