#include <boost/date_time.hpp>
#include <string>
#include <sstream>

void func(std::string &str) {
    std::stringstream ss1(str);
    unsigned short year, mon, day;
    ss1 >> year; ss1.ignore(1);
    ss1 >> mon; ss1.ignore(1);
    ss1 >> day;
    std::stringstream res1;
    res1 << year;
    if (mon < 10) {
        res1 << '0' << mon;
    } else {
        res1 << mon;
    }
    if (day < 10) {
        res1 << '0' << day;
    } else {
        res1 << day;
    }
    str = res1.str();
}

int main() {
    std::string str1;

    std::cin >> str1;

    unsigned long long sum(0);

    std::string str_tmp;
    func(str1);
    while (std::cin >> str_tmp) {
        func(str_tmp);
        //std::cout << str1 <<' '<< str_tmp <<std::endl;
        
        sum += std::abs((boost::gregorian::date_from_iso_string(str1)-
        boost::gregorian::date_from_iso_string(str_tmp)).days());
        str1 = str_tmp;
    }
    std::cout << sum << std::endl;
    return 0;
}
