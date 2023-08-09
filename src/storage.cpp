#include "storage.hpp"
#include "helpers.h"

#include <iostream>
#include <fstream>

Mat3Storage::Mat3Storage()
{
}

Mat3Storage::~Mat3Storage()
{
}

std::string Mat3Storage::scan_file(const std::string &file)
{
    std::ifstream source(file.c_str());
    std::string line;
    std::string buffer;
    std::vector<int> matrix;
    
    if (!source.is_open())
    {
        std::cout << "File cannot open." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Starting reading matrix from file..." << std::endl;

    while (!source.eof())
    {
      getline(source, line);
      if(line.ends_with(":"))
      {
        for (size_t i = 0; i < 3; ++i)
        {
            getline(source, line);
            auto x = splitString(line, ' ');
            for (const auto &digit : x)
            {
                matrix.append(stoi(digit));
        
            }
        

      }

      buffer += line += " ";
    }

   return buffer;
}

 //       if (str == "ID_1:" && str == "ID_2:")
 //       {
 //           key = str;
 //           continue;
 //       }//

 //       auto x = splitString(str, ' ');//

 //       
 //   }//

 //   std::cout << "Reading finished. " << storage.size() << " numbers were read!" << std::endl
 //             << std::endl;
//}

bool Mat3Storage::try_add(const std::string &id, const mat3 &mat)
{
    return false;
}
