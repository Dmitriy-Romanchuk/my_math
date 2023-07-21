#include <iostream>
#include <vector>
#include "class_mat3.h"

int main()
{
    std::vector<int> a = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};
    std::vector<int> b = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};

    mat3 reference{25, 0, 0,
                   0, 25, 0,
                   0, 0, 25};
    mat3 test;

    test.multiply(a, b);

    return EXIT_SUCCESS;
}