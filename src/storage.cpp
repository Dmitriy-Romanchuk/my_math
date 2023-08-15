#include "class_mat3.h"
#include "helpers.h"
#include "storage.hpp"

#include <cassert>
#include <iostream>
#include <fstream>

Mat3Storage::Mat3Storage()
{
}

Mat3Storage::~Mat3Storage()
{
}

void Mat3Storage::scan_file(const std::string &file)
{
    std::ifstream source(file.c_str());
    std::string line;
    std::string id;
    
    if (!source.is_open())
    {
        std::cout << "File cannot open." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Starting reading matrix from file..." << std::endl;

    while (!source.eof())
    {
        getline(source, line);

        if ((line[line.size() - 1]) == ':')
        {
            id = line.substr(0, line.size() - 1);
            m_storage.emplace(id, read_matrix(source).data());
        }
    }
}

const mat3 &Mat3Storage::get(const std::string &id)
{
    auto it = m_storage.find(id);
    if (it == m_storage.end())
    {
        std::cout << "hasn't key" << std::endl;
    }
    
    return m_storage[id];
}

// bool Mat3Storage::try_add(const std::string &id, const mat3 &mat)
//{
//     return false;
// }
