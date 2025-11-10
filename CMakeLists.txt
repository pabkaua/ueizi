cmake_minimum_required(VERSION 3.26)
project(ueizi C)

set(CMAKE_C_STANDARD 99)

add_executable(ueizi
        main.c
        arquivo.c
        alertas.c
        relatorios.c
        persistencia.c)
