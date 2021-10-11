
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <stdexcept>

using Events = std::unordered_set<std::string>;

const std::string kAdd = "ADD";
const std::string kDel = "DELETE";
const std::string kFind = "FIND";
const std::string kPrint = "PRINT";

class Date {
  public:
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
  private:
    void FromStr(std::string s);
    int y = 0;
    int m = 1;
    int d = 1;
};

class Parser {
  public:
    struct ParseResult {
      std::string command;
      Date date;
      std::string event;
    };
    ParseResult process(std::string s);
  private:
    void _process_command(ParseResult& res, std::istringstream& inp);
    void _process_args(ParseResult& res, std::istringstream& inp);
    std::istringstream inp;
    std::unordered_set<std::string> allowed_commands{kAdd, kDel,
                                                     kPrint, kFind};
};

class Database {
  public:
    void AddEvent(const Date& date, const std::string& event);
    bool DeleteEvent(const Date& date, const std::string& event);
    int DeleteDate(const Date& date);
    Events Find(const Date& date) const;
    void Print() const;
  private:
    std::map<Date, Events> data{};
};

bool operator<(const Date& lhs, const Date& rhs);
std::istream& operator>>(std::istream& inp, Date& date);
std::ostream& operator<<(std::ostream& out, Parser::ParseResult& res);
