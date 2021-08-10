#include <iostream>
#include <cmath>

int main()
{
    int m, n;
    std::cin >> m >> n;
    int r1, c1, r2, c2;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        int l_step = abs(r2 - r1);
        if (m - l_step < l_step) {
            l_step = m - l_step;
        }
        int c_step = abs(c2 - c1);
        if (n - c_step < c_step) {
            c_step = n - c_step;
        }
        std::cout << c_step + l_step << std::endl;
    }
    return 0;
}
