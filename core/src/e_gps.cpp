#include "e_gps.hpp"

static const char *TAG = "e_gps";

TinyGPSPlus gps;

void e_gps_init()
{
    GPS_SERIAL.begin(
        CONFIG_CORE_GPS_SERIAL_BAUDRATE,
        SERIAL_8N1,
        CONFIG_CORE_GPS_SERIAL_PIN_RX,
        CONFIG_CORE_GPS_SERIAL_PIN_TX);

    ESP_LOGI(TAG, "GPS initialized.");
}

void e_gps_loop()
{
    // This sketch displays information every time a new sentence is correctly encoded.
    while (GPS_SERIAL.available() > 0)
    {
        auto read = GPS_SERIAL.read();
        if (gps.encode(read))
            e_gps_display_info();
    }

    if (millis() > CONFIG_CORE_GPS_MAX_TIMEOUT && gps.charsProcessed() < 10)
    {
        ESP_LOGE(TAG, "No GPS detected: check wiring.");
    }
}

void e_gps_display_info()
{
    ESP_LOGI(TAG, "Location: %f, %f", gps.location.lat(), gps.location.lng());
    ESP_LOGI(TAG, "HDOP: %f", gps.hdop.hdop());
}