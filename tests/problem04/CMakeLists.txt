get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(targetname test_${CURRENT_DIR_NAME})
add_executable(${targetname} test.cpp ../../src/${CURRENT_DIR_NAME}/problem.cpp)
target_include_directories(${targetname} PUBLIC ../../googletest/googletest/include)
target_include_directories(${targetname} PUBLIC ../../src/${CURRENT_DIR_NAME}/)
target_link_libraries(${targetname} gtest_main)
	
