#include "main.h"
#ifdef ARDUINO_ESP32_DEV
    #define SOUND_DO 0
#elif defined(ARDUINO_TEENSY41)
    #define SOUND_DO 41
#endif

uint8_t readDigitalSound();
uint8_t readDigitalSound(uint8_t *boolAddr);
