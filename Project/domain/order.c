#include "order.h"

order* make_order(product** products, int price) {
    order* new_order = (order*)malloc(sizeof(order));
    new_order->price = price;

    int pos = 0;
    while(products[pos] != NULL){
        new_order->products[pos] = products[pos];
        pos++;
    }

    return new_order;
}
