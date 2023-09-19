#pragma once

#include <esp_system.h>

#include "ArduinoJson.h"
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

#include "esf_api.hpp"
#include "esf_wifi.hpp"

extern "C"
{
    static AsyncWebServer esf_server(80);

    void esf_server_init();
    void esf_server_deinit();
}