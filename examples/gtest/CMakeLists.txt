cmake_minimum_required(VERSION 3.7)

project(gtest_example VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

## main
add_executable(code code.cpp)

## test
add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE gtest)

## tests
enable_testing()
add_subdirectory(../../third_party/gtest ./third_party/gtest)
add_test(NAME main COMMAND tests)

