#include <math.h>
#include <iostream>
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
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}