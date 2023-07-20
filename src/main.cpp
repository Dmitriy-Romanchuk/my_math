#include "class_mat3.h"
#include "helpers.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::string input_path = "";
    std::string output_path = "../output_matrix.txt";

    if (argc > 2)
    {
        std::cout << "To many argument in main function: " << argc << ". Max argc = 2;" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        input_path = argv[1];
    }

    if (argc == 1)
    {
        input_path = "input_matrix.txt";
    }

    std::vector<int> initializer = read_from_file(input_path);

    mat3 first(initializer);
    first.show();
    mat3 second(initializer);
    second.show();
    mat3 result_matrix = mat3::multiply(first, second);

    mat3 read;

    write_to_file(output_path, result_matrix);

    result_matrix.show();

    std::cout << "Read from file output_matrix.txt:" << std::endl;
    std::ifstream infile("../output_matrix.txt", std::ios::binary);
    infile.read(reinterpret_cast<char *>(&read), sizeof(read));
    read.show();

    return EXIT_SUCCESS;
}
