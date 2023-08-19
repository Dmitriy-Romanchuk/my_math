#include "class_mat3.h"

#include <iostream>

mat3::mat3()
    : el_11(0), el_12(0), el_13(0), el_21(0), el_22(0), el_23(0), el_31(0), el_32(0), el_33(0)
{
}

mat3::mat3(int _el_11, int _el_12, int _el_13, int _el_21, int _el_22, int _el_23, int _el_31, int _el_32, int _el_33)
    : el_11(_el_11), el_12(_el_12), el_13(_el_13), el_21(_el_21), el_22(_el_22), el_23(_el_23), el_31(_el_31), el_32(_el_32), el_33(_el_33)
{
}

mat3::mat3(int *arr)
    : el_11(arr[0]), el_12(arr[1]), el_13(arr[2]), el_21(arr[3]), el_22(arr[4]), el_23(arr[5]), el_31(arr[6]), el_32(arr[7]), el_33(arr[8])
{
}

mat3::~mat3()
{
}

void mat3::multiply(const mat3 &first, const mat3 &second, mat3 &result)
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
}

mat3 mat3::multiply(const mat3 &first, const mat3 &second)
{
    mat3 result;
    multiply(first, second, result);
    return result;
}

mat3::Mat3RawData mat3::get_data() const
{
    Mat3RawData elements{el_11, el_12, el_13, el_21, el_22, el_23, el_31, el_32, el_33};

    return elements;
}

bool mat3::operator==(const mat3 &other) const
{
    return (el_11 == other.el_11 && el_12 == other.el_12 && el_13 == other.el_13 && el_21 == other.el_21 && el_22 == other.el_22 && el_23 == other.el_23 && el_31 == other.el_31 && el_32 == other.el_32 && el_33 == other.el_33);
}

bool mat3::operator!=(const mat3 &other) const
{
    return (*this == other) == false;
}
