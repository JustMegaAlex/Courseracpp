
#include "bd.hpp"


int Date::GetYear() const {

}
int Date::GetMonth() const {

}
int Date::GetDay() const {

}
void Date::FromStr(std::string s) {
  
}

Parser::ParseResult Parser::process(std::string s) {
  std::istringstream inp{s};
  ParseResult res;
  inp >> res.command;
  _process_command(res, inp);
  return res;
}
void Parser::_process_args(ParseResult& res, std::istringstream& inp) {
  // inp >> res.date;
}
void Parser::_process_command(ParseResult& res, std::istringstream& inp) {
  if (allowed_commands.count(res.command) == 0)
    throw std::invalid_argument(res.command);
  if (res.command == kPrint)
    return;
  _process_args(res, inp);
}

void Database::AddEvent(const Date& date, const std::string& event) {
  data[date].emplace(event);
};

bool Database::DeleteEvent(const Date& date, const std::string& event) {
  if (data.count(date) == 0)
    return false;
}

int Database::DeleteDate(const Date& date) {
  if (data.count(date) == 0)
    return 0;
  int res = data.at(date).size();
  data.erase(date);
  return res;
};

Events Database::Find(const Date& date) const {
  if (data.count(date) == 0)
    return {};
  return data.at(date);
};

void Database::Print() const {};

bool operator<(const Date& lhs, const Date& rhs) {
  int ly = lhs.GetYear();
  int lm = lhs.GetMonth();
  int ld = lhs.GetDay();
  int ry = rhs.GetYear();
  int rm = rhs.GetMonth();
  int rd = rhs.GetDay();
  if (ly != ry) return ly < ry;
  if (lm != rm) return lm < rm;
  if (ld != rd) return ld < rd;
  return false;
}
std::istream& operator>>(std::istream& inp, Date& date) {
  return inp;
}

std::ostream& operator<<(std::ostream& out, Parser::ParseResult& res) {
  out << res.command << " " /* << res.date << " " */<< res.event;
  return out;
}


int main() {
  Database db;
  std::string command;
  while (getline(std::cin, command)) {
    try {
      auto res = Parser().process(command);
      std::cout << res << '\n';
    } catch (std::invalid_argument &e) {
      std::cout << "Unknown command: " << e.what() << '\n';
    }
  }

  return 0;
}
