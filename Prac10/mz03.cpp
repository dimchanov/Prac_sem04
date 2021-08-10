#include <iostream>
#include <string>


/*
S -> XP
X -> aXb | ab
P -> CP1 | C1
bC -> Cb
aC -> a0
0C -> 00
*/

int main()
{
    std::string str;
    while (std::cin >> str) {
        size_t len = str.length();
        size_t i = 0;
        bool flag = true;
        int n = 0, m = 0;
        int nz = 0, mo = 0;
        while (i < len && str[i] == 'a') {
            ++i;
            ++n;
        }
        while (i < len && str[i] == '0') {
            ++i;
            ++m;
        }
        while (i < len && str[i] == 'b') {
            ++i;
            ++nz;
        }
        while (i < len && str[i] == '1') {
            ++i;
            ++mo;
        }
        if (i < len) {
            flag = false;
        }
        if (n == 0 || m == 0 || n != nz || m != mo) {
            flag = false;
        }
        std::cout << flag << std::endl;
    }
}
