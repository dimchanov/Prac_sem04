#include <vector>
#include <functional>

#include <iostream>
template<typename It1, typename F>
void myapply(It1 my_begin, It1 my_end, F pred) {
    auto it = my_begin;
    while (it != my_end) {
        pred(*it);
        ++it;
        }
}

template<typename It1, typename F>
auto myfilter2(It1 my_begin, It1 my_end, F pred) {
    std::vector<std::reference_wrapper<typename It1::value_type>> res;
    auto it = my_begin;
    while (it != my_end) {
        if (pred(*it)) {
            res.insert(res.end(), *it);
        }
        ++it;
    }
    return res;
}


template<typename It2, typename  F>
auto myapply(It2 *my_begin, It2 *my_end, F pred) {
    It2 *it = my_begin;
    while (it != my_end) {
        pred(*it);
        ++it;
    }
}

template<typename It2, typename  F>
auto myfilter2(It2 *my_begin, It2 *my_end, F pred) {
    std::vector<std::reference_wrapper<It2>> res;
    It2 *it = my_begin;
    while (it != my_end) {
        if (pred(*it)) {
            res.insert(res.end(), *it);
        }
        ++it;
    }
    return res;
}

void G(int &x) {
    x += 10;
}

int main() {
    std::vector<int> idx = {-100, -10, 0, 2, 4, 10};
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    auto v1 = myfilter2(v.begin(), v.end(), [](int x) {return x % 2 == 0;});
    for (auto it : v1) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
    myapply(v.begin(), v.end(), G);
    for (auto it : v1) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    int a[5] = {1, 2, 3, 4, 5};

    auto v2 = myfilter2(a, a+6, [](int x) {return x % 2 == 0;});
    for (auto it : v2) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
}
