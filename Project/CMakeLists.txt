cmake_minimum_required(VERSION 3.27)
project(Project C)

set(CMAKE_C_STANDARD 11)

add_executable(Project main.c
        libraries/string_functions.c
        ui/console.c
        ui/console.h
        libraries/file_functions.h
        libraries/file_functions.c
        repo/person_repo.h
        domain/person.h
        libraries/dynamic_array.c
        libraries/dynamic_array.h
        domain/product.h
        domain/person.c
        domain/product.c
        repo/product_repo.h
        repo/product_repo.c
        domain/order.h
        domain/order.c
        repo/order_repo.h
        repo/order_repo.c
        repo/person_repo.c
        libraries/parse_functions.h
        libraries/parse_functions.c
)
