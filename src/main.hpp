#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern "C"
{
    static TaskHandle_t esf_task_handle_serial_init;

    void esf_task_serial_init(void *arg);

    void app_main();
}