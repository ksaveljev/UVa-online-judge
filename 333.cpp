#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <locale>
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

static inline string& ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int,int>(isspace))));
    return s;
}

static inline string& rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

static inline string& trim(string &s) {
    return ltrim(rtrim(s));
}

int main(void) {
    string input;

    while (getline(cin, input)) {
        trim(input);

        bool ok = input.size() > 0;
        int s1 = 0, s2 = 0, count = 0;

        rep (i, input.size()) {
            if (input[i] >= '0' && input[i] <= '9') {
                s1 += input[i] - '0';
                s2 += s1;
                count++;
            } else if (input[i] == '-') {
            } else if (input[i] == 'X' && count == 9) {
                s1 += 10;
                s2 += s1;
                count++;
            } else {
                ok = false;
                break;
            }
        }

        if (ok) {
            ok = ((count == 10) && (s2 % 11 == 0));
        }

        cout << input << " is " << (ok ? "correct." : "incorrect.") << endl;
    }

    return 0;
}
