#include <iostream>

using namespace std;

int main()
{
    int q1, p1, q2, p2, a;
    cin >> q1 >> p1 >> q2 >> p2 >> a;
    if (q1 > q2) {
        swap(q1, q2);
        swap(p1, p2);
    }
    int leftover = 0;
    if (a % q1 != 0) leftover = 1;
    int sum1 = (a / q1 + leftover)*p1; //сколько понадобится на меньшем
    int min = sum1;
    for (int i = 0; i <= sum1; i++)
    {
        int aq2 = a - i * q1; // перебираем всевозможные сочетания q1 и q2
        int leftover2 = 0;
        if (aq2 % q2 != 0) leftover2 = 1;
        int sum = p1 * i + (aq2 / q2 + leftover2) * p2;
        if (sum < min) min = sum;
    }
    cout << min << endl;
}
