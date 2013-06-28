#include <iostream>
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

int s, d;
long long best;
vector<int> vals;

void solve() {
    if (vals.size() > 4) {
        int sum = 0;
        rep (i, 5) {
            sum += vals[vals.size() - 1 - i];
        }

        if (sum >= 0) {
            return;
        }
    }

    if (vals.size() == 12) {
        int sum = 0;
        rep (i, 12) {
            sum += vals[i];
        }
        if (sum > best) {
            best = sum;
        }
        return;
    }

    vals.push_back(s);
    solve();
    vals.pop_back();
    vals.push_back(d);
    solve();
    vals.pop_back();
}

int main(void) {
    while (cin >> s >> d) {
        d = -d;
        best = -1;
        solve();

        if (best == -1) {
            cout << "Deficit" << endl;
        } else {
            cout << best << endl;
        }
    }

    return 0;
}
