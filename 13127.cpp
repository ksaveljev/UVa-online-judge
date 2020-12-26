#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, m, b, p;
const int maxN = 1e3+1;
vector<pair<int,int>> adj[maxN];
int banks[maxN];
int stations[maxN];
int dist[maxN];

const int INF = 1e9+5;

int main(void) {

    while (cin >> n >> m >> b >> p) {
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }

        int x, y, c;
        while (m--) {
            cin >> x >> y >> c;
            adj[x].push_back({c, y});
            adj[y].push_back({c, x});
        }

        for (int i = 0; i < b; i++) {
            cin >> banks[i];
        }

        for (int i = 0; i < p; i++) {
            cin >> stations[i];
        }

        priority_queue<pair<int,int>> q;

        for (int i = 0; i < n; i++)
            dist[i] = INF;

        for (int i = 0; i < p; i++) {
            int station = stations[i];
            dist[station] = 0;
            q.push({0, station});
        }

        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();

            if (d > dist[v]) continue;

            for (auto [c, u]: adj[v]) {
                if (dist[v] + c < dist[u]) {
                    dist[u] = dist[v] + c;
                    q.push({dist[u], u});
                }
            }
        }

        int result = -INF;
        vector<int> result_banks;
        for (int i = 0; i < b; i++) {
            if (dist[banks[i]] > result) {
                result = dist[banks[i]];
                result_banks.clear();
                result_banks.push_back(banks[i]);
            } else if (dist[banks[i]] == result) {
                result_banks.push_back(banks[i]);
            }
        }

        cout << result_banks.size() << " ";
        if (result == INF) cout << "*" << endl;
        else cout << result << endl;
        sort(result_banks.begin(), result_banks.end());
        for (int i = 0; i < result_banks.size(); i++) {
            if (i > 0) cout << " ";
            cout << result_banks[i];
        }
        cout << endl;
    }

    return 0;
}
