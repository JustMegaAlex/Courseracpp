#include<map>
#include<iostream>

std::map<char, int> get_counter(std::string s) {
    std::map<char, int> res;
    for(char c: s) {
        ++res[c];
    }
    return res;
}

int main() {
    int num = 0;
    std::cin >> num;
    std::string first, second, out;
    while (num--) {
        std::cin >> first;
        std::cin >> second;
        out = get_counter(first) == get_counter(second) ? "YES" : "NO";
        std::cout << out << "\n";
    }
    return 0;
}
