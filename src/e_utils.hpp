#include "esp_log.h"

#include <string.h>

static const char* TAG = "[e_utils]";

typedef union {
    int length;
    void* ptr;
} e_array;

void *e_safe_alloc(int size, int length, bool abort);
void *e_safe_realloc(void *ptr, int size, int length, bool abort);

