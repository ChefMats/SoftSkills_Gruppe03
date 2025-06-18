#include "config.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>


void fetchWeatherData() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Nicht mit WiFi verbunden – Wetterdaten werden nicht abgerufen.");
    return;
  }

  String url = "http://api.openweathermap.org/data/2.5/weather?q=" + String(city) + "," + String(country_code)
               + "&appid=" + String(owm_api_key) + "&units=metric&lang=de";

  HTTPClient http;
  http.begin(url); 

  int httpCode = http.GET();

  if (httpCode == 200) {
    String payload = http.getString();

    StaticJsonDocument<2048> doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (!error) {
      float tempC = doc["main"]["temp"];
      int humidity = doc["main"]["humidity"];
      const char* weatherDesc = doc["weather"][0]["description"];

      Serial.print("Temperatur: ");
      Serial.print(tempC);
      Serial.print(" °C | Feuchtigkeit: ");
      Serial.print(humidity);
      Serial.print(" % | Wetter: ");
      Serial.println(weatherDesc);

      notifyOutsideData(tempC, humidity, weatherDesc);  // Deine eigene Benachrichtigung
    } else {
      Serial.println("JSON Fehler");
    }
  } else {
    Serial.print("HTTP Fehler: ");
    Serial.println(httpCode);
  }

  http.end();
}
