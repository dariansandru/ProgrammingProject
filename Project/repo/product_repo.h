#include <stdlib.h>
#include "../libraries/string_functions.h"
#include "../libraries/file_functions.h"
#include "../domain/product.h"
#include "../libraries/dynamic_array.h"

#ifndef PROJECT_PRODUCT_REPO_H
#define PROJECT_PRODUCT_REPO_H

void product_repo_save(const char* file_path, array* product_arr);

#endif //PROJECT_PRODUCT_REPO_H
