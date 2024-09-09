if(BUILD_TESTING)
  get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  set(EXENAME ${DIR_NAME}_test)
  file(
    GLOB TESTFILES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    *.cpp)
  add_executable(${EXENAME} ${TESTFILES} ${LIBFILES})
  target_link_libraries(${EXENAME} gtest_main)
  include(GoogleTest)
  gtest_discover_tests(${EXENAME})
endif()
