#include "main.hpp"

static const char *TAG = "e_core";

extern "C" void app_main()
{
    initArduino();

    e_serial_init();
    e_rpc_init();
    // e_gps_init();

    // Turn on LED.
    digitalWrite(GPIO_NUM_2, HIGH);

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
        "e_rpc_loop", 10 * 1024, NULL, tskIDLE_PRIORITY + 3, NULL);

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

   e_rpc_send_scan_network_result();
}

void loop() { }