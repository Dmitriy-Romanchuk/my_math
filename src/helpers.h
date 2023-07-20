#pragma once

#include "class_mat3.h"

#include <string>

void write_to_file(std::string output_path, mat3 result);
std::vector<int> read_from_file(std::string input_path);