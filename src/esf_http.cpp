#include "esf_http.hpp"

esf_http_request_result_t *esf_execute_http_get(char *url)
{
    esf_http_client->begin(url);

    int status_code = esf_http_client->GET();

    int body_length = esf_http_client->getSize();
    char *body = (char *)esf_http_client->getString().c_str();

    esf_http_client->end();

    esf_http_request_result_t *result = (esf_http_request_result_t *)calloc(1, sizeof(esf_http_request_result_t));
    if (status_code == 200)
    {
        result->success = true;
        result->status_code = status_code;
        result->length = body_length;
        result->body = body;
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

esf_http_request_result_t *esf_execute_http_post(char *url, char *post_data)
{
    int post_data_length = strlen(post_data);
    uint8_t *post_data_as_int = (uint8_t *)post_data;

    esf_http_client->begin(url);

    int status_code = esf_http_client->POST(post_data_as_int, post_data_length);

    int body_length = esf_http_client->getSize();
    char *body = (char *)esf_http_client->getString().c_str();

    esf_http_client->end();

    esf_http_request_result_t *result = (esf_http_request_result_t *)malloc(sizeof(esf_http_request_result_t));
    if (status_code == 200)
    {
        result->success = true;
        result->status_code = status_code;
        result->length = body_length;
        result->body = body;
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