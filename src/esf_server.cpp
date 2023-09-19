#include "esf_server.hpp"

static const char *TAG = "ESF Server";

void esf_server_init()
{
    esf_server.on(
        "/",
        HTTP_GET,
        [](AsyncWebServerRequest *request)
        {
            request->send(200, "text/plain", "Hello World!");
        });

    esf_server.on(
        "/wifi",
        HTTP_POST,
        [](AsyncWebServerRequest *request) {},
        NULL,
        [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
        {
            if (index == 0)
            {
                ESP_LOGI(TAG, "Receiving data...");
            }

            ESP_LOGI(TAG, "Received data: %s", data);

            // Read JSON and extract SSID and Password.
            DynamicJsonDocument doc(1024);

            DeserializationError err = deserializeJson(doc, data);
            if (err != DeserializationError::Ok)
            {
                ESP_LOGE(TAG, "Deserialization error: %s", err.c_str());
                return;
            }

            const char *c_ssid = doc["ssid"];
            const char *c_pwd = doc["pwd"];

            if (c_ssid == nullptr || c_pwd == nullptr)
            {
                ESP_LOGE(TAG, "Failed to extract SSID or Password. Is the provided JSON body valid?");
                return;
            }

            char *ssid = (char *)c_ssid;
            char *pwd = (char *)c_pwd;

            ESP_LOGI(TAG, "SSID: %s | Password: %s", c_ssid, c_pwd);

            esf_init_wifi_sta(ssid, pwd);

            xTaskCreate(esf_api_auth_task, "api_auth", 4 * 1024, NULL, configMAX_PRIORITIES - 2, NULL);

            request->send(200);
        });

    esf_server.begin();
    ESP_LOGI(TAG, "Initialized server.");
}

void esf_server_deinit()
{
    esf_server.end();
}
