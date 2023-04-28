get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(targetname ${CURRENT_DIR_NAME})
add_executable(${targetname} main.cpp problem.cpp)

