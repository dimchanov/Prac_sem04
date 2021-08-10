#include <iostream>
#include <string>

int main() {
    
    int type_cf(1);
    int type_cfp(1);
    int S_terminal_first(0);
    int S_terminal_second(0);
    int empty_str(0);
    int only_terminal(0);

    std::string first;
    std::string second;

    while (std::cin >> first >> second) {
        int flag(1);
        for (auto c : first) {
            if (!(isdigit(c) || islower(c))) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            only_terminal = 1;
        }
        if (first[0] == 'S' && first.length() == 1) {
            S_terminal_first = 1;
        }
        if (second[0] == '_' && second.length() == 1) {
            if (first[0] == 'S' && first.length() == 1) {
                empty_str = 1;
            } else {
                type_cfp = 0;
            }
        }
        if (flag || first.length() != 1) {
            type_cf = 0;
        }
        if (second.find('S') != std::string::npos) {
            S_terminal_second = 1;
        }
        if (first.length() > second.length()) {
            type_cfp = 0;
        }
    }
    if (empty_str && S_terminal_second) {
        type_cfp = 0;
    }

    if (!S_terminal_first || only_terminal) {
        std::cout << "-1" << std::endl;
    } else if (type_cf) {
        if (type_cfp) {
            std::cout << "23" << std::endl;
        } else {
            std::cout << "2" << std::endl;
        }
    } else {
        std::cout << "10" << std::endl;
    }

    return 0;
}
