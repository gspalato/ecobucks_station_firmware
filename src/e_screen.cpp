#include "e_screen.hpp"

void e_screen_init()
{
    xTaskCreatePinnedToCore(
        [](void *pvParameters)
        {
            while (1)
            {
                lv_timer_handler();
            }
            vTaskDelete(NULL);
        },
        "e_screen_lvgl_timer", 8 * 1024, NULL, configMAX_PRIORITIES - 1, NULL, 0);
}

void e_screen_close_keyboard(lv_obj_t *keyboard)
{
    lv_keyboard_set_textarea(keyboard, NULL);
    lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(keyboard, LV_OBJ_FLAG_CLICKABLE);
}

void e_screen_refresh_wifi_list()
{
    int discovered_wifis = WiFi.scanNetworks();

    log_i("Discovered %d networks", discovered_wifis);

    lv_dropdown_clear_options(ui_SSIDDropdown);
    for (int i = 0; i < discovered_wifis; ++i)
    {
        auto ssid = WiFi.SSID(i).c_str();
        lv_dropdown_add_option(ui_SSIDDropdown, ssid, LV_DROPDOWN_POS_LAST);
        log_i("- Discovered network: %s", ssid);
    }
}

void e_screen_wifi_setup_connect()
{
    char ssid[33] = {0};
    lv_dropdown_get_selected_str(ui_SSIDDropdown, ssid, 33);
    log_i("SSID length: %d", strlen(ssid));

    const char *password = lv_textarea_get_text(ui_PasswordTextArea);

    log_i("Connecting to \"%s\" with password: %s", ssid, password);

    wl_status_t status = WiFi.begin(ssid, password);

    switch (status)
    {
    case WL_CONNECTED:
        log_i("Connected to %s", ssid);
        //ui_MainScreen_screen_init();
        //lv_scr_load(ui_MainScreen);
        break;

    case WL_NO_SSID_AVAIL:
        log_e("No SSID available");
        break;

    case WL_CONNECT_FAILED:
        log_e("Failed to connect to \"%s\"", ssid);
        lv_obj_set_style_border_color(ui_PasswordTextArea, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;

    case WL_IDLE_STATUS:
        log_e("Idle status");
        break;

    case WL_NO_SHIELD:
        log_e("No shield");
        break;

    default:
        log_e("Unknown status: %d", status);
        break;
    }
}