#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> st;
map<int,bool> visited;

void dfs1(int v) {
    visited[v] = true;

    for (int u: adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }

    st.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;

    for (int u: adj[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
}

int main(void) {
    int t;

    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        adj.clear();
        adj.resize(n);
        visited.clear();
        st.clear();

        int a, b;
        while (m--) {
            cin >> a >> b, --a, --b;
            adj[a].push_back(b);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i);
            }
        }

        reverse(st.begin(), st.end());
        visited.clear();

        int result = 0;
        for (int v: st) {
            if (!visited[v]) {
                result++;
                dfs2(v);
            }
        }

        cout << result << endl;
    }

    return 0;
}
