#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <array>
#include <vector>

class mat3
{
public:
    using data_array = std::array<int, 9>;

public:
    mat3();
    mat3(int _el_11, int _el_12, int _el_13, int _el_21, int _el_22, int _el_23, int _el_31, int _el_32, int _el_33);
    mat3(const data_array& arr);
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
    std::cout << "mat3()" << std::endl;
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
    std::cout << "mat3()" << std::endl;
}

mat3::mat3(const data_array& arr)
    : el_11(arr[0])
    , el_12(arr[1])
    , el_13(arr[2])
    , el_21(arr[3])
    , el_22(arr[4])
    , el_23(arr[5])
    , el_31(arr[6])
    , el_32(arr[7])
    , el_33(arr[8])
{  
}

mat3::~mat3()
{
    std::cout << "~mat3()" << std::endl;
}
void mat3::show()
{
    std::cout << el_11 << " " << el_12 << " " << el_13 
    << std::endl <<  el_21 << " " << el_22 << " " << el_23 
    << std::endl <<  el_31 << " " << el_32 << " " << el_33 << std::endl;}

//-------------------------------------------------------------------------------------

std::vector<int> converter_to_int(std::vector<std::string>)
{
    std::vector<int> data;

    return data;
}

//-------------------------------------------------------------------------------------

void read_from_file(std::string input_path) // reading numbers from file on the disk and put them into vector<std::string> str_vec
{
    std::ifstream source(input_path);
    std::vector<std::string> str_vec;
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

                int_vec.push_back(stoi(buffer)); //added stoi
                buffer = "";
            }       
        }
    }

    std::cout << "Reading finished. Count of elements in vector are: " << __has_include_next.size() << "." << std::endl;
}

//----------------------------------------------------------------------------------------

std::vector<int> str_to_int(std::vector<std::string> &str_vec)
{
    std::vector<int> int_vec;
    std::vector<int>::iterator int_it = int_vec.begin();
    std::vector<string>::iterator str_it = str_vec.begin();

    while(!str_it.end())
    {





    }

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
    std::string input_path = "D:\\learning\\C++\\mat3\\input_matrix.txt";
    std::string output_path = "D:\\learning\\C++\\mat3\\output_matrix.txt";

    read_from_file(input_path);

    //mat3 first(matrix_one);
    //mat3 second(matrix_two);

    //mat3 result_matrix = mat3::mutliply(first, second);

    //write_to_file(output_path, result_matrix);

    //result_matrix.show();

    return EXIT_SUCCESS;
}
