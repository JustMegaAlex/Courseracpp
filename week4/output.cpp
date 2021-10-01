#include <fstream>
#include <iostream>

int main() {
    std::ifstream f("input.txt");
    std::ofstream out("output.txt");
    std::string s;
    while (true) {
        std::getline(f, s);
        if (!f)
            break;
        out << s << '\n';
    }
    return 0;
}
