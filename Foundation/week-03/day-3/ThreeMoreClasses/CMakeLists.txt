cmake_minimum_required(VERSION 3.13)
project(ThreeMoreClasses)

set(CMAKE_CXX_STANDARD 14)

add_executable(ThreeMoreClasses main.cpp Animal.cpp Animal.h Sharpie.cpp Sharpie.h Counter.cpp Counter.h SharpieSet.cpp SharpieSet.h Farm.cpp Farm.h)