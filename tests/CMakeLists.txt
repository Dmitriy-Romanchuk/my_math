cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(tests)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/simple_test)

set(TEST_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
)

add_executable(tests ${TEST_SOURCE})
target_link_libraries(tests PRIVATE simple_test)
target_link_libraries(tests PRIVATE main)
target_compile_features(tests PRIVATE cxx_std_17)

add_test(NAME Test_multiply COMMAND tests test_multiply)
add_test(NAME Test_equal_operator COMMAND tests test_equal_operator)
add_test(NAME Test_no_equal_operator COMMAND tests test_no_equal_operator)
add_test(NAME Test_read_from_file COMMAND tests test_read_from_file)