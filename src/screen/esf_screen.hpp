#pragma once

#include <Arduino.h>
#include <esp_log.h>

#include "lvgl.h"

#include "ui/ui.h"
#include "esf_lgfx_driver.hpp"
// #include "touch.h"

extern "C"
{
    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t *disp_draw_buf;
    static lv_disp_drv_t disp_drv;

    void esf_screen_init();
    void esf_screen_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
    void esf_screen_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

    void esf_screen_set_available_wifis(char **wifis, uint8_t count);

    void esf_screen_tick(void *pvParameters);
}