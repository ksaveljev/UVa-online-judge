#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int dp[1001];
int dp2[1001];
const int INF = 1<<25;

int main(void) {
    int coins[6] = { 0, 0, 0, 0, 0, 0 };
    int values[6] = { 5, 10, 20, 50, 100, 200 };
    char c;
    int a, b;

    while (true) {
        bool ok = false;
        rep (i, 6) {
            cin >> coins[i];
            if (coins[i] > 0) ok = true;
        }

        if (!ok) break;

        cin >> a >> c >> b;
        int sum = a * 100 + b;

        rep (i, 1001) dp[i] = INF;
        dp[0] = 0;

        rep(i, 6) {
            rep (j, min(coins[i], 1 + 1000 / values[i])) {
                for (int k = 1000; k >= 0; k--) {
                    if (k+values[i] < 1001) {
                        dp[k+values[i]] = min(dp[k+values[i]], 1 + dp[k]);
                    }
                }
            }
        }

        rep (i, 1001) dp2[i] = INF;
        dp2[0] = 0;

        rep(i, 6) {
            rep (j, 1 + 1000 / values[i]) {
                for (int k = 1000; k >= 0; k--) {
                    if (k+values[i] < 1001) {
                        dp2[k+values[i]] = min(dp2[k+values[i]], 1 + dp2[k]);
                    }
                }
            }
        }

        int result = dp[sum];
        for (int i = sum + 5; i < 1001; i+=5) {
            if (dp[i] + dp2[i-sum] < result) {
                result = dp[i] + dp2[i-sum];
            }
        }

        printf("%3d\n", result);
    }

    return 0;
}
