#include<iostream>
#include<map>
#include<set>

void add_synonims(std::string w, std::string w1,
                   std::map<std::string, std::set<std::string>>& synonims) {
    synonims[w].insert(w1);
    synonims[w1].insert(w);
}

int count(std::string w,
          std::map<std::string, std::set<std::string>>& synonims) {
    return synonims[w].size();
}

std::string check(std::string w, std::string w1,
                  std::map<std::string, std::set<std::string>>& synonims) {
    return (synonims[w].count(w1) != 0) ? "YES" : "NO";
}

int main() {
    int num = 0;
    std::cin >> num;
    std::string com, word, word1;
    std::map<std::string, std::set<std::string>> synonims;
    while(num--) {
        std::cin >> com;
        std::cin >> word;
        if (com == "ADD") {
            std::cin >> word1;
            add_synonims(word, word1, synonims);
        } else if (com == "COUNT") {
            std::cout << count(word, synonims) << "\n";
        } else if (com == "CHECK") {
            std::cin >> word1;
            std::cout << check(word, word1, synonims) << "\n";
        }
    }
    return 0;
}
