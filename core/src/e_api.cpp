#include <e_api.hpp>

static const char *TAG = "e_api";

HTTPClient http_client;

char *e_api_token;

/**
 * @brief Logs into the Ecobucks API and saves the token.
*/
void e_api_login()
{
    JsonDocument request_doc;
    char request_buffer[1024];

    request_doc["username"] = CONFIG_CORE_API_ACCOUNT_USERNAME;
    request_doc["password"] = CONFIG_CORE_API_ACCOUNT_PASSWORD;
    serializeJson(request_doc, request_buffer, sizeof(request_buffer));

    http_client.begin(E_API_AUTH_URL);
    http_client.addHeader("Content-Type", "application/json");
    int code = http_client.POST(request_buffer);
    if (code != 200)
    {
        ESP_LOGE(TAG, "API Login failed. (HTTP %d)", code);
        return;
    }

    String response = http_client.getString();
    http_client.end();

    ESP_LOGI(TAG, "API Login response: %s", response.c_str());

    JsonDocument response_doc;
    deserializeJson(response_doc, response);

    bool successful = response_doc["success"];

    if (!successful) {
        const char *error = response_doc["error"];
        ESP_LOGE(TAG, "API Login failed. Error: %s", error);
        return;
    }

    const char *token = response_doc["token"];
    e_api_token = (char*)token;
}

/**
 * @brief Registers a disposal in the Ecobucks API.
 * @param float credits: The amount of credits to be rewarded.
 * @param float weight: The weight of the disposed material.
 * @param int disposal_type: The type of disposal. (RECYCLABLE = 0, BATTERY = 1, SPONGE = 2, ELECTRONIC = 3)
 * @return e_api_disposal_response_t*: The response from the API.
*/
e_api_disposal_response_t *e_api_register_disposal(float credits, float weight, e_api_disposal_type_t disposal_type)
{
    JsonDocument request_doc;
    char request_buffer[1024];

    request_doc["operatorToken"] = e_api_token;
    request_doc["disposals"][0]["credits"] = credits;
    request_doc["disposals"][0]["weight"] = weight;
    request_doc["disposals"][0]["disposalType"] = disposal_type;

    serializeJson(request_doc, request_buffer, sizeof(request_buffer));

    e_api_disposal_response_t *disposal_response =
        (e_api_disposal_response_t *)e_safe_alloc(sizeof(e_api_disposal_response_t), 1, true);

    http_client.begin(E_API_ECOBUCKS_DISPOSALS_URL);
    http_client.addHeader("Content-Type", "application/json");
    int code = http_client.POST(request_buffer);
    if (code != 200)
    {
        disposal_response->success = false;
        ESP_LOGE(TAG, "API Register Disposal failed. (HTTP %d)", code);
        return disposal_response;
    }

    String response = http_client.getString();
    http_client.end();

    ESP_LOGI(TAG, "API Register Disposal response: %s", response.c_str());

    JsonDocument response_doc;
    deserializeJson(response_doc, response);
    
    bool successful = response_doc["successful"];
    disposal_response->success = successful;

    if (!successful) {
        const char *error = response_doc["error"];
        disposal_response->error = (char*)error;

        ESP_LOGE(TAG, "API Register Disposal failed. Error: %s", error);
        return disposal_response;
    }

    float created_credits = response_doc["credits"];
    disposal_response->credits = created_credits;

    const char *disposal_token = response_doc["token"];
    disposal_response->disposal_token = (char*)disposal_token;

    return disposal_response;
}