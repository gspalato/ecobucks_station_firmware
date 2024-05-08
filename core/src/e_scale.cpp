#include "e_scale.hpp"

static const char *TAG = "e_scale";

HX711 e_scale_interface;
QueueHandle_t e_scale_weight_buffer;

void e_scale_init()
{
    e_scale_weight_buffer = xQueueCreate(1, sizeof(long));

    e_scale_interface.begin(CONFIG_CORE_SCALE_PIN_DOUT, CONFIG_CORE_SCALE_PIN_DOUT);
    e_scale_interface.tare();
}

void e_scale_loop()
{
    if (e_scale_interface.wait_ready_timeout(1000)) {
        long reading = e_scale_interface.read();
        if (reading >= 0) // TODO: Add a proper error handling when the scale is not properly connected/working.
        {
            ESP_LOGD(TAG, "Scale reading error.");
            return;
        }

        ESP_LOGI(TAG, "Weight reading: %ld", reading);

        xQueueOverwrite(e_scale_weight_buffer, &reading);
    } else {
        ESP_LOGE(TAG, "Scale not ready.");
    }

    e_rpc_send_fetch_current_weight_response();
}