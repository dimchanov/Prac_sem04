#include <algorithm>
#include <vector>
#include <utility>

#include <iostream>
template <typename It1, typename It2>
auto myremove(It1 begin_idx, It1 end_idx, It2 begin_elem, It2 end_elem) {
    std::vector<int> copy_idx(begin_idx, end_idx);
    std::sort(copy_idx.begin(), copy_idx.end());
    auto nunq = std::unique(copy_idx.begin(), copy_idx.end());
    copy_idx.erase(nunq, copy_idx.end());

    auto it_elem = begin_elem;
    int count(0);
    auto res = begin_elem;
    int flag = 1;

    while (it_elem != end_elem) {
        flag = 1;
        auto it_copy_idx = copy_idx.begin();
        while (it_copy_idx != copy_idx.end()){
            if (*it_copy_idx == count) {
                flag = 0;
                break;
            }
            ++it_copy_idx;
        }
        if (flag) {
            *res = std::move(*it_elem);
            ++res;
        }
        ++count;
        ++it_elem;
    }
    return res;
}

