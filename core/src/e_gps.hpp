#pragma once

#include "Arduino.h"

#include "TinyGPSPlus.h"

#include <e_utils.hpp>

#define GPS_SERIAL Serial2

#define GPS_RX_PIN GPIO_NUM_2
#define GPS_TX_PIN GPIO_NUM_4
#define GPS_BAUDRATE 9600
#define GPS_MAX_TIMEOUT 5000

void e_gps_init();
void e_gps_loop();
void e_gps_display_info();