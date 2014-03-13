#include <iostream>
#include <vector>
#include <algorithm>
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

int lis(int n, const vector<int> &heights, const vector<int> &weights) {
    int dp[n];

    rep (i, n) {
        dp[i] = weights[i];
        rep (j, i) {
            if (heights[j] < heights[i]) dp[i] = max(dp[i], weights[i] + dp[j]);
        }
    }

    return *max_element(dp, dp + n);
}

int main(void) {
    int cases, n;

    cin >> cases;

    REPI (case_number, 1, cases) {
        cout << "Case " << case_number << ". ";

        cin >> n;

        vector<int> heights(n), weights(n);

        rep (i, n) cin >> heights[i];
        rep (i, n) cin >> weights[i];

        int increasing = lis(n, heights, weights);
        reverse(heights.begin(), heights.end());
        reverse(weights.begin(), weights.end());
        int decreasing = lis(n, heights, weights);

        if (increasing >= decreasing) {
            cout << "Increasing (" << increasing << "). Decreasing (" << decreasing << ")." << endl;
        } else {
            cout << "Decreasing (" << decreasing << "). Increasing (" << increasing << ")." << endl;
        }
    }

    return 0;
}
