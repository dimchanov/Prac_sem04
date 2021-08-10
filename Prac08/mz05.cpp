#include <complex>
#include <array>
#include <vector>
#include <iostream>

namespace Equations
{
    template <typename T>
    std::pair<bool, std::vector<std::complex<T>>>
    quadratic(std::array<std::complex<T>, 3> arr) {
        std::complex<T> null {0.0, 0.0};
        std::complex<T> a{arr[2]}, b{arr[1]}, c{arr[0]};
        std::vector<std::complex<T>> vec;
        if (a == null && b == null && c == null) {
            return {false, vec};
        } else if (a == null && b == null) {
            return {true, vec};
        } else if (a == null) {
            vec.push_back(-c / b);
            return {true, vec};
        } else {
            std::complex<T> D = b * b - std::complex<T>{4.0, 0.0} * a * c;
            vec.push_back((-b + sqrt(D)) / (std::complex<T>{2.0, 0.0} * a));
            vec.push_back((-b - sqrt(D)) / (std::complex<T>{2.0, 0.0} * a));
            return {true, vec}; 
        }
    }
};

