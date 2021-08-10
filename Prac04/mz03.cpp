#include <iostream>
#include <vector>
#include <algorithm>

void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> copy_v1(v1);
    std::sort(copy_v1.begin(), copy_v1.end());
    auto nunq = std::unique(copy_v1.begin(), copy_v1.end());
    copy_v1.erase(nunq, copy_v1.end());

    auto it1 = copy_v1.begin();
    int count{0};
    int v2_size = v2.size();
    auto it_v2 = v2.begin();
    auto it_res = v2.begin();
    while (count < v2_size && it1 < copy_v1.end()) {
        if (*it1 >= 0) {
            if (*it1 == count) {
                ++it1;
            } else {
                std::swap(*it_res, *it_v2);
                ++it_res;
            }
            ++it_v2;
            ++count;
        } else {
            ++it1;
        }
    }
    v2.erase(it_res, it_v2);
}
