#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

double lastMillis = 0;
double lastAlertMillis = 0;

void setup() {
  Serial.begin(115200);

  initializeLeds();
  initializeSensors();
  initializeSpeaker();

  connectWiFi();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
  unsigned long now = millis();

  if (now - lastMillis >= 2000) {
    lastMillis = now;
    Blynk.run();
    fetchWeatherData();
    printIndoorData();
    ledsetup();
  }

  float co2 = readCO2();
  if (co2 > 850 && (now - lastAlertMillis >= 5000)) {
    lastAlertMillis = now;
    Serial.println("CO₂ > 850ppm — Warnton!");
    playAlert(1000);
  }
}

void ledsetup() {
  float co2 = readCO2();
  float humidity = readHumidity();

  Serial.print("CO2: ");
  Serial.print(co2);
  Serial.print(" ppm | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  updateLeds(co2, humidity);
}
