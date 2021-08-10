#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>

namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z) {
        struct {
            void operator ()(complex_stack &stack, complex &z1, complex &z2) const {
                z1 = +stack;
                stack = ~stack;
                z2 = +stack;
                stack = ~stack;
            }
        } init_complex;
        std::map <char, std::function<void(complex_stack &, const complex &)> > OpMap {
            {'+', [init_complex](complex_stack &stack, const complex &z) {
                complex z1, z2;
                init_complex(stack, z1, z2);
                stack = stack << (z1 + z2);   
            }},
            {'-', [init_complex](complex_stack &stack, const complex &z) {
                complex z1, z2;
                init_complex(stack, z1, z2);
                stack = stack << (z2 - z1);
            }},
            {'*', [init_complex](complex_stack &stack, const complex &z) {
                complex z1, z2;
                init_complex(stack, z1, z2);
                stack = stack << (z1 * z2);
            }},
            {'/', [init_complex](complex_stack &stack, const complex &z) {
                complex z1, z2;
                init_complex(stack, z1, z2);
                stack = stack << (z2 / z1);   
            }},
            {'!', [](complex_stack &stack, const complex &z) {
                    stack = (stack << +stack);
            }},
            {';', [](complex_stack &stack, const complex &z) {
                    stack = ~stack;
            }},
            {'~', [](complex_stack &stack, const complex &z) {
                    complex z1 = +stack;
                    stack = ~stack;
                    stack = (stack << ~z1);
            }},
            {'#', [](complex_stack &stack, const complex &z) {
                    complex z1 = +stack;
                    stack = ~stack;
                    stack = (stack << -z1);
            }},
            {'z', [](complex_stack &stack, const complex &z) {
                    stack = (stack << z);
            }}
            };

        complex_stack stack;

        for (const std::string &item : args) {
            if (item.size() == 1) {
                OpMap[item[0]](stack, z);
            } else {
                complex z1(item);
                stack = (stack << z1);
            }
        }
        return +stack; 
    }
}
