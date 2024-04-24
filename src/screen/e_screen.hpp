#include <screen/ui/ui.h>

#include "e_wifi.hpp"

void e_screen_close_keyboard(lv_obj_t *keyboard)
{
    lv_keyboard_set_textarea(keyboard, NULL);
    lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
}

void e_screen_refresh_wifi_list()
{
    int discovered_wifis = WiFi.scanNetworks();

    lv_dropdown_clear_options(ui_SSIDDropdown);
    for (int i = 0; i < discovered_wifis; ++i)
    {
        lv_dropdown_add_option(ui_SSIDDropdown, WiFi.SSID(i).c_str(), LV_DROPDOWN_POS_LAST);
    }
}