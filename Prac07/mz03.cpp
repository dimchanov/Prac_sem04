#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <functional>

/*class Figure {

public:
    virtual ~Figure() {};
    virtual double get_square() const = 0;
};

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
};*/

class Factory
{
private:
    Factory() {};
public:
    static Factory &factory_instance() {
        static Factory single;
        return single;
    }
    std::unique_ptr<Figure> make_figure(std::string str) {
        std::stringstream sstr(str);
        char type;
        sstr >> type;
        std::getline(sstr, str);
        std::map <char, std::function<std::unique_ptr<Figure> (std::string str)> > F_map {
            {'R', [](std::string str) {
                return std::unique_ptr<Rectangle>(Rectangle::make(str)); 
            }},
            {'S', [](std::string str) {
                return std::unique_ptr<Square>(Square::make(str));
            }},
            {'C', [](std::string str) {
                return std::unique_ptr<Circle>(Circle::make(str));
            }}
        };
        return F_map[type](str);
    }
};

bool comparison(const std::unique_ptr<Figure> &x, const std::unique_ptr<Figure> &y) {
    return (x->get_square() < y->get_square());
}

int main()
{
    std::vector<std::unique_ptr<Figure>> F_vec;
    Factory fact = Factory::factory_instance();
    std::string str;
    while (std::getline(std::cin, str)) {
        F_vec.push_back(fact.make_figure(str));
    }
    std::stable_sort(F_vec.begin(), F_vec.end(), comparison);
    for (auto &item : F_vec) {
        std::cout << item->to_string() << std::endl;
    }
    return 0;
}
