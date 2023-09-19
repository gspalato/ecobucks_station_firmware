#include "esf_wifi.hpp"

static const char *TAG = "ESF WiFi";

void esf_init_wifi_ap()
{
    WiFi.mode(WIFI_AP_STA);

    bool success = WiFi.softAP(ESF_WIFI_AP_SSID);
    if (success)
    {
        ESP_LOGI(TAG, "SoftAP started with SSID: %s", ESF_WIFI_AP_SSID);
        ESP_LOGI(TAG, "IP address: %s", WiFi.softAPIP().toString().c_str());
    }
    else
    {
        ESP_LOGE(TAG, "Failed to start SoftAP with SSID: %s", ESF_WIFI_AP_SSID);
    }

    // Sinalize the AP status.
    esf_wifi_ap_init = success;
    ESP_LOGI(TAG, "Sinalized AP status.");
}

void esf_init_wifi_sta(char *ssid, char *pwd)
{
    WiFi.mode(WIFI_AP_STA);

    if (WiFi.isConnected())
    {
        ESP_LOGI("ESF WiFi", "Already connected to WiFi. Changing connection to %s.", ssid);
        WiFi.disconnect();
    }

    bool success = WiFi.begin(ssid, pwd);
    if (success)
    {
        ESP_LOGI("ESF WiFi", "Connected to WiFi with SSID: %s.", ssid);
    }
    else
    {
        ESP_LOGE("ESF WiFi", "Failed to connect to WiFi with SSID: %s.", ssid);
    }

    // Sinalize the STA status.
    esf_wifi_sta_connected = success;
    ESP_LOGI(TAG, "Sinalized STA status.");
}