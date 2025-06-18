#include "config.h"
#include <BlynkSimpleEsp8266.h>  

//draußen daten
void notifyOutsideData(float tempC, int humidity, const char* weatherDesc) {
  if (humidity > 80 && tempC < 20) {
    Blynk.logEvent("lueften", "Draußen ist es kühl & feucht – besser nicht lüften.");
  } else if (humidity < 60 && tempC < 24) {
    Blynk.logEvent("lueften", "Gute Bedingungen zum Lüften!");
  } else {
    Serial.println("Keine Benachrichtigung notwendig.");
  }
}

// Indoor daten beispiel (später)
void notifyIndoorData(int co2ppm, int humidityInnen) {
  if (co2ppm > 1000) {
    Blynk.logEvent("co2_warnung", "CO₂-Wert ist zu hoch! Bitte lüften.");
  }
}
