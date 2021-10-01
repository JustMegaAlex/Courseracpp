#include<iostream>
#include<vector>

/* 
5
7 6 3 0 9
*/
int main() {
    int n;
    int avr = 0;
    int num = 0;
    std::cin >> n;
    if (n == 0)
        return 0;
    std::vector<int> v(n);
    for(int& i: v) {
        std::cin >> i;
        avr += i;
    }
    avr /= n;
    for(const int& i: v) {
        if (i > avr) ++num;
    }
    std::cout << num << "\n";
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > avr)
            std::cout << i << " ";
    }
    return 0;
}