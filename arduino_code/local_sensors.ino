#include "DHT.h"

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void initializeSensors(){
  dht.begin();
}

float readHumidity(){ // in %
  return dht.readHumidity();
}

float readTemperature(){ // in °C
  return dht.readTemperature();
}

// TODO: add CO2 sensor