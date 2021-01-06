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

const int INF = 1e9+7, maxP = 500, maxS = 20, maxC = 100;
int n, p, s, c, m;
vector<int> adj[maxP + maxS + 2];
int capacity[maxP + maxS + 2][maxP + maxS + 2];

int bfs(int source, int target, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int,int>> q;
    q.push({source, INF});
    while (!q.empty()) {
        auto [current, flow] = q.front();
        q.pop();

        for (int next: adj[current]) {
            if (parent[next] == -1 && capacity[current][next]) {
                parent[next] = current;
                int adjusted_flow = min(flow, capacity[current][next]);
                if (next == target)
                    return adjusted_flow;
                q.push({next, adjusted_flow});
            }
        }
    }
    return 0;
}

int main(void) {
    cin >> n;

    while (n--) {
        cin >> p >> s >> c >> m;

        int source = 0;
        int target = p + s + 1;

        for (int i = 0; i < maxP + maxS + 2; i++) {
            adj[i].clear();
            for (int j = 0; j < maxP + maxS + 2; j++)
                capacity[i][j] = 0;
        }

        for (int i = 1; i <= p; i++) {
            adj[source].push_back(i);
            adj[i].push_back(source);
            capacity[source][i] = 1;
            capacity[i][source] = 0;
        }

        for (int i = p + 1; i <= p + s; i++) {
            adj[i].push_back(target);
            adj[target].push_back(i);
            capacity[i][target] = c;
        }

        int a, b;
        while (m--) {
            cin >> a >> b;
            adj[a].push_back(p+b);
            adj[p+b].push_back(a);
            capacity[a][p+b] = 1;
        }

        int flow = 0;
        int tmp;
        vector<int> parent(p + s + 2);
        while ((tmp = bfs(source, target, parent))) {
            flow += tmp;
            int current = target;
            while (current != source) {
                int previous = parent[current];
                capacity[previous][current] -= tmp;
                capacity[current][previous] += tmp;
                current = previous;
            }
        }

        cout << flow << endl;
    }

    return 0;
}
