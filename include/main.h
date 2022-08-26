#pragma once
#include <Arduino.h>
#include <avr/interrupt.h>
#include <FastLED.h>
#define CIRCULAR_BUFFER_INT_SAFE
#define CIRCULAR_BUFFER_DEBUG
#include <Print.h>
#include <CircularBuffer.h>
// #include <Snooze.h>
#include "palettedemo.h"
#include "scratch.h"
#include "soundSensor.h"

#define QUEUE_LEN 8

#ifdef ARDUINO_ESP32_DEV
  #define BOARDLED 2
  #define SOUND_DO 0
#elif defined(ARDUINO_TEENSY41)
  #define BOARDLED 13
  #define SOUND_DO 41
#else 
  #define BOARDLED 13
  #define SOUND_DO 41
#endif

extern CRGB leds[];

#ifndef LED_STRIP_CONSTS
  #define LED_STRIP_CONSTS
  #define LED_PIN     5
  #define NUM_LEDS    22
  #define BRIGHTNESS  64
  #define LED_TYPE    WS2812B
  #define COLOR_ORDER GRB
  #define UPDATES_PER_SECOND 50
#endif