cmake_minimum_required(VERSION 3.10)
project(IndexGenerator02)

# Include directory for header files
include_directories(include)

# Specify the executable and its source files
add_executable(IndexGenerator02 src/main.c
        test/common_words.h)

# Link any necessary libraries (if you have any)
target_link_libraries(IndexGenerator02 m)
