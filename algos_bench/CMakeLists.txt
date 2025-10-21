
cmake_minimum_required(VERSION 3.14)
project(AlgorithmsProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Устанавливаем тип сборки по умолчанию, если он не задан
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type: Debug, Release, RelWithDebInfo, MinSizeRel")
  message(STATUS "Setting build type to 'Release' as default.")
endif()

# === Библиотека (header-only) ===
add_library(algorithms INTERFACE)
target_include_directories(algorithms INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# === Тесты и бенчмарки ===
enable_testing()
option(BUILD_TESTING "Build the tests and benchmarks" ON)

if(BUILD_TESTING)
    find_package(GTest REQUIRED)
    find_package(benchmark QUIET)

    if(benchmark_FOUND)
        message(STATUS "Found Google Benchmark, building benchmarks.")

        add_executable(bench_knapsack benchmark/bench_knapsack.cpp)
        target_link_libraries(bench_knapsack PRIVATE algorithms benchmark::benchmark)
        
        add_executable(bench_lcs benchmark/bench_lcs.cpp)
        target_link_libraries(bench_lcs PRIVATE algorithms benchmark::benchmark)

        add_executable(bench_sparse_table benchmark/bench_sparse_table.cpp)
        target_link_libraries(bench_sparse_table PRIVATE algorithms benchmark::benchmark)

        add_executable(bench_dijkstra benchmark/bench_dijkstra.cpp)
        target_link_libraries(bench_dijkstra PRIVATE algorithms benchmark::benchmark)
    else()
        message(STATUS "Google Benchmark not found, skipping benchmarks.")
    endif()

    include(GoogleTest)

    add_executable(test_knapsack tests/test_knapsack.cpp)
    target_link_libraries(test_knapsack PRIVATE algorithms GTest::gtest_main)
    gtest_discover_tests(test_knapsack)

    add_executable(test_lcs tests/test_lcs.cpp)
    target_link_libraries(test_lcs PRIVATE algorithms GTest::gtest_main)
    gtest_discover_tests(test_lcs)

    add_executable(test_sparse_table tests/test_sparse_table.cpp)
    target_link_libraries(test_sparse_table PRIVATE algorithms GTest::gtest_main)
    gtest_discover_tests(test_sparse_table)

    add_executable(test_dijkstra tests/test_dijkstra.cpp)
    target_link_libraries(test_dijkstra PRIVATE algorithms GTest::gtest_main)
    gtest_discover_tests(test_dijkstra)
else()
    message(STATUS "BUILD_TESTING is OFF, skipping tests and benchmarks.")
endif()


# --- Настройка документации ---
option(BUILD_DOCS "Build the documentation" ON)

if(BUILD_DOCS)
    find_package(Doxygen)
    find_package(Sphinx)

    if(DOXYGEN_FOUND AND SPHINX_FOUND)
        message(STATUS "Doxygen and Sphinx found, 'docs' target will be available.")

        # --- Настройка Doxygen ---
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

        add_custom_target(doxygen
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
        )

        # --- Настройка Sphinx ---
        set(SPHINX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs/source)
        set(SPHINX_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/docs)
        set(SPHINX_HTML_DIR ${SPHINX_BUILD_DIR}/html)
        set(DOXYGEN_XML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen/xml)

        add_custom_target(docs ALL
            COMMAND ${SPHINX_EXECUTABLE} -b html -D breathe_projects.nop=${DOXYGEN_XML_DIR} ${SPHINX_SOURCE_DIR} ${SPHINX_HTML_DIR}
            COMMENT "Generating documentation with Sphinx"
            VERBATIM
        )

        if(TARGET doxygen)
            add_dependencies(docs doxygen)
        endif()

    else()
        message(STATUS "Doxygen or Sphinx not found. Skipping documentation build.")
    endif()
endif()


# === Исполняемый файл ===
add_executable(knapsack_app src/main_knapsack.cpp)
target_link_libraries(knapsack_app PRIVATE algorithms)

add_executable(lcs_app src/main_lcs.cpp)
target_link_libraries(lcs_app PRIVATE algorithms)

add_executable(sparse_table_app src/main_sparse_table.cpp)
target_link_libraries(sparse_table_app PRIVATE algorithms)

add_executable(dijkstra_app src/main_dijkstra.cpp)
target_link_libraries(dijkstra_app PRIVATE algorithms)
