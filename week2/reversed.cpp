#include<vector>
#include<iostream>

std::vector<int> Reversed(const std::vector<int>& v) {
    std::vector<int> res = {};
    int len = v.size();
    for (int i = len - 1; i >= 0; --i) {
        res.push_back(v[i]);
    }
    return res;
}

// int main() {
//     std::vector<int> v = {1, 2, 3, 4};
//     std::vector<int> rev = Reverse(v);
//     for(int i: rev) std::cout << i << " ";
//     std::cout << "\n";
//     return 0;
// }
