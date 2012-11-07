#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

vector<string> dictionaryWords;

void solve(string &passwordRule, string output = "", int index = 0) {
    if (index == passwordRule.size()) {
        cout << output << endl;
        return;
    }

    if (passwordRule[index] == '#') {
        rep (i, dictionaryWords.size()) {
            solve(passwordRule, output + dictionaryWords[i], index+1);
        }
    } else if (passwordRule[index] == '0') {
        rep (i, 10) {
            solve(passwordRule, output + char('0' + i), index+1);
        }
    }
}

int main(void) {
    int numberOfWordsInTheDictionary, numberOfRules;
    string dictionaryWord, passwordRule;

    while (cin >> numberOfWordsInTheDictionary) {
        cin.ignore(100, '\n');
        rep (i, numberOfWordsInTheDictionary) {
            getline(cin, dictionaryWord);
            dictionaryWords.push_back(dictionaryWord);
        }

        cin >> numberOfRules;
        cin.ignore(100, '\n');

        cout << "--" << endl;


        rep (i, numberOfRules) {
            getline(cin, passwordRule);
            solve(passwordRule);
        }

        dictionaryWords.clear();
    }

    return 0;
}
