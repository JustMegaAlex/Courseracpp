#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

std::string join(const std::vector<std::string> arr, const std::string sep) {
    if (arr.size() == 0) return "";
    if (arr.size() == 1) return arr[0];
    std::string res = arr[0];
    for(int i = 1; i < arr.size() - 1; ++i) {
        res += sep + arr[i];
    }
    return res + sep + arr[arr.size() - 1];
}

class Person {
    private:
        std::string first;
        std::string last;
        int birthyear;
        bool birthyear_assigned = false;
        // year - name
        std::map<int, std::string> first_name_log;
        std::map<int, std::string> last_name_log;
        
        std::string get_value_before(int key, std::map<int, std::string> map) const {
            std::string last;
            if (map.count(key) != 0)
                return map[key];
            for(auto item: map) {
                if (item.first > key)
                    break;
                last = item.second;
            }
            return last;
        }

        std::string form_full_name(std::string first, std::string last) const {
            if (first == "" && last == "")
                return "Incognito";
            if (first == "")
                return last + " with unknown first name";
            if (last == "")
                return first + " with unknown last name";
            return first + " " + last;
        }

        std::string name_with_history(int year, std::map<int, std::string> map) const {
            std::vector<std::string> history;
            std::string prev;
            // >> 1945
            // 1920, 1921, 1930*, 1944*
            // 1920, 1921
            // 1920
            for(auto item: map) {
                if (item.first > year)
                    break;
                if (prev != "" && prev != item.second) history.insert(history.begin(), prev);
                prev = item.second;
            }
            // std::string current;
            // if (history.size()) {
            //     current = history[history.size() - 1];
            //     history.pop_back();
            // }
            if (history.size())
                return prev + " " + "(" + join(history, ", ") + ")";
            return prev;
        }

        void check_assign_birthyear(int year) {
            if (!birthyear_assigned) {
                birthyear = year;
                birthyear_assigned = true;
            }
        }

    public:
        Person(std::string f, std::string l, int y) {
            ChangeFirstName(y, f);
            ChangeLastName(y, l);
            birthyear = y;
        }
        void ChangeFirstName(int year, const std::string& new_name) {
            check_assign_birthyear(year);
            if ((new_name == first) || ((year < birthyear)))
                return;
            first = new_name;
            first_name_log[year] = new_name;
        }
        void ChangeLastName(int year, const std::string& new_name) {
            check_assign_birthyear(year);
            if ((new_name == last) || (year < birthyear))
                return;
            last = new_name;
            last_name_log[year] = new_name;
        }

        std::string GetFullName(int year) const {
            if (year < birthyear) return "No person";
            std::string first_name, last_name;
            if (first_name_log.count(year) == 0)
                first_name = get_value_before(year, first_name_log);
            else
                first_name = first_name_log.at(year);
            if (last_name_log.count(year) == 0)
                last_name = get_value_before(year, last_name_log);
            else
                last_name = last_name_log.at(year);

            return form_full_name(first_name, last_name);
        }

        std::string GetFullNameWithHistory(int year) const {
            if (year < birthyear) return "No person";
            std::string first_with_history = name_with_history(year, first_name_log);
            std::string last_with_history = name_with_history(year, last_name_log);
            return form_full_name(first_with_history, last_with_history);
        }

        void print() {
            std::cout << "\nFirst names: \n";
            for(auto it: first_name_log) {
                std::cout << it.first << ": " << it.second << '\n';
            }
            std::cout << "Last names: \n";
            for(auto it: last_name_log) {
                std::cout << it.first << ": " << it.second << '\n';
            }
        }
};
