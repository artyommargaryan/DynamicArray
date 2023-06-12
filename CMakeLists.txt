cmake_minimum_required(VERSION 3.25)
project(DynamicArray C)

set(CMAKE_C_STANDARD 11)

add_executable(DynamicArray main.c DynamicArray.h DynamicArrayCPP.h)
