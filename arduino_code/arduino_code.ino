#include "config.h"    
#include <WiFi.h>                
#include <BlynkSimpleEsp32.h>    
           


void setup() {
  Serial.begin(115200);
  initializeLeds();
  displayCO2(2);
  displayHumidity(6);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

}

void loop() {
  Blynk.run(); 
}