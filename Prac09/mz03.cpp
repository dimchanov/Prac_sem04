#include <iostream>
#include <utility>

class S {
private:
    int value = 0;
    short value_flag;
public:
    S() {
        if (std::cin >> value) {
            value_flag = 1;
        } else {
            value_flag = 0;
        }
    }

    S(S &&last_value) {
        if (std::cin >> value) {
            value_flag = 1;
        } else {
            value_flag = 2;
        }
        value += last_value.value;
        last_value.value_flag = 0;

    }
    
    operator bool() const {
        return (value_flag == 1) ? true : false ;
    }

    ~S() {
        if (value_flag == 2) {
            std::cout << value << std::endl;
        }
    }
};

