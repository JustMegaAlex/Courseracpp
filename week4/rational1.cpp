#include <iostream>
#include <math.h>

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

private:
    int n;
    int d;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    std::cout << '4' << '\n';

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}