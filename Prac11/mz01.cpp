#include <iostream>
#include <string>
#include <algorithm>


int terminal(char c) {
    if (isdigit(c) || islower(c)) {
        return 1;
    } 
    return 0;
}

int not_terminal(char c) {
    if (isupper(c)) {
        return 1;
    }
    return 0;
}

int check_linear(const std::string &str) {
    for (int i = 0; i < (int)str.length() - 1; ++i) {
        if (!terminal(str[i])) {
            return 0;
        }
    }
    return 1;
}

int check_auto(const std::string &str) {
    int str_len = (int)str.length();
    if (str_len > 2) {
        return 0;
    }
    if (str_len == 2) {
        if (terminal(str[0]) && not_terminal(str[1])) {
        } else {
            return 0;
        }
    }
    if (str_len == 1) {
        if (not_terminal(str[0])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int right(1);
    int left(1);
    int right_a(1);
    int left_a(1);
    int cfp(1);
    int empty_str(0);
    int s_in_second(0);
    int flag(0);

    char start = 'S';
    int exept(0);

    std::string first, second;
    while (std::cin >> first >> second) {
        if (second[0] == '_' && second.length() == 1) {
            if (first[0] == 'S' && first.length() == 1) {
                exept = 1;
            }
        }
        if (first[0] == 'S' && first.length() == 1 &&
            not_terminal(second[0]) && second.length() == 1) {
            exept = 2;
        }
        if (not_terminal(second[second.length() - 1])) {
            if (!check_linear(second)) {
              right = 0;  
            } 
        } else if (!check_linear(second + 'S')){
            right = 0;
        }
        
        if (not_terminal(second[0])) {
            if (!check_linear(std::string(second.rbegin(), second.rend()))) {
                left = 0;
            }
        } else if (!check_linear(second + 'S')) {
            left = 0;
        }
        
        if ()
        right_a = right_a & check_auto(second);
        left_a = left_a & check_auto(std::string(second.rbegin(), second.rend()));

        if(first.length() > second.length()) {
            cfp = false;
        }

        if (second[0] == '_' && second.length() == 1) {
            if (first[0] == 'S' && first.length() == 1) {
                empty_str = 1;
            } else {
                cfp = 0;
            }
        }

        if (first[0] == 'S' && first.length() == 1 &&
            not_terminal(second[0]) && second.length() == 1) {
            flag = 1;
        }

        for (auto c : second) {
            if (c == '') {
                s_in_second = 1;
                break;
            }
        }
    }
    
    if (!(right || left)) {
        if (cfp && ((empty_str && s_in_second == 0) || empty_str == 0)) {
            std::cout << "21" << std::endl;
            return 0;
        } else {
            std::cout << "2" << std::endl;
            return 0;
        }
    }

    if (left && !left_a) {
        std::cout << "31" << std::endl;
        return 0;
    }

    if (right && !right_a) {
        std::cout << "32" << std::endl;
    }

    if (right_a && (empty_str == 0 || (empty_str && s_in_second == 0 && flag))) {
        std::cout << "321" << std::endl;
        return 0;
    }

    if (left_a && (empty_str == 0 || (empty_str && s_in_second == 0 && flag))) {
        std::cout << "311" << std::endl;
        return 0;
    }
    return 0;
}
