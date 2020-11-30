cmake_minimum_required(VERSION 3.12)
project(libasm C)

set(CMAKE_C_STANDARD 99)

add_executable(libasm main.c)
add_library(libasm.a)