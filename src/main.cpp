// #include "class_mat3.h"
// #include "helpers.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// namespace
//{
//     constexpr const char *default_input_path = "input_matrix.txt";
//     constexpr const char *default_output_path = "output_matrix.txt";
// } // namespace

void scan_file(const std::string &file)
{
   std::ifstream source(file.c_str());
   std::string line;
   std::string file_content;

   if (!source.is_open())
   {
      std::cout << "File cannot open." << std::endl;
      exit(EXIT_FAILURE);
   }

   std::cout << "Starting reading matrix from file..." << std::endl;

   
   while (!source.eof())
   {
      getline(source, line);
      file_content += line += " ";
     
   }

   std::cout << file_content << std::endl;
}

int main(int argc, char *argv[])
{
   // std::string input_path(default_input_path);
   // std::string output_path(default_output_path);
   //
   // if (argc > 2)
   // {
   //     std::cout << "To many argument in main function: " << argc << ". Max argc = 2;" << std::endl;
   //     exit(EXIT_FAILURE);
   // }
   //
   // if (argc == 2)
   // {
   //     input_path = argv[1];
   // }
   //
   // std::vector<int> initializer = read_from_file(input_path);
   //
   // mat3 first(initializer);
   // std::cout << "First matrix from file:" << std::endl;
   // first.show();
   //
   // mat3 second(initializer);
   // std::cout << "Second matrix from file:" << std::endl;
   // second.show();
   //
   // std::cout << "Matrix multiplication and writing result to file..." << std::endl;
   // mat3 result_matrix = mat3::multiply(first, second);
   // write_to_file(output_path, result_matrix);
   //
   // std::cout << "Was written to the file:" << std::endl;
   // result_matrix.show();
   //
   // std::cout << "Read result matrix from output_matrix.txt:" << std::endl;
   // initializer = read_from_file(output_path);
   // mat3 read(initializer);
   // read.show();

   

   scan_file("d:\\learning\\C++\\mat3\\input_matrix.txt");

   return EXIT_SUCCESS;
}
