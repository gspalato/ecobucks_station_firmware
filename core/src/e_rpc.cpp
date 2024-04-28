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

EventGroupHandle_t xScreenConnectedEventGroup;

void e_rpc_init()
{
    /* Attempt to create the event group. */
    xScreenConnectedEventGroup = xEventGroupCreate();

    /* Was the event group created successfully? */
    if( xScreenConnectedEventGroup == NULL )
    {
        ESP_LOGE(TAG, "Failed to create the xCoreConnectedEventGroup.");
    }

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
void e_rpc_loop()
{
    if (UART.available() > 0)
    {
        String read_string = UART.readStringUntil('\n');
        const char *incoming_data = read_string.c_str();

        Serial.printf("[STRING] Received data (length: %d):\n\t", read_string.length());
        Serial.println(read_string);
        ESP_LOGI(TAG, "[C_STR] Received data (length: %d):\n\t%s", strlen(incoming_data), incoming_data);

        // Parse incoming data.
        JsonDocument doc; // 1024
        deserializeJson(doc, incoming_data);

        // Get method.
        int method = doc["method"];

        switch (method)
        {
        case E_RPC_METHOD::PING:
        {
            ESP_LOGI(TAG, "Received PING from Screen.");

            auto message = e_rpc_generate_message_pong();
            xEventGroupSetBits(xScreenConnectedEventGroup, SCREEN_CONNECTED_BIT);

            UART.println(message);
        }
        break;

        case E_RPC_METHOD::PONG:
        {
            ESP_LOGI(TAG, "Received PONG from Screen.");
            xEventGroupSetBits(xScreenConnectedEventGroup, SCREEN_CONNECTED_BIT);
        }
        break;

        case E_RPC_METHOD::SCAN_NETWORKS:
        {
            ESP_LOGI(TAG, "Received SCAN_NETWORKS.");
            e_rpc_send_scan_network_result();
        }
        break;

        case E_RPC_METHOD::CONNECT_TO_WIFI:
        {
            ESP_LOGI(TAG, "Received CONNECT_TO_WIFI.");

            auto params = doc["params"];
            const char *ssid = params["ssid"];
            const char *password = params["password"];

            auto result = e_wifi_connect(ssid, password);
            auto message = e_rpc_generate_message_connect_to_wifi_result(result);

            UART.println(message);
        }
        break;

        default:
        {
            ESP_LOGW(TAG, "Unknown or unhandled RPC method. (0x%2X)", method);
        }
        break;
        }
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
    JsonDocument doc; // 200
    doc["method"] = E_RPC_METHOD::PING;

    int buffer_size = 25;
    char *buffer = (char*)e_safe_alloc(sizeof(char), buffer_size, true);
    serializeJson(doc, buffer, buffer_size);

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
    JsonDocument doc; // 200
    doc["method"] = E_RPC_METHOD::PONG;

    int buffer_size = 25;
    char *buffer = (char*)e_safe_alloc(sizeof(char), buffer_size, true);
    serializeJson(doc, buffer, buffer_size);

    return buffer;
}

/**
 * @brief Generates a JSON string containing the found WiFi networks. Lists a maximum of 10 networks.
 * @param Vector<char*> networks: The found WiFi networks.
 * @return A JSON string containing the found WiFi networks.
 *
 * @example { "method": 0x05, "networks": ["SSID1", "SSID2", "SSID3"] }
 */
char *e_rpc_generate_message_scan_network_result(std::vector<String> &networks)
{
    JsonDocument doc; // 2048
    doc["method"] = E_RPC_METHOD::SCAN_NETWORKS_RESPONSE;

    JsonDocument networks_doc; // 1024

    for (int i = 0; i < networks.size(); i++)
    {
        String ssid = networks.at(i);
        const char *ssid_str = ssid.c_str();
        ESP_LOGI(TAG, "* Found network: %s", ssid_str);
        networks_doc.add(ssid);
    }

    doc["params"]["networks"] = networks_doc;

    int buffer_size = 1024;
    char *buffer = (char*)e_safe_alloc(sizeof(char), buffer_size, true);
    serializeJson(doc, buffer, buffer_size);

    return buffer;
}

/**
 * @brief Sends the result of the WiFi network scan to the Screen.
 * @return void
 */
void e_rpc_send_scan_network_result()
{
    auto networks = e_wifi_scan_networks();
    auto message = e_rpc_generate_message_scan_network_result(*networks);
    UART.println(message);
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
    JsonDocument doc; // 200
    doc["method"] = E_RPC_METHOD::CONNECT_TO_WIFI_RESPONSE;
    doc["params"]["result"] = result;

    int buffer_size = 64;
    char *buffer = (char*)e_safe_alloc(sizeof(char), buffer_size, true);
    serializeJson(doc, buffer, buffer_size);

    return buffer;
}