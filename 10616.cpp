#include <iostream>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

int main(void) {
    int n, q, m;
    ll tmp, d;
    int test_case = 0;
    ll dp[202][12][22];

    while (cin >> n >> q) {
        if (n == 0 && q == 0) {
            break;
        }
        test_case++;
        cout << "SET " << test_case << ":" << endl;

        vector<ll> nums(n+1);
        REP(i, 1, n+1) {
            cin >> nums[i];
        }

        rep(query, q) {
            cout << "QUERY " << query+1 << ": ";
            cin >> d >> m;

            rep (i, 202) rep (j, 12) rep (k, 22) dp[i][j][k] = 0;

            dp[0][0][0] = 1;

            for (int idx = 1; idx <= n; idx++) {
                for (int taken = 0; taken <= m; taken++) {
                    for (int rem = 0; rem < d; rem++) {
                        int r = (rem - nums[idx]) % d;
                        if (r < 0) r += d;

                        dp[idx][taken][rem] += dp[idx-1][taken][rem];
                        if (taken) {
                            dp[idx][taken][rem] += dp[idx-1][taken-1][r];
                        }
                    }
                }
            }

            cout << dp[n][m][0] << endl;
        }
    }

    return 0;
}
