
#include<iostream>
#include<cmath>
#include"/home/alexgovorov/src/cctz/include/cctz/civil_time.h"
#include"/home/alexgovorov/src/cctz/include/cctz/time_zone.h"

int main() {
	cctz::time_zone tz;
	const std::string tzname = "UTC";
	cctz::civil_day d;
	std::cout << d;
	// bool res = cctz::load_time_zone(tzname, &tz);
	// std::cout << tz.name();
	double a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;
	if (a == 0) {
		std::cout << -c / b;
		return 0;
	}
	double D = b*b - 4 * a * c;
	if (D < 0) {
		std::cout << "";
		return 0;
	}
	if (D == 0) {
		std::cout << -b / 2 / a;
		return 0;
	}
	std::cout << (-b + std::sqrt(D)) / 2/ a << " " << (-b - std::sqrt(D)) / 2/ a ;
	return 0;
}
