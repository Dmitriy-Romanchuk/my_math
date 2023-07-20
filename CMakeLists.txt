cmake_minimum_required(VERSION 3.21.3)
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)

project(main)


include_directories(./src)


add_executable(mat3 src/main.cpp src/helpers.cpp src/class_mat3.cpp)



include(CTest)

if(BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
