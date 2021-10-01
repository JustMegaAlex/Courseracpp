
#include<iostream>
#include<vector>
#include<string>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& dest) {
    for(std::string s: source) dest.push_back(s);
    source.clear();
}

// int main() {
//     std::vector<std::string> ss = {"asdsa", "power", "force", "water"};
//     std::vector<std::string> src = {"engage", "fullfill"};
//     MoveStrings(src, ss);
//     for(std::string s: ss) std::cout << s << " ";
//     std::cout << "\n";
//     return 0;
// }
