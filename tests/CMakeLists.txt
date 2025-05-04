cmake_minimum_required(VERSION 3.10)
project(tests)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add test executable
add_executable(test_main test_main.cpp)
target_link_libraries(test_main gtest gtest_main)

# Add tests
add_test(NAME ExampleTest COMMAND test_main)
