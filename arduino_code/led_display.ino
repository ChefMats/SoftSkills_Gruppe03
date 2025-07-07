#include <Adafruit_NeoPixel.h>

#define LED_PIN D1
#define NUMPIXELS 12
#define HALF_RING (NUMPIXELS / 2)

Adafruit_NeoPixel ring(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t CO2_COLOR;
uint32_t HUMIDITY_COLOR;

void initializeLeds() {
  ring.begin();
  ring.clear();
  ring.show();
  CO2_COLOR = ring.Color(100, 0, 0);      // Rot für CO2
  HUMIDITY_COLOR = ring.Color(0, 0, 100); // Blau für Luftfeuchtigkeit
}

void updateLeds(float co2, float humidity) {
  ring.clear();

  // CO₂ → LEDs 0–5
  int co2Leds = map((int)co2, 100, 500, 0, HALF_RING);
  co2Leds = constrain(co2Leds, 0, HALF_RING);
  for (int i = 0; i < co2Leds; i++) {
    ring.setPixelColor(i, CO2_COLOR);
  }

  // Luftfeuchtigkeit → LEDs 6–11
  int humLeds = map((int)humidity, 0, 100, 0, HALF_RING);
  humLeds = constrain(humLeds, 0, HALF_RING);
  for (int i = NUMPIXELS - 1; i >= NUMPIXELS - humLeds; i--) {
    ring.setPixelColor(i, HUMIDITY_COLOR);
  }

ring.show();
}