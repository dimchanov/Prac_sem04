#include <iostream>
#include <string>

int A(const std::string &str, int idx) {
    if (str[idx] != '0' && str[idx] != '1') {
        return 0;
    }
    if (!idx) {
        return 1;
    }
    return A(str, --idx);
}

int B(const std::string &str, int idx) {
    if (str[idx] != '1') {
        return 0;
    }
    if (!idx) {
        return 1;
    }
    return A(str, --idx);
}

int C(const std::string &str, int idx) {
    if ((str[idx] != '0' && str[idx] != '1') || !idx) {
        return 0;
    }
    return B(str, --idx);
}

int S(const std::string &str, int idx) {
    if ((str[idx] != '0' && str[idx] != '1') || !idx) {
        return 0;
    }
    return C(str, --idx);
}

int main() {
    std::string str;
    while (std::cin >> str) {
        std::cout << S(str, str.length() - 1) << std::endl;
    }
    return 0;
}
