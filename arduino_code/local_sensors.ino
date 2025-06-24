#include "DHT.h"
#include <MQUnifiedsensor.h>

#define DHTPIN D4
#define DHTTYPE DHT11

#define MQ135PIN A0
#define Board "ESP8266"
#define Voltage_Resolution 3.3
#define ADC_Bit_Resolution 10
#define RatioMQ135CleanAir 3.6
#define CO2CalibrationValue 31.0
#define regressionMethod 1
#define aValue 110.47
#define bValue -2.862

DHT dht(DHTPIN, DHTTYPE);

MQUnifiedsensor MQ135(Board, Voltage_Resolution, ADC_Bit_Resolution, MQ135PIN, "MQ-135");

void initializeSensors(){
  dht.begin();

  MQ135.setRegressionMethod(regressionMethod);
  MQ135.setA(aValue);
  MQ135.setB(bValue);
  MQ135.init();
  
  MQ135.setR0(CO2CalibrationValue);
}

float readHumidity(){ // in %
  return dht.readHumidity();
}

float readTemperature(){ // in °C
  return dht.readTemperature();
}

float readCO2(){ // in ppm
  MQ135.update();
  return MQ135.readSensor();
}