#pragma once

#include <stdlib.h>

#include "esp_log.h"

template <typename T> T* safe_alloc(int length, bool abort = false);
template <typename T> T* safe_realloc(T *ptr, int length, bool abort = false);
