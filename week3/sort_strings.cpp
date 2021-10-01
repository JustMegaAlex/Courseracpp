#include<vector>
#include<iostream>
#include<algorithm>

void print_vec(std::vector<std::string> v) {
    for(auto i: v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

std::string str_tolower(std::string s) {
    std::string res;
    for(char c: s) {
        res += tolower(c);
    }
    return res;
}

int main() {
    int n = 0;
    std::string s;
    std::vector<std::string> v;
    std::cin >> n;
    while(n--) {
        std::cin >> s;
        v.push_back(s);
    }
    std::sort(v.begin(), v.end(), [](std::string a, std::string b) {
            return str_tolower(a) < str_tolower(b);
        });
    print_vec(v);
    return 0;
}
