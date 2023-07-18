#pragma once
#include <vector>

class mat3
{
public:
    mat3();
    mat3(int _el_11, int _el_12, int _el_13, int _el_21, int _el_22, int _el_23, int _el_31, int _el_32, int _el_33);
    mat3(std::vector<int> &);
    ~mat3();
    void show();
    static void mutliply(const mat3 &first, const mat3 &second, mat3& result);
    static mat3 mutliply(const mat3 &first, const mat3 &second);

private:
    int el_11, el_12, el_13;
    int el_21, el_22, el_23;
    int el_31, el_32, el_33;
};