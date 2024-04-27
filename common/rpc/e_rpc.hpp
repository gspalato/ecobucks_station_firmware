#include "esp_log.h"

#include "ArduinoJson.h"

#include <e_serial.hpp>
#include <e_utils.hpp>
#include <e_wifi.hpp>

#define E_RPC_INIT                        0x01
#define E_RPC_PING                        0x02
#define E_RPC_PONG                        0x03
#define E_RPC_SCAN_NETWORKS               0x04
#define E_RPC_SCAN_NETWORKS_RESPONSE      0x05
#define E_RPC_CONNECT_TO_WIFI             0x06
#define E_RPC_CONNECT_TO_WIFI_RESPONSE    0x07
#define E_RPC_REGISTER_DISPOSAL           0x08
#define E_RPC_REGISTER_DISPOSAL_RESPONSE  0x09

enum E_RPC_METHOD
{
    INIT                       = E_RPC_INIT,
    PING                       = E_RPC_PING,
    PONG                       = E_RPC_PONG,
    SCAN_NETWORKS              = E_RPC_SCAN_NETWORKS,
    SCAN_NETWORKS_RESPONSE     = E_RPC_SCAN_NETWORKS_RESPONSE,
    CONNECT_TO_WIFI            = E_RPC_CONNECT_TO_WIFI,
    CONNECT_TO_WIFI_RESPONSE   = E_RPC_CONNECT_TO_WIFI_RESPONSE,
    REGISTER_DISPOSAL          = E_RPC_REGISTER_DISPOSAL,
    REGISTER_DISPOSAL_RESPONSE = E_RPC_REGISTER_DISPOSAL_RESPONSE
};

void e_rpc_init();
void e_rpc_loop(void (*handler)(int method, JsonDocument doc));

char *e_rpc_generate_message_ping();
char *e_rpc_generate_message_pong();

char *e_rpc_generate_message_scan_network_result(Vector<char*> networks);

char *e_rpc_generate_message_connect_to_wifi_result(e_wifi_connect_result_t result);