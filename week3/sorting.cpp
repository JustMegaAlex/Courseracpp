#include<vector>
#include<iostream>
#include<algorithm>

void print_vec(std::vector<int> v) {
    for(auto i: v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    int n = 0, i;
    std::vector<int> v;
    std::cin >> n;
    while(n--) {
        std::cin >> i;
        v.push_back(i);
    }
    std::sort(v.begin(), v.end(), [](int a, int b) {
            return std::abs(a) < std::abs(b);
        });
    print_vec(v);
    return 0;
}