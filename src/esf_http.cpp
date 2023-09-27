#include "esf_http.hpp"

static const char *TAG = "ESF HTTP";

esf_http_request_result_t *esf_execute_http_get(char *hostname, char *path)
{
    HttpClient client(esf_wifi_client, hostname);

    int status = client.get(path);
    if (!status) {
        ESP_LOGE(TAG, "Failed to GET.");
        return nullptr;
    }

    int status_code = client.responseStatusCode();

    String response = client.responseBody();
    int body_length = response.length();
    const char* body = response.c_str();

    esf_http_request_result_t *result = (esf_http_request_result_t *)calloc(1, sizeof(esf_http_request_result_t));
    if (status_code == 200)
    {
        result->success = true;
        result->status_code = status_code;
        result->length = body_length;
        result->body = (char*)body;
        return result;
    }
    else
    {
        result->success = false;
        result->status_code = status_code;
        result->length = 0;
        result->body = nullptr;
        return result;
    }
}

esf_http_request_result_t *esf_execute_http_post(char *hostname, char *path, char *post_data)
{
    HttpClient client(esf_wifi_client, hostname);

    const char* content_type = "application/json";

    int error = client.post(path, content_type, post_data);

    int status_code = client.responseStatusCode();

    if (error) {
        ESP_LOGE(TAG, "Failed to POST. Status: %d", status_code);
        return nullptr;
    }

    String response = client.responseBody();
    int body_length = response.length();
    const char* body = response.c_str();

    esf_http_request_result_t *result = (esf_http_request_result_t *)malloc(sizeof(esf_http_request_result_t));
    if (status_code == 200)
    {
        result->success = true;
        result->status_code = status_code;
        result->length = body_length;
        result->body = (char*)safe_alloc(client.contentLength() + 1, sizeof(char));

        strcpy(result->body, body);

        printf("\nBody: %s\nResponse Body: %s\n",body,result->body);

        return result;
    }
    else
    {
        result->success = false;
        result->status_code = status_code;
        result->length = 0;
        result->body = nullptr;
        return result;
    }
}