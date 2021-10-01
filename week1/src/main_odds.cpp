
#include<iostream>
#include<cmath>

int main() {
	int a, b;
	std::cin >> a >> b;
	a += std::abs(a % 2);
	for(int i = a; i <= b; i += 2) {
		std::cout << i << ' ';
	}
	std::cout << "\n";
	return 0;
}
