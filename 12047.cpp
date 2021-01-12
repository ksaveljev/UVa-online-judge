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
    int T;
    int n, m, s, t, p;

    cin >> T;

    while (T--) {
        cin >> n >> m >> s >> t >> p;
        --s, --t;

        vector<vector<pair<int,int>>> adj(n), adj2(n);
        vector<int> dist(n, INF), dist2(n, INF);
        dist[s] = 0;
        dist2[t] = 0;
        int u, v, c;
        while (m--) {
            cin >> u >> v >> c;
            --u, --v;
            adj[u].push_back({v, c});
            adj2[v].push_back({u, c});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, s});
        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();
            if (dist[v] < d) continue;
            for (auto [u, c] : adj[v]) {
                if (d + c < dist[u]) {
                    dist[u] = d + c;
                    q.push({dist[u], u});
                }
            }
        }

        q.push({0, t});
        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();
            if (dist2[v] < d) continue;
            for (auto [u, c] : adj2[v]) {
                if (d + c < dist2[u]) {
                    dist2[u] = d + c;
                    q.push({dist2[u], u});
                }
            }
        }

        if (dist[t] > p) {
            cout << -1 << endl;
        } else {
            int result = 0;
            for (int i = 0; i < n; i++) {
                for (auto [j, c] : adj[i]) {
                    if (dist[i] + dist2[j] + c <= p) {
                        result = max(result, c);
                    }
                }
            }
            cout << result << endl;
        }
    }

    return 0;
}
