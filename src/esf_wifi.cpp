#include "esf_wifi.hpp"

void esf_init_wifi_ap()
{
    WiFi.mode(WIFI_AP_STA);

    bool success = WiFi.softAP(ESF_WIFI_AP_SSID);
    ESP_LOGI("ESF WiFi", "SoftAP started with SSID: %s", ESF_WIFI_AP_SSID);
    ESP_LOGI("ESF WiFi", "IP address: %s", WiFi.softAPIP().toString().c_str());

    // Sinalize that the AP has been initialized.
    xEventGroupSetBits(esf_wifi_event_group, success ? ESF_WIFI_AP_INIT_BIT : ESF_WIFI_AP_INIT_FAIL_BIT);
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

    xEventGroupSetBits(esf_wifi_event_group, success ? ESF_WIFI_STA_CONNECTED_BIT : ESF_WIFI_STA_FAIL_BIT);
}