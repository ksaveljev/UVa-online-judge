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

const int maxN = 1e5+1;
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
    int a, b;

    while (cin >> a >> b) {
        int refusals = 0;
        parent.assign(maxN, -1);
        sz.assign(maxN, 1);

        make_set(a);
        make_set(b);
        join(a, b);

        while (cin >> a) {
            if (a == -1) break;
            cin >> b;

            make_set(a);
            make_set(b);

            int pa = get_parent(a);
            int pb = get_parent(b);
            if (pa == pb) {
                refusals++;
            } else {
                join(pa, pb);
            }
        }

        cout << refusals << endl;
    }

    return 0;
}
