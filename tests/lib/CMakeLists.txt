get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(targetname test_${CURRENT_DIR_NAME})

file(
  GLOB CPPFILES
  RELATIVE ${PROJECT_SOURCE_DIR}/src/lib
  *.cpp)
add_executable(${targetname} test.cpp ${CPPFILES})
enable_testing()

target_include_directories(${targetname} PUBLIC ${PROJECT_SOURCE_DIR}/src/lib)
target_link_directories(${targetname} PUBLIC ${PROJECT_BINARY_DIR}/src/lib)
target_link_libraries(${targetname} gtest_main lint number)

add_test(NAME libtest COMMAND ${targetname})
