#include <iostream>
#include <string>

void no_spaces(int &c) {
    while (!isspace(c) && c != EOF) {
        c = getchar();
    }
}

void check_elem(int &c, int &count, int elem) {

    while (c == elem) {
        ++count;
        c = getchar();
    }
}

int main() {
    
    int c = getchar();

    while (c != EOF) {
        while(isspace(c)) {
            c = getchar();
        }
        if (c == EOF) {
            break;
        }
        int zeros_str_len = 0;
        int ones_str_len = 0;

        check_elem(c, zeros_str_len, '0');

        if (c == '1' && zeros_str_len > 0) {
            check_elem(c, ones_str_len, '1');
            if (c == '0') {
                int end = 1;
                while (c == '0') {
                    int zeros = 0;
                    int ones = 0;
                    check_elem(c, zeros, '0');
                    check_elem(c, ones, '1');
                    
                    if (zeros != zeros_str_len || ones != ones_str_len ||
                            (c != '0' && !isspace(c) && c != EOF)) {
                        end = 0;
                        std::cout << "0" << std::endl;
                        no_spaces(c);
                        break;
                    }
                }
                if (end) {
                    std::cout << "1" << std::endl;
                }
            } else if (isspace(c) || c == EOF) {
                std::cout << "1" << std::endl;
            } else {
                std::cout << "0" << std::endl;
                no_spaces(c);
            }
        } else if (isspace(c) || c == EOF) {
            std::cout << "0" << std::endl;
        } else {
            std::cout << "0" << std::endl;
            no_spaces(c);
        }
        
    }

    return 0;
}
