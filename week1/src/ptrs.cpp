
#include<iostream>

int main() {
    int x;
    int* px = &x;
    int xx[100];
    xx[3] = 4;
    std::cout << "pointer x: " << *px;
    std::cout << "\n";
    return 0;
}
