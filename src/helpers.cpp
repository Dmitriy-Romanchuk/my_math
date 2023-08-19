#include "helpers.h"

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

//------------------------------------------------------------------------------------------------------------

std::vector<std::string> splitString(const std::string &str, char delimeter)
{
    std::vector<std::string> result;

    const auto size = str.size();
    size_t pos = 0u;

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

std::ostream &operator<<(std::ostream &stream, const mat3 &matrix)
{
    auto data = matrix.get_data();

    for (size_t i = 0; i < data.size(); i += 3)
    {
        stream << data[i] << " " << data[i + 1] << " " << data[i + 2] << "\n";
    }

    return stream;
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

    output << result;

    std::cout << "File was written!" << std::endl;
}

mat3::Mat3RawData &read_matrix(std::ifstream &source)
{
    static mat3::Mat3RawData buffer;
    std::string line;

    for (size_t i = 0; i < 3; ++i)
    {
        getline(source, line);
        auto x = splitString(line, ' ');

        size_t offset = 0;
        for (const auto &digit : x)
        {
            const size_t index = i * 3 + offset;
            buffer[index] = stoi(digit);
            offset++;
        }
    }

    return buffer;
}