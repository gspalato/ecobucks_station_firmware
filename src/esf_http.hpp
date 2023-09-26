#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include <Arduino.h>
#include "ArduinoHttpClient.h"

#include "esf_wifi.hpp"

extern "C"
{
    static const int MAX_HTTP_OUTPUT_BUFFER = 2048;

    typedef struct esf_http_request_result
    {
        bool success;
        int status_code;
        int length;
        char *body;
    } esf_http_request_result_t;

    esf_http_request_result_t *esf_execute_http_get(char *hostname, char *path);
    esf_http_request_result_t *esf_execute_http_post(char *hostname, char *path, char *post_data);
}