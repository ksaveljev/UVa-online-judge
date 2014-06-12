#include <iostream>
#include <string>
#include <algorithm>
#include <map>
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

int main(void) {
    int n;
    string input, tmp;
    bool first = true;

    while (cin >> n) {
        cin.ignore(100, '\n');

        if (first) first = false; else cout << endl;

        map<string, int> words;

        while (getline (cin, input)) {
            if (input == "EndOfText") break;

            transform (input.begin(), input.end(), input.begin(), ::tolower);

            tmp = "";

            rep (i, input.size()) {
                if (input[i] >= 'a' && input[i] <= 'z') {
                    tmp += input[i];
                } else {
                    if (tmp != "") {
                        if (words.find(tmp) == words.end()) words[tmp] = 1;
                        else words[tmp] += 1;
                        tmp = "";
                    }
                }
            }
            if (tmp != "") {
                if (words.find(tmp) == words.end()) words[tmp] = 1;
                else words[tmp] += 1;
            }
        }

        vector<string> result;

        for (map<string,int>::iterator it = words.begin(); it != words.end(); it++) {
            if (it->second == n) result.push_back(it->first);
        }

        sort (result.begin(), result.end());

        if (result.empty()) {
            cout << "There is no such word." << endl;
        } else {
            rep (i, result.size()) cout << result[i] << endl;
        }
    }

    return 0;
}
