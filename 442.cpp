#include <iostream>
#include <map>
#include <stack>
#include <string>
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
    int n, a, b;
    char c;
    string input;
    map< char, pair<int,int> > m;
    pair<int,int> first, second;

    cin >> n;

    while (n--) {
        cin >> c >> a >> b;
        m[c] = make_pair(a,b);
    }

    cin.ignore(100, '\n');

    while (getline(cin, input)) {
        bool ok = true;
        long long result = 0;
        stack< pair<int,int> > s;

        rep (i, input.size()) {
            if (input[i] == '(') {
                continue;
            } else if (input[i] == ')') {
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();

                if (first.second != second.first) {
                    ok = false;
                    break;
                } else {
                    result += first.first * first.second * second.second;
                    s.push(make_pair(first.first, second.second));
                }
            } else {
                s.push(m[input[i]]);
            }
        }

        if (ok && s.size() == 2) {
            second = s.top();
            s.pop();
            first = s.top();
            s.pop();

            if (first.second != second.first) {
                ok = false;
            } else {
                result += first.first * first.second * second.second;
            }
        }

        if (ok) {
            cout << result << endl;
        } else {
            cout << "error" << endl;
        }
    }

    return 0;
}
