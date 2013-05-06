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
    int t;
    int x, y, z;

    cin >> t;

    while (t--) {
        cin >> x >> y >> z;

        int per_family = (x * 60 + y * 60) / 3; // in minutes

        if (x * 60 <= per_family)
            cout << 0 << endl;
        else
            cout << (x * 60 - per_family) * 1.0 * z / per_family << endl;
    }

    return 0;
}
