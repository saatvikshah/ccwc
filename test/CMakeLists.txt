# Download and install GoogleTest if needed
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Make the content available
FetchContent_MakeAvailable(googletest)

# Add the WordCountTest executable
add_executable(WordCountTest WordCountTest.cpp)

# Link it with gtest and gtest_main
target_link_libraries(WordCountTest gtest_main)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(WordCountTest)