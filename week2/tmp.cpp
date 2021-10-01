#include<vector>
#include<iostream>


void change(std::vector<std::vector<std::string>>& v) {
    std::cout << v[0][0] << "\n";
    v[0].push_back("second");
}

int main() {
    std::vector<std::vector<std::string>> v = {{"first"}};
    change(v);
    std::cout << v[0][0] << "\n";
    std::cout << v[0][1] << "\n";
    return 0;
}
