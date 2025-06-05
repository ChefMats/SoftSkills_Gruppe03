#include <Adafruit_NeoPixel.h>

#define PIN D1            // D1 pin on Wemos D1 Mini
#define NUMPIXELS 12      // 12 LEDs in the NeoPixel ring

Adafruit_NeoPixel ring(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  ring.begin();           // Initialize NeoPixel
  ring.show();            // Turn off all LEDs initially
}

void loop() {
  // Loop through each LED and light it red
  for (int i = 0; i < NUMPIXELS; i++) {
    ring.clear();                   // Clear previous state
    ring.setPixelColor(i, ring.Color(255, 0, 0)); // Red
    ring.show();                    // Update LEDs
    delay(100);                     // Wait a bit
  }

  // Rainbow animation
  for (int j = 0; j < 256; j++) {
    for (int i = 0; i < NUMPIXELS; i++) {
      ring.setPixelColor(i, ring.ColorHSV((i * 65536 / NUMPIXELS + j * 256) % 65536));
    }
    ring.show();
    delay(20);
  }
}
