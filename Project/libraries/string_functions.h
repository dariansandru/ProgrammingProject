#include <stdlib.h>

/**
 * Returns the length of a char array
 * @param arr char array
 * @return int length of the char array
 */
int my_strlen(const char *arr);


/**
 * Returns whether a string is a substring of another
 * @param arr1 char array that is checked for a subarray
 * @param arr2 char array that is the subarray
 * @return 1, if arr2 is a subarray of arr1 ; 0, otherwise
 */
int my_strchr(const char *arr1, const char *arr2);


/**
 * Returns if a string contains illegal characters
 * @param word char array that is checked for illegal characters
 * @return 1, if word does not contain illegal characters ; 0, if word contains illegal characters
 */
int my_straword(const char *word);


/**
 * Returns the command label from a command
 * @param command command char array
 * @return first word from a command
 */
char *my_strcmdl(const char *command);


/**
 * Returns the stripped version of a char array
 * @param word char array that is stripped
 * @return the stripped version of the char array
 */
char *my_strstrip(char *word);


/**
 * Returns the stripped version of a char array based on a char
 * @param word char array that is stripped
 * @param delim delimitation for stripping
 * @return the stripped version of the char array
 */
char *my_strstripc(char *word, char delim);

/**
 * Compares two char arrays alphabetically
 * @param arr1 first char array
 * @param arr2 second char array
 * @return 1, if arr1 > arr2 ; 0, if arr1 = arr2 ; -1, if arr1 < arr2
 */
int my_strcmp(char *arr1, const char *arr2);

/**
 * Copies a char array from a char* source to a char* destination
 * @param dest char array destination
 * @param source char array source
 */
void my_strcpy(char *dest, const char *source);


/**
 * Reads a char array from buffer
 * @param size maximum size of char array
 * @return copied char array
 */
char *my_strread(int size);


/**
 * Copies n characters from a char array from a char* source to a char* destination
 * @param dest char array destination
 * @param source char array source
 * @param n number of characters that are copied
 */
void my_strncpy(char *dest, const char *source, int n);


/**
 * Lowers all uppercase characters from a char array
 * @param command command to lower
 * @return the char array with all lowercase characters
 */
char *my_strtolower(char *command);


/**
 * Checks if two char arrays are similar (have <5 uncommon characters)
 * @param arr1 first char array
 * @param arr2 second char array
 * @return 1 if arr1 is similar to arr2, 0 otherwise
 */
char my_strsim(char *arr1, char *arr2);


/**
 * Returns the nth word from a char array based on a delimiter
 * @param command command to find the word in
 * @param delim delimiter
 * @param pos position of the word searched for
 * @return char array representing the word on the nth position
 */
char *my_strparam(char *command, char delim, int pos);


/**
 * Concatenates two char arrays
 * @param arr1 first char array
 * @param arr2 second char array
 * @return concatenation of the char arrays
 */
char *my_strcat(char *arr1, char *arr2);


/**
 * Concatenates two char arrays with a delimiter between them
 * @param arr1 first char array
 * @param arr2 second char array
 * @param delim delimiter
 * @return concatenation of the char arrays
 */
char *my_strcatc(char *arr1, char *arr2, char delim);


/**
 * Converts a char to an integer
 * @param arr char array given
 * @return the integer form of a char array
 */
int my_strtoint(char *arr);


/**
 * Converts an integer to a char array
 * @param num number to be converted
 * @return the converted number
 */
char* my_inttostr(int num);


/**
 * Reverses a char array
 * @param arr char array
 * @return the reversed version of the char array
 */
char* my_strrev(char* arr);


