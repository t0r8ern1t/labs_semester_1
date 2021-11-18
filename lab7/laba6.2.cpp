#include <iostream>
#include <fstream>
#include "inc/Functions.hpp"

using namespace std;
using namespace ssh;

int main() {

	int A[N][N];
	ifstream in("input.txt");
	int n;
	int max = 0;
	in >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			in >> A[i][j];
			if ((ifSimple(A[i][j]) == 1) && (A[i][j] > max)) max = A[i][j];
		}
	}
	cout << max << endl;
	bool flag = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (ComparingStrings(A, i, j, n) == 1) {
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1) {
		for (int i = 0; i < n; ++i) {
			int k = MinInColumn(A, i);
			A[i][k] = max;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
