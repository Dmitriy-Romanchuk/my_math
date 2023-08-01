#include "class_mat3.h"
#include "simple_test.hpp"

#include <cstdlib>
#include <iostream>
#include <cstring>

int test_multiply([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    mat3 first_matrix = {5, 0, 0,
                         0, 5, 0,
                         0, 0, 5};

    mat3 second_matrix = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};

    mat3 expected = {25, 0, 0,
                      0, 25, 0,
                      0, 0, 25};

    mat3 current = mat3::multiply(first_matrix, second_matrix);

    if (current == expected)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

int test_equal_operator([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    mat3 first_matrix = {5, 0, 0,
                         0, 5, 0,
                         0, 0, 5};

    mat3 second_matrix = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};

    if (first_matrix == second_matrix)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

int test_no_equal_operator([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    mat3 first_matrix = {10, 0, 0,
                         0, 10, 0,
                         0, 0, 10};

    mat3 second_matrix = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};

    if (first_matrix != second_matrix)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

int test_read_from_file([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    
    
    return EXIT_SUCCESS;
}


void initializeTests()
{
    auto &tests = TestStorage::instance();

    tests.addTest("test_multiply", &test_multiply);
    tests.addTest("test_equal_operator", &test_equal_operator);
    tests.addTest("test_no_equal_operator", &test_no_equal_operator);
    tests.addTest("test_read_from_file", &test_read_from_file);
}