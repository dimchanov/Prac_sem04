#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double sum{0};
    double sqr_sum{0};
    int n{0};
    double number{0};

    while (std::cin >> number) {
        ++n;
        sum += number;
        sqr_sum += (number * number);
    }
    double sum_mean = sum / n;
    std::cout << std::setprecision(10) << sum_mean << std::endl 
    << sqrt(sqr_sum / n - sum_mean * sum_mean) << std::endl;
    return 0;
}
