#include <iostream>
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
    int N, pos, diff, car;
    int *pole = new int[1005];

    while (cin >> N) {
        if (N == 0) break;

        bool ok = true;
        rep (i, 1005) pole[i] = -1;

        REPI (i, 1, N) {
            cin >> car >> diff;
            pos = i + diff;

            if (pos < 1 || pos > N) {
                ok = false;
                continue;
            }

            if (pole[pos] == -1) {
                pole[pos] = car;
            } else {
                ok = false;
            }
        }

        if (ok) {
            REPI (i, 1, N) {
                if (i > 1) cout << " ";
                cout << pole[i];
            }
            cout << endl;
        } else cout << -1 << endl;
    }

    delete pole;

    return 0;
}
