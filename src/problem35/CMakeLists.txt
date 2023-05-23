get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(targetname ${CURRENT_DIR_NAME})
add_executable(${targetname} main.cpp problem.cpp)

target_include_directories(${targetname} PUBLIC ${PROJECT_SOURCE_DIR}/src/lib)
target_link_directories(${targetname} PUBLIC ${PROJECT_BINARY_DIR}/src/lib)
target_link_libraries(${targetname} number number)

