#include "e_rpc.hpp"

static const char *TAG = "e_rpc";

EventGroupHandle_t xCoreConnectedEventGroup;

void e_rpc_init()
{
    /* Attempt to create the event group. */
    xCoreConnectedEventGroup = xEventGroupCreate();

    /* Was the event group created successfully? */
    if( xCoreConnectedEventGroup == NULL )
    {
        ESP_LOGE(TAG, "Failed to create the xCoreConnectedEventGroup.");
    }

    //UART.begin(UART_BAUDRATE, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN);
    UART.begin(UART_BAUDRATE);

    while (!UART)
    {
        delay(10);
    }

    ESP_LOGI(TAG, "UART initialized.");

    while (!UART.availableForWrite())
    {
        delay(10);
    }

    e_rpc_ping_request();
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
            ESP_LOGI(TAG, "Received PING from Core.");
            ESP_LOGI(TAG, "Core connected. Switching to main screen.");

            xEventGroupSetBits(xCoreConnectedEventGroup, CORE_CONNECTED_BIT);

            e_rpc_pong_request();
        }
        break;

        case E_RPC_METHOD::PONG:
        {
            ESP_LOGI(TAG, "Received PONG from Core.");
            xEventGroupSetBits(xCoreConnectedEventGroup, CORE_CONNECTED_BIT);
        }

        case E_RPC_METHOD::SCAN_NETWORKS_RESPONSE:
        {
            ESP_LOGI(TAG, "Received SCAN_NETWORKS_RESPONSE.");

            // The format received is
            // { "method": 0x05, "params": { "networks": ["ssid", "ssid2", "ssid3"] } }

            auto networks = doc["data"]["networks"];
            auto networks_size = networks.size();

            lv_dropdown_clear_options(ui_SSIDDropdown);
            if (networks.isNull() || networks_size == 0)
            {
                ESP_LOGW(TAG, "No networks found.");
                lv_dropdown_set_options(ui_SSIDDropdown, "No networks found.");

                lv_obj_clear_flag(ui_PasswordTextArea, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_set_style_bg_color(ui_PasswordTextArea, lv_color_hex(0xaaaaaa), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(ui_PasswordTextArea, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT);

                return;
            }
            else
            {
                lv_obj_add_flag(ui_PasswordTextArea, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_set_style_bg_opa(ui_PasswordTextArea, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);

                for (int i = 0; i < networks_size; ++i)
                {
                    const char *ssid = networks[i];
                    lv_dropdown_add_option(ui_SSIDDropdown, ssid, LV_DROPDOWN_POS_LAST);
                    ESP_LOGI(TAG, "Discovered network \"%s\"", ssid);
                }
            }
        }
        break;

        case E_RPC_METHOD::CONNECT_TO_WIFI_RESPONSE:
        {
            ESP_LOGI(TAG, "Received CONNECT_TO_WIFI_RESPONSE.");

            int result = doc["data"]["result"];
            switch (result)
            {
                case 0:
                {
                    // Success.
                    ESP_LOGI(TAG, "Connected.");
                    lv_scr_load(ui_MainScreen);
                }
                break;

                case 1:
                {
                    // Invalid password.
                    lv_obj_set_style_border_color(ui_PasswordTextArea, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                break;
            }
        }
        break;

        case E_RPC_METHOD::FETCH_CURRENT_WEIGHT_RESPONSE:
        {
            ESP_LOGI(TAG, "Received FETCH_CURRENT_WEIGHT_RESPONSE.");

            long weight = doc["data"]["weight"];

            lv_label_set_text_fmt(ui_CurrentWeightLabel, "%ldg", weight);
        }

        default:
        {
            ESP_LOGW(TAG, "Unknown or unhandled RPC method. (0x%2X)", method);
        }
        break;
        }
    }
}

/**
 * @brief Generates a JSON string containing the log message.
 * @param const char *message: The message to log.
 * @return A JSON string containing the log message.
*/
/*
char *e_rpc_generate_message_log(const char *tag, e_log_level_t level, const char *message)
{
    JsonDocument doc; // 200
    doc["method"] = E_RPC_METHOD::LOG;
    doc["params"]["tag"] = tag;
    doc["params"]["level"] = (int)level; // e_log_level_t is an enum, so we cast it to an int.
    doc["params"]["message"] = message;

    int buffer_size = 1536;
    char *buffer = (char*)e_safe_alloc(sizeof(char), buffer_size, true);
    serializeJson(doc, buffer, buffer_size);

    return buffer;
}
*/

/**
 * @brief Sends a log message to the Core.
 * @param const char *message: The message to log.
 * @return void
*/
/*
void e_rpc_log(const char *tag, e_log_level_t level, const char *message)
{
    auto log_message = e_rpc_generate_message_log(tag, level, message);
    // ESP_LOGI(TAG, "Sending log message: %s", log_message);
    UART.println(log_message);
}
*/

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
 * @brief Sends a PING request to the Core.
 * @param void
 * @return void
*/
void e_rpc_ping_request()
{
    auto message = e_rpc_generate_message_ping();
    ESP_LOGI(TAG, "Sending PING request: %s", message);
    UART.println(message);
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
 * @brief Sends a PONG request to the Core.
 * @param void
 * @return void
*/
void e_rpc_pong_request()
{
    auto message = e_rpc_generate_message_pong();
    ESP_LOGI(TAG, "Sending PONG request: %s", message);
    UART.println(message);
}

/**
 * @brief Generates a JSON string containing the request to connect to WiFi.
 * @param e_wifi_connect_result_t result: The result of the WiFi connection.
 * @return A JSON string containing the result of the WiFi connection.
 *
 * @example { "method": 0x07, "result": 0x00 }
 */
char *e_rpc_generate_message_connect_to_wifi_request(char *ssid, char *password)
{
    JsonDocument doc; // 200
    doc["method"] = E_RPC_METHOD::CONNECT_TO_WIFI;
    doc["params"]["ssid"] = ssid;
    doc["params"]["password"] = password;

    int buffer_size = 128;
    char *buffer = (char*)e_safe_alloc(sizeof(char), buffer_size, true);
    serializeJson(doc, buffer, buffer_size);

    ESP_LOGI(TAG, "Generated CONNECT_TO_WIFI request: %s", buffer);

    return buffer;
}

/**
 * @brief Sends a CONNECT_TO_WIFI request to the Core.
 * @param char* ssid: The SSID of the network to connect to.
 * @param char* password: The password of the network to connect to.
 * @return void
*/
void e_rpc_connect_to_wifi_request(char *ssid, char *password)
{
    auto message = e_rpc_generate_message_connect_to_wifi_request(ssid, password);
    ESP_LOGI(TAG, "Sending CONNECT_TO_WIFI request: %s", message);
    UART.println(message);
}

/**
 * @brief Generates a JSON string containing the SCAN_NETWORKS message.
 * @param void
 * @return void
*/
char *e_rpc_generate_message_scan_networks_request()
{
    JsonDocument doc; // 200
    doc["method"] = E_RPC_METHOD::SCAN_NETWORKS;

    int buffer_size = 64;
    char *buffer = (char*)e_safe_alloc(sizeof(char), buffer_size, true);
    serializeJson(doc, buffer, buffer_size);

    return buffer;
}

/**
 * @brief Sends a SCAN_NETWORKS request to the Core.
 * @param void
 * @return void
*/
void e_rpc_scan_networks_request()
{
    auto message = e_rpc_generate_message_scan_networks_request();
    ESP_LOGI(TAG, "Sending SCAN_NETWORKS request: %s", message);
    UART.println(message);
}