cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(tests)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/simple_test)

set(TEST_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
)

list(APPEND RESOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/test_matrix.txt
)

file(COPY 
${RESOURCE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_library(main STATIC ${SOURCE})
add_executable(tests ${TEST_SOURCE})
target_link_libraries(tests PRIVATE simple_test)
target_link_libraries(tests PRIVATE main)
target_compile_features(tests PRIVATE cxx_std_17)

add_test(NAME Test_multiply COMMAND tests test_multiply)
add_test(NAME Test_equal_operator COMMAND tests test_equal_operator)
add_test(NAME Test_no_equal_operator COMMAND tests test_no_equal_operator)
add_test(NAME Test_scan_file COMMAND tests test_scan_file)
