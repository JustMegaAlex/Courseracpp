#include <string>

struct Specialization {
    explicit Specialization(std::string s) {
        value = s;
    }
    std::string value;
};

struct Course {
    explicit Course(std::string s) {
        value = s;
    }
    std::string value;
};

struct Week {
    explicit Week(std::string s) {
        value = s;
    }
    std::string value;
};

struct LectureTitle {
    LectureTitle(Specialization s, Course c, Week w) {
        specialization = s.value;
        course = c.value;
        week = w.value;
    }
    std::string specialization;
    std::string course;
    std::string week;
};


// int main() {
//     LectureTitle title(
//         Specialization("C++"),
//         Course("White belt"),
//         Week("4th")
//     );

//     LectureTitle title("C++", "White belt", "4th");

//     LectureTitle title(string("C++"), string("White belt"), string("4th"));

//     LectureTitle title = {"C++", "White belt", "4th"};

//     LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

//     LectureTitle title(
//         Course("White belt"),
//         Specialization("C++"),
//         Week("4th")
//     );

//     LectureTitle title(
//         Specialization("C++"),
//         Week("4th"),
//         Course("White belt")
//     );
// }