#include <iostream>
#include <string>

class BinaryNumber
{
public:
    BinaryNumber(const std::string &s) : number{s} {};
    operator std::string () const {
        return number;
    }
    const BinaryNumber &operator++() {
        int flag{1};
        long long size = number.size();
        for (long long i = size - 1; i >= 0; --i) {
            if (!flag) {
                break;
            }
            if (number[i] == '0') {
                number[i] = '1';
                flag = 0;
            } else {
                number[i] = '0';
            }
        }
        if (flag) {
            number = '1' + number;
        }
        return *this;
    }
private:
    std::string number;
};

