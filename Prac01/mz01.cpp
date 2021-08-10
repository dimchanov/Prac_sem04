#include <iostream>

class Sum {
public:
    Sum(long long first, long long second) {
        a = first;
        b = second;
    }
    Sum(const Sum &first, long long second) {
        a = first.a + first.b;
        b = second;
    }
    long long get() const {
        return a + b;
    }
private:
    int a, b;
};

