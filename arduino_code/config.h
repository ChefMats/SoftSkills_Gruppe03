#ifndef CONFIG_H
#define CONFIG_H

// ------------------------
// WLAN-Zugangsdaten
// ------------------------
const char* ssid = "iPhone von Nico";
const char* password = "testtest";

// ------------------------
// Wetterdaten
// ------------------------
const char* owm_api_key = "68fcded7c5861174eae27c86c2676ad2";  // <- von OpenWeatherMap
const char* city = "Oldenburg";
const char* country_code = "de";

// ------------------------
// Blynk-Konfiguration (für Handy-Benachrichtigungen)
// ------------------------
#define BLYNK_TEMPLATE_ID "TMPL4E5ra_ND-"
#define BLYNK_TEMPLATE_NAME "AirBuddy"
#define BLYNK_AUTH_TOKEN "xwATOZs1_FikfTvNsGF8cFB1ROE_rgpB"

#endif  // CONFIG_H
