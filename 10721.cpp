#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef unsigned long long ull;

ull dp[51][51][51];

int main(void) {
    int n, k, m;

    rep (a, 51) rep (b, 51) rep (c, 51) dp[a][b][c] = 0;

    rep (a, 51) dp[0][0][a] = 1;

    REP (a, 1, 51) {
        REP (b, 1, 51) {
            REP (c, 1, 51) {
                for (int d = 1; d <= min(a, c); d++) {
                    dp[a][b][c] += dp[a-d][b-1][c];
                }
            }
        }
    }

    while (cin >> n >> k >> m) {
        cout << dp[n][k][m] << endl;
    }

    return 0;
}
