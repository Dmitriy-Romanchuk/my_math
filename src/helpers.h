#pragma once

#include "class_mat3.h"

#include <string>

std::vector<int> read_from_file(const std::string &input_path);
void write_to_file(const std::string &output_path, const mat3 &result);