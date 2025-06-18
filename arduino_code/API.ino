#include "config.h"  
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>  
#include <ArduinoJson.h>  
     
void fetchWeatherData() {
  HTTPClient http;
  WiFiClientSecure client;
  client.setInsecure();
  http.begin(client, apiURL);
  http.addHeader("User-Agent", "Mozilla/5.0");

  int httpCode = http.GET();

  if (httpCode == 200) {
    String payload = http.getString();

    Serial.println(payload);

    StaticJsonDocument<2048> doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (!error) {
      float tempC = doc["current_condition"][0]["temp_C"].as<float>();
      int humidity = doc["current_condition"][0]["humidity"].as<int>();
      const char* weatherDesc = doc["current_condition"][0]["weatherDesc"][0]["value"];

      Serial.print("Temperatur: ");
      Serial.print(tempC);
      Serial.print(" °C | Feuchtigkeit: ");
      Serial.print(humidity);
      Serial.print(" % ");
      Serial.println(weatherDesc);
      notifyOutsideData(tempC, humidity, weatherDesc);
    } else {
      Serial.println("JSON Fehler");
    }
  } else {
    Serial.print("HTTP Fehler: ");
    Serial.println(httpCode);
  }

  http.end();
}
