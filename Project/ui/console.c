#include <stdio.h>
#include "console.h"

void print_header() {

    printf("                 ---Welcome to Emag!---\n");
    printf("Here you will be able to find all of your electronic needs!\n\n");
    printf("Before accessing the functionalities of the store, please login using 'login [NAME] [SURNAME]' command!\n");
    printf("If you do not have an account, create one using 'register [NAME] [SURNAME] command!\n");

}


void print_commands(){

    printf("Please select one of the following commands to access that functionality!\n");
    printf("1. Place order                                 2. Sell products to store \n");
    printf("3. View placed orders                          4. Search for products    \n");
    printf("5. Exit                                                                  \n");

}