#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

const int maxC = 1e2;
const int INF = 1e9+7;

int parent[maxC], sz[maxC];
vector<vector<pair<int,int>>> adj;
map<int,bool> visited;
int result;

int get_parent(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = get_parent(parent[a]);
}

void join(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

bool dfs(int start, int end) {
    if (start == end) return true;
    if (visited[start]) return false;
    visited[start] = true;
    for (auto [next, c]: adj[start]) {
        if (dfs(next, end)) {
            result = max(result, c);
            return true;
        }
    }
    return false;
}

int main(void) {
    int c, s, q;
    int scenario = 0;

    while (cin >> c >> s >> q) {
        if (c == 0 && s == 0 && q == 0) break;

        scenario++;
        if (scenario > 1) cout << endl;
        cout << "Case #" << scenario << endl;

        int c1, c2, d;
        vector<tuple<int,int,int>> edges;

        for (int i = 0; i < c; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        adj.clear();
        adj.resize(c);

        while (s--) {
            cin >> c1 >> c2 >> d;
            --c1, --c2;
            edges.push_back({d, c1, c2});
        }

        sort(edges.begin(), edges.end());

        for (auto [cc, a, b]: edges) {
            int pa = get_parent(a);
            int pb = get_parent(b);
            if (pa != pb) {
                adj[a].push_back({b, cc});
                adj[b].push_back({a, cc});
                join(pa, pb);
            }
        }

        while (q--) {
            cin >> c1 >> c2;
            --c1, --c2;

            if (get_parent(c1) != get_parent(c2)) {
                cout << "no path" << endl;
            } else {
                result = -1;
                visited.clear();
                dfs(c1, c2);
                cout << result << endl;
            }
        }
    }

    return 0;
}
