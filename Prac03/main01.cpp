#include "complex.h"
#include <iostream>

int main() {
    numbers::complex A("(1.0,-5)"), B("(3.0,11)");
    //std::cout << A.re() << ' ' << A.im() << std::endl;
    std::cout << (A + B).to_string() << std::endl;
    std::cout << (A - B).to_string() << std::endl;
    std::cout << (A * B).to_string() << std::endl;
    std::cout << (A / B).to_string() << std::endl;
    std::cout << (-A).to_string() << std::endl;
    std::cout << (~B).to_string() << std::endl;
    return 0;
}
