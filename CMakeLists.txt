cmake_minimum_required(VERSION 3.29)
project(datastructure C)

set(CMAKE_C_STANDARD 99)

add_executable(datastructure main.c
        assert_utils.c)
