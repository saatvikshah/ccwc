cmake_minimum_required(VERSION 3.10)

project(ccwc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable warnings and treat warnings as errors
add_compile_options(-Wall -Wextra -Werror)
add_executable(ccwc main.cpp)

# Clang-Tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "Found clang-tidy: ${CLANG_TIDY_EXE}")
    set_target_properties(ccwc PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
endif()