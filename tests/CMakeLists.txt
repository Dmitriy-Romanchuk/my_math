cmake_minimum_required(VERSION 3.21.3)
project(tests)

# find_package (Boost COMPONENTS unit_test_framework REQUIRED)
set(test_source
    ${CMAKE_CURRENT_SOURCE_DIR/} test_multiply.cpp
    ${CMAKE_CURRENT_SOURCE_DIR/} test_read_from_file.cpp
    ${CMAKE_CURRENT_SOURCE_DIR/} test_equal_operator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR/} test_not_equal_operator.cpp
    )

add_executable(test_multiply test_multiply.cpp)
add_executable(test_read_from_file test_read_from_file.cpp)
add_executable(test_equal_operator test_equal_operator.cpp)
add_executable(test_not_equal_operator test_not_equal_operator.cpp)

target_link_libraries(test_multiply ${Boost_LIBRARIES} main)
target_link_libraries(test_read_from_file ${Boost_LIBRARIES} main)
target_link_libraries(test_equal_operator ${Boost_LIBRARIES} main)
target_link_libraries(test_not_equal_operator ${Boost_LIBRARIES} main)
enable_testing()

add_test(NAME test_multiply COMMAND test_multiply)
add_test(NAME test_read_from_file COMMAND test_read_from_file)
add_test(NAME test_equal_operator COMMAND test_equal_operator)
add_test(NAME test_not_equal_operator COMMAND test_not_equal_operator)
