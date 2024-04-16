#include "../libraries/string_functions.h"
#include "../repo/product_repo.h"

typedef struct order{

    product** products;
    int price;

}order;

order *make_order(product** products, int price);
