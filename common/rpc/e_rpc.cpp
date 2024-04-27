#include "e_rpc.hpp"

/*
    The Ecobucks Station's prototype has two main components: the Ecobucks Station Core and Screen.

    * Core: Responsible for handling the station's main functionalities, such as connecting to the WiFi network,
    scanning for networks, and registering disposals.
    * Screen: Responsible for displaying the station's user interface, such as the main menu, network selection,
    and disposal registration.

    Since the Core and Screen are separate components, they need to communicate with each other.
    To achieve this, we will use a Remote Procedure Call (RPC) mechanism.
    We decided to communicate via JSON, due to it's simplicity to implement instead of using a more complex
    protocol like MQTT.
*/

static const char *TAG = "e_rpc";

void e_rpc_init()
{
    UART.begin(UART_BAUDRATE, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN);

    while (!UART)
    {
        delay(10);
    }

    ESP_LOGI(TAG, "UART initialized.");

    while (!UART.availableForWrite())
    {
        delay(10);
    }

    UART.println(e_rpc_generate_message_ping());
}

/**
 * @brief Handles incoming UART data, parses it and calls the handler function.
 * @param void The handler function.
*/
void e_rpc_loop(void (*handler)(int method, JsonDocument doc))
{
    if (UART.available() > 0)
    {
        auto incomingData = UART.readString();

        ESP_LOGI(TAG, "Received data: %s", incomingData);

        // Parse incoming data.
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, incomingData);

        // Get method.
        int method = doc["method"];

        handler(method, doc);
    }
}

/**
 * @brief Generates a JSON string containing the ping message.
 * @return A JSON string containing the ping message.
 * 
 * @example { "method": 0x02 }
*/
char *e_rpc_generate_message_ping()
{
    DynamicJsonDocument doc(200);
    doc["method"] = E_RPC_METHOD::PING;

    char buffer[25];
    serializeJson(doc, buffer);

    return buffer;
}

/**
 * @brief Generates a JSON string containing the pong message.
 * @return A JSON string containing the pong message.
 * 
 * @example { "method": 0x03 }
*/
char *e_rpc_generate_message_pong()
{
    DynamicJsonDocument doc(200);
    doc["method"] = E_RPC_METHOD::PONG;

    char buffer[25];
    serializeJson(doc, buffer);

    return buffer;
}

/**
 * @brief Generates a JSON string containing the found WiFi networks. Lists a maximum of 10 networks.
 * @param Vector<char*> networks: The found WiFi networks.
 * @return A JSON string containing the found WiFi networks.
 * 
 * @example { "method": 0x05, "networks": ["SSID1", "SSID2", "SSID3"] }
*/
char *e_rpc_generate_message_scan_network_result(Vector<char*> networks)
{
    DynamicJsonDocument doc(2048);
    doc["method"] = E_RPC_METHOD::SCAN_NETWORKS_RESPONSE;

    DynamicJsonDocument networks_doc(1024);

    for (int i = 0; i < networks.size(); i++)
    {
        networks_doc.add(networks[i]);
    }

    doc["networks"] = networks_doc;

    char buffer[1024];
    serializeJson(doc, buffer);

    return buffer;
}

/**
 * @brief Generates a JSON string containing the result of the WiFi connection.
 * @param e_wifi_connect_result_t result: The result of the WiFi connection.
 * @return A JSON string containing the result of the WiFi connection.
 * 
 * @example { "method": 0x07, "result": 0x00 }
*/
char *e_rpc_generate_message_connect_to_wifi_result(e_wifi_connect_result_t result)
{
    DynamicJsonDocument doc(200);
    doc["method"] = E_RPC_METHOD::CONNECT_TO_WIFI_RESPONSE;
    doc["result"] = result;

    char buffer[64];
    serializeJson(doc, buffer);

    return buffer;
}