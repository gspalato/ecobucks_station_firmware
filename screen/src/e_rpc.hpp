#pragma once

#include "Arduino.h"

#include "ArduinoJson.h"

#include <screen/ui/ui.h>
#include <widgets/lv_dropdown.h>

#include <e_rpc_defs.hpp>

#include <e_serial.hpp>
#include <e_utils.hpp>

extern EventGroupHandle_t xCoreConnectedEventGroup;
#define CORE_CONNECTED_BIT BIT0

void e_rpc_init();
void e_rpc_loop();

//char *e_rpc_generate_message_log(const char *tag, e_log_level_t level, const char *message);
//void e_rpc_log(const char *tag, e_log_level_t level, const char *message);

void e_rpc_connect_to_wifi_request(char *ssid, char *password);
void e_rpc_scan_networks_request();

char *e_rpc_generate_message_ping();
void e_rpc_ping_request();

char *e_rpc_generate_message_pong();
void e_rpc_pong_request();

char *e_rpc_generate_message_connect_to_wifi_request(char *ssid, char *password);
void e_rpc_connect_to_wifi_request(char *ssid, char *password);

char *e_rpc_generate_message_scan_networks_request();
void e_rpc_scan_networks_request();