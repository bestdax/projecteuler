cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(project_euler VERSION 1.0)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(googletest)

