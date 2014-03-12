#include <iostream>
#include <string>
#include <algorithm>
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

struct word {
    string str;
    int pos;
    bool operator<(const word& other) const {
        if (str == other.str) return pos < other.pos;
        return str < other.str;
    }
};

int main(void) {
    int cases, n;
    string input, w;
    word tmp;

    cin >> cases;

    while (cases--) {
        cin >> n;
        cin.ignore(100, '\n');

        vector<word> words;

        w = "";
        while (getline(cin, input)) {
            w += input;
            if (sz(w) >= n) break;
        }

        if (n == 1) {
            cout << n << endl;
            cout << w << endl;
            if (cases) cout << endl;
            continue;
        }

        rep (i, n) {
            tmp.str = w;
            tmp.pos = i;
            words.push_back(tmp);
            rotate(w.begin(), w.begin()+1, w.end());
        }

        sort(words.begin(), words.end());

        rep (i, n) {
            if (words[i].pos == 1) {
                cout << i << endl;
                break;
            }
        }

        rep (i, n) {
            if (i > 0 && i % 50 == 0 && i != n - 1) cout << endl;
            cout << words[i].str[n-1];
        }
        cout << endl;

        if (cases) cout << endl;
    }

    return 0;
}
