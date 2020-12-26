#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <tuple>
using namespace std;

const int maxP = 1e4+1;
vector<tuple<int,int,int>> adj[maxP];
vector<int> dist(maxP);
vector<tuple<int,int,int>> parent[maxP];

const int INF = 1e9+5;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, t;

    while (cin >> p >> t) {
        dist.assign(p, INF);
        for (int i = 0; i < p; i++) {
            adj[i].clear();
            parent[i].clear();
        }

        dist[0] = 0;

        int p1, p2, l;
        while (t--) {
            cin >> p1 >> p2 >> l;
            adj[p1].push_back({l, p2, t});
            adj[p2].push_back({l, p1, t});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();

            if (d > dist[v]) continue;

            for (auto [c, u, id]: adj[v]) {
                if (dist[v] + c == dist[u]) {
                    parent[u].push_back({v, c, id});
                } else if (dist[v] + c < dist[u]) {
                    dist[u] = dist[v] + c;
                    parent[u] = {{v, c, id}};
                    q.push({dist[u], u});
                }
            }
        }

        long long result = 0;
        unordered_set<int> visited;
        unordered_set<int> visited_nodes;
        queue<int> nodes;
        nodes.push(p-1);
        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for (auto [v, c, id]: parent[node]) {
                if (visited.find(id) == visited.end()) {
                    //cout << "adding from " << node << " to " << v << " [" << c << "]" << endl;
                    result += 2 * c;
                    visited.insert(id);
                    if (visited_nodes.find(v) == visited_nodes.end()) {
                        nodes.push(v);
                    }
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
