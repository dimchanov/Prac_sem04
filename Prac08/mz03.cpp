#include <iostream>
#include <cmath>

namespace Game {
template <typename T>
class Coord{
public:
    typedef T value_type;
    T row;
    T col;
    Coord(T row = {}, T col = {}) : row{row}, col{col} {}
};


template <typename T>
T my_abs(T a) {
    if (a >= 0) {
        return a;
    } else {
        return (-1) * a;
    }
}
template <typename T>
T dist (Coord<T> len, Coord<T> c1, Coord<T> c2) {
    T rc1 = c1.row - (c1.col + 1) / 2;
    T rc2 = c2.row - (c2.col + 1) / 2;
    T max = std::max(my_abs(rc1 - rc2), my_abs(c1.col - c2.col));
    T res = std::max(max, my_abs(rc1 + c1.col - rc2 - c2.col));
    return res;
}
};


