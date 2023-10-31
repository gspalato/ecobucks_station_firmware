#pragma once

#include <Arduino.h>

#include "esp_log.h"
#include "esp_system.h"


static TaskHandle_t esf_task_handle_serial_init;

void esf_task_serial_init(void *arg);