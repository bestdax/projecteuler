get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${CURRENT_DIR_NAME} main.cpp problem.cpp)
# target_include_directories(${CURRENT_DIR_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
# target_link_directories(${CURRENT_DIR_NAME} PRIVATE ${PROJECT_BINARY_DIR}/lib)
target_link_libraries(${CURRENT_DIR_NAME} number)
	
