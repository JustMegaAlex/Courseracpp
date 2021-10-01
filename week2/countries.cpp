#include<map>
#include<iostream>

std::string change_capital(std::string country, std::string new_cap,
                           std::map<std::string, std::string>& countries,
                           std::map<std::string, std::string>& capitals) {
    std::string mess;
    std::string old;
    if (!countries.count(country))
        mess = "Introduce new country " + country + " with capital " + new_cap + "\n"; 
    else if (countries[country] == new_cap)
        mess = "Country " + country +" hasn't changed its capital\n";
    else {
        old = countries[country];
        mess = "Country " + country + " has changed its capital from " + old + " to " + new_cap + "\n";
    }
    countries[country] = new_cap;
    if (!old.empty())
        capitals.erase(old);
    capitals[new_cap] = country;
    return mess;
}

std::string rename_country(std::string country, std::string new_name,
                           std::map<std::string, std::string>& countries,
                           std::map<std::string, std::string>& capitals) {
    std::string mess_incorrect = "Incorrect rename, skip\n";
    if (country == new_name
            || countries.count(country) == 0
            || countries.count(new_name) != 0)
        return mess_incorrect;
    std::string capital = countries[country];
    countries.erase(country);
    countries[new_name] = capital;
    capitals[capital] = new_name;
    return "Country " + country + " with capital " + capital + " has been renamed to " + new_name + "\n";
}

std::string dump(std::map<std::string, std::string>& countries,
                 std::map<std::string, std::string>& capitals) {
    if (countries.size() == 0) 
        return "There are no countries in the world\n";
    std::string res;
    for(auto item: countries) {
        res += item.first + '/' + item.second + ' ';
    }
    res.pop_back();
    return res + "\n";
}

std::string about(std::string country, std::map<std::string, std::string>& countries) {
    if (countries.count(country) == 0)
        return "Country " + country + " doesn't exist\n";
    return "Country " + country + " has capital " + countries[country] + "\n";
}

int main() {
    int num = 0;
    std::map<std::string, std::string> countries;
    std::map<std::string, std::string> capitals;
    std::cin >> num;

    std::string com, country, old, new_, out;

    while(num--) {
        std::cin >> com;
        if (com == "CHANGE_CAPITAL") {
            std::cin >> country;
            std::cin >> new_;
            std::cout << change_capital(country, new_, countries, capitals);
        } else if (com == "RENAME") {
            std::cin >> country;
            std::cin >> new_;
            std::cout << rename_country(country, new_, countries, capitals);
        } else if (com == "DUMP") {
            std::cout << dump(countries, capitals);
        } else if (com == "ABOUT") {
            std::cin >> country;
            std::cout << about(country, countries);
        }
    }
}
