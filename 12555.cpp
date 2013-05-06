#include <iostream>
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
    int t;
    string s;

    cin >> t;

    REPI(case_number, 1, t) {
        int a, b = 0;

        cin >> a;
        cin >> s;

        if (sz(s) > 3)
            b = (int)(s[3] - '0');

        cout << "Case " << case_number << ": " << a * 0.5 + b * 0.05 << endl;
    }


    return 0;
}
