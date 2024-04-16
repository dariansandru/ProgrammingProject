#include "product_repo.h"

void product_repo_save(const char *file_path, array* product_arr) {

    int pos = 0;

    while (pos < product_arr->length){
        product* p = (product*) array_get(product_arr, pos);

        char* product_name = p->name;

        int product_price = p->price;
        char* price = my_inttostr(product_price);

        int product_stock = p->stock;
        char* stock = my_inttostr(product_stock);

        char* product_placeholder = my_strcatc(product_name, price, ',');
        char* product = my_strcatc(product_placeholder, stock, ',');
        product = my_strcat(product, "\n");

        write_file(file_path, product);

        pos++;
    }
}

