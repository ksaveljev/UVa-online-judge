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

int N;
int top[51];
int result;

bool square_sum(int a, int b) {
    int sum = a + b;
    int sq = sqrt(sum);
    return sq * sq == sum;
}

void solve(int n) {
    if (n - 1 > result) result = n - 1;

    rep (i, N) {
        if (top[i] == 0) {
            top[i] = n;
            return solve(n+1);
        } else if (square_sum(top[i], n)) {
            top[i] = n;
            return solve(n+1);
        }
    }
}

int main(void) {
    int T;
    int cache[51];

    rep (i, 51) cache[i] = -1;

    cin >> T;

    while (T--) {
        cin >> N;

        result = 0;
        rep (i, 51) top[i] = 0;

        if (cache[N] == -1) {
            solve(1);
            cache[N] = result;
        }

        cout << cache[N] << endl;
    }

    return 0;
}
