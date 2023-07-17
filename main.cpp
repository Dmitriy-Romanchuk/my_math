#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <iomanip>

class mat3
{
public:
    using data_array = std::array<int, 9>;

public:
    mat3();
    mat3(int _el_11, int _el_12, int _el_13, int _el_21, int _el_22, int _el_23, int _el_31, int _el_32, int _el_33);
    mat3(std::vector<int> &);
    ~mat3();
    void show();

public:
    static void mutliply(const mat3 &first, const mat3 &second, mat3& result)
    {
        result.el_11 = first.el_11 * second.el_11 + first.el_12 * second.el_21 + first.el_13 * second.el_31;
        result.el_12 = first.el_11 * second.el_12 + first.el_12 * second.el_22 + first.el_13 * second.el_32;
        result.el_13 = first.el_11 * second.el_13 + first.el_12 * second.el_23 + first.el_13 * second.el_33;

        result.el_21 = first.el_21 * second.el_11 + first.el_22 * second.el_21 + first.el_23 * second.el_31;
        result.el_22 = first.el_21 * second.el_12 + first.el_22 * second.el_22 + first.el_23 * second.el_32;
        result.el_23 = first.el_21 * second.el_13 + first.el_22 * second.el_23 + first.el_23 * second.el_33;

        result.el_31 = first.el_31 * second.el_11 + first.el_32 * second.el_21 + first.el_33 * second.el_31;
        result.el_32 = first.el_31 * second.el_12 + first.el_32 * second.el_22 + first.el_33 * second.el_32;
        result.el_33 = first.el_31 * second.el_13 + first.el_32 * second.el_23 + first.el_33 * second.el_33;
    };

    static mat3 mutliply(const mat3 &first, const mat3 &second)
    {
        mat3 result;
        mutliply(first, second, result);
        return result;
    };

private:
    int el_11, el_12, el_13;
    int el_21, el_22, el_23;
    int el_31, el_32, el_33;
};

mat3::mat3()
    : el_11(0)
    , el_12(0)
    , el_13(0)
    , el_21(0)
    , el_22(0)
    , el_23(0)
    , el_31(0)
    , el_32(0)
    , el_33(0)
{
}

mat3::mat3(int _el_11, int _el_12, int _el_13, int _el_21, int _el_22, int _el_23, int _el_31, int _el_32, int _el_33)
    : el_11(_el_11)
    , el_12(_el_12)
    , el_13(_el_13)
    , el_21(_el_21)
    , el_22(_el_22)
    , el_23(_el_23)
    , el_31(_el_31)
    , el_32(_el_32)
    , el_33(_el_33)
{
}

mat3::mat3(std::vector<int> &int_vec)
    : el_11 (int_vec[0])
    , el_12 (int_vec[1])
    , el_13 (int_vec[2])
    , el_21 (int_vec[3])
    , el_22 (int_vec[4])
    , el_23 (int_vec[5])
    , el_31 (int_vec[6])
    , el_32 (int_vec[7])
    , el_33 (int_vec[8])
{  
    int_vec.erase(int_vec.begin(), int_vec.begin() + 9);
}

mat3::~mat3()
{
}
void mat3::show()
{
    std::cout << el_11 << " " << el_12 << " " << el_13 
    << std::endl <<  el_21 << " " << el_22 << " " << el_23 
    << std::endl <<  el_31 << " " << el_32 << " " << el_33 << std::endl << std::endl;
}

//-------------------------------------------------------------------------------------

std::vector<int> read_from_file(std::string input_path) // reading numbers from file on the disk and put them into vector<int> int_vec
{
    std::ifstream source(input_path);
    std::vector<int> int_vec;
    std::string buffer = "";
    std::string str = "";
    
    if(source.is_open())
        std::cout << "File was opened." << std::endl;
    else
    {
        std::cout << "File cannot open." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Starting reading..." << std::endl;

    while(!source.eof())
    {
        getline(source, str);
        int strlen = str.length();
 
        for(int i = 0; i < strlen; ++i)
        {
            if(isdigit(str.at(i)) || str.at(i) == '-')
            {
                buffer += str.at(i);
            }
            if(str.at(i) == ' ' || i == (strlen - 1) && buffer.length() > 1)
            {
                int_vec.push_back(stoi(buffer));
                buffer = "";
            }       
        }
    }

    std::cout << "Reading finished. Count of elements in vector are: " << int_vec.size() << "." << std::endl;

    return int_vec;
}

//----------------------------------------------------------------------------------------

void write_to_file(std::string output_path, mat3 result)
{
    std::ofstream to_file(output_path);
    if(to_file.is_open())
        std::cout << "File was opened" << std::endl;

    to_file.write((char*)&result, sizeof(result));

    std::cout << "File was written!" << std::endl;
}

//----------------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    std::string input_path = "../input_matrix.txt";
    std::string output_path = "../output_matrix.txt";

    std::vector<int> initializer = read_from_file(input_path);

    mat3 first(initializer);
    first.show();
    mat3 second(initializer);
    second.show();
    mat3 result_matrix = mat3::mutliply(first, second);

    mat3 read;

    write_to_file(output_path, result_matrix);

    result_matrix.show();

    std::cout << "Read from file output_matrix.txt:" << std::endl;
    std::ifstream infile("../output_matrix.txt", std::ios::binary);
    infile.read(reinterpret_cast<char*>(&read), sizeof(read));
    read.show(); 

    return EXIT_SUCCESS;
}
