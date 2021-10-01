#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream f("input.txt");
    int h, w, n;
    f >> h;
    f >> w;
    std::string s;
    std::cout << std::right;
    // std::cout << std::setfill('.');
    f.ignore(1);
    // std::getline(f, s, ',');
    // std::cout << std::setw(10) << s;
    while (h--) {
        int ww = w;
        bool is_first = true;
        while (ww--) {
            f >> n;
            if (ww)
                f.ignore(1);
            if (!is_first)
                std::cout << ' ';
            else
                is_first = false;
            std::cout << std::setw(10) << n;
        }
        f.ignore(1);
        std::cout << '\n';
    }
    return 0;
}