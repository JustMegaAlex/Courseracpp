#include<iostream>
#include<cmath>
void print(int s) {
    std::cout << s << "\n";
}

int main() {
    // 12 10
    // 50 75 -- 25
    int a, b;
    a = b = 0;
    std::cin >> a >> b;
    if (a > b) {
        int buf = a;
        a = b;
        b = buf;
    }
    if (b % a == 0) {
        print(a);
        return 0;
    }
    int res = 1;
    int possible = 0;
    for (int i = 2; i <= std::sqrt(a); ++i) {
        if ((a % i) == 0) {
            possible = a / i;
            if (b % (possible) == 0) {
                res = possible;
                break;
            }
            if ((b % i) == 0) res = i;
        }
    }
    print(res);
    return 0;
}
