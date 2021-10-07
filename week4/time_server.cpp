#include "time_server.hpp"

std::string AskTimeServer() {
  throw std::system_error();
  return "12:00:00";
}

int main() {
  std::cout << TimeServer().GetCurrentTime() << '\n';
  return 0;
}
