#include <iostream>
#include <sstream>
#include <string>
#include <cmath>


class Rectangle : public Figure {
private:
    double a;
    double b;
public:
    double get_square() const {
        return a * b;
    }
    static Rectangle * make(std::string str) {
        std::stringstream sstr(str);
        double new_a, new_b;
        sstr >> new_a >> new_b;
        Rectangle *rec = new Rectangle();
        rec->a = new_a;
        rec->b = new_b;
        return rec;
    }
};

class Square : public Figure {
private:
    double a;
public:
    double get_square() const {
        return pow(a, 2); 
    }
    static Square * make(std::string str) {
        std::stringstream sstr(str);
        double new_a;
        sstr >> new_a;
        Square *sq = new Square();
        sq->a = new_a;
        return sq;
    }
};

class Circle : public Figure {
private:
    double r;
public:
    double get_square() const {
        return M_PI * pow(r, 2); 
    }
    static Circle * make(std::string str) {
        std::stringstream sstr(str);
        double new_r;
        sstr >> new_r;
        Circle *c = new Circle();
        c->r = new_r;
        return c;
    }
};

