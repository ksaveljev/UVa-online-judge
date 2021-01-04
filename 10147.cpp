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

vector<int> parent, sz;

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

int main(void) {
    int t;

    cin >> t;

    while (t--) {
        int n;
        int x, y;

        cin >> n;
        vector<pair<int,int>> towns(n);
        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
            cin >> towns[i].first >> towns[i].second;
        }

        vector<tuple<double,int,int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = hypot(towns[i].first - towns[j].first, towns[i].second - towns[j].second);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int m;
        cin >> m;

        while (m--) {
            cin >> x >> y;
            --x, --y;
            join(x, y);
        }

        bool constructed = false;

        for (auto [c, a, b]: edges) {
            int pa = get_parent(a);
            int pb = get_parent(b);
            if (pa != pb) {
                cout << a + 1 << " " << b + 1 << endl;
                join(pa, pb);
                constructed = true;
            }
        }

        if (!constructed) {
            cout << "No new highways need" << endl;
        }

        if (t) cout << endl;
    }

    return 0;
}
