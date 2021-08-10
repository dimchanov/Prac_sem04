#include <iostream>
#include <string>
#include <vector>
#include <set>


void find_nused_symbol(const std::vector<std::pair<char, std::string> > &gram,
                std::set<char> &used_symbol, char symbol) {
    for (auto &item1 : gram) {
        if (item1.first == symbol) {
            for (auto &c : item1.second) {
                if (isupper(c) && used_symbol.count(c) == 0) {
                    used_symbol.insert(c);
                    find_nused_symbol(gram, used_symbol, c);
                }
            }
        }
    }
}

int main() {

    std::vector<std::pair<char, std::string> > gram;
    std::set<char> used_symbol;

    char c;
    std::string str;
    while (std::cin >> c >> str) {
        gram.push_back({c, str});
    }

    used_symbol.insert('S');
    find_nused_symbol(gram, used_symbol, 'S');

    for (auto &item1 : gram) {
        if (used_symbol.count(item1.first)) {
            std::cout << item1.first << " " << item1.second << std::endl;
        }
    }

    return 0;
}
