#include <fstream>
#include <iostream>

int main() {
    std::ifstream f("input.txt");
    std::string s;
    while (true) {
        std::getline(f, s);
        if (!f)
            break;
        std::cout << s << '\n';
    }
    return 0;
}
