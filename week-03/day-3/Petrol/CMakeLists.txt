cmake_minimum_required(VERSION 3.13)
project(Petrol)

set(CMAKE_CXX_STANDARD 14)

add_executable(Petrol main.cpp Station.cpp Station.h Car.cpp Car.h)