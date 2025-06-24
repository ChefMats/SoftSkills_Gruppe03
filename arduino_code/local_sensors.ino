#include "DHT.h"

#define DHTPIN D4
#define DHTTYPE DHT11

#define MQ135PIN A0

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

float readCO2(){ // analog value, transformation to ppm is hard
  int adcValue = analogRead(MQ135PIN);

  return adcValue;
}