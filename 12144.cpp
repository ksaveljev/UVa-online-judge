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
const int maxN = 500;
int start, target;
vector<vector<pair<int,int>>> adj(maxN);
vector<vector<int>> parent(maxN);
vector<int> dist(maxN);
map<pair<int,int>, bool> restricted;

void dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, start});
    dist.assign(maxN, INF);
    parent.assign(maxN, {-1});
    dist[start] = 0;
    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();

        if (dist[v] < d) continue;

        for (auto [u, c] : adj[v]) {
            if (restricted[{v, u}]) continue;
            if (c + d == dist[u]) {
                parent[u].push_back(v);
            } else if (c + d < dist[u]) {
                dist[u] = c + d;
                parent[u] = {v};
                q.push({dist[u], u});
            }
        }
    }
}

void restrict(int u = target) {
    if (u == start) return;

    for (int v : parent[u]) {
        restricted[{v, u}] = true;
        restrict(v);
    }
}

int main(void) {
    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        cin >> start >> target;

        restricted.clear();
        for (int i = 0; i < maxN; i++) {
            adj[i].clear();
        }

        int u, v, c;
        while (m--) {
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
        }

        dijkstra();
        int min_dist = dist[target];
        if (min_dist == INF) {
            cout << -1 << endl;
            continue;
        }

        restrict();
        dijkstra();

        if (dist[target] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[target] << endl;
        }
    }

    return 0;
}
