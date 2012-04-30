#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

unsigned int convert_word_to_num(string &s) {
    unsigned int result = 0;
    unsigned int tmp = 1;

    for (int i = s.size() - 1; i >= 0; i--) {
        result += int(s[i] - 'a' + 1) * tmp;
        tmp *= 32;
    }

    return result;
}

int main(void) {
    string input;

    while (getline(cin, input)) {
        vector<string> words;
        istringstream iss(input);

        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter< vector<string> >(words));

        vector<unsigned int> processed_words;
        processed_words.resize(words.size());

        transform (words.begin(), words.end(), processed_words.begin(), convert_word_to_num);

        unsigned int n = words.size();
        sort (processed_words.begin(), processed_words.end());

        unsigned int C = processed_words[0];

        while (true) {
            bool ok = true;

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ((C / processed_words[i]) % n == (C / processed_words[j]) % n) {
                        ok = false;

                        C = min(((C / processed_words[i]) + 1) * processed_words[i], ((C / processed_words[j]) + 1) * processed_words[j]);

                        j = n;
                        i = n;
                    }
                }
            }

            if (ok)
                break;
        }

        cout << input << endl;
        cout << C << endl;
        cout << endl;
    }

    return 0;
}
