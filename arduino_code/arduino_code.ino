#include "wifi.ino"
#include "api.ino"
#include "notification.ino"


void setup() {
  initializeLeds();
  displayCO2(2);
  displayHumidity(6);
  connectWiFi();          
  fetchWeatherData();   
}

void loop() {
  
}