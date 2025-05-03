find_path(TCLAP_INCLUDE_DIR tclap/CmdLine.h
    HINTS /opt/homebrew/include /usr/local/include /usr/include
)

if(NOT TCLAP_INCLUDE_DIR)
    message(FATAL_ERROR "TCLAP not found. Please install it with `brew install tclap`.")
endif()

add_executable(ccwc main.cpp)
target_include_directories(ccwc SYSTEM PRIVATE ${TCLAP_INCLUDE_DIR})
target_link_libraries(ccwc)
enable_clang_tidy(ccwc)