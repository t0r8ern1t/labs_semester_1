#include <iostream> 
#include <fstream>

using namespace std;

int main() {
	ifstream in("input.txt");
	int i, j;
	in >> i >> j;
	int** matrix = new int* [i];
	for (int count = 0; count < i; count++)
		matrix[count] = new int[j];
	for (int k = 0; k < i; ++k) {
		for (int l = 0; l < j; ++l) {
			in >> matrix[k][l];
		}
	}
	int min_column = 0;
	int min = matrix[0][0];
	for (int k = 0; k < i; ++k) {
		for (int l = 0; l < j; ++l) {
			if (min > matrix[k][l]) {
				min = matrix[k][l];
				min_column = l;
			}
			if (matrix[k][l] < 0) matrix[k][l] = 0;
		}
	}
	for (int k = 0; k < i; ++k) {
		for (int l = 0; l < j; ++l) {
			cout << matrix[k][l] << " ";
		}
		cout << endl;
	}
	delete[] matrix;
	cout << "min number's column: " << min_column + 1;
	return 0;
}