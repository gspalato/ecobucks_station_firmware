#pragma once

#include "esp_log.h"

#include "ArduinoJson.h"

#include <e_rpc_defs.hpp>

#include <e_serial.hpp>
#include <e_utils.hpp>
#include <e_wifi.hpp>

extern EventGroupHandle_t xScreenConnectedEventGroup;
#define SCREEN_CONNECTED_BIT BIT0

void e_rpc_init();
void e_rpc_loop();

char *e_rpc_generate_message_ping();
char *e_rpc_generate_message_pong();

char *e_rpc_generate_message_scan_network_result(std::vector<String> &networks);
void e_rpc_send_scan_network_result();

char *e_rpc_generate_message_connect_to_wifi_result(e_wifi_connect_result_t result);