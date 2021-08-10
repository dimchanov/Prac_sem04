#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Functor
{
    double sum;
    Functor() : sum(0.0) {}
    void operator()(double d)
    {
        sum += d;
    }
};

int main()
{
    std::vector<double> v;
    double number;
    while (std::cin >> number) {
        v.push_back(number);
    }

    size_t v_size = v.size();
    auto new_begin = v.begin() + (v_size / 10);
    auto new_end = v.end() - (v_size / 10);

    v_size = new_end - new_begin;
    std::sort(new_begin, new_end);

    new_begin += v_size / 10;
    new_end -= v_size / 10;
    v_size = new_end - new_begin;
    

    Functor func = std::for_each(new_begin, new_end, Functor());
    std::cout << std::fixed << std::setprecision(10) << func.sum / v_size << std::endl;
    return 0;
}
