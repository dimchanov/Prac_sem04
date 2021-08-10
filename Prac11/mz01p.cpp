#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <utility>
struct Pair {
    char l;
    std::string r;
    int valid;
};
int main() {
    std::vector<struct Pair> grammar;
    char l, start = 'S';
    std::string r;
    bool srule = false, nonautomata = false;
    while (std::cin >> l >> r) {
        grammar.push_back({l , r, 0});
        if ((l == 'S') && (r[0] == '_')) {
            srule = true;
        }
    }
    for (auto grit = grammar.begin(); grit != grammar.end(); ++grit) {
        if (srule == true) {
            if ((grit->l == 'S') && (isupper(grit->r[0])) && (grit->r.size() == 1)) {
                if (start != 'S') {
                    nonautomata = true;
                    break;
                }
                start = grit->r[0];
                grit->valid = 2;
            }
        }
    }
    std::map<char, int> N1;
    unsigned N1size = N1.size();
    while (1) {
        for (auto grit = grammar.begin(); grit != grammar.end(); ++grit) {
            int size = grit->r.size(), count = 0, N = 0;
            for (int i = 0; i < size; ++i) {
                if (grit->valid > 0) {
                    break;
                }
                if (std::islower(grit->r[i]) || std::isdigit(grit->r[i]) || (grit->r[i] == '_')) {
                    ++count;
                } else {
                    if (N1.find(grit->r[i]) != N1.end()) {
                        ++N;
                    }
                }
            }
            if (N + count == size) {
                grit->valid = 1;
                ++N1[grit->l];
            }
        }
        if (N1size == N1.size()) {
            break;
        } else {
            N1size = N1.size();
        }
    }
    std::map<char, int> V1;
    unsigned V1size = V1.size();
    while (1) {
        for (auto grit = grammar.begin(); grit != grammar.end(); ++grit) {
            int size = grit->r.size();
            if (grit->l == start) {
                ++V1[grit->l];
            }
            if (V1.find(grit->l) != V1.end()) {
                for (int i = 0; i < size; ++i) {
                    ++V1[grit->r[i]];
                }
            }
        }
        if (V1size == V1.size()) {
            break;
        } else {
            V1size = V1.size();
        }
    }
    for (auto grit = grammar.begin(); grit != grammar.end(); ++grit) {
        int size = grit->r.size();
        if ((V1.find(grit->l) != V1.end()) && (grit->valid > 0)) {
            for (int i = 0; i < size; ++i) {
                if (V1.find(grit->r[i]) == V1.end()) {
                    grit->valid = 0;
                    break;
                }
            }
        }
    }
    if ((srule == true) && (nonautomata == false)) {
        srule = false;
        char left;
        std::string right;
        int sright = 0, less = 0, SNrule = 0, NN = 0;
        bool isreg = true, leftautomata = true, rightautomata = true, 
        leftlinear = true, rightlinear = true;
        for (auto grit = grammar.begin(); grit != grammar.end(); ++grit) {
            if (grit->valid == 0) {
                continue;
            }
            left = grit->l;
            right = grit->r;
            int rsize = right.size(), uppernum = 0, termnum = 0;
            bool Tfirst = false, Tcarry = false;
            if (islower(right[0]) || isdigit(right[0])) {
                Tfirst = true;
                Tcarry = true;
                ++termnum;
            } else {
                if (isupper(right[0])) {
                    ++uppernum;
                }
            }
            for (int i = 0; i < rsize; ++i) {
                if (i > 0) {
                    if (isupper(right[i])) {
                        Tcarry = false;
                        ++uppernum;
                    }
                    if (islower(right[i]) || isdigit(right[i])) {
                        ++termnum;
                    }
                    if ((Tfirst == true) && (Tcarry == false) && (islower(right[i]) || 
                        isdigit(right[i]))) {
                        isreg = false;
                    }
                }
                if (right[i] == 'S') {
                    leftautomata = false;
                    rightautomata = false;
                    ++sright;
                    break;
                }
            }
            if (uppernum > 1) {
                isreg = false;
                break;
            }
            if (isreg == true) {
                if (Tfirst == false) {
                    if (isupper(right[0]) && (rsize == 1)) {
                        ++NN;
                        if (NN > 0) {
                            leftautomata = false;
                            rightautomata = false;
                            break;
                        }
                    } else {
                        if (rsize > 2) {
                            leftautomata = false;
                        }
                        rightlinear = false;
                    }
                } else {
                    if (rsize > 2) {
                        rightautomata = false;
                    }
                    if (rsize > 1) {
                        leftlinear = false;
                    }
                }
            } else {
                break;
            }
            if (left == 'S') {
                if (right[0] == '_') {
                    srule = true;
                }
                if (isupper(right[0]) && (rsize == 1)) {
                    ++SNrule;
                }
            }
            if (right[0] == '_') {
                leftautomata = false;
                rightautomata = false;
                ++less;
                break;
            }
        }
        if ((less == 0) || 
            ((less == 1) && (srule == true) && (sright == 0))) {
            if ((leftlinear == true) && (leftautomata == true)) {
                std::cout << "311" << std::endl;
                return 0;
            }
            if ((rightlinear == true) && (rightautomata == true)) {
                std::cout << "321" << std::endl;
                return 0;
            }
        }
    }
    srule = false;
    int sright = 0, less = 0, SNrule = 0, NN = 0;
    bool isreg = true, leftautomata = true, rightautomata = true, 
    leftlinear = true, rightlinear = true;
    for (auto grit = grammar.begin(); grit != grammar.end(); ++grit) {
        char left = grit->l;
        std::string right = grit->r;
    //while (std::cin >> left >> right) {
        int rsize = right.size(), uppernum = 0, termnum = 0;
        bool Tfirst = false, Tcarry = false;
        if (islower(right[0]) || isdigit(right[0])) {
            Tfirst = true;
            Tcarry = true;
            ++termnum;
        } else {
            if (isupper(right[0])) {
                ++uppernum;
            }
        }
        for (int i = 0; i < rsize; ++i) {
            if (i > 0) {
                if (isupper(right[i])) {
                    Tcarry = false;
                    ++uppernum;
                }
                if (islower(right[i]) || isdigit(right[i])) {
                    ++termnum;
                }
                if ((Tfirst == true) && (Tcarry == false) && (islower(right[i]) || 
                    isdigit(right[i]))) {
                    isreg = false;
                }
            }
            if (right[i] == 'S') {
                ++sright;
            }
        }
        if (uppernum > 1) {
            isreg = false;
        }
        if (isreg == true) {
            if (Tfirst == false) {
                if (isupper(right[0]) && (rsize == 1)) {
                    ++NN;
                    if (NN > 1) {
                        leftautomata = false;
                        rightautomata = false;
                    }
                } else {
                    if (rsize > 2) {
                        leftautomata = false;
                    }
                    rightlinear = false;
                }
            } else {
                if (rsize > 2) {
                    rightautomata = false;
                }
                if (rsize > 1) {
                    leftlinear = false;
                }
            }
        }
        if (left == 'S') {
            if (right[0] == '_') {
                srule = true;
            }
            if (isupper(right[0]) && (rsize == 1)) {
                ++SNrule;
            }
        }
        if (right[0] == '_') {
            ++less;
        }
    }
    std::cout << "suka blyat "<< std::endl;
    if ((less == 0) || 
        ((less == 1) && (srule == true) && (sright == 0))) {
        if ((isreg == false) || ((leftlinear == false) && (rightlinear == false))) {
            std::cout << "21" << std::endl;
            return 0;
        }
        if ((leftlinear == true) && (leftautomata == true) && 
            (((srule == false) && (SNrule == 0) && (NN == 0)) || 
                ((srule == true) && (SNrule == 1) && (NN == 1)))) {
            std::cout << "311" << std::endl;
            return 0;
        }
        if (leftlinear == true) {
            std::cout << "31" << std::endl;
            return 0;
        }
        if ((rightlinear == true) && (rightautomata == true) && 
            (((srule == false) && (SNrule == 0) && (NN == 0)) || 
                ((srule == true) && (SNrule == 1) && (NN == 1)))) {
            std::cout << "321" << std::endl;
            return 0;
        }
        if (rightlinear == true) {
            std::cout << "32" << std::endl;
            return 0;
        }
        return 0;
    }
    if (less >= 0) {
        std::cout << "2" << std::endl;
        return 0;
    }
}
