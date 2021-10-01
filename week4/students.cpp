#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::string second_name;
    int bday;
    int bmonth;
    int byear;
};

void handle_request(std::vector<Student> students) {
    std::string rtype;
    int k;
    std::cin >> rtype;
    std::cin >> k;
    k--;
    if (k < 0 || k > (students.size() - 1)) {
        std::cout << "bad request\n";
        return;
    }
    if (rtype == "name")
        std::cout << students[k].name + ' ' + students[k].second_name << '\n';
    else if (rtype == "date")   
        std::cout << students[k].bday << '.'
                  << students[k].bmonth << '.'
                  << students[k].byear << '\n';
    else
        std::cout << "bad request\n";
}

int main() {
    int students_num = 0, requests_num = 0;
    std::cin >> students_num;
    std::vector<Student> students;
    while(students_num) {
        Student st;
        std::cin >> st.name;
        std::cin >> st.second_name;
        std::cin >> st.bday;
        std::cin >> st.bmonth;
        std::cin >> st.byear;
        students.push_back(st);
        students_num--;
    }
    std::cin >> requests_num;
    while(requests_num) {
        handle_request(students);
        requests_num--;
    }
    return 0;
}
