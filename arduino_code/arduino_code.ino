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
  if (millis() - lastMillis >= 1000){
    lastMillis = millis();
    Blynk.run();
    fetchWeatherData();
  }

  if (digitalRead(BUTTON_PIN) == LOW && !buttonIsPressed){
    buttonIsPressed = true;
    Serial.println("Button pressed!");
    delay(200); // delay for debouncing
  }
  if (digitalRead(BUTTON_PIN) == HIGH && buttonIsPressed){
    buttonIsPressed = false;
    Serial.println("Button not pressed anymore!");
    delay(200); // delay for debouncing
  }
}