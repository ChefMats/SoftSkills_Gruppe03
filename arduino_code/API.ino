#include <HTTPClient.h>
#include <ArduinoJson.h>


void fetchWeatherData() {
  HTTPClient http;
  http.begin("http://wttr.in/Oldenburg?format=j1");  // !!! Hier deinen Stadtnamen !!!





  int httpCode = http.GET();

  if (httpCode == 200) {
    String payload = http.getString();

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
    } else {
      Serial.println("JSON Fehler");
    }
  } else {
    Serial.print("HTTP Fehler: ");
    Serial.println(httpCode);
  }

  http.end();
}
