cmake_minimum_required(VERSION 3.17)
project(sudoku C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(sudoku
        main.c
        print.c
        sudoku.h)
