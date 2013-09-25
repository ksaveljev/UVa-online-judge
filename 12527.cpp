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

bool acceptable(int n) {
    bool taken[10] = { false };
    bool result = true;

    while (n > 0) {
        int i = n % 10;
        n /= 10;

        if (taken[i] == true) {
            result = false;
            break;
        } else {
            taken[i] = true;
        }
    }

    return result;
}

int solve(int n, int m) {
    int counter = 0;

    REPI(i, n, m) {
        if (acceptable(i)) counter++;
    }

    return counter;
}

int main(void) {
    int n, m;

    while (cin >> n >> m) {
        cout << solve(n, m) << endl;
    }

    return 0;
}
