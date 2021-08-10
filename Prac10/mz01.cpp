#include <iostream>
#include <string>

int check (const std::string &str) {
    size_t i = 0;
    size_t len = str.length();
    while (i < len && (str[i] == '3' || str[i] == '4')) {
        ++i;
    }
    while (i < len && (str[i] == '1' || str[i] == '2')) {
        ++i;
    }
    if (i < len) {
        return 0;
    }
    return 1;
}

int main()
{
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    }
}
