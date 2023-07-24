cmake_minimum_required(VERSION 3.21.3)
project(tests)

# find_package (Boost COMPONENTS unit_test_framework REQUIRED)
set(test_source
    ${CMAKE_CURRENT_SOURCE_DIR/} test_multiply.cpp
    ${CMAKE_CURRENT_SOURCE_DIR/} test_read_from_file.cpp
    )

add_executable(tests ${test_source})

target_link_libraries(tests ${Boost_LIBRARIES} main)
enable_testing()

# add_test(Test_0, src/main.cpp)
add_test(NAME Test1_multiply COMMAND tests)
add_test(NAME Test2_read_from_file COMMAND tests)