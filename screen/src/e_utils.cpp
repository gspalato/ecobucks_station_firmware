#include "e_utils.hpp"

void *e_safe_alloc(int size, int length, bool abort)
{
    size_t total = size * length;

    void *ptr = calloc(length, size);
    if (ptr == nullptr) {
        ESP_LOGE("e_utils", "Failed to allocate memory with size %d (%d * %d) bytes.", total, length, size);
        if (abort) exit(1);
        return nullptr;
    }

    return ptr;
}

void *e_safe_realloc(void *ptr, int size, int length, bool abort)
{
    size_t total = length * size;

    ptr = realloc(ptr, length * size);
    if (ptr == nullptr) {
        ESP_LOGE("e_utils", "Failed to reallocate memory for pointer %p with size %d (%d * %d) bytes.", ptr, total, length, size);
        if (abort) exit(1);
        return nullptr;
    }

    memset(ptr, 0, total);
    
    return ptr;
}

