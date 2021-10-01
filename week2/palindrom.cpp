#include<iostream>
#include<vector>


bool IsPalindrom(std::string s) {
    int len = s.length();
    for (int i = 0; i < (len / 2); ++i) {
        if (s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> v, int minlen) {
    std::vector<std::string> res;
    for(auto s: v) {
        if (s.length() < minlen)
            continue;
        if (IsPalindrom(s))
            res.push_back(s);
    }
    return res;
}

/* int main() {
    std::vector<std::string> v = {"aaa", "asddsa", "sdlfjsldkfj", "a"};
    for(auto s: PalindromFilter(v, 3)) {
        std::cout << s << " ";
    }
    std::cout << "\n";
    return 0;
} */
