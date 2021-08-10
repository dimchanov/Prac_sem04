#include <iostream>
#include <cctype>

using namespace std;

enum { MAX_LEVEL = 6 };
char c;

void gc()
{
    cin >> c;
}

int operation_level()
{
    int level;
    switch (c) {
        case '*':
        case '/':
            level = 2;
            break;
        case '+':
        case '-':
            level = 3;
            break;
        case '&':
            level = 4;
            break;
        case '^':
            level = 5;
            break;
        case '|':
            level = 6;
            break;
        default:
            level = MAX_LEVEL;
            break;
    }
    return level;
}

pair<string, int> A();

pair<string, int> F(int pos)
{
    int level = 1;
    string s = "";
    if (c == '(') {
        gc();
        pair<string, int> tmp = A();
        gc();
        if (pos <= tmp.second || tmp.second > operation_level()) {
            s += "(" + tmp.first + ")";
        } else {
            s += tmp.first;
            level = tmp.second;
        }
    } else {
        s += c;
        gc();
    }
    return pair<string, int>(s, level);
}

pair<string, int> E(int pos)
{
    int level = 2;
    string s = "";
    pair<string, int> tmp = F(pos);
    s += tmp.first;
    int val = tmp.second;
    while (c == '*' || c == '/') {
        s += c;
        gc();
        tmp = F(level);
        s += tmp.first;
        val = level;
    }
    return pair<string, int>(s, val);
}

pair<string, int> D(int pos)
{
    int level = 3;
    string s = "";
    pair<string, int> tmp = E(pos);
    s += tmp.first;
    int val = tmp.second;
    while (c == '+' || c == '-') {
        s += c;
        gc();
        tmp = E(level);
        s += tmp.first;
        val = level;
    }
    return pair<string, int>(s, val);
}

pair<string, int> C(int pos)
{
    int level = 4;
    string s = "";
    pair<string, int> tmp = D(pos);
    s += tmp.first;
    int val = tmp.second;
    while (c == '&') {
        s += c;
        gc();
        tmp = D(level);
        s += tmp.first;
        val = level;
    }
    return pair<string, int>(s, val);
}

pair<string, int> B(int pos)
{
    int level = 5;
    string s = "";
    pair<string, int> tmp = C(pos);
    s += tmp.first;
    int val = tmp.second;
    while (c == '^') {
        s += c;
        gc();
        tmp = C(level);
        s += tmp.first;
        val = level;
    }
    return pair<string, int>(s, val);
}

pair<string, int> A()
{
    int level = 6;
    string s = "";
    pair<string, int> tmp = B(MAX_LEVEL + 1);
    s += tmp.first;
    int val = tmp.second;
    while (c == '|') {
        s += c;
        gc();
        tmp = B(level);
        s += tmp.first;
        val = level;
    }
    return pair<string, int>(s, val);
}


int main()
{
    gc();
    pair<string, int> res = A();
    cout << res.first << endl;
    return 0;
}
