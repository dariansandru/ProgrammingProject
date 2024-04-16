#include <stdio.h>
#include <stdlib.h>
#include "../domain/product.h"


/**
 * Opens a file
 * @param file_path file path
 * @param mode 'r' for read, 'w' for write
 * @return a pointer to the file stream
 */
FILE* open_file(const char* file_path, const char* mode);

/**
 * Writes a message in a file
 * @param message message to write
 * @param file_path file path
 */
void write_file(const char* file_path, const char* message);


/**
 * Reads messages from a file
 * @param file_path file path
 */
void read_file(const char* file_path);


/**
 * Erases a file
 * @param file_path file path
 */
void erase_file(const char* file_path);


/**
 * Searches for all the products that match a name and price range
 * @param file_path file path
 * @param message char array of the product
 * @param min_val int minimum of the range
 * @param max_val int maximum of the range
 */
void valid_search(const char* file_path, char* message, int min_val, int max_val);


/**
 * Searches for all the products a person has placed
 * @param file_path file path
 * @param name char array name of person
 * @param surname char array surname of person
 */
void search_orders(const char* file_path, char* name, char* surname);


/**
 * Shows all the products that are included in the store
 * @param file_path file path
 */
void show_products(const char* file_path);



void place_order(const char* file_path, product** products, int order_size, char* user);


/**
 * Sells a product to the store
 * @param file_path file path
 */
void sell_products(const char* file_path);


/**
 * Checks if the name of a product is valid
 * @param file_path file path
 * @param product product
 * @return 1 is product is valid, 0 otherwise
 */
int valid_product(const char* file_path, const char* product);


/**
 * Gets the price of a product
 * @param file_path file path
 * @param product product
 * @return the price of the input product
 */
int get_price(const char* file_path, const char* product);


/**
 * Gets the stock of a product
 * @param file_path file path
 * @param product product
 * @return the stock of the input product
 */
int get_stock(const char* file_path, const char* product);
