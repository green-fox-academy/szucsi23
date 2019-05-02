cmake_minimum_required(VERSION 3.14)
project(extension)

set(CMAKE_CXX_STANDARD 14)

# Change this to the name of the directory that contains your code
set(PROJECT_LIB_NAME extension_lib)
# Change this to the name of the directory that contains your tests
set(PROJECT_TESTS_NAME extension_tests)
# Change this to the path where you extracted the Google Test files to
set(PATH_TO_GOOGLETEST "C:/Users/hun46/Documents/Programming/GreenFox/googletest")
# The next line creates an executable file from main.cpp with the same name as your project
add_executable(${PROJECT_NAME} main.cpp extension_lib/extension.cpp extension_lib/extension.h)
# This block includes the subdirectories containing your code and tests
include_directories(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_TESTS_NAME})
# This line links your code to the main executable
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIB_NAME})
