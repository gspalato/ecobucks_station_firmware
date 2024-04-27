#pragma once

#include "Arduino.h"

#include "esp_log.h"

#define UART Serial

#define UART_RX_PIN GPIO_NUM_16
#define UART_TX_PIN GPIO_NUM_17
#define UART_NUMBER 2
#define UART_BAUDRATE 115200

static const int RX_BUF_SIZE = 1024;

void e_serial_init();