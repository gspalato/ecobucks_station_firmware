#pragma once

#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <Arduino.h>

#include "esp_system.h"
#include "esp_spi_flash.h"

#include "screen/esf_screen.hpp"
#include "esf_serial.hpp"
#include "esf_server.hpp"
#include "esf_wifi.hpp"
#include "esf_api.hpp"

#include "main.hpp"

extern "C"
{
    static TaskHandle_t esf_task_handle_serial_init;
    static TaskHandle_t esf_task_handle_screen_tick;

    void esf_task_serial_init(void *arg);

    void app_main();
}
