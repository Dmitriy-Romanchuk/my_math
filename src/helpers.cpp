#include "helpers.h"

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

//------------------------------------------------------------------------------------------------------------

std::vector<std::string> splitString(const std::string &str, char delimeter)
{
    const auto size = str.size();
    size_t pos = 0u;
    std::vector<std::string> result;

    for (size_t i = 0; i <= size; i++)
    {
        if ((i == size || str[i] == delimeter) && i > pos)
        {
            result.push_back(str.substr(pos, i - pos));

            while (i < size && str[i] == delimeter)
            {
                i++;
            }

            pos = i;
        }
    }

    return result;
}

std::vector<int> read_from_file(const std::string &input_path) // reading numbers from file on the disk and put them into vector<int> int_vec
{
    std::ifstream source(input_path.c_str());
    std::vector<int> int_vec;

    std::string str = "";

    if (!source.is_open())
    {
        std::cout << "File cannot open." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Starting reading matrix from file..." << std::endl;

    while (!source.eof())
    {
        std::cout << "Test while cycle" << std::endl;
        getline(source, str);
        std::cout << "test getline " << str << std::endl;
        auto x = splitString(str, ' ');

        for (const auto &digit : x)
        {
            int_vec.push_back(stoi(digit));
        }
    }

    std::cout << "Reading finished. " << int_vec.size() << " numbers were read!" << std::endl
              << std::endl;

    return int_vec;
}

//------------------------------------------------------------------------------------------------------------

void write_to_file(const std::string &output_path, const mat3 &result)
{
    std::ofstream output(output_path);
    if (!output.is_open())
    {
        std::cout << "File cannot open." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<int> data = result.get_data();

    for (size_t i = 0; i < data.size(); i += 3)
    {
        output << data[i] << " " << data[i + 1] << " " << data[i + 2] << "\n";
    }

    std::cout << "File was written!" << std::endl;
}