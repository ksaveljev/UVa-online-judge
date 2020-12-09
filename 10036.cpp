#include <iostream>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool dp[10001][101];

int main(void) {
    int cases;
    int n, k, num;

    cin >> cases;

    while (cases--) {
        cin >> n >> k;

        rep (i, 10001) {
            rep (j, 101) {
                dp[i][j] = false;
            }
        }

        dp[0][0] = true;

        vector<int> nums(n);

        rep (i, n) {
            cin >> nums[i];
        }

        REP (i, 1, n+1) {
            rep (j, 101) {
                if (dp[i-1][j]) {
                    dp[i][((j + nums[i-1]) % k + k) % k] = true;
                    dp[i][((j -nums[i-1]) % k + k) % k] = true;
                }
            }
        }

        if (dp[n][0]) {
            cout << "Divisible" << endl;
        } else {
            cout << "Not divisible" << endl;
        }
    }

    return 0;
}
