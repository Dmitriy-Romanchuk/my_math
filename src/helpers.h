#pragma once

#include "class_mat3.h"

#include <string>
#include <fstream>
#include <array>
#include <vector>

std::vector<std::string> splitString(const std::string &str, char delimeter);

std::ostream &operator<<(std::ostream &stream, const mat3 &matrix);

void write_to_file(const std::string &output_path, const mat3 &result);

mat3::Mat3RawData& read_matrix(std::ifstream &source);
