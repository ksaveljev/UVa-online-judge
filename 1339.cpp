#include <iostream>
#include <string>
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

int main(void) {
    string a, b;

    while (getline(cin, a)) {
        getline(cin, b);

        vector<int> ac(26), bc(26);

        ac.assign(26, 0);
        bc.assign(26, 0);

        rep (i, a.size()) {
            ac[a[i] - 'A']++;
            bc[b[i] - 'A']++;
        }

        sort(ac.begin(), ac.end());
        sort(bc.begin(), bc.end());

        bool ok = true;

        rep (i, 26) {
            if (ac[i] != bc[i]) {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
