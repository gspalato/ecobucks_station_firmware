#include "esf_serial.hpp"

static const char* TAG = "ESF Serial";

void esf_task_serial_init(void *arg)
{
    Serial.begin(115200);
    while (!Serial)
        delay(10);

    ESP_LOGI(TAG, "Welcome to Ecobucks Station!");

    vTaskDelete(NULL);
}