#pragma once

#include "esp_log.h"

void *e_safe_alloc(int size, int length, bool abort);
void *e_safe_realloc(void *ptr, int size, int length, bool abort);

