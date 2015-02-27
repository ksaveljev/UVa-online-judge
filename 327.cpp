#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
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

void do_replace(string& str, const string& search_for, const string& replace_to) {
    size_t pos = 0;

    while ((pos = str.find(search_for, pos)) != string::npos) {
        str.replace(pos, search_for.length(), replace_to);
        pos += replace_to.length();
    }
}

int main(void) {
    string input;

    while (getline(cin, input)) {
        map<char,int> m;
        vector<char> present;
        vector< pair<char, int> > todo;

        string replaced = input;
        do_replace(replaced, " ", "");
        do_replace(replaced, "++", "*");
        do_replace(replaced, "--", "^");

        REPI (i, 1, 26) {
            m['a' + i - 1] = i;
        }

        rep (i, replaced.size()) {
            if (replaced[i] == '*') {
                if (i == 0) {
                    m[replaced[i+1]] += 1;
                } else {
                    if (replaced[i-1] >= 'a' && replaced[i-1] <='z') {
                        todo.push_back( make_pair(replaced[i-1], 1) );
                    } else {
                        m[replaced[i+1]] += 1;
                    }
                }
            } else if (replaced[i] == '^') {
                if (i == 0) {
                    m[replaced[i+1]] -= 1;
                } else {
                    if (replaced[i-1] >= 'a' && replaced[i-1] <= 'z') {
                        todo.push_back( make_pair(replaced[i-1], -1) );
                    } else {
                        m[replaced[i+1]] -= 1;
                    }
                }
            }
        }

        do_replace(replaced, "*", "");
        do_replace(replaced, "^", "");

        int result = 0;

        rep (i, replaced.size()) {
            if (replaced[i] >= 'a' && replaced[i] <= 'z') {
                present.push_back(replaced[i]);

                if (i == 0) {
                    result += m[replaced[i]];
                } else {
                    if (replaced[i-1] == '+') {
                        result += m[replaced[i]];
                    } else if (replaced[i-1] == '-') {
                        result -= m[replaced[i]];
                    }
                }
            }
        }

        rep (i, todo.size()) {
            m[todo[i].first] += todo[i].second;
        }

        cout << "Expression: " << input << endl;
        cout << "    value = " << result << endl;

        sort (present.begin(), present.end());

        rep (i, present.size()) {
            cout << "    " << present[i] << " = " << m[present[i]] << endl;
        }
    }

    return 0;
}
