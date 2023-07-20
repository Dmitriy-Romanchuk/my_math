cmake_minimum_required(VERSION 3.21.3)
project(tests)

# find_package (Boost COMPONENTS unit_test_framework REQUIRED)
set(test1_source
    ${CMAKE_CURRENT_SOURCE_DIR/}test_mat3.cpp)

add_executable(test1 ${test1_source})

# target_link_libraries(test1 ${Boost_LIBRARIES} calc)
enable_testing()

# add_test(Test_0, src/main.cpp)
add_test(NAME Test1 COMMAND test1)