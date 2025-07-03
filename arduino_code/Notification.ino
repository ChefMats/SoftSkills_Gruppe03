#include "config.h"
#include <BlynkSimpleEsp8266.h>


float readTemperature();
float readHumidity();
float readCO2();

void checkIndoorNotifications() {
  float tempinside = readTemperature();
  float humidityinside = readHumidity();
  float co2ppminside = readCO2();

  
//für widgets
  Blynk.virtualWrite(V1, tempinside);     
  Blynk.virtualWrite(V2, humidityinside); 
  Blynk.virtualWrite(V3, co2ppminside);


bool notificationSent = false;

if (co2ppminside > 1000) {
  Blynk.logEvent("co2_warnung", "CO₂-Wert ist zu hoch! Bitte lüften.");
  notificationSent = true;
}

if (humidityinside < 30) {
  Blynk.logEvent("trocken", "Luftfeuchtigkeit zu niedrig — evtl. Luftbefeuchter nutzen.");
  notificationSent = true;
}

if (humidityinside > 70) {
  Blynk.logEvent("feucht", "Luftfeuchtigkeit zu hoch — evtl. lüften.");
  notificationSent = true;
}

if (!notificationSent) {
  Serial.println("Keine Benachrichtigung für drinnen notwendig.");
}

//draußen daten
void notifyOutsideData(float tempC, int humidity, const char* weatherDesc) {
  if (humidity > 80 && tempC < 20) {
    Blynk.logEvent("lueften", "Draußen ist es kühl & feucht – besser nicht lüften.");
  } else if (humidity < 60 && tempC < 24) {
    Blynk.logEvent("lueften", "Gute Bedingungen zum Lüften!");
  } else {
    Serial.println("Keine Benachrichtigung für draußen notwendig.");
  }
}

