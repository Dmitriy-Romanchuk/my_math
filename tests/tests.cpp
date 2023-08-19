#include "class_mat3.h"
#include "helpers.h"
#include "simple_test.hpp"
#include "storage.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

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

    return (current == expected) == EXIT_SUCCESS;
}

int test_equal_operator([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    mat3 first_matrix = {5, 0, 0,
                         0, 5, 0,
                         0, 0, 5};

    mat3 second_matrix = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};

    return (first_matrix == second_matrix) == EXIT_SUCCESS;
}

int test_no_equal_operator([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    mat3 first_matrix = {10, 0, 0,
                         0, 10, 0,
                         0, 0, 10};

    mat3 second_matrix = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};

    return !(first_matrix != second_matrix) == true;
}

int test_scan_file([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{

    const char *default_input_path = "test_matrix.txt";

    mat3 first_matrix = {10, 0, 0,
                         0, 10, 0,
                         0, 0, 10};

    Mat3Storage storage;

    storage.scan_file(default_input_path);

    mat3 second_matrix = storage.get("ID_TEST");

    return (first_matrix == second_matrix) == EXIT_SUCCESS;
}

void initializeTests()
{
    auto &tests = TestStorage::instance();

    tests.addTest("test_multiply", &test_multiply);
    tests.addTest("test_equal_operator", &test_equal_operator);
    tests.addTest("test_no_equal_operator", &test_no_equal_operator);
    tests.addTest("test_scan_file", &test_scan_file);
}