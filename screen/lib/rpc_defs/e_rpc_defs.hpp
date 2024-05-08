#pragma once

#define E_RPC_INIT                           0x00
#define E_RPC_LOG                            0x01
#define E_RPC_PING                           0x02
#define E_RPC_PONG                           0x03
#define E_RPC_SCAN_NETWORKS                  0x04
#define E_RPC_SCAN_NETWORKS_RESPONSE         0x05
#define E_RPC_CONNECT_TO_WIFI                0x06
#define E_RPC_CONNECT_TO_WIFI_RESPONSE       0x07
#define E_RPC_FETCH_CURRENT_WEIGHT           0x08
#define E_RPC_FETCH_CURRENT_WEIGHT_RESPONSE  0x09
#define E_RPC_REGISTER_DISPOSAL              0x0a
#define E_RPC_REGISTER_DISPOSAL_RESPONSE     0x0b

enum E_RPC_METHOD
{
    INIT                          = E_RPC_INIT,
    LOG                           = E_RPC_LOG,
    PING                          = E_RPC_PING,
    PONG                          = E_RPC_PONG,
    SCAN_NETWORKS                 = E_RPC_SCAN_NETWORKS,
    SCAN_NETWORKS_RESPONSE        = E_RPC_SCAN_NETWORKS_RESPONSE,
    CONNECT_TO_WIFI               = E_RPC_CONNECT_TO_WIFI,
    CONNECT_TO_WIFI_RESPONSE      = E_RPC_CONNECT_TO_WIFI_RESPONSE,
    FETCH_CURRENT_WEIGHT          = E_RPC_FETCH_CURRENT_WEIGHT,
    FETCH_CURRENT_WEIGHT_RESPONSE = E_RPC_FETCH_CURRENT_WEIGHT_RESPONSE,
    REGISTER_DISPOSAL             = E_RPC_REGISTER_DISPOSAL,
    REGISTER_DISPOSAL_RESPONSE    = E_RPC_REGISTER_DISPOSAL_RESPONSE
};