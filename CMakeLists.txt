cmake_minimum_required(VERSION 3.25)

project(ccwc)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable warnings and treat warnings as errors
add_compile_options(-Wall -Wextra -Werror)

# Find clang-tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "Found clang-tidy: ${CLANG_TIDY_EXE}")
else()
    message(FATAL_ERROR "clang-tidy not found!")
endif()

function(enable_clang_tidy target)
    set_target_properties(${target} PROPERTIES
        CXX_CLANG_TIDY "${CLANG_TIDY_EXE};--quiet"
    )
endfunction()

# Add source and test directories
add_subdirectory(src)
add_subdirectory(test)