#include "esf_screen.hpp"

#define TFT_BL 2
#define GFX_BL 2

static const char *TAG = "ESF Screen";

/*
Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    40,      // DE
    41,      // VSYNC
    39,      // HSYNC
    42,      // PCLK
    45,      // R0
    48,      // R1
    47,      // R2
    21,      // R3
    14,      // R4
    5,       // G0
    6,       // G1
    7,       // G2
    15,      // G3
    16,      // G4
    4,       // G5
    8,       // B0
    3,       // B1
    46,      // B2
    9,       // B3
    1,       // B4
    0,       // hsync_polarity
    8,       // hsync_front_porch
    4,       // hsync_pulse_width
    8,       // hsync_back_porch
    0,       // vsync_polarity
    8,       // vsync_front_porch
    4,       // vsync_pulse_width
    8,       // vsync_back_porch
    0,       // pclk_active_neg
    16000000 // prefer_speed
);

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    800, // width
    480, // height
    rgbpanel);
*/

void esf_screen_task(void *parameters)
{
    size_t buf_size = 800 * 480 / 4;

    static lv_disp_draw_buf_t draw_buf;
    static lv_disp_drv_t disp_drv;
    static lv_color_t *disp_draw_buf;
    static lv_indev_drv_t indev_drv;

    uint32_t screenWidth = 800;
    uint32_t screenHeight = 480;

    disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * buf_size, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
    if (!disp_draw_buf)
    {
        ESP_LOGE(TAG, "LVGL disp_draw_buf allocate failed.");
        vTaskDelete(NULL);
    }

    ESP_LOGI(TAG, "Initializing screen...");

    gfx.begin();
    gfx.setBrightness(127);

    ESP_LOGI(TAG, "Set screen brightness.");

    gfx.fillScreen(0x0000FFU);
    vTaskDelay(pdMS_TO_TICKS(500));
    gfx.fillScreen(0x00FF00U);
    vTaskDelay(pdMS_TO_TICKS(500));
    gfx.fillScreen(0x11DA33U);
    vTaskDelay(pdMS_TO_TICKS(1000));

    ESP_LOGI(TAG, "Color-flashed screen.");

    lv_init();
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, buf_size);

    // Initialize the display
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = esf_screen_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Initialize the input device driver
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = esf_screen_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    // Your UI code or SquareLine Studio Code
    ui_init();

    lv_disp_load_scr(ui_StartScreen);

    while (true)
    {
        int next = lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(next));
    }

    vTaskDelete(NULL);
}

void esf_screen_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    if (gfx.getStartCount() == 0)
        gfx.startWrite();

    gfx.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::rgb565_t *)&color_p->full);
    lv_disp_flush_ready(disp);
}

void esf_screen_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint16_t touchX, touchY;

    data->state = LV_INDEV_STATE_REL;

    if (gfx.getTouch(&touchX, &touchY))
    {
        data->state = LV_INDEV_STATE_PR;

        // Set the coordinates
        data->point.x = touchX;
        data->point.y = touchY;
    }
}

void esf_screen_set_available_wifis(char **wifis, uint8_t count)
{
    ui_SetupWifiScreen_screen_init();
    lv_dropdown_clear_options(ui_Dropdown1);
    for (uint8_t i = 0; i < count; i++)
    {
        lv_dropdown_add_option(ui_Dropdown1, wifis[i], LV_DROPDOWN_POS_LAST);
    }
    lv_obj_invalidate(ui_Dropdown1);
    lv_obj_invalidate(ui_SetupWifiScreen);
    lv_obj_invalidate(ui_SetupWifiLabel);
    lv_obj_invalidate(ui_InfoPanel);
    lv_obj_invalidate(ui_TextArea1);
    lv_obj_invalidate(ui_ConnectButton);
    lv_obj_invalidate(ui_ConnectLabel);
}