cmake_minimum_required(VERSION 3.21.3)
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)

project(main)

include_directories(./src)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/helpers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/class_mat3.cpp
)
add_library(main STATIC ${SOURCE})

add_executable(mat3 ${SOURCE})

list(APPEND RESOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/input_matrix.txt
)

file(COPY ${RESOURCE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
