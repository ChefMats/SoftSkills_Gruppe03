#ifndef CONFIG_H
#define CONFIG_H

// ------------------------
// WLAN-Zugangsdaten
// ------------------------
const char* ssid = "SSID";
const char* password = "SmartBuddy";

// ------------------------
// Wetterdaten
// ------------------------
const char* owm_api_key = "";  // <- von OpenWeatherMap
const char* city = "Oldenburg";
const char* country_code = "de";

// ------------------------
// Blynk-Konfiguration (für Handy-Benachrichtigungen)
// ------------------------
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#endif