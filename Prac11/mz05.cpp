#include <iostream>
#include <vector>
#include <string>

template <typename T>

void vec_print(T &vec) {
    for (auto &item : vec) {
        std::cout << item << std::endl;
    }
}

int main() {
    std::vector<char> elems;
    std::string str;
    char c;
    while (std::cin >> c) {
        elems.push_back(c);
    }
    if (elems.size() == 1) {
        std::cout << elems[0] << std::endl;
        return 0;
    }

    int elems_len = elems.size();
    std::vector<std::string> res;
    while (elems_len > 0) {
        if (islower(elems[0])) {
            std::string tmp;
            tmp += elems[0];
            res.push_back(tmp);
        } else {
            std::string right = res.back();
            res.pop_back();
            std::string left = res.back();
            res.pop_back();
            res.push_back('(' + left + elems[0] + right + ')');
        }

        elems.erase(elems.begin());
        --elems_len;
    }

    vec_print(res);
    
    return 0;
}
