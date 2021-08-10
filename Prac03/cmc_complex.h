#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

namespace numbers {
    enum {
        BUF_SIZE = 1024
    };
    class complex {
    public:
        complex(double re = 0.0, double im = 0.0) : Re{re}, Im{im} {}
        explicit complex(const std::string & s) {
            std::stringstream ss(s);
            ss.ignore(1);
            ss >> Re;
            ss.ignore(1);
            ss >> Im;
            ss.ignore(1);
            }
        double re() const {
            return Re;
        }
        double im() const {
            return Im;
        }
        double abs() const {
            return sqrt(Re * Re + Im * Im);
        }
        double abs2() const {
            return (Re * Re + Im * Im);
        }
        std::string to_string() const {
        char buf[BUF_SIZE];
            snprintf(buf, BUF_SIZE, "(%.10g,%.10g)", Re, Im);
            return buf;
        }
        const complex& operator +=(const complex &second) {
            Re += second.re();
            Im += second.im();
            return *this;
        }
        const complex& operator -=(const complex &second) {
            Re -= second.re();
            Im -= second.im();
            return *this;
        }
        const complex& operator *=(const complex &second) {
            double re = Re * second.re() - Im * second.im();
            double im = Im * second.re() + Re * second.im();
            Re = re;
            Im = im;
            return *this;
        }
        const complex& operator /=(const complex &second) {
            double re = (Re * second.re() + Im * second.im()) / second.abs2();
            double im = (Im * second.re() - Re * second.im()) / second.abs2();
            Re = re;
            Im = im;
            return *this;
        }
        friend complex operator +(const complex &first, const complex &second);
        friend complex operator -(const complex &first, const complex &second);
        friend complex operator *(const complex &first, const complex &second);
        friend complex operator /(const complex &first, const complex &second);
        complex operator ~() const {
            return complex(Re, -Im);
        }
        complex operator -() const {
            return complex(-Re, -Im);
        }
    private:
        double Re{};
        double Im{};
    };
    complex operator +(const complex &first, const complex &second) {
        complex result(first.re(), first.im());
        result += second;
        return result;
    }
    complex operator -(const complex &first, const complex &second) {
        complex result(first.re(), first.im());
        result -= second;
        return result;
    }
    complex operator *(const complex &first, const complex &second) {
        complex result(first.re(), first.im());
        result *= second;
        return result;
    }
    complex operator /(const complex &first, const complex &second) {
        complex result(first.re(), first.im());
        result /= second;
        return result;
    }
}


