#include "person.h"

person *make_person(char *name, char *surname) {

    person *new_person = (person*)malloc(sizeof(person));
    new_person -> name = (char*)malloc(sizeof(char));
    new_person -> surname = (char*)malloc(sizeof(char));
    my_strcpy(new_person -> name, name);
    my_strcpy(new_person -> surname, surname);

    return new_person;
}
