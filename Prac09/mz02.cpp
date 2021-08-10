#include <iostream>

class Result {
public:
    long long _result;

    Result(long long res) : _result{res} {};
};

void function(long long a, long long b, unsigned k) {
    if (k > 0 && b > 1) {
        try {
            function(a, b - 1, k);
        } catch (const Result &res1) {
            try {
                function(a, res1._result, k - 1);
            } catch (const Result &res2) {
                throw res2;
            }
        }
    } else if (k == 0){
        throw Result {a + b};
    } else if (b == 1) {
        throw Result {a};
    }
}
int main ()
{
    long long a, b;
    unsigned k;
    while (std::cin >> a >> b >> k) {
        try {
            function(a, b, k);
        } catch (const Result &res) {
            std::cout << res._result << std::endl;
        }
    }
    return 0;
}
