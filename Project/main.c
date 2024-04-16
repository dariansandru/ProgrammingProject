#include "libraries/string_functions.h"
#include "ui/console.h"
#include "libraries/file_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libraries/dynamic_array.h"
#include "repo/person_repo.h"
#include "libraries/parse_functions.h"

int main() {

    FILE *fp;
    char* cwd = NULL;
    getcwd(cwd, 1000);
    const char *file_path_users = my_strcat(cwd, "files/users.txt");
    const char *file_path_products = my_strcat(cwd, "files/products.txt");
    const char *file_path_orders = my_strcat(cwd, "files/orders.txt");

    fp = open_file(file_path_users, "r");
    read_file(file_path_users);

    // Print the header for the store
    print_header();

    // Read the login command from input
    char *first_command = my_strread(255);

    // login
    while (1) {
        if (parse_register(first_command, file_path_users)) break;
        if (parse_login(first_command, file_path_users)) break;
        printf("Please login or register before using the store's features!\n");

        first_command = my_strread(255);
    }

    char *account_firstname = my_strparam(first_command, ' ', 1);
    char *account_surname = my_strparam(first_command, ' ', 2);
    char *full_name = my_strcatc(account_firstname, account_surname, ' ');

    // Header to store functionalities
    printf("Welcome %s!\n\n", my_strcatc(account_firstname, account_surname, ' '));
    printf("Account user: %s", my_strcatc(account_firstname, account_surname, ' '));

    fclose(fp);

    char *func_command = "";
    do {
        if (my_strcmp(func_command, "1") == 0 || my_strcmp(func_command, "place order") == 0) {
            product** products = (product**)malloc(sizeof(product));
            int pos = 0;

            show_products(file_path_products);

            printf("\nWhat product would you like to order?\n");
            char* product_order = my_strread(255);

            while (product_order != NULL && my_strcmp(product_order, "") != 0 && my_strcmp(product_order, "done") != 0){
                if (valid_product(file_path_products, product_order) == 1){
                    printf("How many would you like to order?\n");
                    int quantity;
                    quantity = atoi(my_strread(10));

                    if (quantity <= get_stock(file_path_products, product_order)){
                        products[pos] = make_product(product_order, get_price(file_path_products, product_order), quantity);
                        pos++;
                    }
                    else{
                        printf("The current stock for this product is %d!\n", get_stock(file_path_products, product_order));
                    }
                }
                else{
                    printf("Product could not be found!\n");
                }

                printf("Is there anything else you would like to order? If not, type 'done'!\n");
                product_order = my_strread(255);
            }

            place_order(file_path_orders, products, pos, full_name);
            if (pos > 0) printf("Order placed successfully! You may see your current orders by accessing the 'view placed orders' functionality!\n");

            free(products);

        } else if (my_strcmp(func_command, "2") == 0 || my_strcmp(func_command, "sell products to store") == 0) {
            show_products(file_path_products);
            printf("Here are the products we are looking for in the refurbished section of our store!\n");
            sell_products(file_path_products);

            printf("\n");
        } else if (my_strcmp(func_command, "3") == 0 || my_strcmp(func_command, "view placed orders") == 0) {
            printf("Here are the orders you have placed:\n");
            search_orders(file_path_orders, account_firstname, account_surname);

            printf("\n");
        } else if (my_strcmp(func_command, "4") == 0 || my_strcmp(func_command, "search for products") == 0) {
            printf("What are you searching for?\n");
            char *product_search = my_strread(255);
            printf("What is the price range?\n");

            printf("Minimum:");
            int min_val;
            min_val = atoi(my_strread(10));

            printf("Maximum:");
            int max_val;
            max_val = atoi(my_strread(10));

            valid_search(file_path_products, product_search, min_val, max_val);

            printf("\n");
        } else if (my_strcmp(func_command, "5") == 0 || my_strcmp(func_command, "exit") == 0) break;

        printf("\n");
        print_commands();

        func_command = my_strread(255);
        my_strcpy(func_command, my_strstrip(my_strtolower(func_command)));

    } while (my_strcmp(func_command, "5") != 0 && my_strcmp(func_command, "exit") != 0);

    printf("We hope to see you again %s %s!", account_firstname, account_surname);

    exit(0);

}