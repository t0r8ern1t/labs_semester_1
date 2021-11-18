#include "Functions.hpp"

namespace ssh {

	bool ifSimple(int x) {
		if (x < 2) return 0;
		for (int i = 1; i * i < x; ++i) {
			if (x % i == 0)
				return 0;
			else return 1;
		}
	}

	int MinInColumn(int mas[N][N], int number) {
		int min = mas[number][1];
		int minnum = 0;
		for (int i = 1; i < N; ++i) {
			if (mas[number][i] < min) {
				min = mas[number][i];
				minnum = i;
			}
		}
		return minnum;
	}

	bool ComparingStrings(int mas[N][N], int n1, int n2, int n) {
		for (int i = 0; i < n; ++i) {
			if (mas[i][n1] != mas[i][n2]) return 0;
		}
		return 1;
	}
}