#include "main.hpp"

static const char *TAG = "Ecobucks Station Firmware";

extern "C" void app_main()
{
    initArduino();

    xTaskCreate(esf_task_serial_init, "serial_init", 4 * 1024, NULL, 1, &esf_task_handle_serial_init);

    esf_init_wifi_ap();

    xTaskCreate(
        [](void *args)
        {
            esf_server_init();
            vTaskDelete(NULL);
        },
        "esf_server_init",
        4 * 1024,
        NULL,
        configMAX_PRIORITIES - 2,
        NULL);
}

void esf_task_serial_init(void *arg)
{
    Serial.begin(115200);
    while (!Serial)
        delay(10);

    ESP_LOGI(TAG, "Welcome to Ecobucks Station!");

    vTaskDelete(NULL);
}