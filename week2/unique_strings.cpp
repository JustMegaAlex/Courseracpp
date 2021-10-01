#include<set>
#include<iostream>

int main() {
    int num = 0;
    std::string s;
    std::cin >> num;
    std::set<std::string> set;
    while(num--) {
        std::cin >> s;
        set.insert(s);
    }
    std::cout << set.size() << "\n";
}