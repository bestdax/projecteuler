add_executable(test01 test01.cpp ../src/problem01/euler01.cpp)
target_include_directories(test01 PUBLIC ../googletest/googletest/include)
target_link_libraries(test01 gtest_main)

