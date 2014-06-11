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

#define LIMIT 2000
#define EPSILON 1e-9

int main(void) {
    long long a, b, c, d, product, sum;

    for (a = 1; 4 * a <= LIMIT; a++) {
        for (b = a; a + 3 * b <= LIMIT; b++) {
            for (c = b; a + b + 2 * c <= LIMIT; c++) {
                sum = a + b + c;
                product = a * b * c;

                if (product <= 1000000) continue;

                d = 1000000 * sum / (product - 1000000);

                if (d < c || sum + d > LIMIT) continue;

                if (fabs((sum + d) / 100.0 - product * d / 100000000.0) < EPSILON)
                    printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
            }
        }
    }

    return 0;
}
