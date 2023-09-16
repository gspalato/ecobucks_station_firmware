#include "esf_server.hpp"

static const char *TAG = "ESF Server";

/*
typedef struct
{
    esp_err_t status;
    size_t buffer_size;
} _esf_handle_post_body_result_t;

esp_err_t _esf_handle_post_body(httpd_req_t *req, char *buffer)
{
    static size_t MAX_HTTP_RECV_BUFFER = 512;
    size_t buffer_size = std::min(req->content_len, MAX_HTTP_RECV_BUFFER);

    int ret, remaining = req->content_len;

    while (remaining > 0)
    {
        // Read the data for the request
        if ((ret = httpd_req_recv(req, buffer, std::min((unsigned)remaining, sizeof(buffer_size)))) <= 0)
        {
            if (ret == HTTPD_SOCK_ERR_TIMEOUT)
            {
                // Retry receiving if timeout occurred
                continue;
            }

            return ESP_FAIL;
        }

        remaining -= ret;
    }

    return ESP_OK;
}

esp_err_t handle_get_index(httpd_req_t *req)
{
    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, "<h1>Hello World!</h1>", -1);
    return ESP_OK;
}

static const httpd_uri_t get_index = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = handle_get_index,
};

esp_err_t handle_post_wifi(httpd_req_t *req)
{
    static size_t MAX_HTTP_RECV_BUFFER = 512;
    size_t buffer_size = std::min(req->content_len, MAX_HTTP_RECV_BUFFER);
    char *buffer = (char *)calloc(buffer_size, sizeof(char));

    const char *uri = req->uri;
    ESP_LOGD(TAG, "URI: %s", uri);

    esp_err_t result = _esf_handle_post_body(req, buffer);
    if (result != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to handle POST request body.");
        return ESP_FAIL;
    }

    ESP_LOGD(TAG, "Body: %s", buffer);

    DynamicJsonDocument doc(1024);
    DeserializationError err = deserializeJson(doc, buffer);
    if (!err)
    {
        ESP_LOGE(TAG, "Failed to deserialize JSON. Error: %s", err.c_str());
        return ESP_FAIL;
    }

    //esf_init_wifi_sta(ssid, pwd);

    return ESP_OK;
}

static const httpd_uri_t post_wifi = {
    .uri = "/wifi",
    .method = HTTP_POST,
    .handler = handle_post_wifi,
};
*/

void esf_server_init()
{
    if ((xEventGroupGetBits(esf_wifi_event_group) & ESF_WIFI_AP_INIT_BIT) != 0)
    {
        ESP_LOGW(TAG, "WiFi Access Point not yet initialized. Waiting...");
        xEventGroupWaitBits(esf_wifi_event_group, ESF_WIFI_AP_INIT_BIT, pdFALSE, pdTRUE, portMAX_DELAY);
    }

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
            const int capacity = 1 * JSON_OBJECT_SIZE(1);
            StaticJsonDocument<capacity> doc;

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
                ESP_LOGE(TAG, "Failed to extract SSID or Password.");
                return;
            }

            ESP_LOGI(TAG, "(const char *) SSID: %s | Password: %s", c_ssid, c_pwd);

            char *ssid = (char *)c_ssid;
            char *pwd = (char *)c_pwd;

            ESP_LOGI(TAG, "(char *) SSID: %s | Password: %s", c_ssid, c_pwd);
        });

    esf_server.begin();
    ESP_LOGI(TAG, "Initialized server.");

    /*
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.lru_purge_enable = true;

    // Start the httpd server
    ESP_LOGI(TAG, "Starting server on port: '%d'", config.server_port);

    esp_err_t status = httpd_start(&server, &config);
    if (server == NULL)
    {
        ESP_LOGE(TAG, "Failed to start server! Server was null.");
        return NULL;
    }

    switch (status)
    {
    case ESP_OK:
    {
        // Set URI handlers.
        ESP_LOGI(TAG, "Registering URI handlers...");

        httpd_register_uri_handler(server, &get_index);
        httpd_register_uri_handler(server, &post_wifi);

        ESP_LOGI(TAG, "URI handlers registered.");

        return server;
    }
    break;

    case ESP_ERR_INVALID_ARG:
    {
        ESP_LOGE(TAG, "Invalid argument!");
        return NULL;
    }

    case ESP_ERR_HTTPD_TASK:
    {
        ESP_LOGE(TAG, "Error starting task!");
        return NULL;
    }

    case ESP_ERR_HTTPD_ALLOC_MEM:
    {
        ESP_LOGE(TAG, "Insufficient memory!");
        return NULL;
    }

    default:
    {
        ESP_LOGE(TAG, "Error starting server!");
        return NULL;
    }
    break;
    }
    */
}

void esf_server_deinit()
{
    esf_server.end();
}
