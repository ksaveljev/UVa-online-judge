#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
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
    int t;

    cin >> t;

    while (t--) {
        int n, m;

        parent.clear();
        sz.clear();

        cin >> n >> m;

        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        vector<tuple<int,int,int>> edges;

        int a, b, c;
        while (m--) {
            cin >> a >> b >> c;
            --a, --b;
            edges.push_back({c, a, b});
        }

        sort(edges.begin(), edges.end());

        vector<int> mst;
        int cheapest = 0;
        for (int i = 0; i < edges.size(); i++) {
            auto [c, a, b] = edges[i];
            if (get_parent(a) != get_parent(b)) {
                mst.push_back(i);
                cheapest += c;
                join(a, b);
            }
        }

        int second_cheapest = -1;
        for (int i = 0; i < mst.size(); i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                parent[j] = j;
                sz[j] = 1;
            }
            int tmp = 0;
            for (int j = 0; j < edges.size(); j++) {
                if (j == mst[i]) continue;
                auto [c, a, b] = edges[j];
                if (get_parent(a) != get_parent(b)) {
                    v.push_back(j);
                    tmp += c;
                    join(a, b);
                }
            }
            if (v.size() != mst.size()) continue;

            if (second_cheapest == -1) {
                second_cheapest = tmp;
            } else {
                second_cheapest = min(second_cheapest, tmp);
            }
        }

        cout << cheapest << " " << second_cheapest << endl;
    }

    return 0;
}
