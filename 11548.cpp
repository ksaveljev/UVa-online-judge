#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int number_of_matches(const string &a, const string &b) {
    int result = 0;

    for (int offset = b.size() - 1; offset >= 0; offset--) {
        int counter = 0;

        for (int i = 0; i < b.size(); i++) {
            if (i < offset) continue;
            if (i >= a.size() + offset) break;

            if (a[i - offset] == b[i]) counter++;
        }

        result = max(result, counter);
    }

    for (int offset = 1; offset < a.size(); offset++) {
        int counter = 0;

        for (int i = 0; i < a.size(); i++) {
            if (i < offset) continue;
            if (i >= b.size() + offset) break;

            if (a[i] == b[i-offset]) counter++;
        }

        result = max(result, counter);
    }

    return result;
}

int main(void) {
    int number_of_cases, n;
    string word;

    cin >> number_of_cases;

    while (number_of_cases--) {
        cin >> n;
        
        vector<string> words;

        rep (i, n) {
            cin >> word;
            words.push_back(word);
        }

        int result = 0;

        rep (i, n) {
            REP (j, i+1, n) {
                result = max(result, number_of_matches(words[i], words[j]));
            }
        }

        cout << result << endl;
    }

    return 0;
}
