if(BUILD_TESTING)
  get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  set(EXENAME ${DIR_NAME}_test)
  add_executable(${EXENAME} prime_test.cpp
                            ${PROJECT_SOURCE_DIR}/lib/prime.cpp)
  target_link_libraries(${EXENAME} gtest_main)
  include(GoogleTest)
  gtest_discover_tests(${EXENAME})
endif()
