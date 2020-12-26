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

int calc_diff(int key1, int key2) {
    int a[4], b[4];

    for (int i = 0; i < 4; i++) {
        a[3-i] = key1 % 10;
        b[3-i] = key2 % 10;
        key1 /= 10;
        key2 /= 10;
    }

    int result = 0;

    for (int i = 0; i < 4; i++) {
        if (a[i] >= b[i]) {
            result += min(a[i] - b[i], 10 + b[i] - a[i]);
        } else {
            result += min(b[i] - a[i], 10 + a[i] - b[i]);
        }
    }

    return result;
}

int main(void) {
    int T;

    cin >> T;

    while (T--) {
        int n;

        cin >> n;

        parent.resize(n+1);
        sz.resize(n+1);

        vector<int> keys(n);
        for (auto& k: keys) {
            cin >> k;
        }
        keys.push_back(0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;

        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int diff = calc_diff(keys[i], keys[j]);
                q.push({diff, i, j});
            }
        }

        int result = 0;
        bool zero = false;

        while (!q.empty()) {
            auto [c, a, b] = q.top();
            q.pop();

            if (a == n || b == n) {
                if (zero) continue;
                zero = true;
            }

            int pa = get_parent(a);
            int pb = get_parent(b);

            if (pa != pb) {
                join(pa, pb);
                result += c;
            }
        }

        cout << result << endl;
    }

    return 0;
}
