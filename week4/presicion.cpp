#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream f("input.txt");
    double s;
    std::cout << std::fixed << std::setprecision(3);
    while(true) {
        f >> s;
        if (!f) break;
        std::cout << s << '\n';
    }
    return 0;
}