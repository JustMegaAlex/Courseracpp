
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <stdexcept>

class UnknownCommand : public std::runtime_error {
  public:
    UnknownCommand(std::string s) : std::runtime_error::runtime_error(s) {}
};
class WrongFormat : public std::runtime_error {
  public:
    WrongFormat(std::string s) : std::runtime_error::runtime_error(s) {}
};
class InvalidDateInput : public std::exception {
  public:
    InvalidDateInput(std::string s, int month_or_day): _what(s), _month_or_day(month_or_day) {}
    std::string what() {
      return _what + ": " + std::to_string(_month_or_day);
    }
  private:
    std::string _what;
    int _month_or_day;
};

using Events = std::unordered_set<std::string>;
const char kDateSep = '-';

class Date {
  public:
    Date() = default;
    Date(int, int, int);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
  private:
    int y = 0;
    int m = 1;
    int d = 1;
};

class Parser {
  public:
    static const std::string kAdd = "ADD";
    static const std::string kDel = "DELETE";
    static const std::string kFind = "FIND";
    static const std::string kPrint = "PRINT";
    struct ParseResult {
      std::string command;
      Date date;
      std::string event;
    };
    ParseResult process(std::string s);
  private:
    void _process_command(ParseResult& res, std::istringstream& inp);
    void _process_args(ParseResult& res, std::istringstream& inp);
    void _process_date(Parser::ParseResult& res, std::istringstream& inp);
    void _process_event(Parser::ParseResult& res, std::istringstream& inp);
    void throw_wrong_format(std::istringstream& inp, int pos);
    int get_int_before_sep(std::istringstream& inp, char sep, int pos);
    bool check_space_after_date(std::istringstream& inp);
    void assert_input_empty(std::istringstream& inp, int pos);
    void assert_space_after_date(std::istringstream& inp, int pos);

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
std::ostream& operator<<(std::ostream& out, Date& date);
std::ostream& operator<<(std::ostream& out, Parser::ParseResult& res);
