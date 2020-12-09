#include <iostream>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int dp[101][20001];
vector<int> bills(101);
const int INF = 1<<30;

int main(void) {
    int cases;
    int price;
    int n;

    cin >> cases;

    while (cases--) {
        cin >> price;
        cin >> n;

        rep (i, 101) {
            rep (j, 20001) {
                dp[i][j] = INF;
            }
            dp[i][0] = 0;
        }


        rep (i, n) {
            cin >> bills[i];
        }

        REP (i, 1, n+1) {
            rep (j, 20001) {
                if (j < bills[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-bills[i-1]]);
                }
            }
        }

        REP (i, price, 20001) {
            if (dp[n][i] < INF) {
                cout << i << " " << dp[n][i] << endl;
                break;
            }
        }
    }

    return 0;
}
