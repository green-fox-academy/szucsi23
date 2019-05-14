cmake_minimum_required(VERSION 3.13)
project(AnimalsInTheZoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnimalsInTheZoo main.cpp Animals.cpp Animals.h Birds.cpp Birds.h Mammals.cpp Mammals.h Reptiles.cpp Reptiles.h)