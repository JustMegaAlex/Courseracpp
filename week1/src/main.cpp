
#include<iostream>

int main() {
	int a = 3;
	int* b = &a;
	std::cout << *b;
	*b = 2;
	std::cout << a << '\n';
	return 0;
}
