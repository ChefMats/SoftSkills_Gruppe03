#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BUTTON_PIN D2
bool buttonIsPressed = false;
double lastMillis = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  initializeLeds();
  initializeSensors();

  connectWiFi();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
  if (millis() - lastMillis >= 2000) {
    lastMillis = millis();
    Blynk.run();
    fetchWeatherData();
    printIndoorData();
    ledsetup();
  }

  // Button-Status
  if (digitalRead(BUTTON_PIN) == LOW && !buttonIsPressed){
    buttonIsPressed = true;
    Serial.println("Button pressed!");
    delay(200);
  }
  if (digitalRead(BUTTON_PIN) == HIGH && buttonIsPressed){
    buttonIsPressed = false;
    Serial.println("Button released!");
    delay(200);
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