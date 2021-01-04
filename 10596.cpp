#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

const int maxN = 200;
const int maxR = 10001;
int n, r;
vector<pair<int,int>> adj[maxN];
bool visited[maxR];
int degree[maxN];
vector<int> result;

void dfs(int v) {
    for (auto [u, e]: adj[v]) {
        if (!visited[e]) {
            visited[e] = true;
            dfs(u);
        }
    }
    result.push_back(v);
}

int main(void) {
    while (cin >> n >> r) {
        result.clear();
        for (int i = 0; i < maxN; i++) {
            adj[i].clear();
            degree[i] = 0;
        }
        for (int i = 0; i < r; i++) {
            visited[i] = false;
        }

        int a, b;
        for (int i = 0; i < r; i++) {
            cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
            degree[a]++;
            degree[b]++;
        }

        if (r == 0) {
            cout << "Not Possible" << endl;
            continue;
        } else if (r == 1) {
            if (a == b) {
                cout << "Possible" << endl;
            } else {
                cout << "Not Possible" << endl;
            }
            continue;
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (degree[i] & 1) {
                ok = false;
                break;;
            }
        }

        if (!ok) {
            cout << "Not Possible" << endl;
            continue;
        }

        dfs(a);

        for (int i = 0; i < r; i++) {
            if (!visited[i]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "Not Possible" << endl;
        } else {
            cout << "Possible" << endl;
        }
    }

    return 0;
}
