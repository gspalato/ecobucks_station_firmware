#include "e_wifi.hpp"

// Deal with any wi-fi related configurations here before connecting.
void e_wifi_init()
{
    WiFi.mode(WIFI_STA);
}