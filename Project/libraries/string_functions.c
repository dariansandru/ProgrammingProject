// ---String related functions---
#include <stdlib.h>
#include <stdio.h>
#include "string_functions.h"


int my_strlen(const char *arr){

    if (arr == NULL) return 0;

    int index = 0;
    int size = 0;

    while (arr[index] != '\0'){
        index++;
        size++;
    }

    return size;
}


int my_strchr(const char *arr1, const char *arr2){

    char curr_pos = 0;
    for ( int i = 0 ; i < my_strlen(arr1) ; i++ ){

        if ( arr1[i] == arr2[curr_pos] ){
            curr_pos++;
        }
        else{
            curr_pos = 0;
        }

        if ( curr_pos == my_strlen(arr2) ) return 1;
    }

    return 0;

}


int my_straword(const char *word){

    for ( int i = 0 ; i < my_strlen(word) ; i++ ){
        if ( !('A' <= word[i] && word[i] <= 'z') ) return 0;
    }

    return 1;
}


char *my_strcmdl(const char *command){

    char *new_word = (char *)malloc(my_strlen(command) + 1);

    for ( int i = 0 ; i < my_strlen(command) ; i++ ){
        if ( command[i] != ' ' ) new_word[i] = command[i];
        else return new_word;
    }

    return new_word;
}


char *my_strstrip(char *word){
    return my_strstripc(word, ' ');
}


int my_strcmp(char *arr1, const char *arr2){

    if (my_strlen(arr1) == 0) return 1;

    if (my_strlen(arr1) > my_strlen(arr2)) return 1;
    if (my_strlen(arr2) > my_strlen(arr1)) return -1;

    for ( int i = 0 ; i < my_strlen(arr1) ; i++ ){
        if ( arr1[i] > arr2[i] ) return 1;
        else if ( arr2[i] > arr1[i] ) return -1;
    }

    return 0;

}


char *my_strread(int size) {

    char *buffer = malloc(10 * sizeof(char));
    char current = (char)fgetc(stdin);

    int index = 0;
    int curr_size = 10;
    while (current != '\n' && index <= 255){

        if ( index >= curr_size ){
            char *temp_buffer = malloc(curr_size * sizeof(char));

            my_strncpy(temp_buffer, buffer, curr_size);
            free(buffer);

            curr_size *= 2;
            buffer = malloc(curr_size * sizeof(char));
            my_strcpy(buffer, temp_buffer);
            free(temp_buffer);
        }

        buffer[index] = current;
        current = (char)fgetc(stdin);
        index++;
    }

    if ( index < curr_size ){
        char *temp_buffer = malloc(curr_size * sizeof(char));

        my_strncpy(temp_buffer, buffer, index);
        free(buffer);

        buffer = malloc(index * sizeof(char));
        my_strcpy(buffer, temp_buffer);
        free(temp_buffer);
    }

    buffer[index] = '\0';
    return buffer;

}


void my_strcpy(char *dest, const char *source) {

    int source_alloc = my_strlen(source);

    for ( int i = 0 ; i < source_alloc ; i++ ){
        dest[i] = source[i];
    }
    dest[source_alloc] = '\0';

}


void my_strncpy(char *dest, const char *source, int n) {

    for ( int i = 0 ; i <= n ; i++ ){
        dest[i] = source[i];
    }
    //dest[n+1] = '\0';

}


char *my_strtolower(char *command) {

    for ( int i = 0 ; i < my_strlen(command) ; i++ ){
        if ('A' <= command[i] && command[i] <= 'Z') command[i] += 32;
    }

    return command;

}


char my_strsim(char *arr1, char *arr2) {

    int f_arr1[129] = {0};
    int f_arr2[129] = {0};

    for (int i = 0 ; i < my_strlen(arr1) ; i++){
        f_arr1[arr1[i]]++;
    }

    for (int i = 0 ; i < my_strlen(arr2) ; i++){
        f_arr2[arr2[i]]++;
    }

    int diff = 0;
    for (int chr = 0 ; chr < 129 ; chr++){
        if (f_arr1[chr] != 0 && f_arr2[chr] != 0) diff += (f_arr1[chr] > f_arr2[chr]) ? f_arr1[chr] - f_arr2[chr]: f_arr2[chr] - f_arr1[chr];
        if (diff >= 5) return 0;
    }
    return 1;

}


