#pragma once

#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <Arduino.h>

#include "esp_system.h"
#include "esp_spi_flash.h"

#include "esf_serial.hpp"
#include "esf_server.hpp"
#include "esf_wifi.hpp"
#include "esf_api.hpp"

#include "main.hpp"

extern "C" void app_main();