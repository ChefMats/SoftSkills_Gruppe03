#ifndef CONFIG_H
#define CONFIG_H

// ------------------------
// WLAN-Zugangsdaten
// ------------------------
const char* ssid = "SSID";
const char* password = "PASSWORT";

// ------------------------
// Wetterdaten
// ------------------------
const char* owm_api_key = "API_KEY";  // <- von OpenWeatherMap
const char* city = "Oldenburg";
const char* country_code = "de";

// ------------------------
// Blynk-Konfiguration (für Handy-Benachrichtigungen)
// ------------------------
#define BLYNK_TEMPLATE_ID "TMPL4E5ra_ND-"
#define BLYNK_TEMPLATE_NAME "AirBuddy"
#define BLYNK_AUTH_TOKEN "BLYNK_KEY"

#endif