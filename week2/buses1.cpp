#include<map>
#include<vector>
#include<iostream>

std::string join(const std::vector<std::string>& v) {
    if (v.empty()) return "";
    std::string res;
    for(std::string s: v) {
        res += s + " ";
    }
    res.pop_back();
    return res;
}

std::string join_except(const std::vector<std::string>& v, std::string except) {
    if (v.empty()) return "";
    std::string res;
    for(std::string s: v) {
        res += (s != except) ? (s + " ") : "";
    }
    res.pop_back();
    return res;
}

void add_bus(std::map<std::string, std::vector<std::string>>& buses,
             std::map<std::string, std::vector<std::string>>& stops) {
    int count = 0;
    std::string stop_name, bus_name;
    std::cin >> bus_name;
    std::cin >> count;
    std::vector<std::string> stops_list;

    while(count--) {
        std::cin >> stop_name;
        stops_list.push_back(stop_name);
        stops[stop_name].push_back(bus_name);
    }
    buses[bus_name] = stops_list;
}

void show_buses_for_stop(std::map<std::string, std::vector<std::string>>& stops) {
    std::string stop_name;
    std::cin >> stop_name;
    if (stops.count(stop_name) == 0) {
        std::cout << "No stop\n";
        return;
    }
    std::cout << join(stops[stop_name]) + "\n";
}

void show_stops_for_bus(const std::map<std::string, std::vector<std::string>>& buses,
                        const std::map<std::string, std::vector<std::string>>& stops) {
    std::string bus_name;
    std::cin >> bus_name;
    if (buses.count(bus_name) == 0) {
        std::cout << "No bus\n";
        return;
    }
    for(auto stop_name: buses.at(bus_name)) {
        std::vector<std::string> stop_buses = stops.at(stop_name);
        if (stop_buses.size() == 0
            || (stop_buses.size() == 1 && stop_buses[0] == bus_name))
            std::cout << "Stop " << stop_name << ": no interchange\n";
        else
            std::cout << "Stop " << stop_name << ": " << join_except(stops.at(stop_name), bus_name) << "\n";
    }
}

void show_all(std::map<std::string, std::vector<std::string>>& buses) {
    if (buses.size() == 0) {
        std::cout << "No buses\n";
        return;
    }
    for(auto item: buses) {
        std::cout << "Bus " << item.first << ": " << join(item.second) + "\n";
    }
}


int main() {
    int num = 0;
    std::cin >> num;
    std::string com;
    std::map<std::string, std::vector<std::string>> buses;
    std::map<std::string, std::vector<std::string>> stops;
    while(num--) {
        std::cin >> com;
        if (com == "NEW_BUS")
            add_bus(buses, stops);
        else if (com == "BUSES_FOR_STOP")
            show_buses_for_stop(stops);
        else if (com == "STOPS_FOR_BUS")
            show_stops_for_bus(buses, stops);
        else if (com == "ALL_BUSES")
            show_all(buses);
    }
    return 0;
}
