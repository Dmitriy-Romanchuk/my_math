#include "class_mat3.h"
#include "helpers.h"
#include "storage.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace
{
   constexpr const char *default_input_path = "input_matrix.txt";
   constexpr const char *default_output_path = "output_matrix.txt";
} // namespace

int main(int argc, char *argv[])
{
   std::string input_path(default_input_path);
   std::string output_path(default_output_path);

   if (argc > 2)
   {
      std::cout << "To many argument in main function: " << argc << ". Max argc = 2;" << std::endl;
      exit(EXIT_FAILURE);
   }

   if (argc == 2)
   {
      input_path = argv[1];
   }

   Mat3Storage storage;

   storage.scan_file(default_input_path);
   auto &test = storage.get("ID_1");
   std::cout << test << std::endl;

   auto &test1 = storage.get("ID_2");
   std::cout << test1 << std::endl;

   mat3 result_matrix = mat3::multiply(test, test1);
   std::cout << result_matrix << std::endl;

   write_to_file(output_path, result_matrix);

   return EXIT_SUCCESS;
}
