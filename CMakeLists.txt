cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(projecteuler VERSION 1.0)
include(CTest)

set(DAX_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
include_directories(${DAX_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(external)
add_subdirectory(lib)

find_package(GTest REQUIRED)
