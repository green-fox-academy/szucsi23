cmake_minimum_required(VERSION 3.14)
project(bus C)

set(CMAKE_C_STANDARD 11)

add_executable(bus main.c bus.c bus.h)