#include <iterator>
#include <functional>
#include <iostream>


template<typename It1, 
        typename It2, 
        typename F1 = decltype(std::multiplies<>()), 
        typename F2 = decltype(std::plus<>())>
typename std::iterator_traits<It1>::value_type 
scalar_mul(It1 Ibeg, 
        It1 Iend, 
        It2 I2, 
        typename std::iterator_traits<It1>::value_type init = {},
        F1 MulF = std::multiplies<>(),
        F2 AddF = std::plus<>()) {
    typename std::iterator_traits<It1>::value_type sum = init;
    auto it1 = Ibeg;
    auto it2 = I2;
    while (it1 != Iend) {
        sum = AddF(sum, MulF(*it1, *it2));
        ++it1;
        ++it2;
    }
    return sum;
}

