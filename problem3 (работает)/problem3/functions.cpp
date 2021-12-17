#include "functions.hpp"
#include <string>

using namespace std;

namespace ssh {

    string AllToUpper(string word) {
        int letter;
        for (int i = 0; i < word.length(); ++i) {
            letter = (unsigned char)word[i];
            if (((letter >= 224) && (letter <= 255)) || ((letter >= 97) && (letter <= 122)))
                word[i] -= 32;
            if (letter == 184)
                word[i] = 168;
        }
        return word;
    }

    string AllToLower(string word) {
        int letter;
        for (int i = 0; i < word.length(); ++i) {
            letter = (unsigned char)word[i];
            if (((letter >= 192) && (letter <= 223)) || ((letter >= 65) && (letter <= 90)))
                word[i] += 32;
            if (letter == 168)
                word[i] = 184;
        }
        return word;
    }

    int Repeats(string word, char letter) {
        int sum = 0;
        for (int i = 0; i < word.length(); ++i) {
            if ((letter == word[i]) || (letter == word[i] - 32) || (letter == word[i] + 32))
                ++sum;
        }
        return sum;
    }
}