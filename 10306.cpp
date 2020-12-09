#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int dp[301][301];
const int INF = 1<<30;

int main(void) {
    int n, m, s;
    int va, vb;

    cin >> n;

    while (n--) {
        rep (i, 301) rep (j, 301) dp[i][j] = INF;
        dp[0][0] = 0;

        cin >> m >> s;

        while (m--) {
            cin >> va >> vb;

            rep (i, 301) {
                rep (j, 301) {
                    dp[i][j] = min(dp[i][j], i >= va && j >= vb ? 1 + dp[i-va][j-vb] : INF);
                }
            }
        }

        int best = INF;

        rep (i, 301) {
            rep (j, 301) {
                if (i * i + j * j == s * s && dp[i][j] < best) {
                    best = dp[i][j];
                }
            }
        }

        if (best == INF) {
            cout << "not possible" << endl;
        } else {
            cout << best << endl;
        }
    }

    return 0;
}
