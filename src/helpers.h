#pragma once

#include "class_mat3.h"

#include <string>
#include <fstream>
#include <array>


std::vector<std::string> splitString(const std::string &str, char delimeter);
// std::vector<int> read_from_file(const std::string &input_path);
void write_to_file(const std::string &output_path, const mat3 &result);

using Mat3RawData = std::array<int, 9>;
Mat3RawData& read_matrix(std::ifstream &source);
