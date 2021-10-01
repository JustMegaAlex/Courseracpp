#include <string>
#include <stdexcept>

void EnsureEqual(std::string& s1, std::string& s2) {
  if (s1 != s2)
    throw std::runtime_error(s1 + " != " + s2);
}
