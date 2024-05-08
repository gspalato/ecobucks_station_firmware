#include "HX711.h"

#include <e_rpc.hpp>

#define SCALE_PIN_DOUT 32
#define SCALE_PIN_SCK 33

extern QueueHandle_t e_scale_weight_buffer;

void e_scale_init();
void e_scale_loop();