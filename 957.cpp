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

int popes[100000];

int main(void) {
    int y, p;
    int count, start, end, best;

    while (cin >> y >> p) {
        rep (i, p) {
            cin >> popes[i];
        }

        count = start = end = best = 0;

        rep (i, p) {
            count = 0;
            int j = i;

            while (j < p && popes[j] < popes[i] + y) {
                j++;
                count++;
            }

            if (count > best) {
                best = count;
                start = popes[i];
                end = popes[j-1];
            }
        }

        cout << best << " " << start << " " << end << endl;
    }

    return 0;
}
