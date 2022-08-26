
#ifndef LED_STRIP_CONSTS
    #define LED_STRIP_CONSTS
    #define LED_PIN     5
    #define NUM_LEDS    22
    #define BRIGHTNESS  64
    #define LED_TYPE    WS2812B
    #define COLOR_ORDER GRB
    #define UPDATES_PER_SECOND 50
#endif

void setupDEMO();
void loopDEMO();
void FillLEDsFromPaletteColors(uint8_t colorIndex);
void ChangePalettePeriodically();
void SetupTotallyRandomPalette();
void SetupBlackAndWhiteStripedPalette();
void SetupPurpleAndGreenPalette();