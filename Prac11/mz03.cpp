#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    std::map<std::string, std::map<char, std::string> > avt;
    std::string cur, char_s, new_s;

    while (std::cin >> cur && cur != "END") {
        std::cin >> char_s >> new_s;
        avt[cur][char_s[0]] = new_s;
    }

    std::vector<std::string> end_elems;
    std::string end_elem;
    while (std::cin >> end_elem && end_elem != "END") {
        end_elems.push_back(end_elem);
    }
    
    std::string start, check_str;
    std::cin >> start >> check_str;
    int flag = 1;
    int count_symbol(0);
    while (count_symbol < (int)check_str.length()) {
        auto iter1 = avt.find(start);
        if (iter1 == avt.end()) {
            flag = 0;
            break;
        } else {
            auto iter2 = iter1->second.find(check_str[count_symbol]);
            if (iter2 == iter1->second.end()) {
                flag = 0;
                break;
            } else {
                start = iter2->second;
                ++count_symbol;
            }
        }
    }

    if (flag) {
        flag = 0;
        for (auto &elem : end_elems) {
            if (start == elem) {
                flag = 1;
                break;
            } 
        }
    }
    std::cout << flag << std::endl << count_symbol << std::endl << start << std::endl;

    return 0;
}
