#include <iostream>
#include <fstream>

using namespace std;

int FirstNumber(int x) {
    int num = x;
    while (num / 10 > 0) {
        num = num / 10;
    }
    return num;
}

int MaxNumber(int x) {
    int max = 0;
    int k = x;
    while (k > 0) {
        if (max < k % 10) max = k % 10;
        k = k / 10;
    }
    return max;
}

int main()
{
    int n;
    ifstream in("input.txt");
    in >> n;
    int* mas = new int[n];
    for (int i = 0; i < n; ++i) {
        in >> mas[i];
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (FirstNumber(mas[i]) > FirstNumber(mas[j])) swap(mas[i], mas[j]);
            else if ((FirstNumber(mas[i]) == FirstNumber(mas[j])) && (MaxNumber(mas[i]) > MaxNumber(mas[j]))) swap(mas[i], mas[j]);
            else if (((FirstNumber(mas[i]) == FirstNumber(mas[j])) && (MaxNumber(mas[i]) == MaxNumber(mas[j]))) && (mas[i] > mas[j])) swap(mas[i], mas[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
        delete[] mas[i];
    }
    delete[] mas;
    return 0;
}
