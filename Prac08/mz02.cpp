#include <iostream>
#include <cmath>

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
    T tmp = std::min(my_abs(c2.row - c1.row - len.row), my_abs(c2.row - c1.row + len.row));
    T r_step = my_abs(c1.row - c2.row);
    if (r_step > tmp) {
        r_step = tmp;
    }
    tmp = std::min(my_abs(c2.col - c1.col - len.col), my_abs(c2.col - c1.col + len.col));
    T c_step = my_abs(c1.col - c2.col);
    if (c_step > tmp) {
        c_step = tmp;
    }
    return std::min(c_step, r_step) + my_abs(c_step - r_step);
}


