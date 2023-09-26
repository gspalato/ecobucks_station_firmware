#pragma once

#include "esp_log.h"

#include "ArduinoJson.h"

#include "esf_http.hpp"
#include "esf_wifi.hpp"

extern "C"
{
    static char *esf_fndtn_token = CONFIG_FNDTN_TOKEN;
    static SemaphoreHandle_t esf_fndtn_token_mutex = NULL;

    void esf_fndtn_request();
    void esf_api_auth();
    void esf_api_register_disposal();

    void esf_api_auth_task(void *args);
}