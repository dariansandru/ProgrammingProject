#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array{
    int length;
    int max_length;

    int elem_size;
    char** data;
}array;


array* array_init(int initial_length, int elem_size);


void array_flush(array* arr);


void array_push(array* arr, void* elem);


void array_remove(array* arr, int index);


void* array_get(array* arr, int index);