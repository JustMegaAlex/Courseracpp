#include<iostream>
#include<map>
#include<set>

int main() {
    int num = 0, len = 0, route_count = 0;
    std::cin >> num;
    std::map<std::set<std::string>, int> routes;
    std::set<std::string> new_route;
    std::string stop_name;
    while(num--) {
        std::cin >> len;
        while(len--) {
            std::cin >> stop_name;
            new_route.insert(stop_name);
        }
        if (routes.count(new_route) != 0)
            std::cout << "Already exists for " << routes[new_route] << "\n";
        else {
            std::cout << "New bus " << ++route_count << "\n";
            routes[new_route] = route_count;
        }
        new_route.clear();
    }
    return 0;
}
