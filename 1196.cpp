#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

const int INF = 1e9+7;

int main(void) {
    int n;

    while (cin >> n) {
        if (!n) break;

        vector<pair<int,int>> v(n);

        for (auto& x: v) {
            cin >> x.first >> x.second;
        }

        sort(v.begin(), v.end());

        vector<int> dp(n+1, INF);
        dp[0] = -INF;

        for (int i = 0; i < n; i++) {
            int j = upper_bound(dp.begin(), dp.end(), v[i].second) - dp.begin();
            dp[j] = v[i].second;
        }

        int result = 0;

        for (int i = 1; i <= n; i++) {
            if (dp[i] < INF) result = i;
        }

        cout << result << endl;
    }

    cout << "*" << endl;

    return 0;
}
