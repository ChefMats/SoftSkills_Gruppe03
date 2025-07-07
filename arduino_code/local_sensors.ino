#include "DHT.h" 
#include <MQUnifiedsensor.h>

#define DHT_PIN D4
#define DHT_TYPE DHT11

#define MQ135PIN A0
#define BOARD "ESP8266"
#define VOLTAGE_RESOLUTION 3.3
#define ADC_BIT_RESOLUTION 10
#define CO2CalibrationValue 31.0
#define REGRESSION_METHOD 1
#define A_VALUE 110.47
#define B_VALUE -2.862

DHT dht(DHT_PIN, DHT_TYPE);
MQUnifiedsensor MQ135(BOARD, VOLTAGE_RESOLUTION, ADC_BIT_RESOLUTION, MQ135PIN, "MQ-135");

void initializeSensors() {
  dht.begin();

  MQ135.setRegressionMethod(REGRESSION_METHOD);
  MQ135.setA(A_VALUE);
  MQ135.setB(B_VALUE);
  MQ135.init();

  MQ135.setR0(CO2CalibrationValue);
}

float readHumidity() {
  return dht.readHumidity();
}

float readTemperature() {
  return dht.readTemperature();
}

float readCO2() {
  MQ135.update();
  return MQ135.readSensor();
}

void printIndoorData() {
  float humidity = readHumidity();
  float temperature = readTemperature();
  float co2 = readCO2();

  Serial.print("DrinnenTemperatur: ");
  Serial.print(temperature);
  Serial.print(" °C, DrinnenLuftfeuchtigkeit: ");
  Serial.print(humidity);
  Serial.print(" %, DrinnenCO₂: ");
  Serial.print(co2);
  Serial.println(" ppm");
}
