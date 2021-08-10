#include <iostream>
#include <string>

int main() {
    char c, last{0};
    int count{0};
    std::string s ="";
    while (!std::cin.eof()) {
        c = std::cin.get();
        if (c == last) {
            ++count;
            s += c;
            last = c;
        } else {    
            if (count > 4) {
                std::cout << '#' << last << std::hex << count << '#';
                s = "";
                s += c;
                count = 1;
                last = c;
            } else {
                if (last == '#') {
                    std::cout << "##" << std::hex << count << '#';
                } else {
                    std::cout << s;
                }
                s = "";
                s += c;
                last = c;
                count = 1; 
            }
        }
    }
    return 0;
}
