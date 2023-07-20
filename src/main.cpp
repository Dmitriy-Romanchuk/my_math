#include "class_mat3.h"
#include "helpers.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace
{
    constexpr const char *default_input_path = "input_matrix.txt";
    constexpr const char *default_output_path = "output_matrix.txt";
} // namespace

int main(int argc, char *argv[])
{
    std::string input_path(default_input_path);
    std::string output_path(default_output_path);

    if (argc > 2)
    {
        std::cout << "To many argument in main function: " << argc << ". Max argc = 2;" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        input_path = argv[1];
    }

    std::vector<int> initializer = read_from_file(input_path);

    mat3 first(initializer);
    first.show();
    mat3 second(initializer);
    second.show();
    mat3 result_matrix = mat3::multiply(first, second);

    write_to_file(output_path, result_matrix);
    result_matrix.show();

    std::cout << "Read from file output_matrix.txt:" << std::endl;
    mat3 read;
    std::ifstream file(output_path.c_str(), std::ios::binary);
    file.read(reinterpret_cast<char *>(&read), sizeof(read));
    read.show();

    return EXIT_SUCCESS;
}
