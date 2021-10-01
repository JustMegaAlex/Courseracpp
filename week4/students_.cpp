#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Student {
    std::string name;
    std::string second_name;
    int bday;
    int bmonth;
    int byear;
};

std::ifstream input("inp.txt");

void handle_request(std::vector<Student> students) {
    std::string rtype;
    int k;
    input >> rtype;
    input >> k;
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
    input >> students_num;
    std::vector<Student> students;
    while(students_num) {
        Student st;
        input >> st.name;
        input >> st.second_name;
        input >> st.bday;
        input >> st.bmonth;
        input >> st.byear;
        students.push_back(st);
        students_num--;
    }
    std::cout << "students: " << students.size() << '\n';
    input >> requests_num;
    while(requests_num) {
        handle_request(students);
        requests_num--;
    }
    return 0;
}
