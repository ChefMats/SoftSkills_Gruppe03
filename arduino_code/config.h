#ifndef CONFIG_H
#define CONFIG_H

// ------------------------
// WLAN-Zugangsdaten
// ------------------------
const char* ssid = "DEIN_WIFI_NAME";
const char* password = "DEIN_PASSWORT";

// ------------------------
// API-URL für Wetterdaten
// ------------------------
const char* apiURL = "http://wttr.in/Oldenburg?format=j1";

// ------------------------
// Blynk-Konfiguration (für Handy-Benachrichtigungen)
// ------------------------
#define BLYNK_TEMPLATE_ID "TMPL4E5ra_ND-"
#define BLYNK_TEMPLATE_NAME "AirBuddy"
#define BLYNK_AUTH_TOKEN "xwATOZs1_FikfTvNsGF8cFB1ROE_rgpB"

#endif  // CONFIG_H
