#include <iostream>
#include "complex.h"
#include "complex_stack.h"
void print_complex_stack(const numbers::complex_stack &cs) {
    for (int i = 0; i < (int)cs.size(); ++i) {
        std::cout << cs[i].to_string() << ' ';
    }
}

int main() {
    numbers::complex_stack first(12);
    numbers::complex A("(1.0,-5)");
    numbers::complex_stack second = first << A;
    std::cout << "first.size == " << first.size() << std::endl;
    std::cout << "second.size == " << second.size() << std::endl;
    std::cout << "Second elem == "; print_complex_stack(second); std::cout << std::endl;
    std::cout << "second.heap == " << (+second).to_string() << std::endl;
    numbers::complex_stack third = ~second;
    std::cout << "Second elem == "; print_complex_stack(second); std::cout << std::endl;
    std::cout << "Third elem == "; print_complex_stack(third); std::cout << std::endl;
    return 0;
}
