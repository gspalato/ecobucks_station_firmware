#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <screen/ui/ui.h>

#include <src/extra/libs/qrcode/lv_qrcode.h>
#include "e_wifi.hpp"

void OnRotateClicked(lv_event_t *e)
{
    auto disp = lv_disp_get_default();
    auto rotation = (lv_disp_rot_t)((lv_disp_get_rotation(disp) + 1) % (LV_DISP_ROT_270 + 1));
    lv_disp_set_rotation(disp, rotation);
}

void setup()
{
#ifdef ARDUINO_USB_CDC_ON_BOOT
    delay(5000);
#endif
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();

    __attribute__((unused)) auto disp = lv_disp_get_default();
    smartdisplay_lcd_set_backlight(.5f);

    ui_init();

    // Load stuff before showing the main screen.
    e_refresh_wifi_list();

    // Show the main screen.
    lv_scr_load(ui_MainScreen);

    // To use third party libraries, enable the define in lv_conf.h: #define LV_USE_QRCODE 1
    auto ui_qrcode = lv_qrcode_create(ui_QRCodeContainer, 200, lv_color_black(), lv_color_white());
    const char *qr_data = "https://github.com/rzeldent/esp32-smartdisplay";
    lv_qrcode_update(ui_qrcode, qr_data, strlen(qr_data));
    lv_obj_center(ui_qrcode);
}


void loop()
{
    lv_timer_handler();
}