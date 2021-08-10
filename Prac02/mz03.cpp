#include <iostream>

class C {
public:
    C(const C, const C) {}
    C() {}
    C(double d) {}
    int operator~() const {
        return 0;
    }
    C operator++() {
        return C();
    }
    C(const C* p) {}
    friend C operator *(const int a, const C c);
    friend C operator *(const int c1, const C c2);
private:
    int val = 0;
};

C operator +(const int a, const C c) {
    return C();
}

int operator *(const C c1, C *const c2) {
    return 1;
}

