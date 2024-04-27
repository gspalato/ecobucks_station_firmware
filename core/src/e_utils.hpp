#pragma once

#include "esp_log.h"

#include <string.h>

template <typename T>
class Array
{
    public:
        T *data;
        int length;

        Array();
        Array(int size);
        ~Array();

        void add(T item);
        T get(int index);
        T set(int index, T item);

        int size();
};

void *e_safe_alloc(int size, int length, bool abort);
void *e_safe_realloc(void *ptr, int size, int length, bool abort);

