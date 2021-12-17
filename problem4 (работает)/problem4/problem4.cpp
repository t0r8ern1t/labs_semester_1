#include <iostream>

bool IfSumsEqual(int x, int y) {
	int sum1 = 0, sum2 = 0;
	while (x != 0) {
		sum1 += x % 10;
		x = x / 10;
		}
	while (y != 0) {
		sum2 += y % 10;
		y = y / 10;
	}
		if (sum1 == sum2) return 1;
		else return 0;
}

int main()
{
	int a, b;
	int sum = 0;
	for (int i = 0; i < 1000000; ++i) {
		a = i / 1000;
		b = i % 1000;
		if (IfSumsEqual(a, b) == 1) {
			//std::cout << a << b << std::endl;
			++sum;
		}
	}
	std::cout << sum;
	return 0;
}