cmake_minimum_required(VERSION 3.16.0)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
list(APPEND EXTRA_COMPONENT_DIRS espressif_esp_lcd_touch_gt911_1.1.0)
project(ecobucks_station_firmware)
