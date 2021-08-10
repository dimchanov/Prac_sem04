#include <iostream>
#include <string>

enum {
    OCT_COUNT = 16
};

int str_to_num(const char &c) {
    if ('0' <= c && c <= '9') {
        return (c - '0');
    } else {
        return (c - 'a' + 10);
    }
}

int main() {
    std::string str_value{""};
    while (1) {
        if (std::cin.eof()) {break;}
        std::cin >> str_value;
        int i{0};
        unsigned int value{0};
        while (i < OCT_COUNT && !std::cin.eof()) {
            std::cin >> str_value;
            value = value * 16 + str_to_num(str_value[0]);
            value = value * 16 + str_to_num(str_value[1]);
            ++i;
            if (i % 4 == 0) { 
                std::cout << value << std::endl;
                value = 0;
            }
        }
        i = 0;
    }
    return 0;
}
