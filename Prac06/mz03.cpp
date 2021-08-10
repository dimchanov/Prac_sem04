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
    unsigned v;
    std::map <unsigned, std::map <unsigned, unsigned> > matr, res;
    bool flag = true;
    while (std::cin >> r) {
        std::cin >> c >> v;
        if (r == 0 && c == 0 && v == MOD) {
            flag = false;
            continue;
        }
        if (flag) {
            matr[c][r] = static_cast<unsigned>(v);
        }
        else {
            unsigned long long a = static_cast<unsigned long long>(v);
            auto it = matr[r].begin();
            for (; it != matr[r].end(); ++it) {
                //std::cout << r << ' ' << it->first << ' ' << a <<' ' << it->second<<std::endl;
                unsigned long long b = static_cast<unsigned long long>(res[it->first][c]);
                res[it->first][c] = static_cast<unsigned>(((a * it->second % MOD) + b) % MOD);
            }
        }
    } 
    //print_matr(matr);
    print_matr(res);
}
