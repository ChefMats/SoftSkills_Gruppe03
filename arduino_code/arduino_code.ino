#include <Adafruit_NeoPixel.h>

#define PIN D1
#define NUMPIXELS 12

Adafruit_NeoPixel ring(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const uint32_t CO2_COLOR = ring.Color(100, 0, 0);
const uint32_t HUMIDITY_COLOR = ring.Color(0, 0, 100);

void setup() {
  ring.begin();
  ring.show(); // turn all leds off initially

  displayCO2(3);
  displayHumidity(5);
}

void loop() {
  
}

void displayCO2 (double value){
  int ledsToShow = value; // TODO: translate here from value (CO2 concentration) to leds (how many should turn on)

  if (ledsToShow > NUMPIXELS / 2) {
    ledsToShow = NUMPIXELS / 2;
  }
  
  for (int i = 0; i < ledsToShow; i++) {
    ring.setPixelColor(i, CO2_COLOR);
  }

  ring.show();
}

void displayHumidity (double value){
  int ledsToShow = value; // TODO: translate here from value (humidity) to leds (how many should turn on)

  if (ledsToShow > NUMPIXELS / 2) {
    ledsToShow = NUMPIXELS / 2;
  }
  
  for (int i = NUMPIXELS - 1; i > NUMPIXELS - ledsToShow - 1; i--) {
    ring.setPixelColor(i, HUMIDITY_COLOR);
  }

  ring.show();
}