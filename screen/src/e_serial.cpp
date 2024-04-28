#include "e_serial.hpp"

static const char *TAG = "e_serial";

void e_serial_init()
{
    Serial.begin(115200);

    while (!Serial)
    {
        delay(10);
    }

    ESP_LOGI(TAG, "Serial initialized.");
}