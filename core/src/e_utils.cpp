#include "e_utils.hpp"


template <typename T>
Array<T>::Array()
{
    data = NULL;
    length = 0;
}

template <typename T>
Array<T>::Array(int size)
{
    data = (T *)e_safe_alloc(sizeof(T), size, true);
    length = size;
}

template <typename T>
Array<T>::~Array()
{
    if (data != NULL)
    {
        free(data);
    }
}

template <typename T>
void Array<T>::add(T item)
{
    data = (T *)e_safe_realloc(data, sizeof(T), length + 1, true);
    data[length] = item;
    length++;
}

template <typename T>
T Array<T>::get(int index)
{
    return data[index];
}

template <typename T>
T Array<T>::set(int index, T item)
{
    if (index < length && index >= 0)
        data[index] = item;
}

template <typename T>
int Array<T>::size()
{
    return length;
}

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

