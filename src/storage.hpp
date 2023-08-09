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
    void init(const std::string& file);
    const mat3& get(const std::string& id);
    bool try_add(const std::string& id, const mat3& mat);

private:
    std::unordered_map<std::string, int> storage;
};
