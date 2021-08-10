#include <iostream>
namespace numbers {
    class complex_stack {
    public:
        complex_stack() {}
        complex_stack(size_t new_size) : Size{new_size} {
            stack = new complex[Size];
        }
        complex_stack (const complex_stack &new_stack) : Size{new_stack.size()} {
            stack = new complex[Size];
            for (int i = 0; i < (int)size(); ++i) {
                stack[i] = new_stack.stack[i];
            }
        }
        ~complex_stack() {
            delete [] stack;
        }
        size_t size() const {
            return this->Size;
        }

        complex operator [](int i) const {
            return stack[i];
        }

        friend complex_stack operator <<(const complex_stack &cs, complex c);
        
        complex operator +() const {
            return stack[size() - 1];
        }

        complex_stack operator ~() const {
            complex_stack tmp(size() - 1);
            for (int i = 0; i < (int)tmp.size(); ++i) {
                tmp.stack[i] = stack[i];
            }
            return tmp;
        }
        
        const complex_stack& operator =(const complex_stack &cs) {
            if (this != &cs) {
                delete [] stack;
                Size = cs.size();
                stack = new complex[Size];
                for (int i = 0; i < (int)size(); ++i) {
                    stack[i] = cs.stack[i];
                }
            }
            return *this;
        }

    private:
    complex *stack{nullptr};
    size_t Size{};
    };

    complex_stack operator <<(const complex_stack &cs, complex c) {
        complex_stack tmp(cs.size() + 1);
        for (int i = 0; i < (int)cs.size(); ++i) {
            tmp.stack[i] = cs.stack[i];
        }
        tmp.stack[cs.size()] = c;
        return tmp;
    }
}

