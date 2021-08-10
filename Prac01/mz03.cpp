#include <iostream>

int main() {
    char c{}, last{};
    bool flag{true};

    while ((c = getchar()) != EOF) {
        if ((c >= '1' && c <= '9') || c == '0') {
            if (flag && (c != '0')) {
                last = c;
                flag = false;
            } else {
                last = c;
            }
            if (!flag) {
                last = c;
                std::cout << c;
            }
        } else {
            if (flag && (last == '0')) {
                std::cout << '0';
            }
            last = c;
            std::cout << c;
            flag = true;
        }
    }
    if (flag && (last == '0')) {
        std::cout << '0';
    }
    return 0;
}
