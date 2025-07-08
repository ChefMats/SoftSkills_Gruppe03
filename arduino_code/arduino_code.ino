#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BUTTON_PIN D2

bool buttonIsPressed = false;
bool ledsEnabled = true;  // LED-Ring anfangs an
double lastMillis = 0;
double lastAlertMillis = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  initializeLeds();
  initializeSensors();

  connectWiFi();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
  unsigned long now = millis();

  if (millis() - lastMillis >= 2000) {
    lastMillis = millis();
    Blynk.run();
    fetchWeatherData();
    printIndoorData();
    ledsetup();
    initializeSpeaker();
  }

  // Button-Status prüfen & toggeln
  if (digitalRead(BUTTON_PIN) == LOW && !buttonIsPressed) {
    buttonIsPressed = true;

    ledsEnabled = !ledsEnabled;  // umschalten

    if (ledsEnabled) {
      Serial.println("LED-Ring eingeschaltet.");
    } else {
      Serial.println("LED-Ring ausgeschaltet.");
      turnOffLeds();  // LEDs sofort aus
    }

    delay(200);  // debounce
  }

  if (digitalRead(BUTTON_PIN) == HIGH && buttonIsPressed) {
    buttonIsPressed = false;
    delay(200);  // debounce
  }
  
  float co2 = readCO2();
  if (co2 > 850 && (now - lastAlertMillis >= 5000)) {
    lastAlertMillis = now;
    Serial.println("CO₂ > 850ppm — Warnton!");
    playAlert(1000);
  }

}

void ledsetup() {
  if (!ledsEnabled) return;  // wenn LEDs aus, nichts tun

  float co2 = readCO2();
  float humidity = readHumidity();

  Serial.print("CO2: ");
  Serial.print(co2);
  Serial.print(" ppm | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  updateLeds(co2, humidity);
}