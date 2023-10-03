#pragma once

#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "WiFi.h"

extern "C"
{
    static WiFiClient esf_wifi_client;

    static bool esf_wifi_ap_init = false;
    static EventGroupHandle_t esf_wifi_ap_event_group = xEventGroupCreate();

    static EventGroupHandle_t esf_wifi_sta_event_group = xEventGroupCreate();

    const int ESF_WIFI_STA_CONNECTED_BIT = BIT0;
    const int ESF_WIFI_STA_DISCONNECTED_BIT = BIT1;
    const int ESF_WIFI_STA_FAIL_BIT = BIT2;

    const int ESF_WIFI_AP_INIT_BIT = BIT0;
    const int ESF_WIFI_AP_INIT_FAIL_BIT = BIT1;

    void esf_init_wifi_ap();
    void esf_init_wifi_sta(char *ssid, char *pwd);
}