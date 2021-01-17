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

const int maxN = 5000, maxM = 12500000;
int n, m;
vector<int> parent(maxN), sz(maxN);
tuple<int,int,int> edges[maxM];

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

bool ok(int x) {
    int mine = 1e9, maxe = 0;

    for (int i = 0; i < m; i++) {
        auto [k, u, v] = edges[i];
        int pu = get_parent(u);
        int pv = get_parent(v);
        if (pu == x && pv == x) {
            mine = min(mine, -k);
        } else if (pu == x || pv == x) {
            maxe = max(maxe, -k);
        }
    }

    return mine > maxe;
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        int u, v, k;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> k;
            --u, --v;
            edges[i] = {-k, u, v};
        }

        sort(edges, edges + m);

        int taken = 0;
        int idx = 0;
        int result = 0;
        while (taken < n - 1) {
            auto [k, u, v] = edges[idx];
            idx++;

            int pu = get_parent(u);
            int pv = get_parent(v);

            if (pu == pv) continue;

            join(pu, pv);
            taken++;

            int x = get_parent(pu);
            if (ok(x)) {
                result += sz[x];
            }
        }

        cout << result << endl;
    }

    return 0;
}
