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

const int maxN = 1e6;
vector<int> parent, sz;

void make_set(int a) {
    if (parent[a] == -1) {
        parent[a] = a;
        sz[a] = 1;
    }
}

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
    int w;

    cin >> w;

    while (w--) {
        int n;
        cin >> n;

        parent.assign(maxN, -1);
        sz.assign(maxN, 1);

        vector<pair<int,int>> sensors;
        int x, y;

        while (cin >> x) {
            if (x == -1) break;
            cin >> y;
            sensors.push_back({x, y});
        }

        vector<tuple<double,int,int>> edges;

        for (int i = 0; i < sensors.size(); i++) {
            make_set(i);
            for (int j = i + 1; j < sensors.size(); j++) {
                double dist = hypot(sensors[i].first - sensors[j].first, sensors[i].second - sensors[j].second);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int component = sensors.size();
        for (auto [c, a, b]: edges) {
            int pa = get_parent(a);
            int pb = get_parent(b);
            if (pa != pb) {
                join(pa, pb);
                component--;
                if (component <= n) {
                    cout << ceil(c) << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
