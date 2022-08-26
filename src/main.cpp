#include "main.h"

CRGB leds[NUM_LEDS];
CRGB leds_status[NUM_LEDS];
uint8_t led_toggle = 0;
uint32_t last_time = 0;
uint32_t last_time_clap = 0;
// uint32_t time_arr[] = {0, 0, 0, 0, 0, 0, 0, 0};
Print *pp;
CircularBuffer<uint16_t, QUEUE_LEN> time_arr;
IntervalTimer wakeCycle;
// SnoozeTimer cycle;
// SnoozeBlock config(cycle);

void blinky() {
  digitalWrite(BOARDLED, HIGH);
  delay(1000);
  digitalWrite(BOARDLED, LOW);
  delay(1000);
}

void flip_leds_no_debounceISR() {
  led_toggle = !led_toggle;
    if (led_toggle) {
      fill_solid(leds, NUM_LEDS, CRGB::White);
    } else {
      fill_solid(leds, NUM_LEDS, CRGB::Black);
    }
}

void flip_leds() {
  if (millis()-last_time > 250) {
    led_toggle = !led_toggle;
    if (led_toggle) {
      *leds = *leds_status;
      // fill_solid(leds, NUM_LEDS, CRGB::White);
    } else {
      *leds_status = *leds;
      FastLED.clear(leds);
    }
    last_time = millis();
  } 
}

void flip_ledsISR() {
  if (millis()-last_time > 250) {
    led_toggle = !led_toggle;
    if (led_toggle) {
      fill_solid(leds, NUM_LEDS, CRGB::White);
    } else {
      FastLED.clear(leds);
    }
    last_time = millis();
  } 
}

void pushDeltaTimeISR() {
  uint32_t deltat = millis() - last_time_clap;
  if (deltat > 50) { // Software debounce, later, add an RC LPF
    last_time_clap += deltat;
    if (deltat > 2000) {  // Clear array if more than 2s
      // memset(time_arr, 0, sizeof(time_arr));
      time_arr.clear();
    } else {
      time_arr.push(deltat);
    }
  }
}

void WIP() {
  if (millis() - last_time > 1000) {
    last_time = millis();
    Serial.print("awake\n");
    if (millis() - last_time_clap > 1000) { // Assume we wait 1s to "send" command && max delay of 2s
    time_arr.debug(pp);
      Serial.print("In one\n");
      if (time_arr.size() == 1) {
        if (time_arr.first() >= 100 || time_arr.first() <= 200) { // if two fast claps
          Serial.print("two fast clap\n");
          flip_leds();
        } else if (time_arr.size() == 2) {
          if ((time_arr[0] >= 100 || time_arr[0] <= 200) && (time_arr[1] >= 100 || time_arr[1] <= 200)) // if three fast claps
          {
            Serial.print("Three fast clap\n");
            if (leds[0].red) {
              fill_solid(leds, NUM_LEDS, CRGB::Green);
            } else if (leds[0].green) {
              fill_solid(leds, NUM_LEDS, CRGB::Blue);
            } else if (leds[0].blue) {
              fill_solid(leds, NUM_LEDS, CRGB::Red);
            } else {
              fill_solid(leds, NUM_LEDS, CRGB::Yellow);
            }
          } else
          if ((time_arr[0] >= 100 || time_arr[0] <= 200) && (time_arr[1] > 200 || time_arr[1] <= 500)) {
            Serial.print("2 fast 1 slow clap\n");
            fill_solid(leds, NUM_LEDS, CRGB::White);
          }
        }
      }
    }
    FastLED.show();
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BOARDLED, OUTPUT);
  pinMode(SOUND_DO, INPUT);
  attachInterrupt(SOUND_DO, pushDeltaTimeISR, HIGH);
  // attachInterrupt(SOUND_DO, flip_leds, HIGH);
  setupDEMO();
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  // cycle.setTimer(1);
  // wakeCycle.begin(func, 250000);
  Serial.println("Setup Complete");
}

void loop() {
  // Snooze.idle(config);
  // WIP();

  
}


// ISR (TIMER1_OVF_vect){

// }
