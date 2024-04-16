#include "parse_functions.h"


int parse_login(char *command, const char* file_path){
    command = my_strstrip(command);
    char *command_firstword = my_strcmdl(command);

    if (my_strcmp(command_firstword, "login") != 0){
        return 0;
    }
    if (my_strparam(command, ' ', 3) != NULL) return 0;

    FILE* file = open_file(file_path, "r");
    char data[200];

    char* name = my_strparam(command, ' ', 1);
    char* surname = my_strparam(command, ' ', 2);

    if (name == NULL || surname == NULL) return 0;
    if (my_strlen(name) <= 1 || my_strlen(surname) <= 1) return 0;

    while(!feof(file)){
        fgets(data, 200, file);
        char* curr_name = my_strparam(data, ' ', 0);
        char* curr_surname = my_strparam(data, ' ', 1);

        curr_name = my_strstripc(curr_name, '\n');
        curr_surname = my_strstripc(curr_surname, '\n');

        if (curr_surname != NULL && curr_name != NULL)
            if (my_strcmp(name, curr_name) == 0 && my_strcmp(surname, curr_surname) == 0) return 1;
    }
    printf("User was not found!\n");
    return 0;
}


int parse_register(char *command, const char* file_path){

    command = my_strstrip(command);
    char *command_firstword = my_strcmdl(command);

    if (my_strcmp(command_firstword, "register") != 0){
        return 0;
    }
    char data[200];

    char* name = my_strparam(command, ' ', 1);
    char* surname = my_strparam(command, ' ', 2);

    if (name == NULL || surname == NULL) return 0;
    if (my_strlen(name) <= 1 || my_strlen(surname) <= 1) return 0;

    FILE* file = open_file(file_path, "r");

    while (!feof(file)){
        fgets(data, 255, file);

        char* curr_name = my_strparam(data, ' ', 0);
        char* curr_surname = my_strparam(data, ' ', 1);

        if (curr_surname != NULL && curr_name != NULL)
            if (my_strcmp(name, curr_name) == 0 && my_strcmp(surname, curr_surname) == 0){
                printf("There is already an user with this name and surname!\n");
                return 0;
            }
    }

    write_file(file_path, my_strcat(my_strcatc(name, surname, ' '), "\n"));
    printf("You have registered successfully!\n");
    return 1;

}