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

const int maxN = 1e3, maxM = 51;
int n;
bool visited[maxN];
vector<pair<int,int>> adj[maxM];
vector<int> result;
int degree[maxM];

void dfs(int v) {
    for (auto [u, e]: adj[v]) {
        if (!visited[e]) {
            visited[e] = true;
            dfs(u);
        }
    }
    result.push_back(v);
}

int main(void) {
    int t;
    cin >> t;


    for (int T = 1; T <= t; T++) {
        cin >> n;

        result.clear();

        for (int i = 0; i < maxM; i++) {
            degree[i] = 0;
            adj[i].clear();
        }

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        int a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b, --a, --b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
            degree[a]++;
            degree[b]++;
        }

        bool ok = true;
        for (int i = 0; i < 51; i++) {
            if (degree[i] & 1) {
                ok = false;
                break;
            }
        }

        if (T > 1) cout << endl;
        cout << "Case #" << T << endl;

        dfs(a);

        if (!ok || result.size() != n + 1) {
            cout << "some beads may be lost" << endl;
            continue;
        }

        for (int i = 1; i < result.size(); i++) {
            cout << result[i-1] + 1 << " " << result[i] + 1 << endl;
        }
    }

    return 0;
}
