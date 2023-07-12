#include <iostream>

class mat3
{
public:
    mat3();
    mat3(int _el_11, int _el_12, int _el_13, int _el_21, int _el_22, int _el_23, int _el_31, int _el_32, int _el_33);
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

mat3::~mat3()
{
    std::cout << "~mat3()" << std::endl;
}
void mat3::show()
{
    std::cout << el_11 << " " << el_12 << " " << el_13 
    << std::endl <<  el_21 << " " << el_22 << " " << el_23 
    << std::endl <<  el_31 << " " << el_32 << " " << el_33 << std::endl;
}

int main(int argc, char* argv[])
{
    mat3 first(1, 2, 3, 4, 5, 6, 7, 8, 10);
    mat3 second(10, 11, 12, 13, 14, 15, 16, 17, 18);
    
    // mat3 result_matrix;
    // mat3::mutliply(first, second, result_matrix);

    mat3 result_matrix = mat3::mutliply(first, second);

    result_matrix.show();

    return EXIT_SUCCESS;
}
