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
    int cases, input, i;

    cin >> cases;

    while (cases--) {
        cin >> input;

        if (input < 0) input = -input;

        i = 1;
        while (i++) {
            if (i * (i + 1) / 2 >= input && (i * (i + 1) / 2 - input) % 2 == 0) break;
        }

        cout << (input == 0 ? 3 : i) << endl;

        if (cases) cout << endl;
    }

    return 0;
}
