#include <iostream>
#include <fstream>
#include <string>
#include "functions.hpp"

using namespace std;

using namespace ssh;

int main()
{
    setlocale(LC_ALL, "Rus");
    string word;
    ifstream in("input.txt");
    in >> word;
    cout << word << endl << endl;
    int max = 0;
    char maxletter = word[1];
   /* for (int j = 0; j < word.length(); ++j) {
        int letter = (unsigned char)word[j];
        cout << word[j] << " " << letter << " " << endl;
    }*/ // just in case мне нужно будет еще раз проверить кодировку
    for (int i = 0; i < word.length(); ++i) {
        if (Repeats(word, word[i]) > max) {
            max = Repeats(word, word[i]);
            maxletter = word[i];
        }
    }
    string times;
    if ((max % 10 == 2) || (max % 10 == 3) || (max % 10 == 4))
        times = " раза";
    else times = " раз";
    cout << AllToLower(word) << endl << endl << AllToUpper(word) << endl << endl;
    cout << "Наиболее повторяющаяся буква: " << maxletter << ". Она встречается " << max << times << endl;
}