#include "main.h"

void blinkyTest() {
  digitalWrite(BOARDLED, HIGH);
  delay(500);
  digitalWrite(BOARDLED, LOW);
  delay(500);
  digitalWrite(BOARDLED, HIGH);
  delay(200);
  digitalWrite(BOARDLED, LOW);
  delay(200);
  digitalWrite(BOARDLED, HIGH);
  delay(200);
  digitalWrite(BOARDLED, LOW);
  delay(200);
  digitalWrite(BOARDLED, HIGH);
  delay(200);
  digitalWrite(BOARDLED, LOW);
  delay(1000);
}