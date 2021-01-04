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
        int n, m;

        cin >> n >> m;

        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        int a, b, c;
        vector<tuple<int,int,int>> edges;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            --a, --b;
            edges.push_back({c, a, b});
        }

        sort(edges.rbegin(), edges.rend());
        int result = 0;

        for (auto [c, a, b]: edges) {
            int pa = get_parent(a);
            int pb = get_parent(b);

            if (pa == pb) {
                result += c;
            } else {
                join(pa, pb);
            }
        }

        cout << result << endl;
    }

    return 0;
}
