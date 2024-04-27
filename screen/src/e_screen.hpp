#pragma once

#include <screen/ui/ui.h>

#include "e_wifi.hpp"

void e_screen_init();

void e_screen_close_keyboard(lv_obj_t *keyboard);
void e_screen_wifi_setup_connect();
void e_screen_refresh_wifi_list();