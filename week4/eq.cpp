
#include <iostream>

struct S {
    S(int _a) : a(_a) {};
    bool operator==(S s) {
        return s.geta() == a;
    }
    int geta() { return a; }
    private:
        int a;
};

int main() {
    S s1(1);
    s1 = {2};
    S s2(1);
    std::cout << (s1 == s2);
    return 0;
}
