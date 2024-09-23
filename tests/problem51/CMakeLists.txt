# 假设你的测试文件路径是 "test.cpp"
set(TEST_FILE_PATH "test.cpp")

# 读取文件内容
file(READ ${TEST_FILE_PATH} FILE_CONTENTS)

# 检查文件中是否包含 "eulerno"
string(FIND "${FILE_CONTENTS}" "eulerno" EULERNO_FOUND)

# 如果没有找到 "eulerno"，则生成可执行文件
if(EULERNO_FOUND EQUAL -1)
  if(BUILD_TESTING)
    get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    set(EXENAME ${DIR_NAME}_test)
    add_executable(${EXENAME} test.cpp
                              ${PROJECT_SOURCE_DIR}/src/${DIR_NAME}/problem.cpp)
    target_include_directories(${EXENAME}
                               PUBLIC ${PROJECT_SOURCE_DIR}/src/${DIR_NAME}/)
    target_link_libraries(${EXENAME} gtest_main prime)
    include(GoogleTest)
    gtest_discover_tests(${EXENAME})
  endif()
else()
  message(
    STATUS
      "Skipping executable generation for ${TEST_FILE_PATH} because it contains 'eulerno'."
  )
endif()
