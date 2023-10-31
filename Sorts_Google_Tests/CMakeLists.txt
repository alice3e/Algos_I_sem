cmake_minimum_required(VERSION 3.26)
project(sorting_test)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES main.cpp)
add_executable(SortingAlgos_run ${SOURCE_FILES})

include_directories(SortingAlgos_lib)

add_subdirectory(SortingAlgos_lib)
add_subdirectory(Google_tests)

target_link_libraries(SortingAlgos_run SortingAlgos_lib)

