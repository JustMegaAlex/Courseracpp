#include<map>
#include<vector>
#include<iostream>

int main() {
    int num = 0, len = 0;
    std::cin >> num;
    std::vector<std::string> new_route;
    std::map<std::vector<std::string>, int> routes;
    std::string name;
    int route_num = 0;
    while(num--) {
        std::cin >> len;
        while(len--) {
            std::cin >> name;
            new_route.push_back(name);
        }
        if(routes.find(new_route) == routes.end()) {
            std::cout << "New bus " << ++route_num << "\n";
            routes[new_route] = route_num;
        } else {
            std::cout << "Already exists for " << routes[new_route] << "\n";
        }
        new_route.clear();
    }
    return 0;
}