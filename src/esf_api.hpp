#pragma once

#include "ArduinoJson.h"

#include "esf_http.hpp"

extern "C"
{
    void esf_fndtn_request();
    void esf_authenticate_as_operator();
    void esf_register_disposal();
}