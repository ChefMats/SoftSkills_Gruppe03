
//Hier deine Daten eintragen:
const char* ssid = "DEIN_WIFI_NAME";
const char* password = "DEIN_PASSWORT";










void connectWiFi() {
  Serial.println("Verbinden...");
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n Verbunden!");
    Serial.print("IP-Adresse: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n Verbindung fehlgeschlagen.");
  }
}