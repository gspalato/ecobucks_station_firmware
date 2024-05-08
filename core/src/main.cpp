#include "main.hpp"

static const char *TAG = "e_core";

extern "C" void app_main()
{
    initArduino();

    e_scale_init();
    e_serial_init();
    e_rpc_init();
    // e_gps_init();


    xTaskCreate(
        [](void *pvParameters)
        {
            while (true)
            {
                e_rpc_loop();
                vTaskDelay(5 / portTICK_PERIOD_MS);
            }
            vTaskDelete(NULL);
        },
        "e_rpc_loop", 10 * 1024, NULL, 5, NULL);

    /*
    xTaskCreate(
        [](void *pvParameters)
        {
            while (true)
            {
                e_gps_loop();
                vTaskDelay(5 / portTICK_PERIOD_MS);
            }
            vTaskDelete(NULL);
        },
        "e_gps_loop", 5 * 1024, NULL, tskIDLE_PRIORITY + 2, NULL);
    */

   xTaskCreate(
        [](void *pvParameters)
        {
            while (true)
            {
                e_scale_loop();
                vTaskDelay(500 / portTICK_PERIOD_MS);
            }
            vTaskDelete(NULL);
        },
        "e_scale_loop", 5 * 1024, NULL, tskIDLE_PRIORITY + 4, NULL);

   e_rpc_send_scan_network_response();
}

void loop() { }