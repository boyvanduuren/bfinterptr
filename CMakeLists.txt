cmake_minimum_required(VERSION 3.2)
project(bfintrptr)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES main.c)
add_executable(bfintrptr ${SOURCE_FILES} main.h main.c)