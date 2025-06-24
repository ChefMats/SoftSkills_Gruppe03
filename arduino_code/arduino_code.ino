#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

void setup() {
  Serial.begin(115200);
  //connectWiFi();

  initializeLeds();

  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
  //Blynk.run();

  //fetchWeatherData();
  
  readCO2();

  delay(1000);
}