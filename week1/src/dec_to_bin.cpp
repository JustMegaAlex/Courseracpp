#include<iostream>

int main() {
    int n = 0;
    std::string s = "";
    std::cin >> n;
    do {
        s = std::to_string((n & 1)) + s;
        n = n >> 1;
    } while (n);
    std::cout << s << "\n";
    return 0;
}