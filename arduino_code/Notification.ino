#include "config.h"
#include <BlynkSimpleEsp8266.h>  

// draußen daten
void notifyOutsideData(float tempC, int humidity, const char* weatherDesc) {
  if (humidity > 80 && tempC < 20) {
    Blynk.logEvent("lueften", "Draußen ist es kühl & feucht – besser nicht lüften.");
  } else if (humidity < 60 && tempC < 24) {
    Blynk.logEvent("lueften", "Gute Bedingungen zum Lüften!");
  } else {
    Serial.println("Keine Benachrichtigung notwendig.");
  }
}

// Indoor daten
void notifyIndoorData(float tempInnen, int humidityInnen, int co2ppm) {
  Blynk.virtualWrite(V1, (int)tempInnen);
  Blynk.virtualWrite(V2, (int)humidityInnen);
  Blynk.virtualWrite(V3, (int)co2ppm);

  // LogEvents für jeden Wert
  Blynk.logEvent("tempinside", String("Temperatur innen: ") + String(tempInnen) + " °C");
  Blynk.logEvent("humidityinside", String("Luftfeuchtigkeit innen: ") + String(humidityInnen) + " %");
  Blynk.logEvent("co2ppminside", String("CO₂ innen: ") + String(co2ppm) + " ppm");

  // zusätzliche CO₂-Warnung
  if (co2ppm > 1000) {
    Blynk.logEvent("co2_warnung", "CO₂-Wert ist zu hoch! Bitte lüften.");
  }
}
