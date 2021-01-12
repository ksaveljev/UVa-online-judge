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
    int c, v;

    while (cin >> c >> v) {
        vector<vector<pair<int,int>>> adj(c);
        vector<int> dist(c, INF), dist2(c, INF);
        dist[0] = 0;

        int a, b, x;
        while (v--) {
            cin >> a >> b >> x;
            --a, --b;
            adj[a].push_back({b, x});
            adj[b].push_back({a, x});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();

            for (auto [u, dd] : adj[v]) {
                if (dist[v] + dd < dist2[u]) {
                    dist2[u] = dist[v] + dd;
                    q.push({dist2[u], u});
                }
                if (dist2[v] + dd < dist[u]) {
                    dist[u] = dist2[v] + dd;
                    q.push({dist[u], u});
                }
            }
        }

        if (dist[c - 1] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[c-1] << endl;
        }
    }

    return 0;
}
