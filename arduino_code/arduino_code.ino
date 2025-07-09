#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BUTTON_PIN D2

bool buttonIsPressed = false;
bool ledsEnabled = true;
unsigned long lastMillis = 0;
unsigned long lastAlertMillis = 0;
bool blynkEnabled = false;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  initializeLeds();
  initializeSensors();

  connectWiFi();


  if (strlen(BLYNK_AUTH_TOKEN) > 0) {
    Serial.println("Starte Blynk...");
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
    blynkEnabled = true;
  } else {
    Serial.println("Kein Blynk Token konfiguriert – Blynk deaktiviert.");
  }
}

void loop() {
  unsigned long now = millis();

  if (now - lastMillis >= 2000) {
    lastMillis = now;

    if (blynkEnabled) {
      Blynk.run();
    }

    fetchWeatherData();
    printIndoorData();

    ledsetup();
    initializeSpeaker();


    float temp = readTemperature();
    int humidity = (int)readHumidity();
    int co2 = (int)readCO2();


    if (blynkEnabled) {
      notifyIndoorData(temp, humidity, co2);
    }
  }

  // Button Status prüfen
  if (digitalRead(BUTTON_PIN) == LOW && !buttonIsPressed) {
    buttonIsPressed = true;

    ledsEnabled = !ledsEnabled;  // Umschalten

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

  // CO₂ Warnung
  float co2 = readCO2();
  if (co2 > 850 && (now - lastAlertMillis >= 5000)) {
    lastAlertMillis = now;
    Serial.println("CO₂ > 850ppm — Warnton!");
    playAlert(1000);
  }
}

void ledsetup() {
  if (!ledsEnabled) return;

  float co2 = readCO2();
  float humidity = readHumidity();

  Serial.print("CO₂: ");
  Serial.print(co2);
  Serial.print(" ppm | Feuchtigkeit: ");
  Serial.print(humidity);
  Serial.println(" %");

  updateLeds(co2, humidity);
}
