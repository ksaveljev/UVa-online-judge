#include <iostream>
#include <cmath>
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
    unsigned long long n;
    int case_number = 0;

    while (cin >> n) {
        if (n == 0) break;

        case_number++;

        printf("Case %d: %.0lf\n", case_number, ceil(1.5 + sqrt(9 + 8 * n)/2));
    }

    return 0;
}
