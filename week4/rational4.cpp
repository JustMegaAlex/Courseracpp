#include <math.h>
#include <iostream>
#include <stdexcept>
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

    Rational operator/(Rational b) {
      if (b.Numerator() == 0)
        throw std::domain_error("zero divider!");
      return {n * b.Denominator(), d * b.Numerator()};
    }

    Rational operator*(Rational b) {
      return {n * b.Numerator(), d * b.Denominator()};
    }

    bool operator==(Rational b) {
      return (n == b.Numerator()) && (d == b.Denominator());
    }

private:
    int n;
    int d;
};

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
