#include <iostream>

int main()
{
    int count;
    std::cin >> count;

    Holder *H_elems = new Holder[count];

    for (int i = 0; i < count / 2; ++i) {
        H_elems[i].swap(H_elems[count - 1 - i]); 
    }

    delete [] H_elems;
    return 0;
}
