#pragma once

#include "Arduino.h"

#include "TinyGPSPlus.h"

#include <e_utils.hpp>

#define GPS_SERIAL Serial2

void e_gps_init();
void e_gps_loop();
void e_gps_display_info();