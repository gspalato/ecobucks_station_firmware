#pragma once

#include <stdlib.h>

#include "esp_log.h"

extern "C" {
    void *safe_alloc(int length, size_t size, bool abort = false);
    void *safe_realloc(void *ptr, int length, size_t size, bool abort = false);
}