#include <iostream>
#include <iomanip>

int main()
{
    unsigned w1(0);
    unsigned w2(0);
    unsigned num(0);

    std::cin >> w1 >> w2;

    unsigned l(0);
    unsigned dl(0);

    while (std::cin >> num) {

        unsigned tmp_l(0);

        while(num) {
            if (num % 2) {
                ++tmp_l;
            }
            num /= 2;
        }
        l +=  tmp_l;
        dl += 32 - tmp_l;
    }


    double max(-1);
    double min(-1);
    max += 2 * (double) (l + std::min(w1, dl))/(dl + l);
    min += 2 * (double) (l - std::min(w2, l))/(dl + l);

    std::cout  << std::setprecision(10) << min << ' ' << max << std::endl;
    return 0;
}
