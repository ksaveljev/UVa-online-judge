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

int n, m;
vector<int> indegree;
vector<vector<int>> adj;

int main(void) {
    int a, b;

    while (cin >> n) {
        indegree.assign(n, 0);
        adj.assign(n, {});

        cin >> m;

        if (n == 0 && m == 0) break;

        while (m--) {
            cin >> a >> b;
            --a, --b;

            adj[a].push_back(b);
            indegree[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            result.push_back(v);

            for (int u: adj[v]) {
                indegree[u]--;
                if (indegree[u] == 0) {
                    q.push(u);
                }
            }
        }

        if (result.size() != n) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int v: result) {
                cout << v + 1 << endl;
            }
        }
    }

    return 0;
}
