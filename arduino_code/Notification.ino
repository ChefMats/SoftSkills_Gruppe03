#include "config.h"
#include <BlynkSimpleEsp8266.h>  

// draußen daten
void notifyOutsideData(float tempC, int humidity, const char* weatherDesc) {
  if (humidity > 80 && tempC < 20) {
    Blynk.logEvent("outsideluft0", "Draußen ist es kühl & feucht – besser nicht lüften.");
  } else if (humidity < 60 && tempC < 24) {
    Blynk.logEvent("outsideluft1", "Gute Bedingungen zum Lüften!");
  } else {
    Serial.println("Alles in Ordnung. Genieße deinen Tag!");
  }
}

// Indoor daten
void notifyIndoorData(float tempInnen, int humidityInnen, int co2ppm) {
  // Auf Virtual Pins schreiben
  Blynk.virtualWrite(V1, (int)tempInnen);
  Blynk.virtualWrite(V2, (int)humidityInnen);
  Blynk.virtualWrite(V3, (int)co2ppm);

  // CO₂-Warnung bei 500ppm
  if (co2ppm > 500) {
    Blynk.logEvent("co2_warnung", "CO₂-Wert ist zu hoch! Bitte lüften.");
  }
}
