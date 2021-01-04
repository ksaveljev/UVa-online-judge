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

const unsigned int INF = 4e9+7;
int v, e;
const int maxV = 100;
int parent[maxV], sz[maxV];
vector<tuple<int,int,int>> edges;

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

bool mst(int idx, vector<int>& result) {
    for (int i = 0; i < v; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < e; i++) {
        if (i == idx) continue;
        auto [c, a, b] = edges[i];
        if (get_parent(a) != get_parent(b)) {
            join(a, b);
            result.push_back(i);
            if (result.size() == v - 1) {
                return true;
            }
        }
    }

    return false;
}

unsigned int calc_result(vector<int>& second) {
    unsigned int result = 0;
    for (int idx: second) {
        result += get<0>(edges[idx]);
    }
    return result;
}

int main(void) {
    int t;

    cin >> t;

    for (int T = 1; T <= t; T++) {
        cout << "Case #" << T << " : ";
        cin >> v >> e;

        edges.clear();

        int a, b, c;
        for (int i = 0; i < e; i++) {
            cin >> a >> b >> c;
            --a, --b;
            edges.push_back({c, a, b});
        }

        if (v == 1) {
            cout << "No second way" << endl;
            continue;
        }

        sort(edges.begin(), edges.end());

        vector<int> first;
        if (mst(-1, first)) {
            unsigned int result = INF;
            for (int idx: first) {
                vector<int> second;
                if (mst(idx, second)) {
                    result = min(result, calc_result(second));
                }
            }
            if (result == INF) {
                cout << "No second way" << endl;
            } else {
                cout << result << endl;
            }
        } else {
            cout << "No way" << endl;
        }
    }

    return 0;
}
