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
    vector<pair<int,int>> turtles;

    int w, s;
    while (cin >> w >> s) {
        turtles.push_back({s, w});
    }

    sort(turtles.begin(), turtles.end());

    int n = turtles.size();

    vector<int> dp(n+1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n; j > 0; j--) {
            if (dp[j-1] <= turtles[i].first - turtles[i].second && dp[j] > dp[j-1] + turtles[i].second) {
                dp[j] = dp[j-1] + turtles[i].second;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] < INF) {
            result = i;
        }
    }

    cout << result << endl;

    return 0;
}
