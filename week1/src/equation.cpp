
#include<iostream>
#include<cmath>

int main() {
	double a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;
	if (a == 0) {
        if (b == 0)
            return 0;
		std::cout << -c / b;
		return 0;
	}
	double D = b*b - 4 * a * c;
	if (D < 0)
		return 0;
	if (D == 0) {
		std::cout << -b / 2 / a;
		return 0;
	}
	std::cout << (-b + std::sqrt(D)) / 2/ a << " " << (-b - std::sqrt(D)) / 2/ a ;
	return 0;
}
