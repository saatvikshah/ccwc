# Download and install GoogleTest if needed
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# Make the content available
FetchContent_MakeAvailable(googletest)

add_executable(ccwc_test WordCountTest.cpp)
target_link_libraries(ccwc_test gtest_main)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(ccwc_test)
enable_clang_tidy(ccwc_test)