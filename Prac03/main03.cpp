#include <iostream>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main() {
    std::vector<std::string> a{"(8,0)", "(2,0)", "(5,0)", "*", "+", "(1,0)", "(3,0)", "(2,0)", "*", "+", "(4,0)", "-", "/"};
    numbers::complex z("(3,5)");
    std::vector<std::string> b{"(8,0)", "(2,12)", "z"};
    std::cout <<"RESULT  " << numbers::eval(b, z).to_string() << std::endl;
    return 0;
}
