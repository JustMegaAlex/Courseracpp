
#include "bd.hpp"
#include <fmt/core.h>
#include <iomanip>

Date::Date(int yy, int mm, int dd) :
    y(yy), m(mm), d(dd) {
  if (m < 1 || m > 12)
    throw InvalidDateInput("Month value is invalid", m);
  if (d < 1 || d > 31)
    throw InvalidDateInput("Day value is invalid", d);
}

int Date::GetYear() const {
  return y;
}
int Date::GetMonth() const {
  return m;
}
int Date::GetDay() const {
  return d;
}

void Parser::_process_args(ParseResult& res, std::istringstream& inp) {
  int pos = inp.tellg();
  _process_date(res, inp);
  assert_space_after_date(inp, pos);
  _process_event(res, inp);
}
void Parser::_process_command(ParseResult& res, std::istringstream& inp) {
  inp >> res.command;
  if (res.command == "")
    return;
  if (allowed_commands.count(res.command) == 0)
    throw UnknownCommand(res.command);
}

Parser::ParseResult Parser::process(std::string s) {
  std::istringstream inp{s};
  ParseResult res;
  _process_command(res, inp);
  if (res.command == kPrint)
    return res;
  else if (res.command == kDel) {
    _process_date(res, inp);
    if (check_space_after_date(inp))
      _process_event(res, inp);
  } else {
    _process_args(res, inp);
  }
  return res;
}

void Parser::throw_wrong_format(std::istringstream& inp, int pos) {
  std::string what;
  inp.clear();
  inp.seekg(pos);
  inp >> what;
  throw WrongFormat(what);
}

int Parser::get_int_before_sep(std::istringstream& inp, char sep, int pos) {
  int i;
  char _sep;
  inp >> i;
  inp >> _sep;
  if (_sep != sep)
    throw_wrong_format(inp, pos);
  return i;
}

void Parser::assert_input_empty(std::istringstream& inp, int pos) {
  std::string s;
  inp >> s;
  if (!inp.fail()) {
    throw_wrong_format(inp, pos);
  }
}

bool Parser::check_space_after_date(std::istringstream& inp) {
  char c;
  inp.get(c);
  return c == ' ';
}

void Parser::assert_space_after_date(std::istringstream& inp, int pos) {
  if (!check_space_after_date(inp))
    throw_wrong_format(inp, pos);
}

void Parser::_process_date(Parser::ParseResult& res, std::istringstream& inp) {
  int y, m, d;
  std::string what;
  y = m = d = 0;
  auto pos = inp.tellg();
  y = get_int_before_sep(inp, kDateSep, pos);
  m = get_int_before_sep(inp, kDateSep, pos);
  inp >> d;
  if (inp.fail()) {
    throw_wrong_format(inp, pos);
  }
  try {
    Date date(y, m, d);
    res.date = date;
  } catch (std::invalid_argument) {
    std::cout << y << ' ' << m << ' ' << d << '\n';
    throw WrongFormat("Wrong date format");
  }
}

void Parser::_process_event(Parser::ParseResult& res, std::istringstream& inp) {
  std::string event;
  int pos = inp.tellg();
  inp >> res.event;
  assert_input_empty(inp, pos);
}

void Database::AddEvent(const Date& date, const std::string& event) {
  data[date].emplace(event);
};

bool Database::DeleteEvent(const Date& date, const std::string& event) {
  if (data.count(date) == 0)
    return false;
  data[date].erase(event);
  return true;
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

std::ostream& operator<<(std::ostream& out, Date& date) {
  out << date.GetYear() << '-' << date.GetMonth() << '-' << date.GetDay();
  return out;
}

std::ostream& operator<<(std::ostream& out, Parser::ParseResult& res) {
  out << res.command << " " << res.date << " " << res.event;
  return out;
}

std::string RunCommand(Database db, Parser::ParseResult com) {
  if (com.command == Parser::kAdd) {

  } else if (com.command == Parser::kDel) {

  } else if (com.command == Parser::kFind) {

  } else if (com.command == Parser::kPrint) {

  }
}

int main() {
  Database db;
  std::string command;
  int i;
  while (getline(std::cin, command)) {
    try {
      auto res = Parser().process(command);
      std::cout << res << '\n';
      std::cout << RunCommand(db, res);
    } catch (UnknownCommand &e) {
      std::cout << "Unknown command: " << e.what() << '\n';
    } catch (WrongFormat &e) {
      std::cout << "Wrong date format: " << e.what() << '\n';
    } catch (InvalidDateInput &e) {
      std::cout << e.what() << '\n';
    }
  }
  return 0;
}
