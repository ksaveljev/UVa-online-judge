#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int dp[71][71];

int main(void) {
    int K, N, T, P;

    cin >> K;

    while (K--) {
        cin >> N >> T >> P;

        rep (i, 71) rep (j, 71) dp[i][j] = 0;

        dp[0][0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= T; j++) {
                if (j < i * P) {
                    dp[i][j] = 0;
                } else {
                    for (int k = P; k <= j - (i-1) * P; k++) {
                        dp[i][j] += dp[i-1][j - k];
                    }
                }
            }
        }

        cout << dp[N][T] << endl;
    }

    return 0;
}
