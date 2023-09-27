#include "esf_utils.hpp"

static const char* TAG = "ESF Utils";

void *safe_alloc(int length, size_t size, bool abort = false) {
    size_t total = length * size;
    void *ptr = calloc(length, size);
    if (ptr == nullptr) {
        ESP_LOGE(TAG, "Failed to allocate memory with size %d (%d * %d) bytes.", total, length, size);
        if (abort) exit(1);
        return nullptr;
    }
    return ptr;
}

void *safe_alloc(void *ptr, int length, size_t size, bool abort = false) {
    size_t total = length * size;
    ptr = realloc(ptr, length * size);
    if (ptr == nullptr) {
        ESP_LOGE(TAG, "Failed to reallocate memory for pointer %p with size %d (%d * %d) bytes.", ptr, total, length, size);
        if (abort) exit(1);
        return nullptr;
    }
    return ptr;
}