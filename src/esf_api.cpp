#include "esf_api.hpp"

static const char *TAG = "ESF API";

void esf_fndtn_request()
{
    // Do your own thing
}

void esf_api_auth()
{
    DynamicJsonDocument doc(1024);

    const char *mutation =
        "mutation auth($u: String!, $p: String!) { authenticate(username: $u, password: $p) { successful, token, error } }";

    doc["query"] = mutation;
    doc["variables"]["u"] = CONFIG_ECOBUCKS_USERNAME;
    doc["variables"]["p"] = CONFIG_ECOBUCKS_PWD;

    size_t len = measureJson(doc) + 1;
    char *json = (char *)calloc(len, sizeof(char));
    if (json == nullptr)
    {
        ESP_LOGE(TAG, "Failed to allocate memory for JSON.");
        return;
    }

    serializeJson(doc, json, len);

    esf_http_request_result_t *response = esf_execute_http_post(CONFIG_FNDTN_ENDPOINT, json);

    doc.clear();
    deserializeJson(doc, response->body);

    if (!doc.containsKey("data"))
    {
        ESP_LOGE(TAG, "Failed to authenticate with Foundation.");
        ESP_LOGE(TAG, "Response: %s", response->body);
        return;
    }

    bool success = doc["data"]["authenticate"]["success"];
    if (success)
    {
        const char *token = doc["data"]["authenticate"]["token"];
        esf_fndtn_token = (char *)token;

        ESP_LOGI(TAG, "Successfully logged in to Foundation.\nToken: %s", token);
    }
}

void esf_api_auth_task(void *args)
{
    if (!WiFi.isConnected())
    {
        ESP_LOGE(TAG, "WiFi is not connected. Waiting...");

        do
        {
            ESP_LOGW(TAG, "Checking WiFi connection...");
            vTaskDelay(5000 / portTICK_RATE_MS);
        } while (!WiFi.isConnected());
    }

    do
    {
        esf_api_auth();
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    } while (esf_fndtn_token == nullptr || strlen(esf_fndtn_token) >= 1);

    vTaskDelete(NULL);
}

void esf_api_register_disposal()
{
    // Do your own thing
}
