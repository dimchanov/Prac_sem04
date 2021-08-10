#include <iostream>
#include <cinttypes>
#include <vector>
void process(
        std::vector<std::int64_t> &v1, 
        std::int64_t st) {
    size_t v1_size = v1.size();
    if (v1_size != 0) {
        v1.resize(2 * v1_size);
        auto it = v1.begin() + v1_size - 1;
        int count{0};
        while(it >= v1.begin()) {
            if (*it >= st) {
                *(v1.begin() + count + v1_size) = *it;
                ++count;
            }
            --it;
        }
        v1.resize(v1_size + count);
    }
}

