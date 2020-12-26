#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string,vector<string>> adj, adj2;
vector<string> st;
map<string,bool> visited;
map<int,vector<string>> comp;

void dfs1(string v) {
    visited[v] = true;

    for (string u: adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }

    st.push_back(v);
}

void dfs2(string v, int j) {
    visited[v] = true;
    comp[j].push_back(v);

    for (string u: adj2[v]) {
        if (!visited[u]) {
            dfs2(u, j);
        }
    }
}

int main(void) {
    int n, m;
    string a, b;
    int result = 0;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        result++;

        adj.clear();
        adj2.clear();
        visited.clear();
        comp.clear();
        st.clear();

        while (m--) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj2[b].push_back(a);
        }

        for (auto [k, v]: adj) {
            if (!visited[k]) {
                dfs1(k);
            }
        }

        reverse(st.begin(), st.end());
        visited.clear();

        int j = 0;
        for (auto v: st) {
            if (!visited[v]) {
                dfs2(v, j++);
            }
        }

        if (result > 1) cout << endl;
        cout << "Calling circles for data set " << result << ":" << endl;
        for (auto [k, v]: comp) {
            for (int i = 0; i < v.size(); i++) {
                if (i > 0) cout << ", ";
                cout << v[i];
            }
            cout << endl;
        }
    }

    return 0;
}
