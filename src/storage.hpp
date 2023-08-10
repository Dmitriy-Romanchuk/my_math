#pragma once

#include "class_mat3.h"

#include <string>
#include <unordered_map>
#include <vector>

class Mat3Storage
{
public:
    Mat3Storage();
    ~Mat3Storage();
public:
    void scan_file(const std::string& file);
    
    const mat3& get(const std::string& id);
    bool try_add(const std::string& id, const mat3& mat);

private:

private:
    std::unordered_map<std::string, mat3> m_storage;
};
