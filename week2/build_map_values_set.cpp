#include<iostream>
#include<map>
#include<set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string> m) {
    std::set<std::string> set;
    for(auto item: m) {
        set.insert(item.second);
    }
    return set;
}
/* 
int main() {
    std::set<std::string> set = BuildMapValuesSet({{1, "one"}, {22, "two two"}});
    for(auto it: set) {
        std::cout << it << " ";
    }
    std::cout << "\n";
    return 0;
}
*/
