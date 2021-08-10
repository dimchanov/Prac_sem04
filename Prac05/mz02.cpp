#include <iostream>
#include <vector>

template<typename T1, typename F>
T1 myfilter(const T1 &vec, F pred) {
    T1 res;
    auto it = vec.begin();

    while (it != vec.end()) {
        if (pred(*it)) {
            res.insert(res.end(), *it);
        }
        ++it;
    }
    return res;
}
int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> v1 = myfilter(v, [] (const int x)
        {return x % 2 == 1;});
    for (auto item : v1) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}
