#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

unsigned long long dp[62][61];

int main(void) {
    int n, back, c = 0;

    rep (i, 62) rep (j, 61) dp[i][j] = 1;
    rep (j, 61) dp[1][j] = 1;
    rep (j, 61) dp[0][j] = 1;

    REP (i, 2, 62) {
        REP (j, 1, 61) {
            dp[i][j] = 1;
            REP (k, 1, j+1) {
                dp[i][j] += (i >= k ? dp[i-k][j] : 1);
            }
        }
    }

    while (cin >> n >> back) {
        if (n > 60) break;
        c++;
        cout << "Case " << c << ": " << dp[max(n, 0)][max(back, 0)] << endl;
    }

    return 0;
}
