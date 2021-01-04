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
    int n;
    int scenario = 0;

    while (cin >> n) {
        if (n == 0) break;

        scenario++;
        vector<pair<int,int>> stones(n);

        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        for (auto& x: stones) {
            cin >> x.first >> x.second;
        }

        vector<tuple<double,int,int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = sqrt(pow(stones[i].first - stones[j].first, 2) + pow(stones[i].second - stones[j].second, 2));
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        double result;
        for (auto [c, a, b]: edges) {
            a = get_parent(a);
            b = get_parent(b);

            if (a != b) {
                join(a, b);
            }

            if (get_parent(0) == get_parent(1)) {
                result = c;
                break;
            }
        }

        cout << "Scenario #" << scenario << endl;
        printf("Frog Distance = %.3lf\n\n", result);
    }

    return 0;
}
