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
    int n, m, c, k;

    while (cin >> n >> m >> c >> k) {
        if ((n|m|c|k) == 0) break;

        vector<vector<pair<int,int>>> adj(n);
        int u, v, p;
        while (m--) {
            cin >> u >> v >> p;
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<int> dist(n, INF);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, k});
        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();

            if (dist[v] < d) continue;

            for (auto [u, dd] : adj[v]) {
                if (v < c) {
                    if (u == v+1 && d + dd < dist[u]) {
                        dist[u] = d + dd;
                        q.push({dist[u], u});
                    }
                } else {
                    if (d + dd < dist[u]) {
                        dist[u] = d + dd;
                        q.push({dist[u], u});
                    }
                }
            }
        }

        cout << dist[c - 1] << endl;
    }

    return 0;
}
