cmake_minimum_required(VERSION 3.25)
project(count_distinct C)

set(CMAKE_C_STANDARD 11)

add_executable(count_distinct new_solution.c main.c old_easy_way.c)
