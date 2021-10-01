#include<vector>
#include<iostream>

void Reverse(std::vector<int>& v) {
    int len = v.size();
    for (size_t i = 0; i < len / 2; i++) {
        int buf = v[i];
        int symmetr = len - 1 - i;
        v[i] = v[symmetr];
        v[symmetr] = buf;
    }
}

// int main() {
//     std::vector<int> v = {1, 2, 3, 4};
//     Reverse(v);
//     for(int i: v) std::cout << i << " ";
//     std::cout << "\n";
//     return 0;
// }
