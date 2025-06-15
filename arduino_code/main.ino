#include "wifi.ino"
#include "api.ino"
#include "notification.ino"


void setup() {
  Serial.begin(115200);
  connectWiFi();          
  fetchWeatherData();   
}

