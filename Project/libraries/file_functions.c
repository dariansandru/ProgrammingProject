#include <stdlib.h>
#include <stdio.h>
#include "string_functions.h"
#include "file_functions.h"
#include "../domain/product.h"
#include "../repo/product_repo.h"
#include "../repo/order_repo.h"
#include "../domain/person.h"
#include "../libraries/dynamic_array.h"


FILE *open_file(const char *file_path, const char *mode) {
    if (file_path == NULL || mode == NULL || my_strlen(file_path) == 0 || my_strlen(mode) == 0 ) return NULL;

    FILE* file = fopen(file_path, mode);
    return file;
}


void write_file(const char *file_path, const char *message) {
    if (my_strlen(message) == 0 || message == NULL) return;

    FILE* file = open_file(file_path, "a");
    if (file == NULL ) return;

    fprintf(file, "%s", message);
    fclose(file);
}


void read_file(const char *file_path) {
    FILE* file = open_file(file_path, "r");
    if ( file == NULL ) return;

    char data[200];

    while (!feof(file)){
        fgets(data, 200, file);
    }

}


void valid_search(const char *file_path, char *message, int min_val, int max_val) {
    if (message == NULL) return;

    FILE* file = open_file(file_path, "r");
    if ( file == NULL ) return;

    char data[255];
    char found = 0;

    while (!feof(file)){
        fgets(data, 255, file);

        char *product = my_strstrip(my_strparam(data, ',', 0));
        char *product_copy = (char*)malloc(sizeof(char));
        my_strcpy(product_copy, product);

        char *price = my_strstrip(my_strparam(data, ',', 1));
        int new_price = atoi(price);

        char flag1 = 0;
        char flag2 = 0;

        if (my_strchr(my_strtolower(product_copy), my_strtolower(message)) == 1) flag1 = 1;
        if (min_val <= new_price && new_price <= max_val) flag2 = 1;

        if (flag1 == 1 && flag2 == 1){
            if (found == 0) printf("The result of your search is:\n");
            printf("%d.  %s\n", found + 1, product);
            found++;
        }

        free(product_copy);
    }

    if (found == 0) printf("No products match your search!");

}


void search_orders(const char *file_path, char *name, char *surname) {

    FILE *file = open_file(file_path, "r");
    if (file == NULL) return;

    char data[255];
    char* user = my_strcatc(name, surname, ' ');

    int order_price = 0;
    while(!feof(file)){

        my_strcpy(data, "");
        fgets(data, 255, file);

        if (my_strlen(my_strstrip(my_strstripc(data, '\n'))) == 0){
            continue;
        }

        if (my_strcmp(user, my_strparam(data, ',', 0)) == 0){
            order_price += my_strtoint(my_strparam(data, ',', 2));
            printf("Product: %s, Quantity: %s", my_strparam(data, ',', 1), my_strparam(data, ',', 3));
        }
    }
    printf("Your order's price is: %d!", order_price);
}


void show_products(const char* file_path){

    FILE *file = open_file(file_path, "r");
    if (file == NULL) return;

    char data[255];
    while (!feof(file)){

        my_strcpy(data, "");
        fgets(data, 255, file);

        if (my_strlen(my_strstrip(my_strstripc(data, '\n'))) == 0){
            continue;
        }

        char* product = my_strparam(data, ',', 0);
        int product_stock = atoi(my_strparam(data, ',', 2));

        printf("Name: %s, Quantity: %d\n", product, product_stock);

    }
}


void sell_products(const char* file_path){

    FILE *file = open_file(file_path, "r");
    if (file == NULL) return;

    //product** product_arr = (product**)malloc(sizeof(product));
    array* product_arr = array_init(10, sizeof(product));

    char data[255];
    while (!feof(file)){

        my_strcpy(data, "");
        fgets(data, 255, file);

        if (my_strlen(my_strstrip(my_strstripc(data, '\n'))) == 0){
            continue;
        }

        char* product_name = my_strparam(data, ',', 0);
        int product_price = atoi(my_strparam(data, ',', 1));
        int product_stock = atoi(my_strparam(data, ',', 2));

        product* curr_product = make_product(product_name, product_price, product_stock);
        array_push(product_arr, curr_product);
    }

    printf("What product would you like to sell?\n");
    char* sold_product = my_strread(255);

    char found = 0;
    for (int i = 0; i < product_arr->length; i++ ){
        product* p = ((product*)(array_get(product_arr, i)));
        if (my_strcmp(p->name, sold_product) == 0){
            found++;
            printf("How many of this products will you be selling? (Max. 5 allowed)\n");
            int quantity; quantity = atoi(my_strread(10));

            while(quantity > 5){
                printf("You cannot sell that quantity, max. 5 allowed!\n");
                quantity = atoi(my_strread(10));
            }
            printf("Selling was successful! Your money will be transferred somewhere between now and never!\n");
            p->stock += quantity;
        }
    }

    if (found == 0) { printf("The product you wanted to sell could not be found!\n"); return; }

    erase_file(file_path);
    product_repo_save(file_path, product_arr);

    free(product_arr);

}


void erase_file(const char *file_path) {

    FILE* file = open_file(file_path, "w");
    if (file == NULL ) return;

    fprintf(file, "%s", "");
    fclose(file);

}


void place_order(const char *file_path, product** products, int order_size, char* user) {
    FILE *file = open_file(file_path, "r");
    if (file == NULL) return;

    for ( int pos = 0 ; pos < order_size ; pos++ ){
        char* new_line = my_strcatc(user,
                         my_strcatc(products[pos]->name,
                         my_strcatc(my_inttostr(products[pos]->price), my_inttostr(products[pos]->stock), ','),
                         ','), ',');
        new_line = my_strcat(new_line, "\n");

        write_file(file_path, new_line);
    }


}


int valid_product(const char *file_path, const char *product) {
    if (product == NULL) return 0;

    FILE* file = open_file(file_path, "r");
    if ( file == NULL ) return 0;

    char data[255];
    while(!feof(file)){

        fgets(data, 255, file);
        char* new_product = my_strparam(data, ',', 0);

        if (my_strcmp(my_strstrip(new_product), my_strstrip(product)) == 0) return 1;
    }

    return 0;
}


int get_price(const char *file_path, const char *product) {
    if (product == NULL) return 0;

    FILE* file = open_file(file_path, "r");
    if ( file == NULL ) return 0;

    char data[255];
    while(!feof(file)){

        fgets(data, 255, file);
        char* new_product = my_strparam(data, ',', 0);

        if (my_strcmp(new_product, product) == 0){
            return atoi(my_strparam(data, ',', 1));
        }
    }

    return 0;
}


int get_stock(const char *file_path, const char *product) {
    if (product == NULL) return 0;

    FILE* file = open_file(file_path, "r");
    if ( file == NULL ) return 0;

    char data[255];
    while(!feof(file)){

        fgets(data, 255, file);
        char* new_product = my_strparam(data, ',', 0);

        if (my_strcmp(my_strstrip(new_product), product) == 0){
            return atoi(my_strparam(data, ',', 2));
        }
    }

    return 0;
}