char *my_strparam(char *input, char delim, int pos) {

    int occurrences = 0;
    int next_index = 0;
    int prev_index = 0;

    for (int i = 0; i < my_strlen(input); i++) {
        if (occurrences < pos) {
            if (input[i] == delim) occurrences++;
        }
        else if (occurrences == pos) {
            prev_index = i;
            occurrences++;
        }
        else {
            next_index = i;
            if (input[i] == delim) {
                i += 1;
                while (input[i] == delim && i < my_strlen(input)) {
                    i++;
                    next_index++;
                }
                break;
            }
        }
    }

    if (occurrences < pos) return NULL;

    char *param = (char *)malloc(next_index - prev_index);
    my_strncpy(param, input + prev_index, next_index - prev_index);
    return my_strstripc(param, delim);

}


char *my_strstripc(char *word, char delim){

    if (word == NULL) return 0;

    int first_pos = 0;
    int last_pos = 0;

    for ( int i = 0 ; i < my_strlen(word) ; i++ ){
        if (word[i] == delim) first_pos = i + 1;
        else break;
    }

    for ( int i = my_strlen(word) - 1 ; i >= 0 ; i-- ){
        if (word[i] != delim){
            last_pos = i ;
            break;
        }
    }

    char *new_word;
    new_word = (char *) malloc(last_pos - first_pos + 2);
    int index = 0;

    for ( int i = first_pos ; i <= last_pos ; i++ ){
        new_word[index] = word[i];
        index++;
    }

    return new_word;
}

char *my_strcat(char *arr1, char *arr2) {

    int mem_alloc1 = my_strlen(arr1);
    int mem_alloc2 = my_strlen(arr2);

    char *new_arr = (char *)malloc(mem_alloc1 + mem_alloc2 + 1);

    int index = 0;
    for ( int i = 0 ; i < mem_alloc1 ; i++ ){
        new_arr[index] = arr1[i];
        index++;
    }

    for ( int j = 0 ; j < mem_alloc2 ; j++ ){
        new_arr[index] = arr2[j];
        index++;
    }

    new_arr[index] = '\0';
    return new_arr;

}

char *my_strcatc(char *arr1, char *arr2, char delim) {

    int mem_alloc1 = my_strlen(arr1);
    int mem_alloc2 = my_strlen(arr2);

    char *new_arr = (char *)malloc(mem_alloc1 + mem_alloc2 + 1);

    int index = 0;
    for ( int i = 0 ; i < mem_alloc1 ; i++ ){
        new_arr[index] = arr1[i];
        index++;
    }

    new_arr[index] = delim;
    index++;
    for ( int j = 0 ; j < mem_alloc2 ; j++ ){
        new_arr[index] = arr2[j];
        index++;
    }

    new_arr[index] = '\0';
    return new_arr;

}


int my_strtoint(char *arr) {

    int new_num = 0;
    for ( int i = 0 ; i < my_strlen(arr) ; i++ ){
        new_num = new_num * 10 + (arr[i] - '0');
    }

    return new_num;
}


char* my_inttostr(int num) {

    char* new_num = (char*)malloc(sizeof(char));
    int pos = 0;

    while (num != 0){
        new_num[pos] = (char)(num % 10 + '0');
        pos++;
        num /= 10;
    }

    new_num = my_strrev(new_num);
    return new_num;
}


char* my_strrev(char *arr) {

    for (int i = 0 ; i < my_strlen(arr) / 2 ; i++){
        char aux = arr[i];
        arr[i] = arr[my_strlen(arr) - i - 1];
        arr[my_strlen(arr) - i - 1] = aux;
    }

    return arr;
}



