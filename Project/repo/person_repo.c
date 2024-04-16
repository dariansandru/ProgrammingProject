//#include "person_repo.h"
//#include "../libraries/dynamic_array.h"
//
//
//array *user_arr;
//void person_repo_load(const char *file_path) {
//    FILE *fp;
//    if (user_arr == NULL) user_arr = array_init(10, sizeof(person));
//    fp = open_file(file_path, "rw");
//
//    char data[255];
//    while(!feof(fp)){
//        fgets(data, 255, fp);
//        person* new_person = make_person(my_strparam(data, ' ', 0),
//                                         my_strparam(data, ' ', 1));
//        array_push(user_arr, new_person);
//    }
//
//}
//
//
//void person_repo_save(const char *file_path) {
//    FILE *fp;
//    fp = open_file(file_path, "w");
//    fclose(fp);
//
//    for (int i = 0 ; i < user_arr -> length ; i++ ){
//        person* pers = (person*) array_get(user_arr, i);
//        write_file(file_path, my_strcatc(pers -> name, pers -> surname, ' '));
//    }
//}
//
//
//void person_repo_add(const char* file_path, struct person* pers) {
//    array_push(user_arr, pers);
//    person_repo_save(file_path);
//}