#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

void print_matr(const std::vector< std::vector<int> > &matr) {
    for (unsigned  i = 0; i < matr.size(); ++i) {
        for (unsigned j = 0; j < matr[i].size(); ++j) {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void change_max(std::vector<int> &vec, int ch, int idx) {
    if (idx > 0) {
        vec[idx - 1] = std::max(0, vec[idx - 1] - (ch / 2));
    }
    vec[idx] = std::max(0, vec[idx] - ch);
    if (idx < (int)vec.size() - 1) {
        vec[idx + 1] = std::max(0, vec[idx + 1] - (ch / 2));
    }
}

void get_change(std::vector< std::vector<int> > &matr, int ch) {
    int max(0);
    int row_idx(0);
    int cell_idx(0);
    for (int i = 0; i < (int)matr.size(); ++i) {
        for (int j = 0; j < (int)matr[i].size(); ++j) {
            if (matr[i][j] > max) {
                row_idx = i;
                cell_idx = j;
                max = matr[i][j];
            }
        }
    }
    if (row_idx > 0) {
        change_max(matr[row_idx - 1], ch / 2, cell_idx);
    }
    change_max(matr[row_idx ], ch, cell_idx);
    if (row_idx < (int)matr.size() - 1) {
        change_max(matr[row_idx + 1], ch / 2, cell_idx);
    }
}

int main() {
    std::string str;
    std::vector< std::vector<int> > matr;

    while (getline(std::cin, str)) {
        std::vector<int> tmp;

        std::stringstream ss(str);
        int number{};
        while (ss >> number) {
            tmp.push_back(number);
        }
        if (tmp.size() == 0) {
            break;
        }
        matr.push_back(tmp);
    }
    int ch{};
    while (std::cin >> ch) {
        get_change(matr, ch);
    }
    print_matr(matr);


}
