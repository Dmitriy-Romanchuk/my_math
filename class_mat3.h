#pragma once

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
}