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

const int maxS = 300, INF = 1e9+7;
int n, s;
int dp[maxS+1], parent[maxS+1];

int main(void) {
    int t;

    cin >> t;

    for (int T = 1; T <= t; T++) {
        cout << "Case " << T << ": ";
        cin >> n >> s;

        for (int i = 0; i <= maxS; i++) {
            dp[i] = INF;
            parent[i] = -1;
        }
        dp[0] = 0;

        int tmp;
        while (n--) {
            cin >> tmp;
            for (int i = 1; i <= s; i++) {
                if (i >= tmp && dp[i-tmp]+1 <= dp[i]) {
                    dp[i] = dp[i-tmp]+1;
                    parent[i] = i - tmp;
                }
            }
        }

        if (dp[s] == INF) {
            cout << "impossible" << endl;
        } else {
            vector<int> v;
            int x = s;
            while (parent[x] != -1) {
                v.push_back(x - parent[x]);
                x = parent[x];
            }
            cout << "[" << v.size() << "]";
            for (int x : v) cout << " " << x;
            cout << endl;
        }
    }

    return 0;
}
