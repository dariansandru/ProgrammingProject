#include "product.h"

product* make_product(char* name, int price, int stock){
    product* new_product = (product*)malloc(sizeof(product));

    new_product->name = name;
    new_product->price = price;
    new_product->stock = stock;

    return new_product;
}

