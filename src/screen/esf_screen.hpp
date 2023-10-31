#pragma once

#include <Arduino.h>
#include <esp_log.h>

#include "freertos/task.h"

#include "lvgl.h"

#include "ui/ui.h"
#include "esf_lgfx_driver.hpp"

#include <Arduino_GFX_Library.h>
#include <Arduino_GFX.h>

extern "C"
{
    void esf_screen_init();
    void esf_screen_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
    void esf_screen_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

    void esf_screen_set_available_wifis(char **wifis, uint8_t count);

    void esf_screen_task(void *parameters);
    void esf_screen_tick(void *pvParameters);
}