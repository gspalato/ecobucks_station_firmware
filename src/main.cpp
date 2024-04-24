#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <screen/ui/ui.h>

#include <src/extra/libs/qrcode/lv_qrcode.h>

#include "e_screen.hpp"
#include "e_wifi.hpp"

void setup()
{
#ifdef ARDUINO_USB_CDC_ON_BOOT
    delay(5000);
#endif

    Serial.begin(115200);
    Serial.setDebugOutput(true);

    e_wifi_init();

    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

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
        "e_screen_lvgl_timer", 8 * 1024, NULL, 10, NULL, 1);

    e_screen_refresh_wifi_list();

    // Show the main screen.
    lv_scr_load(ui_MainScreen);

    // To use third party libraries, enable the define in lv_conf.h: #define LV_USE_QRCODE 1
    auto ui_qrcode = lv_qrcode_create(ui_QRCodeContainer, 200, lv_color_black(), lv_color_white());
    const char *qr_data = "https://github.com/rzeldent/esp32-smartdisplay";
    lv_qrcode_update(ui_qrcode, qr_data, strlen(qr_data));
    lv_obj_center(ui_qrcode);
}

void loop() {}