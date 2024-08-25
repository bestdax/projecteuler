get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(EXENAME ${CURRENT_DIR_NAME})
add_executable(${EXENAME} main.cpp problem.cpp)
target_link_libraries(${EXENAME} PUBLIC bint)
