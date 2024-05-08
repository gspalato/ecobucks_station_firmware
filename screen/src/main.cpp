#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <screen/ui/ui.h>

#include <src/extra/libs/qrcode/lv_qrcode.h>

#include <esp_log.h>

#include <e_screen.hpp>
#include <e_serial.hpp>

static const char *TAG = "main";

void setup()
{
#ifdef ARDUINO_USB_CDC_ON_BOOT
    delay(5000);
#endif

    Serial.begin(115200);
    Serial.setDebugOutput(true);

    e_serial_init();
    e_rpc_init();

    esp_log_level_set("*", ESP_LOG_NONE);

    ESP_LOGI(TAG, "Board: %s", BOARD_NAME);
    ESP_LOGI(TAG, "CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    ESP_LOGI(TAG, "Free heap: %d bytes", ESP.getFreeHeap());
    ESP_LOGI(TAG, "Free PSRAM: %d bytes", ESP.getPsramSize());
    ESP_LOGI(TAG, "SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();

    __attribute__((unused)) auto disp = lv_disp_get_default();
    smartdisplay_lcd_set_backlight(.5f);

    ui_init();

    xTaskCreatePinnedToCore(
        [](void *pvParameters)
        {
            while (true)
            {
                lv_timer_handler();
                vTaskDelay(5 / portTICK_PERIOD_MS);
            }
            vTaskDelete(NULL);
        },
        "lvgl_timer", 8 * 1024, NULL, 10, NULL, 1);

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

    xEventGroupWaitBits(xCoreConnectedEventGroup, CORE_CONNECTED_BIT, pdFALSE, pdFALSE, portMAX_DELAY);

    // Show the main screen.
    lv_scr_load(ui_MainScreen);

    e_screen_refresh_wifi_list();

    // To use third party libraries, enable the define in lv_conf.h: #define LV_USE_QRCODE 1
    auto ui_qrcode = lv_qrcode_create(ui_QRCodeContainer, 200, lv_color_black(), lv_color_white());
    const char *qr_data = "https://github.com/rzeldent/esp32-smartdisplay";
    lv_qrcode_update(ui_qrcode, qr_data, strlen(qr_data));
    lv_obj_center(ui_qrcode);
}

void loop() {}