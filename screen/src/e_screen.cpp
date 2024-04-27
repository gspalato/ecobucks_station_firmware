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

    bool found_any_valid_network = false;

    lv_dropdown_clear_options(ui_SSIDDropdown);
    for (int i = 0; i < discovered_wifis; ++i)
    {
        auto ssid = WiFi.SSID(i);
        auto rssi = WiFi.RSSI(i);
        found_any_valid_network = ssid[0] != '\0';
        Serial.println("NETWORK: ");
        Serial.println(ssid);

        lv_dropdown_add_option(ui_SSIDDropdown, ssid.c_str(), LV_DROPDOWN_POS_LAST);
        log_i("- Discovered network \"%s\" (%d)", ssid, rssi);
    }

    // Disable password input if no valid networks are found.
    if (!found_any_valid_network)
    {
        lv_dropdown_set_options(ui_SSIDDropdown, "No networks found.");

        lv_obj_clear_flag(ui_PasswordTextArea, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_color(ui_PasswordTextArea, lv_color_hex(0xaaaaaa), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PasswordTextArea, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else
    {
        lv_obj_add_flag(ui_PasswordTextArea, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_opa(ui_PasswordTextArea, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void e_screen_wifi_setup_connect()
{
    char ssid[33] = {0};
    lv_dropdown_get_selected_str(ui_SSIDDropdown, ssid, 33);
    log_i("SSID length: %d", strlen(ssid));

    const char *password = lv_textarea_get_text(ui_PasswordTextArea);

    log_i("Connecting to \"%s\" with password: %s", ssid, password);

    //e_wifi_connect_sta(ssid, (char *)password);
   
    wl_status_t status = WiFi.begin(ssid, password);

    int retries = 0;
    while (status != WL_CONNECTED)
    {
        vTaskDelay(100 / portTICK_PERIOD_MS);
        if (retries >= 5)
            break;
        retries++;
    }

    switch (status)
    {
    case WL_CONNECTED:
        log_i("Connected to %s", ssid);
        lv_scr_load(ui_MainScreen);
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

    case WL_DISCONNECTED:
        log_e("Disconnected");
        break;

    default:
        log_e("Unknown status: %d", status);
        break;
    }
}