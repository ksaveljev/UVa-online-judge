#include <iostream>
#include <cmath>
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
    int cases;
    long long result, input;

    cin >> cases;

    while (cases--) {
        cin >> input;

        if (input < 1) {
            cout << 0 << endl;
            continue;
        }

        result = 0;
        int sq = sqrt(input);

        REPI (i, 1, sq) {
            result += input / i;
        }

        result = 2 * result - sq * sq;

        cout << result << endl;
    }

    return 0;
}
