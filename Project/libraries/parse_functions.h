#include <stdio.h>
#include "string_functions.h"
#include "file_functions.h"

/**
 * Checks validity of login command
 * @param command command to be checked
 * @param file_path file path
 * @return 1 if login is valid, 0 otherwise
 */
int parse_login(char* command, const char* file_path);


/**
 * Checks validity of register command
 * @param command command to be checked
 * @param file_path file path
 * @return 1 if register is valid, 0 otherwise
 */
int parse_register(char* command, const char* file_path);