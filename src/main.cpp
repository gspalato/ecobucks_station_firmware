#include "main.hpp"

static const char *TAG = "Ecobucks Station Firmware";

extern "C" void app_main()
{
    initArduino();

    xTaskCreate(esf_task_serial_init, "serial_init", 4 * 1024, NULL, 1, &esf_task_handle_serial_init);

    esf_init_wifi_ap();

    esf_api_init();

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