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

string search(const vector<string> &fragments, bool *taken, int counter, string result, int len) {
    if (counter == sz(fragments)) {
        return result;
    }

    rep (i, sz(fragments)) {
        if (taken[i]) continue;

        taken[i] = true;

        rep (j, sz(fragments)) {
            if (taken[j]) continue;
            if (sz(fragments[i]) + sz(fragments[j]) != len) continue;

            taken[j] = true;

            if (result == "") {
                string tmp = search(fragments, taken, counter + 2, fragments[i] + fragments[j], len);
                if (tmp != "") return tmp;
                tmp = search(fragments, taken, counter + 2, fragments[j] + fragments[i], len);
                if (tmp != "") return tmp;
            } else {
                if (fragments[i] + fragments[j] == result) {
                    string tmp = search(fragments, taken, counter + 2, fragments[i] + fragments[j], len);
                    if (tmp != "") return tmp;
                }
                if (fragments[j] + fragments[i] == result) {
                    string tmp = search(fragments, taken, counter + 2, fragments[j] + fragments[i], len);
                    if (tmp != "") return tmp;
                }
            }

            taken[j] = false;
        }

        taken[i] = false;
    }

    return "";
}

int main(void) {
    bool first = true;
    int cases, len;
    string input;

    cin >> cases;
    cin.ignore(100, '\n');
    getline(cin, input); // empty line

    while (cases--) {
        if (first) first = false; else cout << endl;
        len = 0;
        vector<string> fragments;

        while (getline(cin, input)) {
            if (input == "") break;
            len += input.size();
            fragments.push_back(input);
        }

        len = len * 2 / sz(fragments);

        bool *taken = new bool[sz(fragments)];
        rep (i, sz(fragments)) taken[i] = false;

        cout << search(fragments, taken, 0, "", len) << endl;
    }

    return 0;
}
