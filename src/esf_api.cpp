#include "esf_api.hpp"

static const char *TAG = "ESF API";

void esf_api_init()
{
    esf_fndtn_token_mutex = xSemaphoreCreateMutex();
    if (esf_fndtn_token_mutex == NULL)
    {
        ESP_LOGE(TAG, "Failed to create token mutex. Aborting...");
        exit(1);
    }
}

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
    ESP_LOGD(TAG, "Resulting JSON: %s", json);

    esf_http_request_result_t *response = esf_execute_http_post(CONFIG_FNDTN_ENDPOINT_HOSTNAME, CONFIG_FNDTN_ENDPOINT_PATH, json);

    doc.clear();

    if (response->body == nullptr) {
        ESP_LOGE(TAG, "Failed to authenticate with Foundation. Response body is null.");
        return;
    }

    deserializeJson(doc, response->body);

    ESP_LOGI(TAG, "Response: %s", response->body);

    if (!doc.containsKey("data"))
    {
        ESP_LOGE(TAG, "Failed to authenticate with Foundation.");
        return;
    }

    bool success = doc["data"]["authenticate"]["success"];
    if (success)
    {
        const char *token = doc["data"]["authenticate"]["token"];

        // Lock the token mutex to modify it. Release it afterwards.
        xSemaphoreTake(esf_fndtn_token_mutex, portMAX_DELAY);
        esf_fndtn_token = (char *)token;
        xSemaphoreGive(esf_fndtn_token_mutex);

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

        ESP_LOGI(TAG, "WiFi connected. Proceeding to authenticate in Foundation.");
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
