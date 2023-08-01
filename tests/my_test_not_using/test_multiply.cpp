#include "class_mat3.h"

#include <iostream>

int main()
{
    mat3 first_matrix = {5, 0, 0,
                         0, 5, 0,
                         0, 0, 5};

    mat3 second_matrix = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};

    mat3 reference = {25, 0, 0,
                      0, 25, 0,
                      0, 0, 25};

    mat3 tester = mat3::multiply(first_matrix, second_matrix);

    if (tester == reference)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}