#include <iostream>
#include <cinttypes>
#include <vector>
void process(
        const std::vector<std::uint64_t> &v1, 
        std::vector<std::uint64_t> &v2, 
        int st) {
    auto it1 = v1.begin();
    auto it2 = v2.rbegin();
    while(it1 < v1.end() && it2 < v2.rend()) {
        *it2 += *it1;
        it1 += st;
        ++it2;
    }
}
