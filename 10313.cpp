#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

long long dp[301][301];

int main(void) {
    int tmp, L1, L2;
    string input;

    // dp[i][j] stands for number of ways we can produce sum i using 0..j coins

    rep (i, 301) {
        dp[i][0] = 0;
        dp[0][i] = 1;
    }

    REP (i, 1, 301) {
        REP (j, 1, 301) {
            dp[i][j] = dp[i][j-1] + (i>=j?dp[i-j][j]:0);
        }
    }

    while (getline(cin, input)) {
        stringstream ss(input);

        vector<int> nums;
        while (ss >> tmp) {
            nums.push_back(tmp);
        }

        if (nums.size() == 1) {
            L1 = 0;
            L2 = min(300, nums[0]);
        } else if (nums.size() == 2) {
            L1 = 0;
            L2 = min(300, nums[1]);
        } else {
            L1 = min(300, nums[1]);
            L2 = min(300, nums[2]);
        }

        if (nums[0] == 0) {
            cout << 1 << endl;
        } else {
            cout << dp[nums[0]][L2] - (L1==0?dp[nums[0]][L1]:dp[nums[0]][L1-1]) << endl;
        }
    }

    return 0;
}
