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

vector<int> adj[30];
vector<int> result;
map<int,bool> visited;
set<char> s;

void dfs(int v) {
    visited[v] = true;

    for (int u: adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }

    result.push_back(v);
}

int main(void) {
    string input;
    vector<string> v;

    while (getline(cin, input)) {
        if (input == "#") break;
        v.push_back(input);

        for (int i = 0; i < input.size(); i++) {
            s.insert(input[i]);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            int idx = 0;
            while (idx < v[i].size() && idx < v[j].size()) {
                if (v[i][idx] != v[j][idx]) {
                    adj[v[i][idx] - 'A'].push_back(v[j][idx] - 'A');
                    break;
                }
                idx++;
            }
        }
    }

    for (char c: s) {
        if (!visited[c - 'A']) {
            dfs(c - 'A');
        }
    }

    reverse(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << char(result[i] + 'A');
    }
    cout << endl;

    return 0;
}
