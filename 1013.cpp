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

vector<int> parent, sz, weight;

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
        weight[a] += weight[b];
    }
}

int main(void) {
    int n;
    int group = 0;

    while (cin >> n) {
        if (n == 0) break;

        group++;

        parent.resize(n);
        sz.resize(n);
        weight.resize(n);

        int a, b, c;
        vector<pair<int,int>> islands(n);
        vector<int> m(n);
        for (int i = 0; i < n; i++) {
            cin >> islands[i].first >> islands[i].second;
            islands[i].first--, islands[i].second--;
            cin >> m[i];
        }

        vector<tuple<double,int,int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = hypot(islands[i].first - islands[j].first, islands[i].second - islands[j].second);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        double div = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
            weight[i] = m[i];
            div += m[i];
        }

        for (auto [c, a, b]: edges) {
            int pa = get_parent(a);
            int pb = get_parent(b);
            int p0 = get_parent(0);
            if (pa != pb) {
                if (pa == p0) {
                    sum += weight[pb] * c;
                }
                if (pb == p0) {
                    sum += weight[pa] * c;
                }
                join(pa, pb);
            }
        }

        printf("Island Group: %d Average %.2lf\n\n", group, sum / div);
    }

    return 0;
}
