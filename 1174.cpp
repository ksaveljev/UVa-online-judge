#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <tuple>
#include <queue>
using namespace std;

map<string,string> parent;
map<string,string> sz;

string get_parent(string a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = get_parent(parent[a]);
}

void join(string a, string b) {
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
        int m, n;

        cin >> m >> n;

        parent.clear();
        sz.clear();

        priority_queue<tuple<int,string,string>, vector<tuple<int,string,string>>, greater<tuple<int,string,string>>> q;
        string a, b;
        int c;

        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            parent[a] = a;
            parent[b] = b;
            sz[a] = 1;
            sz[b] = 1;
            q.push({c, a, b});
        }

        int edges = 0;
        int result = 0;
        while (!q.empty()) {
            if (edges == n - 1) break;

            auto [c, a, b] = q.top();
            q.pop();

            a = get_parent(a);
            b = get_parent(b);

            if (a != b) {
                join(a, b);
                result += c;
                edges++;
            }
        }

        cout << result << endl;
        if (t) cout << endl;
    }

    return 0;
}
