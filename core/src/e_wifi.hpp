#pragma once

#include <vector>

#include "WiFi.h"

#include <e_utils.hpp>

enum e_wifi_connect_result_t
{
    SUCCESS,
    WRONG_CREDENTIALS
};

void e_wifi_init();

e_wifi_connect_result_t e_wifi_connect(const char* ssid, const char* password);
std::vector<String> *e_wifi_scan_networks();