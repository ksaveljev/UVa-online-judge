#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int n;
    const long long INF = 1L<<60;

    while (cin >> n) {
        vector<long long> nums(n);
        vector<long long> dp(n+1);
        vector<int> len(n), len2(n);

        dp[0] = -INF;

        REP (i, 1, n+1) {
            dp[i] = INF;
        }

        rep (i, n) {
            len[i] = 1;
            len2[i] = 1;
            cin >> nums[i];
        }

        rep (i, n) {
            int j = int (upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin());
            if (dp[j-1] < nums[i]) {
                len[i] = j;
                if (nums[i] < dp[j]) {
                    dp[j] = nums[i];
                }
            }
        }

        dp[0] = -INF;

        REP (i, 1, n+1) {
            dp[i] = INF;
        }

        reverse(nums.begin(), nums.end());

        rep (i, n) {
            int j = int (upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin());
            if (dp[j-1] < nums[i]) {
                len2[i] = j;
                if (nums[i] < dp[j]) {
                    dp[j] = nums[i];
                }
            }
        }

        int best = 1;
        rep (i, n) {
            int result = min(len[i], len2[n-i-1]) * 2 - 1;
            best = max(best, result);
        }
        cout << best << endl;
    }

    return 0;
}
