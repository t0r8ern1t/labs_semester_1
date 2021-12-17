//в условии дана последовательность _натуральных_ чисел
#include <iostream>
#include <fstream>
#define N 20000

using namespace std;

bool IfDivis6(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x = x / 10;
    }
    if (sum % 6 == 0) return 1;
    else return 0;
}

bool IfStartsWith1(int x) {
    while (x > 9) {
        x = x / 10;
    }
    if (x == 1) return 1;
    else return 0;
}

void EraseNumbers(int (&numbers)[N], int& number, int& k) {
    for (int i = number; i < k-1; ++i) {
        numbers[i] = numbers[i + 1];
    }
    --k;
    --number;
}

void DoubleNumbers(int (&numbers)[N], int& number, int& k) {
    for (int i = k+1; i > number; --i) {
        numbers[i] = numbers[i - 1];
    }
    ++k;
    ++number;
}

int main()
{
    ifstream in("input.txt");
    int numbers[N] = {2};
    int k = 0;
    while (!in.eof()) {
        in >> numbers[k];
        cout << numbers[k] << " ";
        ++k;
    }
    cout << endl << endl;
    k++;
    for (int i = 0; i < k; ++i) {
        //cout << numbers[i] << " " << IfDivis6(numbers[i]) << " " << IfStartsWith1(numbers[i]) << endl;

        if (IfDivis6(numbers[i]) == 1) {
            EraseNumbers(numbers, i, k);
        }

        else if (IfStartsWith1(numbers[i]) == 1) {
            DoubleNumbers(numbers, i, k);
        }
    }
    for (int j = 0; j < k; ++j) {
        cout << numbers[j] << " ";
    }
    return 0;
}