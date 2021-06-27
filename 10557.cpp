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
#include <cstdio>
#include <list>
#include <cassert>
#include <climits>
#include <cassert>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int INF = 1e9+7;

void dfs(int v, vector<vector<int>>& adj, vector<int>& reachable, vector<bool>& visited) {
    visited[v] = true;
    reachable.push_back(v);

    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, reachable, visited);
        }
    }
}

int main(void) {
    int n;

    while (cin >> n) {
        if (n == -1) break;

        vector<int> energy(n);
        vector<pair<int,int>> edges;
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            cin >> energy[i];

            int d;
            cin >> d;

            int x;
            while (d--) {
                cin >> x, --x;
                edges.push_back({i, x});
                adj[x].push_back(i);
            }
        }

        vector<int> dist(n, -INF);
        dist[0] = 100;

        for (int i = 0; i < n - 1; i++) {
            for (auto [a, b] : edges) {
                if (dist[a] > 0) {
                    if (dist[a] + energy[b] > dist[b]) {
                        dist[b] = dist[a] + energy[b];
                    }
                }
            }
        }

        if (dist[n-1] > 0) {
            cout << "winnable\n";
        } else {
            vector<int> cycle;
            for (auto [a, b] : edges) {
                if (dist[a] > 0) {
                    if (dist[a] + energy[b] > dist[b]) {
                        dist[b] = dist[a] + energy[b];
                        cycle.push_back(b);
                    }
                }
            }

            if (cycle.size() == 0) {
                cout << "hopeless\n";
            } else {
                vector<int> reachable;
                vector<bool> visited(n, false);
                dfs(n-1, adj, reachable, visited);

                bool ok = false;
                for (auto a : reachable) {
                    for (auto b : cycle) {
                        if (a == b) {
                            ok = true;
                        }
                    }
                }

                if (ok) cout << "winnable\n";
                else cout << "hopeless\n";
            }
        }
    }

    return 0;
}
