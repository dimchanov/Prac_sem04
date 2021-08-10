#include <iostream>
#include <string>

class Str_Item
{
private:
    std::string str;
public:
    Str_Item (std::string str) : str{str} {};
    ~Str_Item () {
        std::cout << str << std::endl;
    }
};

void rec_function() {
    std::string str;
    if (std::cin >> str) {
        Str_Item tmp_si(str);
        try {
            rec_function();
        } catch (const int x) {
            throw 1;
        }
    } else {
        throw 2;
    }
}

int main()
{
    try {
        rec_function();
    } catch (const int x) {}
    return 0;
}
