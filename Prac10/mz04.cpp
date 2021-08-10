#include <iostream>

/* Grammar:
S -> aSd | aAd
A -> bAc | bc
*/

void A(int m)
{
    std::cout << 'b';
    if (m > 1) {
        A(m - 1);
    }
    std::cout << 'c';
}

void S(int k, int n)
{
    std::cout << 'a';
    if (n > 1) {
        S(k - 2, n - 1);
    } else {
        A(k / 2 - 1);
    }
    std::cout << 'd';
}

void f(int k, int n)
{
    S(k, n);
    std::cout << std::endl;
    if (n > 1) {
        f(k, n - 1);
    }
}

int main()
{
    int k;
    std::cin >> k;
    if (k >= 4 && (k % 2) == 0) {
        f(k, k / 2 - 1);
    }
}
