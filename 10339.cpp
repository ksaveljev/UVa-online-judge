#include <iostream>
#include <cstdio>
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
    unsigned int k, m;

    while (cin >> k >> m) {
        unsigned int diff = k > m ? k - m : m - k;

        unsigned int result = (43200 * (86400 - k) / diff) % 43200 + 30;

        printf("%d %d %02d:%02d\n", k, m, result / 3600 % 12 == 0 ? 12 : result / 3600 % 12, result / 60 % 60);
    }

    return 0;
}
