#include "helpers.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------------------------------------------------------------

std::vector<int> read_from_file(const std::string &input_path) // reading numbers from file on the disk and put them into vector<int> int_vec
{
    std::ifstream source(input_path.c_str());
    std::vector<int> int_vec;
    std::string buffer = "";
    std::string str = "";

    if (source.is_open())
    {
        std::cout << "File was opened." << std::endl;
    }
    else
    {
        std::cout << "File cannot open." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Starting reading..." << std::endl;

    while (!source.eof())
    {
        getline(source, str);
        int strlen = str.length();

        for (int i = 0; i < strlen; ++i)
        {
            if (isdigit(str.at(i)) || str.at(i) == '-')
            {
                buffer += str.at(i);
            }
            if (str.at(i) == ' ' || i == (strlen - 1) && buffer.length() > 1)
            {
                int_vec.push_back(stoi(buffer));
                buffer = "";
            }
        }
    }

    std::cout << "Reading finished. Count of elements in vector are: " << int_vec.size() << "." << std::endl;

    return int_vec;
}

//------------------------------------------------------------------------------------------------------------

void write_to_file(const std::string &output_path, const mat3 &result)
{
    std::ofstream to_file(output_path);
    if (to_file.is_open())
        std::cout << "File was opened" << std::endl;

    std::vector<int> data = result.get_data();

    //size_t counter = 0u;
    //for (const auto &element : data)
    //{
    //    to_file << element << " ";
    //    counter++;
    //    if (counter % 3 == 0)
    //    {
    //        to_file << "\n";
    //    }
    //}
    for (size_t i = 0; i < data.size(); i+=3)
    {
        to_file << data[i] << " " << data[i + 1] << " " << data[i + 2] << "\n";
    }
    

    std::cout << "File was written!" << std::endl;
}