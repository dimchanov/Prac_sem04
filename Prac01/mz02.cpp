#include <iostream>

class A {
public:
    A() {
        flag = false;
        std::cin >> sum;
    }
    A(const A &b) {
        flag = true;
        std::cin >> sum;
        sum += b.sum;
    }
    ~A() {
        if (flag) {
            std::cout << sum << std::endl;
        }
    }
private:
    int sum;
    bool flag;
};

