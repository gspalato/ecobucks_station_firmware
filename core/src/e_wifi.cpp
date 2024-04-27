#include "e_wifi.hpp"

static const char *TAG = "e_wifi";

static const int MAX_NETWORKS = 10;

void e_wifi_init()
{
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

e_wifi_connect_result_t e_wifi_connect(const char* ssid, const char* password)
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED && WiFi.status() != WL_CONNECT_FAILED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }

    switch (WiFi.status())
    {
        case WL_CONNECTED:
        {
            ESP_LOGI(TAG, "Connected to the WiFi network.");
            return e_wifi_connect_result_t::SUCCESS;
        }

        case WL_CONNECT_FAILED:
        {
            ESP_LOGE(TAG, "Failed to connect to the WiFi network.");
            return e_wifi_connect_result_t::WRONG_CREDENTIALS;
        }
        break;

        default:
        {
            ESP_LOGE(TAG, "Unhandled WiFi status.");
            return e_wifi_connect_result_t::WRONG_CREDENTIALS;
        }
    }
}

std::vector<String> *e_wifi_scan_networks()
{
    int n = WiFi.scanNetworks();
    int num_networks = n > MAX_NETWORKS ? MAX_NETWORKS : n;

    std::vector<String> *networks = new std::vector<String>();
    networks->reserve(num_networks);

    for (int i = 0; i < num_networks; i++)
    {
        String ssid = WiFi.SSID(i);
        const char *ssid_str = ssid.c_str();

        ESP_LOGI(TAG, "Network found: %s", ssid_str);

        networks->push_back(ssid);
    }

    return networks;
}