#include<iostream>
#include<vector>

const std::vector<int> MONTHS = {31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31};

std::string join(const std::vector<std::string>& v) {
    if (v.empty()) return "";
    std::string res;
    for(std::string s: v) {
        res += s + " ";
    }
    res.pop_back();
    return res;
}

int transfer_to_next_month(int cur, std::vector<std::vector<std::string>>& days) {
    int prev_len = MONTHS[cur];
    cur = (cur >= 11) ? 0 : (cur + 1);
    int cur_len = MONTHS[cur];
    // for(int i = prev; i < cur; ++i) {
    //     days[i].clear();
    // }
    if (cur_len < prev_len) {
        for(int i = cur_len + 1; i <= prev_len; ++i) {
            for (std::string s: days[i]) {
                days[cur_len].push_back(s);
            }
            days[i].clear();
        }
    }
    return cur;
}

/* 12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
 */

int main() {
    int num = 0;
    int cur_month = 0;
    std::cin >> num;
    int i = 0;
    int d = 0;
    std::string com;
    std::string task;
    std::vector<std::vector<std::string>> days;
    days.assign(32, {});
    while (i++ < num) {
        std::cin >> com;
        if (com == "ADD") {
            std::cin >> d;
            std::cin >> task;
            days[d].push_back(task);
        } else if (com == "DUMP") {
            std::cin >> d;
            std::cout << days[d].size() << " " << join(days[d]) << "\n";
        } else if (com == "NEXT") {
            cur_month = transfer_to_next_month(cur_month, days);
        }
    }
}