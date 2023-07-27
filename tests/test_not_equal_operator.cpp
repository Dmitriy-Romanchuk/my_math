#include "class_mat3.h"

#include <iostream>

int main()
{
    mat3 first_matrix = {10, 0, 0,
                         0, 5, 0,
                         0, 0, 5};

    mat3 second_matrix = {5, 0, 0,
                          0, 5, 0,
                          0, 0, 5};

    if (first_matrix != second_matrix)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}