#include <math.h>
#include <iostream>
#include <stdexcept>
#include <map>
#include <set>
#include <vector>
using namespace std;


int MaxCommonDivider(int a, int b) {
    // 12 10
    // 50 75 -- 25
    if (a == 0)
        return std::abs(b);
    a = std::abs(a);
    b = std::abs(b);
    if (a > b) {
        int buf = a;
        a = b;
        b = buf;
    }
    if (b % a == 0) {
        return a;
    }
    int res = 1;
    int possible = 0;
    for (int i = 2; i <= std::sqrt(a); ++i) {
        if ((a % i) == 0) {
            possible = a / i;
            if (b % (possible) == 0) {
                res = possible;
                break;
            }
            if ((b % i) == 0) res = i;
        }
    }
    return res;
}

class Rational {
public:
    Rational() : n(0), d(1) {}

    Rational(int numerator, int denominator)
      : n(numerator), d(denominator) {
        if (d == 0)
          throw std::invalid_argument("zero denom!");
        int divider = MaxCommonDivider(n, d);
        n /= divider;
        d /= divider;
        if (d < 0) {
            n *= -1;
            d *= -1;
        }
      }

    int Numerator() const {
        return n;
    }

    int Denominator() const {
        return d;
    }

    void Set(int _n, int _d) {
      n = _n;
      d = _d;
    }
    
    Rational operator+(Rational b) {
      // 2/3 + 3/4
      int dd = b.Denominator();
      // gain
      int g = 1, gg = 1;
      if (d != dd) {
        int div = MaxCommonDivider(d, dd);
        g = dd / div;
        gg = d / div;
      }
      int nom = n * g + b.Numerator() * gg;
      int denom = d * g;
      return {nom, denom};
    }

    Rational operator-(Rational b) {
      Rational r(-b.Numerator(), b.Denominator());
      return (*this + r);
    }

private:
    int n;
    int d;
};

bool operator< (const Rational& a, const Rational& b) {
  double d1 = a.Denominator();
  double d2 = b.Denominator();
  return (a.Numerator() / d1)
          < (b.Numerator() / d2);
}

bool operator==(const Rational& a, const Rational& b) {
  return (a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator());
}

Rational operator/(Rational a, Rational b) {
  if (b.Numerator() == 0)
    throw std::domain_error("zero divider!");
  return {a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator()};
}

Rational operator*(Rational a, Rational b) {
  return {a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator()};
}

std::ostream& operator<<(std::ostream& out, Rational r) {
  out << r.Numerator() << '/' << r.Denominator();
  return out;
}

std::istream& operator>>(std::istream& inp, Rational& r) {
  int n{0}, d{0};
  char div;
  inp >> n;
  inp >> div;
  if (div != '/')
    return inp;
  inp >> d;
  if (!inp)
    return inp;
  // check values
  Rational _r(n, d);
  r.Set(_r.Numerator(), _r.Denominator());
  return inp;
}
