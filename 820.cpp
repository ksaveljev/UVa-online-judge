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

const int maxN = 100, INF = 1e9+7;
int n;
vector<pair<int,int>> edges;
vector<int> adj[maxN];
vector<int> capacity;

int bfs(int source, int target, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int,int>> q;
    q.push({source, INF});
    while (!q.empty()) {
        auto [current, flow] = q.front();
        q.pop();

        for (int e: adj[current]) {
            int next = edges[e].second;
            if (parent[next] == -1 && capacity[e]) {
                parent[next] = e;
                int adjusted_flow = min(flow, capacity[e]);
                if (next == target)
                    return adjusted_flow;
                q.push({next, adjusted_flow});
            }
        }
    }
    return 0;
}

int main(void) {
    int s, t, c;
    int network = 0;

    while (cin >> n) {
        if (n == 0) break;

        capacity.clear();
        edges.clear();
        for (int i = 0; i < maxN; i++)
            adj[i].clear();

        network++;
        cin >> s >> t >> c;
        --s, --t;

        int a, b, cost;
        for (int i = 0; i < c; i++) {
            cin >> a >> b >> cost;
            --a, --b;
            edges.push_back({a, b});
            edges.push_back({b, a});
            adj[a].push_back(2*i);
            adj[b].push_back(2*i+1);
            capacity.push_back(cost);
            capacity.push_back(cost);
        }

        int flow = 0;
        int tmp;
        vector<int> parent(n);
        while ((tmp = bfs(s, t, parent))) {
            flow += tmp;
            int current = t;
            while (current != s) {
                int e = parent[current];
                int previous = edges[e].first;
                capacity[e] -= tmp;
                capacity[e^1] += tmp;
                current = previous;
            }
        }

        cout << "Network " << network << endl;
        cout << "The bandwidth is " << flow << "." << endl;
        cout << endl;
    }

    return 0;
}
