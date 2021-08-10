#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main(int argc, char **argv) {
    numbers::complex C(argv[1]);
    double R;
    std::stringstream ss(argv[2]);
    ss >> R;
    std::stringstream ss1(argv[3]);
    int N;
    ss1 >> N;
    char **complex_func = argv + 4;
    std::vector<std::string> vec_func(complex_func, complex_func + argc - 4);
    numbers::complex sum;
    for (int i = 0; i < N; ++i) {
        double arg = ((double) i + 1/2) * 2 * M_PI / N;
        numbers::complex z = numbers::complex(R * cos(arg), R * sin(arg));
        sum += numbers::eval(vec_func, C + z) * numbers::complex(-sin(arg), cos(arg));
    }
    sum *= numbers::complex(2 * M_PI * R / N);
    std::cout << sum.to_string() << std::endl;
    return 0;
}
