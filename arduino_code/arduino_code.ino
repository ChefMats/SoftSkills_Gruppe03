#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

void setup() {
  Serial.begin(115200);
  connectWiFi();
  initializeLeds();
  displayCO2(2);
  displayHumidity(6);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
  Blynk.run();
  fetchWeatherData();
  delay(1000);
}