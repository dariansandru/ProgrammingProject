#include <stdlib.h>

#ifndef PROJECT_PRODUCT_H
#define PROJECT_PRODUCT_H

typedef struct product{
    char* name;
    int price;
    int stock;
}product;

product * make_product(char* name, int price, int stock);

#endif //PROJECT_PRODUCT_H
