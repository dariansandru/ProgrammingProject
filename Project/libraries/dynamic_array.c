#include "dynamic_array.h"

array* array_init(int initial_length, int elem_size) {
    array* result = (array*)malloc(sizeof(array));

    result -> data = (void*)malloc(initial_length * elem_size);
    result -> length = 0;
    result -> max_length = initial_length;
    result -> elem_size = elem_size;

    return result;
}


void array_flush(array *arr) {
    free(arr -> data);
    free(arr);
}


void array_push(array* arr, void* elem) {
    if (arr -> length == arr -> max_length){
        char** new_data = (char**)malloc(arr -> elem_size * arr -> max_length * 2);
        for ( int i = 0 ; i < arr -> max_length ; i++ ){
            memcpy(new_data + i * (arr -> elem_size), array_get(arr, i), arr -> elem_size);
        }

        arr -> max_length *= 2;
        free(arr -> data);
        arr -> data = new_data;
    }

    memcpy(arr -> data + (arr -> length) * (arr -> elem_size), elem, arr -> elem_size);
    arr -> length++;
}


void* array_get(array *arr, int index) {
    return arr -> data + index * (arr -> elem_size);
}


void array_remove(array *arr, int index) {

    free(arr -> data + index * (arr -> elem_size));
    for ( int j = index + 1 ; j < arr -> length ; j++ ){
        memcpy(arr -> data + (j - 1) * arr -> elem_size, arr -> data + j * arr -> elem_size, arr -> elem_size);
    }
    arr -> length--;

}

