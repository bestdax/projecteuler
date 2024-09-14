add_executable(prime_test prime_test.cpp ${PROJECT_SOURCE_DIR}/lib/prime.cpp)
add_executable(stringint_test stringint_test.cpp
                              ${PROJECT_SOURCE_DIR}/lib/stringint.cpp)
add_executable(numutils_test numutils_test.cpp
                             ${PROJECT_SOURCE_DIR}/lib/numutils.cpp)
add_executable(bint_test bint_test.cpp
                             ${PROJECT_SOURCE_DIR}/lib/bigint.cpp)
target_link_libraries(prime_test gtest_main prime)
target_link_libraries(stringint_test gtest_main sint)
target_link_libraries(numutils_test gtest_main numutils)
target_link_libraries(bint_test gtest_main bint)
include(GoogleTest)
gtest_discover_tests(prime_test)
gtest_discover_tests(stringint_test)
gtest_discover_tests(numutils_test)
gtest_discover_tests(bint_test)
