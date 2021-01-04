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

const int INF = 1e9+7;

int n;
vector<pair<int,int>> stations;
vector<vector<int>> adj;
map<int,bool> visited;

int dfs(int v) {
    if (visited[v]) return 0;
    visited[v] = true;
    return 1 + dfs(adj[v][0]) + dfs(adj[v][1]);
}

int main(void) {
    int counter = 0;
    while (cin >> n) {
        if (n == 0) break;

        counter++;
        if (counter == 56) {
            cout << n << endl;
        }

        stations.resize(n);
        adj.assign(n, {});

        for (int i = 0; i < n; i++) {
            cin >> stations[i].first >> stations[i].second;
        }

        for (int i = 0; i < n; i++) {
            int mina = INF, minb = INF;
            int a = i, b = i;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int dist = (stations[i].first - stations[j].first) * (stations[i].first - stations[j].first) + (stations[i].second - stations[j].second) * (stations[i].second - stations[j].second);
                if (dist <= mina) {
                    minb = mina;
                    mina = dist;
                    b = a;
                    a = j;
                } else if (dist < minb) {
                    minb = dist;
                    b = j;
                }
            }

            adj[i].push_back(a);
            adj[i].push_back(b);
        }

        visited.clear();
        //visited[-1] = true;
        if (dfs(0) == n) {
            cout << "All stations are reachable." << endl;
        } else {
            cout << "There are stations that are unreachable." << endl;
        }
    }

    return 0;
}
