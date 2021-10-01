#include<iostream>

int Factorial(int a) {
    if (a <= 1)
        return 1;
    int res = 1;
    for (int i = 2; i <= a; ++i) {
        res *= i;
    }
    return res;
}

/*
int main() {
    int a = 0;
    std::cin >> a;
    std::cout << Factorial(a) << "\n";
    return 0;
}
*/