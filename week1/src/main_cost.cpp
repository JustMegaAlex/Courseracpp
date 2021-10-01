
#include<iostream>
#include<cmath>

int main() {
	/*
	100 110 120 5 10 -- 100
	115 110 120 5 10 -- 109.25
	150 110 120 5 12.5 -- 131.25
	 */
	double n, a, b, x, y;
	std::cin >> n >> a >> b >> x >> y;
	if (n <= a)
		std::cout << n << "\n";
	else if (n <= b)
		std::cout << n * (1 - x/100);
	else
		std::cout << n * (1 - y/100);
	std::cout << "\n";
	return 0;
}
