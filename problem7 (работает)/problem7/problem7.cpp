//в условии дана последовательность _натуральных_ чисел
#include <iostream>
#include <fstream>
#include <vector>

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

int main()
{
    ifstream in("input.txt");
    vector <int> numbers;
    while (!in.eof()) {
        int x;
        in >> x;
        numbers.push_back(x);
        cout << x << " ";
    }
    cout << endl;
    int k = numbers.size();

    for (int i = 0; i < k; ++i) {
        //cout << numbers[i] << " " << IfDivis6(numbers[i]) << " " << IfStartsWith1(numbers[i]) << endl;
        if (IfDivis6(numbers[i]) == 1) {
            numbers.erase(numbers.begin() + i);
            --i;
            --k;
        }
        else if (IfStartsWith1(numbers[i]) == 1) {
            numbers.insert(numbers.begin() + i, numbers[i]);
            ++i;
            ++k;
        }
    }
    for (int j = 0; j < k; ++j) {
        cout << numbers[j] << " ";
    }
    return 0;
}