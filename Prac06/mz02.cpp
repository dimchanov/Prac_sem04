#include <iostream>
#include <vector>
#include <map>

enum {
    MOD = 4294967161
};

void print_matr(const std::map<unsigned,  std::map<unsigned, unsigned> > &matr) {
    for (const auto& item1 : matr) {
        for (const auto& item2 : item1.second) {
            if (item2.second) {
                std::cout << item1.first << ' ' << item2.first 
                << ' ' << item2.second << std::endl;
            }
        }
    }
}


int main() {
    unsigned r, c;
    long long v;
    std::map <unsigned, std::map <unsigned, unsigned> > matr;
    while (std::cin >> r) {
        std::cin >> c >> v;
        if (r == 0 && c == 0 && v == MOD) {
            continue;
        }
        unsigned long long a = static_cast<unsigned long long>(matr[r][c]);
        matr[r][c] = static_cast<unsigned>((static_cast<unsigned long long>(v) + a) % MOD);
    }    
    print_matr(matr);
}
