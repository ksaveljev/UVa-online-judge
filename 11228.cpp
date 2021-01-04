#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

vector<int> parent;
vector<int> sz;

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
    int t, n;
    double r;

    cin >> t;

    for (int T = 1; T <= t; T++) {
        cout << "Case #" << T << ": ";

        cin >> n >> r;

        parent.clear();
        sz.clear();
        vector<pair<int,int>> cities(n);
        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        int x, y;
        for (auto& city: cities) {
            cin >> city.first >> city.second;
        }

        vector<tuple<double,int,int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = sqrt(pow(cities[i].first - cities[j].first, 2) + pow(cities[i].second - cities[j].second, 2));
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int states = n;
        double road = 0;
        double railroad = 0;

        for (auto [w, a, b]: edges) {
            if (get_parent(a) != get_parent(b)) {
                if (w <= r) {
                    states--;
                    road += w;
                } else {
                    railroad += w;
                }
                join(a, b);
            }
        }

        printf("%d %.lf %.lf\n", states, road, railroad);
    }

    return 0;
}
