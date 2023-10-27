#include "esf_screen.hpp"

#define TFT_BL 2
#define GFX_BL 2

static const char *TAG = "ESF Screen";

static const uint16_t screenWidth = 800;
static const uint16_t screenHeight = 480;

static lv_color_t buf[2][screenWidth * 10];

void esf_screen_init()
{
    gfx.begin();
    gfx.setBrightness(127);

    gfx.fillScreen(0x0000FFU);
    delay(50);
    gfx.fillScreen(0x00FF00U);
    delay(50);
    gfx.fillScreen(0x11DA33U);

    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf[0], buf[1], screenWidth * 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = esf_screen_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = esf_screen_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    // Your UI code or SquareLine Studio Code
    ui_init();
}

/*
void esf_screen_init()
{
    // Init Display
    gfx->begin();

    gfx->fillScreen(RED);
    delay(500);
    gfx->fillScreen(GREEN);
    delay(500);
    gfx->fillScreen(BLUE);
    delay(500);
    gfx->fillScreen(BLACK);
    delay(500);
    lv_init();

    // Init touch device
    pinMode(TOUCH_GT911_RST, OUTPUT);
    digitalWrite(TOUCH_GT911_RST, LOW);
    delay(10);
    digitalWrite(TOUCH_GT911_RST, HIGH);
    delay(10);
    touch_init();
    //  touch.setTouch( calData );

    screenWidth = gfx->width();
    screenHeight = gfx->height();

#ifdef ESP32
    disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * screenWidth * screenHeight / 4, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
#else
    disp_draw_buf = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth * screenHeight / 4);
#endif

    if (!disp_draw_buf)
        ESP_LOGE(TAG, "LVGL disp_draw_buf allocate failed!");
    else
    {
        lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * screenHeight / 4);

        // Initialize the display
        lv_disp_drv_init(&disp_drv);

        // Change the following line to your display resolution
        disp_drv.hor_res = screenWidth;
        disp_drv.ver_res = screenHeight;
        disp_drv.flush_cb = esf_screen_disp_flush;
        disp_drv.draw_buf = &draw_buf;
        lv_disp_drv_register(&disp_drv);

        // Initialize the (dummy) input device driver
        static lv_indev_drv_t indev_drv;
        lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = esf_screen_touchpad_read;
        lv_indev_drv_register(&indev_drv);

        ui_init();

        ESP_LOGI(TAG, "Setup done.");
    }
}
*/

void esf_screen_tick(void *pvParameters)
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(10);

    // Initialise the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        // Wait for the next cycle.
        vTaskDelayUntil(&xLastWakeTime, xFrequency);

        lv_timer_handler();
    }
}

void esf_screen_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    if (gfx.getStartCount() == 0)
    {
        gfx.startWrite();
    }
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

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;
    }
}

/* Display flushing */
/*
void esf_screen_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
    gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

    lv_disp_flush_ready(disp);
}

void esf_screen_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    if (touch_has_signal())
    {
        if (touch_touched())
        {
            data->state = LV_INDEV_STATE_PR;

            // Set the coordinates
            data->point.x = touch_last_x;
            data->point.y = touch_last_y;
            Serial.print("Data X: ");
            Serial.println(data->point.x);
            Serial.print("Data Y: ");
            Serial.println(data->point.y);
        }
        else if (touch_released())
        {
            data->state = LV_INDEV_STATE_REL;
        }
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
}
*/

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