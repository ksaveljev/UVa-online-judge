#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<int> parent;
vector<int> sz;

int get_parent(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = get_parent(parent[v]);
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
    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ":" << endl;
        int n;
        cin >> n;

        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;

        int c;
        char tmp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c;
                if (j + 1 < n)
                    cin >> tmp;

                if (c > 0) {
                    q.push({c, i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [c, a, b] = q.top();
            q.pop();

            int pa = get_parent(a);
            int pb = get_parent(b);

            if (pa != pb) {
                join(pa, pb);
                cout << char('A' + a) << "-" << char('A'+b) << " " << c << endl;
            }
        }
    }

    return 0;
}
