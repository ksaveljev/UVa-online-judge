#include <climits>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
#include <cassert>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<vector<pair<int,int>>> adj(51, vector<pair<int,int>>());

pair<int, vector<int>> find_shortest_path(int start, int end) {
    int dist[51];
    memset(dist, -1, sizeof dist);

    dist[start] = 0;

    queue<pair<int, vector<int>>> q;
    q.push({start, vector<int>()});
    while (!q.empty()) {
        auto [node, path] = q.front();
        q.pop();

        if (node == end) {
            return {dist[end], path};
        }

        for (auto x : adj[node]) {
            if (dist[x.first] < 0) {
                dist[x.first] = dist[node] + x.second;
                path.push_back(x.second);
                q.push({x.first, path});
                path.pop_back();
            }
        }
    }

    return {-1, vector<int>()};
}

const int INF = 1<<21;
int dp[51][100001];

void solve(int start, int end, int cost) {
    auto [min_cost, path] = find_shortest_path(start, end);

    if (min_cost == cost) {
        cout << "Yes " << path.size() << "\n";
        return;
    }

    if (min_cost > cost || path.size() < 2) {
        cout << "No\n";
        return;
    }

    path.pop_back();

    int target = cost - min_cost;
    if (target % 2 == 1) {
        cout << "No\n";
        return;
    }

    target /= 2;

    for (int i = 0; i <= path.size(); i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= path.size(); i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if ((j - path[i-1]) >= 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-path[i-1]] + 1);
            }
        }
    }

    if (dp[path.size()][target] == INF) {
        cout << "No\n";
    } else {
        cout << "Yes " << dp[path.size()][target] * 2 + path.size() + 1 << "\n";
    }
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < 51; i++) {
            adj[i].clear();
        }

        int a, b, c;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        int k;
        cin >> k;

        while (k--) {
            cin >> a >> b >> c;
            solve(a, b, c);
        }

        if (t) cout << endl;
    }

    return 0;
}
