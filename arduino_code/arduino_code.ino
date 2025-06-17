
void setup() {
  Serial.begin(115200);

  initializeLeds();
  initializeSensors();

  // testing leds, remove later
  displayCO2(2);
  displayHumidity(6);
  // testing leds end
}

void loop() {
  // testing sensors, remove later
  float h = readHumidity();
  float t = readTemperature();
  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatur: ");
  Serial.print(t);
  Serial.println(" *C");
  delay(2000);
  // testing sensors end
}