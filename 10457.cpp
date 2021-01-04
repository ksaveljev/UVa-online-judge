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

int n, m;
vector<int> parent, sz;
vector<tuple<int,int,int>> roads;
map<int,bool> visited;
vector<tuple<int,int,int>> trip;

int get_parent(int a) {
    if (parent[a] == a) {
        return parent[a];
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

bool mst(int idx, int from, int to, int& biggest) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = idx; i < m; i++) {
        auto [c, a, b] = roads[i];
        if (get_parent(a) != get_parent(b)) {
            join(a, b);
            if (get_parent(from) == get_parent(to)) {
                biggest = c;
                return true;
            }
        }
    }

    return false;
}

int main(void) {

    while (cin >> n >> m) {
        trip.clear();
        roads.resize(m);
        parent.resize(n);
        sz.resize(n);

        int a, b, c;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c, --a, --b;
            roads[i] = {c, a, b};
        }

        sort(roads.begin(), roads.end());

        int start, end;
        cin >> start >> end;

        int k;
        cin >> k;
        while (k--) {
            cin >> a >> b;
            --a, --b;
            int result = 1e9+7;
            int biggest;
            for (int i = 0; i < m; i++) {
                if (mst(i, a, b, biggest)) {
                    result = min(result, biggest - get<0>(roads[i]));
                } else {
                    break;
                }
            }
            cout << start + end + result << endl;
        }
    }

    return 0;
}
