
#include<iostream>

int main() {
    // fcsa
    std::string s;
    std::cin >> s;
    int res = -2;
    for (int i = 0; i < s.length(); i++) {
        bool match = s[i] == 'f';
        if (match && res == -2) ++res;
        else if (match && res == -1){
            std::cout << i << "\n";
            return 0;
        }
    }
    std::cout << res << "\n";
    return 0;
}