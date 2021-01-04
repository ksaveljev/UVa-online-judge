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

int n, m;
map<string,int> ids;
map<int,string> names;
vector<int> indegree;
vector<vector<int>> adj;

int main(void) {
    int scenario = 0;
    string input;

    while (cin >> n) {
        scenario++;
        indegree.assign(n, 0);
        adj.assign(n, {});

        for (int i = 0; i < n; i++) {
            cin >> input;
            ids[input] = i;
            names[i] = input;
        }

        cin >> m;

        string a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            indegree[ids[b]]++;
            adj[ids[a]].push_back(ids[b]);
        }

        cout << "Case #" << scenario << ": Dilbert should drink beverages in this order:";

        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int v = q.top();
            q.pop();

            cout << " " << names[v];

            for (int u: adj[v]) {
                indegree[u]--;
                if (indegree[u] == 0) {
                    q.push(u);
                }
            }
        }
        cout << "." << endl << endl;
    }

    return 0;
}
