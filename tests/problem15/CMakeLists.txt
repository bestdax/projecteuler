get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(targetname test_${CURRENT_DIR_NAME})
add_executable(${targetname} test.cpp ${PROJECT_SOURCE_DIR}/src/${CURRENT_DIR_NAME}/problem.cpp)
target_include_directories(${targetname} PUBLIC ${PROJECT_SOURCE_DIR}/googletest/googletest/include)
target_include_directories(${targetname} PUBLIC ${PROJECT_SOURCE_DIR}/src/${CURRENT_DIR_NAME}/)

target_include_directories(${targetname} PUBLIC ${PROJECT_SOURCE_DIR}/src/lib)
target_link_directories(${targetname} PUBLIC ${PROJECT_BINARY_DIR}/src/lib)
target_link_libraries(${targetname} gtest_main longint)

